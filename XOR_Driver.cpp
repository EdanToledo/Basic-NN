#include <iostream>
#include "AN_Network.h"

int main(int argc, const char *argv[])
{

    if (argc < 2)
    {
        return 0;
    }

    std::string data = (std::string)argv[1];

    TLDEDA001::TrainingData Tdata;

    TLDEDA001::AN_Network Network(2, 2, 0.01, 0, 10,false);

    //XOR GATE

    Tdata.LoadDataFromFile(data);

    Network.BatchTrain(4, Tdata);

    std::cout << "OR Gate" << std::endl;
    Network.getNode(0, 0).PrintParameters();
    for (int i = 0; i < 4; i++)
    {

        std::cout << Tdata.getInput1(i) << "," << Tdata.getInput2(i) << " : " << Network.PredictIndividual(0, 0, Tdata.getInputs(i)) << std::endl;
    }

    std::cout << "NAND Gate" << std::endl;
    Network.getNode(0, 1).PrintParameters();
    for (int i = 0; i < 4; i++)
    {

        std::cout << Tdata.getInput1(i) << "," << Tdata.getInput2(i) << " : " << Network.PredictIndividual(0, 1, Tdata.getInputs(i)) << std::endl;
    }

    std::cout << "AND Gate" << std::endl;
    Network.getNode(1, 0).PrintParameters();
    for (int i = 0; i < 4; i++)
    {

        std::cout << Tdata.getInput1(i) << "," << Tdata.getInput2(i) << " : " << Network.PredictIndividual(1, 0, Tdata.getInputs(i)) << std::endl;
    }

    std::cout << "XOR Gate" << std::endl;
    for (int i = 0; i < 4; i++)
    {
        std::cout << Tdata.getInput1(i) << "," << Tdata.getInput2(i) << " : " << Network.Predict(Tdata.getInputs(i)) << std::endl;
    }

    return 0;
}
