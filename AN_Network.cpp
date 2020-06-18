#include "AN_Network.h"

//Parameter Constructor
TLDEDA001::AN_Network::AN_Network(const int NumInputs, const int NumInHiddenLayer, const double learningRate, const double threshold, const int epochs, const bool sigmoid)
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
            std::vector<double> hiddenlayerOut;
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

//predict
const double TLDEDA001::AN_Network::Predict(const std::vector<double> inputs)
{

    std::vector<double> newInputs;
    for (int i = 0; i < layers[0].size(); i++)
    {
        layers[0][i].setInputs(inputs);
        newInputs.push_back(layers[0][i].Output());
    }

    layers[1][0].setInputs(newInputs);

    return layers[1][0].Output();
}

//Reset all node Weights and biases
void TLDEDA001::AN_Network::Reset()
{

    for (int i = 0; i < layers[0].size(); i++)
    {
        layers[0][i].ResetWeights(NumInputs);
    }

    layers[1][0].ResetWeights(layers[0].size());
}

//Sets threshold value of all nodes
void TLDEDA001::AN_Network::setThresholdOfAllNodes(const double thresh)
{

    for (int i = 0; i < layers[0].size(); i++)
    {
        layers[0][i].setThreshold(thresh);
    }

    layers[1][0].setThreshold(thresh);
}

//returns reference to node in network
TLDEDA001::Node &TLDEDA001::AN_Network::getNode(const int layer, const int index)
{
    return layers[layer][index];
}

//set the learning rate
void TLDEDA001::AN_Network::setLearningRate(const double rate)
{
    this->learningrate = rate;
}

const double TLDEDA001::AN_Network::PredictIndividual(const int layer, const int index, const std::vector<double> inputs)
{

    layers[layer][index].setInputs(inputs);

    return layers[layer][index].Output();
}

//train the network in batches i.e each node on certain consecutive batches
void TLDEDA001::AN_Network::BatchTrain(const int BatchSize, const TLDEDA001::TrainingData data)
{
    for (int l = 0; l < epochs; l++)
    {
        int batch = 0;
        for (int k = 0; k < layers.size(); k++)
        {
            for (int j = 0; j < layers[k].size(); j++)
            {
                for (int i = 0; i < BatchSize; i++)
                {
                    layers[k][j].setInputs(data.getInputs(batch));
                    layers[k][j].AdjustWeights(learningrate, data.getOutput(batch));
                    batch++;
                }
            }
        }
    }
}

//Returns the MSE of a single input through the network
const double TLDEDA001::AN_Network::getMSE(const std::vector<double> inputs, const double ExpectedOutput)
{
    return pow((Predict(inputs) - ExpectedOutput), 2);
}
