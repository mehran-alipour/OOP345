// Car.h
// Name: Mehran Alipour
// Seneca Student ID: 126778182
// Seneca email: malipour7@myseneca.ca
// Date of completion: Mar 5,2020
//
// I confirm that the content of this file is created by me,
//   with the exception of the parts provided to me by my professor.
#ifndef SDDS_CAR_H__
#define SDDS_CAR_H__
#include <iostream>
#include <string>
#include "Vehicle.h"
namespace sdds {
    class Car:public Vehicle {
        std::string c_maker;
        std::string c_condition;
        double c_speed;
    public:
        Car();
        Car(Car& copyCar);
        Car(Car&& moveCar);
        Car(std::istream& is);
        ~Car();
        // Display or Report
        std::string condition() const;
        double topSpeed() const;
        void display(std::ostream& out) const;

        //Operators
        Car& operator=(const Car& copyCar);
        Car& operator=(Car&& moveCar);

        //Utility
        void setEmpty();
    };
}
#endif // !SDDS_CAR_H__