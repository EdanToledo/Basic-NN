#ifndef AN_Network_H
#define AN_Network_H
#include <iostream>
#include <vector>
#include "Node.h"
#include "TrainingData.h"
#include <math.h>

namespace TLDEDA001
{
    class AN_Network
    {
        //Number of epochs
        int epochs;
        //Number of input nodes
        int NumInputs;
        //number of layers not including input layer
        int numberOfLayers;
        //vector containing layers of nodes
        std::vector<std::vector<TLDEDA001::Node>> layers;
        //learning to give nodes
        float learningrate;

    public:
        //Parameter Constructor
        AN_Network(const int NumInputs, const int NumInHiddenLayer, const float learningRate, const float threshold, const int epoch, const bool sigmoid);

        //train the network
        void Train(const TLDEDA001::TrainingData data);

        //train the network
        void BatchTrain(const int BatchSize, const TLDEDA001::TrainingData data);

        //Predict outcome using inputs
        const float Predict(const std::vector<float> inputs);

        //Predict outcome using inputs for specific node
        const float PredictIndividual(const int layer, const int index, const std::vector<float> inputs);

        //Reset all node Weights and biases
        void Reset();

        //Sets threshold value of all nodes
        void setThresholdOfAllNodes(const float thresh);

        //returns reference to node in network
        TLDEDA001::Node &getNode(const int layer, const int index);

        //set the learning rate
        void setLearningRate(const float rate);

        const float getMSE(const std::vector<float> inputs, const float ExpectedOutput);
    };

} //Namespace TLDEDA001

#endif