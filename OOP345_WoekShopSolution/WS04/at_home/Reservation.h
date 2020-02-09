// Reservation.h
// Name: Mehran Alipour
// Seneca Student ID: 126778182
// Seneca email: malipour7@myseneca.ca
// Date of completion: Feb 2,2020
//
// I confirm that the content of this file is created by me,
//   with the exception of the parts provided to me by my professor.
#pragma once
#include <iostream>
#include <string>
namespace sdds {
    class Reservation {
        std::string r_reservationId;
        std::string r_resName;
        std::string r_email;
        unsigned int r_numPeople;
        unsigned int r_day; // int between 1-31
        unsigned int r_hour; // int between 1-24
    public:
        Reservation();
        Reservation(const std::string& res);
        std::string findEras(std::string& res, const char delimeter);
        void setEmpty();
        void setResv(const Reservation& resvCop);
        std::ostream& display(std::ostream& os = std::cout) const;
        Reservation& operator=(const Reservation& resvCop);
        virtual ~Reservation();
    };
    std::ostream& operator<<(std::ostream& os, const Reservation& resv);
}