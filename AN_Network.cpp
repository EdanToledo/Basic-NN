#include "AN_Network.h"

//Parameter Constructor
TLDEDA001::AN_Network::AN_Network(const int NumInputs, const int NumInHiddenLayer, const float learningRate, const float threshold, const int epochs, const bool sigmoid)
{
    this->epochs = epochs;
    this->NumInputs = NumInputs;
    this->learningrate = learningRate;
    layers.push_back(std::vector<TLDEDA001::Node>());
    for (int i = 0; i < NumInHiddenLayer; i++)
    {
        layers[0].push_back(Node(threshold, 0.0, sigmoid));
        layers[0][i].ResetWeights(NumInputs);
    }

    layers.push_back(std::vector<TLDEDA001::Node>());
    layers[1].push_back(Node(threshold, 0.0, sigmoid));
    layers[1][0].ResetWeights(layers[0].size());
}

