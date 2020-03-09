// Racecar.cpp
// Name: Mehran Alipour
// Seneca Student ID: 126778182
// Seneca email: malipour7@myseneca.ca
// Date of completion: Mar 5,2020
//
// I confirm that the content of this file is created by me,
//   with the exception of the parts provided to me by my professor.
#include <iostream>
#include <string>
#include "Racecar.h"
#include "Utilities.h"
using namespace std;

namespace sdds {
    Racecar::Racecar(std::istream& in) :Car(in) {
        string myCar;
        myCar = find(in, ',');
        if (myCar != "") {
            m_booster = stod(myCar);
        }
        else {
            m_booster = 0;
        }
    }
    void Racecar::display(std::ostream& out) const {
        Car::display(out);
        out << "*";
    }
    void setBooster(double boos) {

    }
    double Racecar::topSpeed() const {
        return  Car::topSpeed() * (m_booster + 1);
    }
}