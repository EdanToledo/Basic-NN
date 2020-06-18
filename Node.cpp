#include "Node.h"

//parameter Constructor for Node
TLDEDA001::Node::Node(const double threshold, const double bias, const bool sigmoid)
{
    this->threshold = threshold;
    this->sigmoid = sigmoid;
    this->bias = bias;
}

//Adjust Weights based on expected output and returns current output
const double TLDEDA001::Node::AdjustWeights(double learningrate, double expectedOutput)
{

    double out = Output();
    bias += learningrate * (expectedOutput - out);

    for (int i = 0; i < weights.size(); i++)
    {
        weights[i] += learningrate * (expectedOutput - out) * inputs[i];
    }

    return out;
}

//take all inputs and apply respective weights and bias and then Apply activation Function and return the output
const double TLDEDA001::Node::Output() const
{
    double tot = 0;
    for (int i = 0; i < inputs.size(); i++)
    {
        tot += inputs[i] * weights[i];
    }
    tot += bias;

    if (sigmoid)
    {
        return SigmoidActivation(tot);
    }
    else
    {
        return ThresholdActivation(tot);
    }
}

//initialises the weights and bias and/or resets them
void TLDEDA001::Node::ResetWeights(const int NumOfWeights)
{
    weights.clear();
    bias = 0;
    for (int i = 0; i < NumOfWeights; i++)
    {
        weights.push_back(0);
    }
}
//sets the inputs
void TLDEDA001::Node::setInputs(const std::vector<double> inputs)
{
    this->inputs.clear();
    this->inputs = inputs;
}

//Set threshold value for node
void TLDEDA001::Node::setThreshold(const double threshold)
{
    this->threshold = threshold;
}

//Manually set the bias for the node
void TLDEDA001::Node::setBias(const double bias)
{
    this->bias = bias;
}

//Print to console the threshold and bias values
void TLDEDA001::Node::PrintParameters() const
{

    std::cout << "Threshold: " << this->threshold << std::endl;
    std::cout << "Bias: " << this->bias << std::endl;
    for (int i = 0; i < weights.size(); i++)
    {
        std::cout << "Weight " << i << ": " << weights[i] << std::endl;
    }
}

 //Manually set the weights
void TLDEDA001::Node::setWeights(const std::vector<double> newWeights)
{
    weights.clear();
    for (int i = 0; i < newWeights.size(); i++)
    {
        weights.push_back(newWeights[i]);
    }
}

//Threshold activation function
const double TLDEDA001::Node::ThresholdActivation(const double input) const
{

    return (input <= threshold) ? 0 : 1;
}

//sigmoid activation function
const double TLDEDA001::Node::SigmoidActivation(const double input) const
{
    return ((exp(input)) / (exp(input) + 1));
}