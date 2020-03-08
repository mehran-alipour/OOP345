// RaceCar.h
// Name: Mehran Alipour
// Seneca Student ID: 126778182
// Seneca email: malipour7@myseneca.ca
// Date of completion: Mar 5,2020
//
// I confirm that the content of this file is created by me,
//   with the exception of the parts provided to me by my professor.
#ifndef SDDS_RACECAR_H__
#define SDDS_RACECAR_H__
#include <iostream>
#include <string>
#include "Car.h"
namespace sdds {
    class Racecar :public Car {
        double m_booster; // set between 0 and 1
    public:
        Racecar(std::istream& in);
        void display(std::ostream& out) const;
        double topSpeed() const;
        ~Racecar() {};
    };
}
#endif // !SDDS_RACECAR_H__