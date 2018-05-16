#include "neuron.h"
#include <vector>
#include <iostream>
#include <cmath>

using namespace std;
double Neuron::eta = .5; // overall net learning rate     0.5 is the best so far
double Neuron::alpha = .85; // momentum, multiplier of last deltaWeight   .85 is the best so far

Neuron::Neuron(int numOutputs, int myIndex, bool g)
{
	for(int c = 0; c < numOutputs; ++c){

		 Neuron::outputWeight.push_back(Connection());
		 Neuron::outputWeight.back().weight = randomNum();
    	 }
     last_layer = g;
     Neuron::n_index = myIndex;
}

void Neuron::feedForward(const Layer &prevLayer)
{
	    double sum = 0.0;

        for (int n = 0; n < prevLayer.size(); ++n){

            sum += prevLayer[n].getOutputVal() * prevLayer[n].outputWeight[Neuron::n_index].weight;
        }
        
        if(this->last_layer){

            this->output = Neuron::sigmoidFunction(sum);

        }
        else{
            this->output = transferFunction(sum);
        }
}

double Neuron::transferFunction(double x)
{
	return tanh(x);
}
double Neuron::sigmoidFunction(double x){
	 
    return (1.0/(1.0 + exp(-1 * x)));
}
double Neuron::transferFunctionDerivative(double x)
{
	// Derivative of Tanh
	return 1.0 - x * x;
}
void Neuron::setOutputVal(double val) { 
	output = val; 
}
double Neuron::getOutputVal(void) const{ 
	return output; 
};

void Neuron::findOutputGradient(double targetVal)
{
	double delta = targetVal - output;
	gradient = delta * Neuron::transferFunctionDerivative(output);
}

void Neuron::findHiddenGradient(const Layer &nextLayer)
{
	double dow = sumLayer(nextLayer);
	gradient = dow * Neuron::transferFunctionDerivative(output);
}

double Neuron::sumLayer(const Layer &nextLayer) const
{
	double sum = 0.0;

	// sum our contributions of the errors at the nodes we feed

	for (int n = 0; n < nextLayer.size() - 1; ++n) {
		sum += outputWeight[n].weight * nextLayer[n].gradient;
	}

	return sum;
}

void Neuron::updateInputWeights(Layer &prevLayer)
{
	// the weights to be updated are in the Connection container
	// in the neurons in the preceeding layer

	for (int n = 0; n < prevLayer.size(); ++n) {
		Neuron &neuron = prevLayer[n];
		double oldDeltaWeight = neuron.outputWeight[n_index].deltaWeight;
		double newDeltaWeight =
				// individual input, magnified by the gradient and train rate:
				eta
				* neuron.getOutputVal()
				* gradient
				// also add momentum = a fraction of the previous delta weight
				+ alpha
				* oldDeltaWeight;
	//	cout << "Weights:" << newDeltaWeight << endl;
		neuron.outputWeight[n_index].deltaWeight = newDeltaWeight;
		neuron.outputWeight[n_index].weight += newDeltaWeight;
	}
}