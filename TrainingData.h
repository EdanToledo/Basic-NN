#ifndef TrainingData_H
#define TrainingData_H
#include <iostream>
#include <vector>
#include <fstream>
#include <string>
#include <sstream>

namespace TLDEDA001
{
    class TrainingData
    {
        //list of inputs and outputs
        std::vector<float> input1;
        std::vector<float> input2;
        std::vector<float> output;

    public:
        //Add a record
        void AddDataSet(const float input1, const float input2, const float output);

        //return the first input at specifed row index
        const float getInput1(int index) const;
        //return the second input at specifed row index
        const float getInput2(int index) const;
        //return the output at specifed row index
        const float getOutput(int index) const;
        //Return input1 and input2 in a const vector
        const std::vector<float> getInputs(const int index) const;
        //get number of records
        const int getSize() const;
        //clear all data/records
        void clearData();

        //load data from training
        void LoadDataFromFile(std::string textfile);
    };

} //Namespace TLDEDA001

#endif
