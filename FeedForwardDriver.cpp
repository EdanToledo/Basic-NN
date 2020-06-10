#include <iostream>
#include "AN_Network.h"

int main()
{
    TLDEDA001::AN_Network Network(3, 2, 0.01, 0, 10,true);

    std::vector<float> inputs;
    inputs.push_back(1.30);
    inputs.push_back(2.70);
    inputs.push_back(0.80);

    Network.getNode(0, 0).setBias(0.1);
    Network.getNode(0, 1).setBias(-0.3);
    Network.getNode(1, 0).setBias(-0.3);

    std::vector<float> weights1;
    weights1.push_back(0.1);
    weights1.push_back(0.2);
    weights1.push_back(0.5);

    std::vector<float> weights2;
    weights2.push_back(-0.4);
    weights2.push_back(1.0);
    weights2.push_back(-0.6);

    std::vector<float> weights3;
    weights3.push_back(0.8);
    weights3.push_back(1.0);

    Network.getNode(0, 0).setWeights(weights1);
    Network.getNode(0, 1).setWeights(weights2);
    Network.getNode(1, 0).setWeights(weights3);

    std::cout << "Q3: Hidden layer nodes outputs:" << std::endl;
    std::cout << Network.PredictIndividual(0, 0, inputs) << std::endl;
    std::cout << Network.PredictIndividual(0, 1, inputs) << std::endl;
    std::cout << "Q4: output layer node output:" << std::endl;
    std::cout << Network.Predict(inputs) << std::endl;
    std::cout << "Q5: MSE value:" << std::endl;
    std::cout << Network.getMSE(inputs, 0.36) << std::endl;

    return 0;
}