// Autoshop.h
// Name: Mehran Alipour
// Seneca Student ID: 126778182
// Seneca email: malipour7@myseneca.ca
// Date of completion: Mar 5,2020
//
// I confirm that the content of this file is created by me,
//   with the exception of the parts provided to me by my professor.
#ifndef SDDS_AUTOSHOP_H__
#define SDDS_AUTOSHOP_H__
#include <vector>
#include <list>
#include "Vehicle.h"
namespace sdds {
    class Autoshop {
        std::vector<Vehicle*> m_vehicles;
    public:
        Autoshop& operator +=(Vehicle* theVehicle);
        void display(std::ostream& out) const;
        ~Autoshop();
        template<typename T>
        void select(T test, std::list<const Vehicle*>& vehicles) {
            for (auto i = m_vehicles.begin(); i != m_vehicles.end(); i++) {
                if (test(*i)) {
                    vehicles.push_back(*i);
                }
            }
        }
    };
}
#endif // !SDDS_AUTOSHOP_H__