#include <vector>
#include <cstdlib>

struct Connection{

    double weight = 0.25; 
    double deltaWeight;

};
class Neuron
{
public:

    typedef std::vector<Neuron> Layer;
	Neuron(int numOutputs, int myIndex, bool g);
	void setOutputVal(double val);
	double getOutputVal(void) const;
	void feedForward(const Layer &prevLayer);
	void findOutputGradient(double targetVal);
	void findHiddenGradient(const Layer &nextLayer);
	void updateInputWeights(Layer &prevLayer);
	bool last_layer;

private:
	static double eta; //  training rate
	static double alpha; // multiplier of weight delta
	static double transferFunction(double x);
 	double sigmoidFunction(double x);  // sigmoid
	static double transferFunctionDerivative(double x); //derivative
	static double randomNum(void) { return (double)rand() / double(RAND_MAX); }
	double sumLayer(const Layer &nextLayer) const;
	double output;
	std::vector<Connection> outputWeight;
	int n_index;
	double gradient;
};
