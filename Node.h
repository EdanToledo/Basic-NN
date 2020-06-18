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
        std::vector<double> inputs;

        //Current weight to Node
        std::vector<double> weights;

        //Threshhold Value
        double threshold;

        //bias value
        double bias;

        //True if nodes use sigmoid activation function
        bool sigmoid;

    public:
        
        //parameter Constructor for Node
        Node(const double threshold, const double bias, const bool sigmoid);

        //Adjust Weights based on expected output and returns current output
        const double AdjustWeights(const double learningrate, const double Exoutput);

        //take all inputs and apply respective weights and bias and then Apply activation Function and return the output
        const double Output() const;

        //initialises the weights and bias and/or resets them
        void ResetWeights(const int NumOfWeights);

        //sets the inputs
        void setInputs(const std::vector<double> inputs);

        //Set threshold value for node
        void setThreshold(const double threshold);

        //Manually set the bias for the node
        void setBias(const double bias);

        //Manually set the weights
        void setWeights(const std::vector<double> newWeights);

        //Print to console the threshold and bias values
        void PrintParameters() const;

        //Threshold activation function
        const double ThresholdActivation(const double input) const;

        //sigmoid activation function
        const double SigmoidActivation(const double input) const;
    };

} //Namespace TLDEDA001

#endif