// Utilities.cpp
// Name: Mehran Alipour
// Seneca Student ID: 126778182
// Seneca email: malipour7@myseneca.ca
// Date of completion: Mar 5,2020
//
// I confirm that the content of this file is created by me,
//   with the exception of the parts provided to me by my professor.
#include <sstream>
#include <iostream>
#include "Utilities.h"
#include "Car.h"
#include "Racecar.h"
using namespace std;
namespace sdds {
    string find(istream& is, const char delimeter) {
        string temp;
        getline(is, temp, delimeter);
        return trim(temp);
    }
    void ltrim(string& s) {
        const string WHITESPACE = " \r\t\f\v";
        size_t start = s.find_first_not_of(WHITESPACE);
        s = start == string::npos ? "" : s.substr(start);
    }
    void rtrim(string& s) {
        const string WHITESPACE = " \r\t\f\v";
        size_t end = s.find_last_not_of(WHITESPACE);
        s = end == string::npos ? "" : s.substr(0, end + 1);
    }
    string trim(string& s) {
        ltrim(s);
        rtrim(s);
        return s;
    }
    Vehicle* createInstance(istream& in) {
        std::string line;
        char type = '\0';
        char delim = '\0';
        string t;
        getline(in, line);
        stringstream ss(line);
        ss >> type >> delim;
        if (ss) {
            switch (type)
            {
            case 'c':
            case 'C':
                return new Car(ss);
                break;
            case 'r':
            case 'R':
                return new Racecar(ss);
                break;
            default:
                t += type;
                throw "Unrecognized record type: [" + t + "]";
                break;
            }
        }

        return nullptr;
    }
}