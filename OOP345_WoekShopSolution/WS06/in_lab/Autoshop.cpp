// Autoshop.cpp
// Name: Mehran Alipour
// Seneca Student ID: 126778182
// Seneca email: malipour7@myseneca.ca
// Date of completion: Mar 5,2020
//
// I confirm that the content of this file is created by me,
//   with the exception of the parts provided to me by my professor.
#include<iostream>
#include<string>
#include"Autoshop.h"
using namespace std;

namespace sdds {
    Autoshop& Autoshop::operator +=(Vehicle* theVehicle) {
        if (theVehicle != nullptr)
            m_vehicles.push_back(theVehicle);
        return *this;
    }
    void Autoshop::display(std::ostream& out) const {
        //vector<Vehicle*>::iterator i;
        out << "--------------------------------" << endl;
        out << "| Cars in the autoshop!        |" << endl;
        out << "--------------------------------" << endl;
        for (auto i = m_vehicles.begin(); i != m_vehicles.end(); i++) {
            (*i)->display(out);
        }
        out << "--------------------------------" << endl;
    }
    Autoshop::~Autoshop() {
        for (Vehicle* vehicle : m_vehicles) {
            delete vehicle;
        }
    }
}

