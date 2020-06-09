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
