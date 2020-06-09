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


//train the network
void TLDEDA001::AN_Network::Train(const TLDEDA001::TrainingData data)
{
    for (int l = 0; l < epochs; l++)
    {

        for (int i = 0; i < data.getSize(); i++)
        {
            std::vector<float> hiddenlayerOut;
            for (int j = 0; j < layers[0].size(); j++)
            {
                layers[0][j].setInputs(data.getInputs(i));
                hiddenlayerOut.push_back(layers[0][j].AdjustWeights(learningrate, data.getOutput(i)));
            }
            layers[1][0].setInputs(hiddenlayerOut);
            layers[1][0].AdjustWeights(learningrate, data.getOutput(i));
        }
    }
}


void TLDEDA001::AN_Network::Reset()
{

    for (int i = 0; i < layers[0].size(); i++)
    {
        layers[0][i].ResetWeights(NumInputs);
    }

    layers[1][0].ResetWeights(layers[0].size());
}

void TLDEDA001::AN_Network::setThresholdOfAllNodes(const float thresh)
{

    for (int i = 0; i < layers[0].size(); i++)
    {
        layers[0][i].setThreshold(thresh);
    }

    layers[1][0].setThreshold(thresh);
}

TLDEDA001::Node &TLDEDA001::AN_Network::getNode(const int layer, const int index)
{
    return layers[layer][index];
}

//set the learning rate
void TLDEDA001::AN_Network::setLearningRate(const float rate)
{
    this->learningrate = rate;
}


