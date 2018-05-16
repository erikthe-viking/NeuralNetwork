#include "net.h"
#include <vector>
#include <iostream>
#include <cstdlib>
#include <cassert>
#include <cmath>
#include <fstream>
#include <sstream>
 
using namespace std;
Net::Net(const std::vector<unsigned> &topology)
{	bool x = false;
	int numLayers = topology.size();
	for (int layerNum = 0; layerNum < numLayers; ++layerNum) {
		m_layers.push_back(Neuron::Layer());
		unsigned numOutputs = layerNum == topology.size() - 1 ? 0 : topology[layerNum + 1];
		
		// we have made a new layer, now fill it with neurons and 
		// add a bias neuron to the layer:
		for (int i = 0; i <= topology[layerNum]; ++i) {
			if(numLayers - 1 == i){
				x = true;
			}
			m_layers.back().push_back(Neuron(numOutputs, i,x));
			
		}
		// force the bias node's output value to 1.0. It's the last neuron created above
		m_layers.back().back().setOutputVal(1.0);
	}
}

void Net::feedForward(const std::vector<double> &inputVals) 
{
	assert(inputVals.size() == m_layers[0].size() - 1);

	// assign (latch) the input values into the input neurons
	for (unsigned i = 0; i < inputVals.size(); ++i) {
		m_layers[0][i].setOutputVal(inputVals[i]);
	}

	// forward propagate
	for (int j = 1; j < m_layers.size(); ++j) {
		Neuron::Layer &prevLayer = m_layers[j - 1];
		for (int n = 0; n < m_layers[j].size() - 1; ++n) {
			m_layers[j][n].feedForward(prevLayer);
		}
	}
}

void Net::backPropogation(const std::vector<double> &targetVals)
{
	// calc overall net error (rms of output neuron errors)

	Neuron::Layer &outputLayer = m_layers.back();
	m_error = 0.0;

	for (int n = 0; n < outputLayer.size() - 1; ++n) {
		double delta = targetVals[n] - outputLayer[n].getOutputVal();
		m_error += delta * delta;
	}
	m_error /= outputLayer.size() - 1;
	m_error = sqrt(m_error);  // RMS

	// implement a recent avg measurement
	m_recentAverageError = 
			(m_recentAverageError * m_recentAverageSmoothingFactor + m_error)
			/ (m_recentAverageSmoothingFactor + 1.0);

	// calc output layer gradients

	for (int n = 0; n < outputLayer.size() - 1; ++n) {
		outputLayer[n].findOutputGradient(targetVals[n]);
	}

	// calc gradients on hidden layers

	for (int layerNum = m_layers.size() - 2; layerNum > 0; --layerNum) {
		Neuron::Layer &hiddenLayer = m_layers[layerNum];
		Neuron::Layer &nextLayer = m_layers[layerNum + 1];

		for (int n = 0; n < hiddenLayer.size(); ++n) {
			hiddenLayer[n].findHiddenGradient(nextLayer);
		}
	}

	// for all layers from outputs to first hidden layer,
	// update connection weights

	for (int j = m_layers.size() - 1; j > 0; --j) {
		Neuron::Layer &layer = m_layers[j];
		Neuron::Layer &prevLayer = m_layers[j - 1];

		for (int n = 0; n < layer.size() - 1; ++n) {
			layer[n].updateInputWeights(prevLayer);
		}
	}
}

void Net::Output(std::vector<double> &resultVals) const
{
	resultVals.clear();

	for (int n = 0; n < m_layers.back().size() - 1; ++n)
	{
		resultVals.push_back(m_layers.back()[n].getOutputVal());
	}
}
