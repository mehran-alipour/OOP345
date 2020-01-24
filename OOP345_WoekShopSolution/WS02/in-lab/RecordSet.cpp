// RecordSet.cpp
// Name: Mehran Alipour
// Seneca Student ID: 126778182
// Seneca email: malipour7@myseneca.ca
// Date of completion: Jan 24,2020
//
// I confirm that the content of this file is created by me,
//   with the exception of the parts provided to me by my professor.
#include <iostream>
#include <fstream>
#include <string>
#include "RecordSet.h"
using namespace std;
namespace sdds {
    unsigned int RecordSet::r_numRecSet = 0;
    RecordSet::RecordSet() {
        r_arr = nullptr;
    }
    RecordSet::RecordSet(const RecordSet& copyCon):r_arr(nullptr) {
        *this = copyCon;
    }
    RecordSet::RecordSet(RecordSet&& moveCon) {
        *this = moveCon;
        delete[] moveCon.r_arr;
        moveCon.r_numRecSet = 0;
    }
    RecordSet::RecordSet(const char* fileName) {
        string buffer = {};
        ifstream file;
        file.open(fileName);
        if (file.is_open())
        {
            while (getline(file, buffer, ' ' ))
                ++r_numRecSet;
        }

        // allocate memory
        r_arr = new string[r_numRecSet];
        file.close();
        file.open(fileName);

        unsigned int i = 0;
        string line = {};

        //while (std::getline(file, line, ' '))
        while (std::getline(file, r_arr[i++], ' '));
           //r_arr[i++] = line;
    }
    size_t RecordSet::size() const {
        return r_numRecSet;
    }
    std::string RecordSet::getRecord(size_t myIndex) {
        if (myIndex < size()) {
            return r_arr[myIndex];
        }
        else {
            return "";
        }
    }
    RecordSet& RecordSet::operator=(const RecordSet& copyOp) {
        unsigned int i;
        if (this != &copyOp) {
            r_numRecSet = copyOp.r_numRecSet;
            delete[] r_arr;
            r_arr = new string[r_numRecSet];
            for (i = 0; i < r_numRecSet; i++) {
                r_arr[i] = copyOp.r_arr[i];
            }
        }
        return *this;
    }
    RecordSet::~RecordSet() {
        delete[] r_arr;
        r_arr = nullptr;
    }
}