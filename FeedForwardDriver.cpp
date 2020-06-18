#include <iostream>
#include "AN_Network.h"

int main()
{
    //Network instantiated with 3 inputs, 2 hidden layer nodes, 1 output layer node (no user input),
    // a learning rate of 0.01, threshold of 0 (unnecessary in this example), 10 epochs, uses sigmoid activation funtion
    TLDEDA001::AN_Network Network(3, 2, 0.01, 0, 10, true);

    //given inputs
    std::vector<double> inputs;
    inputs.push_back(1.30);
    inputs.push_back(2.70);
    inputs.push_back(0.80);

    //given biases
    Network.getNode(0, 0).setBias(0.1);
    Network.getNode(0, 1).setBias(-0.3);
    Network.getNode(1, 0).setBias(-0.3);

    //given weights
    std::vector<double> weights1;
    weights1.push_back(0.1);
    weights1.push_back(0.2);
    weights1.push_back(0.5);

    std::vector<double> weights2;
    weights2.push_back(-0.4);
    weights2.push_back(1.0);
    weights2.push_back(-0.6);

    std::vector<double> weights3;
    weights3.push_back(0.8);
    weights3.push_back(1.0);

    Network.getNode(0, 0).setWeights(weights1);
    Network.getNode(0, 1).setWeights(weights2);
    Network.getNode(1, 0).setWeights(weights3);

    //Answers
    std::cout << "Q3: Hidden layer nodes outputs:" << std::endl;
    std::cout << Network.PredictIndividual(0, 0, inputs) << std::endl;
    std::cout << Network.PredictIndividual(0, 1, inputs) << std::endl;
    std::cout << "Q4: output layer node output:" << std::endl;
    std::cout << Network.Predict(inputs) << std::endl;
    std::cout << "Q5: MSE value:" << std::endl;
    std::cout << Network.getMSE(inputs, 0.36) << std::endl;

    return 0;
}