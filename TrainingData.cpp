#include "TrainingData.h"

 //Add a record
void TLDEDA001::TrainingData::AddDataSet(const double input1, const double input2, const double output)
{
    this->input1.push_back(input1);
    this->input2.push_back(input2);
    this->output.push_back(output);
}

//return the first input at specifed row index
const double TLDEDA001::TrainingData::getInput1(const int index) const { return input1[index]; }

 //return the second input at specifed row index
const double TLDEDA001::TrainingData::getInput2(const int index) const { return input2[index]; }

 //return the output at specifed row index
const double TLDEDA001::TrainingData::getOutput(const int index) const { return output[index]; }

//get number of records
const int TLDEDA001::TrainingData::getSize() const
{
    return output.size();
}

//Return input1 and input2 in a const vector
const std::vector<double> TLDEDA001::TrainingData::getInputs(const int index) const
{
    std::vector<double> returnvec;
    returnvec.push_back(input1[index]);
    returnvec.push_back(input2[index]);

    return returnvec;
}

 //clear all data/records
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
        double in1, in2, out;
        s >> in1 >> std::ws >> in2 >> std::ws >> out;
        input1.push_back(in1);
        input2.push_back(in2);
        output.push_back(out);
    }
}