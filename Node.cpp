#include "Node.h"

//parameter Constructor for Node
TLDEDA001::Node::Node(const float threshold, const float bias, const bool sigmoid)
{
    this->threshold = threshold;
    this->sigmoid = sigmoid;
    this->bias = bias;
}

//Adjust Weights based on expected output
const float TLDEDA001::Node::AdjustWeights(float learningrate, float expectedOutput)
{

    float out = Output();
    bias += learningrate * (expectedOutput - out);

    for (int i = 0; i < weights.size(); i++)
    {
        weights[i] += learningrate * (expectedOutput - out) * inputs[i];
    }

    return out;
}

//Apply activation Function
const float TLDEDA001::Node::Output() const
{
    float tot = 0;
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


void TLDEDA001::Node::ResetWeights(const int NumOfWeights)
{
    weights.clear();
    bias = 0;
    for (int i = 0; i < NumOfWeights; i++)
    {
        //  float r = static_cast<float>(rand()) / static_cast<float>(RAND_MAX);

        weights.push_back(0);
    }
}

void TLDEDA001::Node::setInputs(const std::vector<float> inputs)
{
    this->inputs.clear();
    this->inputs = inputs;
}

//Set threshold value for node
void TLDEDA001::Node::setThreshold(const float threshold)
{
    this->threshold = threshold;
}

void TLDEDA001::Node::setBias(const float bias)
{
    this->bias = bias;
}


void TLDEDA001::Node::PrintParameters() const
{

    std::cout << "Threshold: " << this->threshold << std::endl;
    std::cout << "Bias: " << this->bias << std::endl;
}

//Manually set the weights
void TLDEDA001::Node::setWeights(const std::vector<float> newWeights)
{
    weights.clear();
    for (int i = 0; i < newWeights.size(); i++)
    {
        weights.push_back(newWeights[i]);
    }
}


//Threshold activation function
const float TLDEDA001::Node::ThresholdActivation(const float input) const
{

    return (input < threshold) ? 0 : 1;
}

//sigmoid activation function
const float TLDEDA001::Node::SigmoidActivation(const float input) const
{
    return ((exp(input)) / (exp(input) + 1));
}
