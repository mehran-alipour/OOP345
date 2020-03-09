// Utilities.h
// Name: Mehran Alipour
// Seneca Student ID: 126778182
// Seneca email: malipour7@myseneca.ca
// Date of completion: Mar 5,2020
//
// I confirm that the content of this file is created by me,
//   with the exception of the parts provided to me by my professor.
#ifndef SDDS_UTILITIES_H__
#define SDDS_UTILITIES_H__
#include "Vehicle.h"

namespace sdds {
    std::string find(std::istream& is, const char delimeter);
    void ltrim(std::string& s);
    void rtrim(std::string& s);
    std::string trim(std::string& s);
    Vehicle* createInstance(std::istream& in);
}
#endif // !SDDS_UTILITIES_H__