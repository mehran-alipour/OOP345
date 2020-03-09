// Car.cpp
// Name: Mehran Alipour
// Seneca Student ID: 126778182
// Seneca email: malipour7@myseneca.ca
// Date of completion: Mar 5,2020
//
// I confirm that the content of this file is created by me,
//   with the exception of the parts provided to me by my professor.
#include <iostream>
#include <stdexcept> 
#include <string>
#include "Car.h"
#include "Utilities.h"
using namespace std;

namespace sdds {
    Car::Car() {
        setEmpty();
    }
    Car::Car(Car& copyCar) {
        *this = copyCar;
    }
    Car::Car(Car&& moveCar) {
        *this = move(moveCar);
    }
    Car::Car(istream& is) {
        string condition;
        c_maker = find(is,',');
        condition = find(is, ',');
        if (condition == "n" || condition == "") {
            c_condition = "new";
        }
        else if (condition == "u") {
            c_condition = "used";
        }
        else if (condition == "b") {
            c_condition = "broken";
        }
        else {
            throw "Invalid record!";// throw const char*
            is.ignore(1000, '\n');
        }
        c_speed = stod(find(is, ','));
    }
    Car::~Car() {

    }
    // Display or Report
    string Car::condition() const {
        return c_condition;
    }
    double Car::topSpeed() const {
        return c_speed;
    }
    void Car::display(ostream& out) const {
        out << "| ";
        out.width(10);
        out << c_maker << " | ";
        out.width(6);
        out.setf(ios::left);
        out << c_condition << " | ";
        out.unsetf(ios::left);
        out.width(6);
        out.setf(ios::fixed);
        out.precision(2);
        out << topSpeed() << " |";
        out.unsetf(ios::fixed);

    }

    //Operators
    Car& Car::operator=(const Car& copyCar) {
        if (this != &copyCar) {
            c_maker = copyCar.c_maker;
            c_condition = copyCar.c_condition;
            c_maker = copyCar.c_maker;
        }
        return *this;
    }
    Car& Car::operator=(Car&& moveCar) {
        if (this != &moveCar) {
            *this = moveCar;
            moveCar.setEmpty();
        }
        return *this;
    }

    //Utility
    void Car::setEmpty() {
        c_maker = " ";
        c_condition = '\0';
        c_speed = -1;
    }
}