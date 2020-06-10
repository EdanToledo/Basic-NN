#ifndef Node_H
#define Node_H
#include <iostream>
#include <vector>
#include <math.h>

namespace TLDEDA001
{
    class Node
    {
        //Current inputs to Node
        std::vector<float> inputs;

        //Current weight to Node
        std::vector<float> weights;

        //Threshhold Value
        float threshold;

        //bias value
        float bias;

        //True if nodes use sigmoid activation function
        bool sigmoid;

    public:
        //parameter Constructor for Node
        Node(const float threshold, const float bias, const bool sigmoid);

        //Adjust Weights based on expected output and returns current output
        const float AdjustWeights(const float learningrate, const float Exoutput);

        //take all inputs and apply respective weights and bias and then Apply activation Function and return the output
        const float Output() const;

        //initialises the weights and bias and/or resets them
        void ResetWeights(const int NumOfWeights);

        //sets the inputs
        void setInputs(const std::vector<float> inputs);

        //Set threshold value for node
        void setThreshold(const float threshold);

        //Manually set the bias for the node
        void setBias(const float bias);

        //Manually set the weights
        void setWeights(const std::vector<float> newWeights);

        //Print to console the threshold and bias values
        void PrintParameters() const;

        //Threshold activation function
        const float ThresholdActivation(const float input) const;

        //sigmoid activation function
        const float SigmoidActivation(const float input) const;
    };

} //Namespace TLDEDA001

#endif