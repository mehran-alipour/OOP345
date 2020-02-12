// Reastaurant.cpp
// Name: Mehran Alipour
// Seneca Student ID: 126778182
// Seneca email: malipour7@myseneca.ca
// Date of completion: Feb 7,2020
//
// I confirm that the content of this file is created by me,
//   with the exception of the parts provided to me by my professor.

#include <iostream>
#include "Restaurant.h"
#include "Reservation.h"

using namespace std;

namespace sdds {
    Restaurant::Restaurant() :rt_reservation(nullptr), rt_numOfrsvn(0) {
    }
    Restaurant::Restaurant(const Restaurant& resCop) : rt_reservation(nullptr) {
        *this = resCop;
    }
    Restaurant::Restaurant(Restaurant&& resCop) : rt_reservation(nullptr) {
        *this = move(resCop);

    }
    Restaurant::Restaurant(Reservation* reservations[], size_t cnt) {
        if (cnt > 0) {
            delete[] rt_reservation;
            rt_reservation = new Reservation[cnt];

            for (size_t i = 0; i < cnt; i++) {
                rt_reservation[i] = *reservations[i];
            }
            rt_numOfrsvn = cnt;
        }
        else {
            setEmpty();
        }
    }
    Restaurant::~Restaurant() {
        delete[] rt_reservation;
        rt_reservation = nullptr;
    }
    void Restaurant::setEmpty() {
        delete[] rt_reservation;
        rt_reservation = nullptr;
        rt_numOfrsvn = 0;
    }
    Restaurant& Restaurant::operator=(const Restaurant& resCop) {
        setRest(resCop);
        return *this;
    }
    Restaurant& Restaurant::operator=(Restaurant&& resCop) {
        if (this != &resCop) {
            delete[] rt_reservation;
            rt_numOfrsvn = resCop.rt_numOfrsvn;
            rt_reservation = resCop.rt_reservation;
            resCop.rt_reservation = nullptr;
            resCop.rt_numOfrsvn = 0;
        }
        return *this;
    }
    void Restaurant::setRest(const Restaurant& restCop) {
        if (this != &restCop) {
            delete[] rt_reservation;
            rt_numOfrsvn = restCop.rt_numOfrsvn;
            rt_reservation = new Reservation[rt_numOfrsvn];
            for (size_t i = 0; i < rt_numOfrsvn; i++) {
                rt_reservation[i] = restCop.rt_reservation[i];
            }
        }
    }
    size_t Restaurant::size() const {
        return rt_numOfrsvn;
    }
    ostream& Restaurant::display(std::ostream& os)const {
        os << "--------------------------\n";
        os << "Fancy Restaurant\n";
        os << "--------------------------\n";
        if (rt_numOfrsvn == 0) {
            os << "The object is empty!\n";
            os << "--------------------------\n";
        }
        else {
            for (size_t i = 0; i < rt_numOfrsvn; os << rt_reservation[i++]);
            os << "--------------------------\n";
        }
        return os;
    }
    std::ostream& operator<<(std::ostream& os, const Restaurant& rest) {
        return rest.display();
    }
}