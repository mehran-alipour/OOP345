// Reastaurant.h
// Name: Mehran Alipour
// Seneca Student ID: 126778182
// Seneca email: malipour7@myseneca.ca
// Date of completion: Feb 7,2020
//
// I confirm that the content of this file is created by me,
//   with the exception of the parts provided to me by my professor.

#pragma once
#include <iostream>
#include "Reservation.h"

namespace sdds {
    class Restaurant {
        Reservation* rt_reservation;
        size_t rt_numOfrsvn; // nunber of the mmemebers in the array
    public:
        Restaurant();
        Restaurant(const Restaurant& resCop);
        Restaurant(Restaurant&& resCop);
        Restaurant(Reservation* reservations[], size_t cnt);
        virtual ~Restaurant();
        void setEmpty();
        void setRest(const Restaurant& restCop);
        Restaurant& operator=(const Restaurant& resCop);
        Restaurant& operator=(Restaurant&& resCop);
        size_t size() const;
        std::ostream& display(std::ostream& os = std::cout)const;
    };
    std::ostream& operator<<(std::ostream& os, const Restaurant& rest);
}