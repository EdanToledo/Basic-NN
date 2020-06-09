#include "TrainingData.h"

const float TLDEDA001::TrainingData::getInput1(const int index) const { return input1[index]; }

const float TLDEDA001::TrainingData::getInput2(const int index) const { return input2[index]; }

const float TLDEDA001::TrainingData::getOutput(const int index) const { return output[index]; }

const int TLDEDA001::TrainingData::getSize() const
{
    return output.size();
}

const std::vector<float> TLDEDA001::TrainingData::getInputs(const int index) const
{
    std::vector<float> returnvec;
    returnvec.push_back(input1[index]);
    returnvec.push_back(input2[index]);

    return returnvec;
}


void TLDEDA001::TrainingData::AddDataSet(const float input1, const float input2, const float output)
{
    this->input1.push_back(input1);
    this->input2.push_back(input2);
    this->output.push_back(output);
}


void TLDEDA001::TrainingData::clearData()
{
    this->input1.clear();
    this->input2.clear();
    this->output.clear();
}

//load data from training
void TLDEDA001::TrainingData::LoadDataFromFile(std::string textfile)
{
    std::ifstream inp(textfile);
    std::string line;

    while (getline(inp, line))
    {
        std::stringstream s(line);
        float in1, in2, out;
        s >> in1 >> std::ws >> in2 >> std::ws >> out;
        input1.push_back(in1);
        input2.push_back(in2);
        output.push_back(out);
    }
}
