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
        std::vector<double> input1;
        std::vector<double> input2;
        std::vector<double> output;

    public:
        //Add a record
        void AddDataSet(const double input1, const double input2, const double output);

        //return the first input at specifed row index
        const double getInput1(int index) const;
        //return the second input at specifed row index
        const double getInput2(int index) const;
        //return the output at specifed row index
        const double getOutput(int index) const;
        //Return input1 and input2 in a const vector
        const std::vector<double> getInputs(const int index) const;
        //get number of records
        const int getSize() const;
        //clear all data/records
        void clearData();

        //load data from training
        void LoadDataFromFile(std::string textfile);
    };

} //Namespace TLDEDA001

#endif