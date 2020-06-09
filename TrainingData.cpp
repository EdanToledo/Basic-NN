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
