// Reservation.cpp
// Name: Mehran Alipour
// Seneca Student ID: 126778182
// Seneca email: malipour7@myseneca.ca
// Date of completion: Feb 2,2020
//
// I confirm that the content of this file is created by me,
//   with the exception of the parts provided to me by my professor.
#include <iostream>
#include <string>
#include "Reservation.h"

using namespace std;

namespace sdds {
    Reservation::Reservation() {
        setEmpty();
    };

    Reservation::Reservation(const string& res) {
        std::string temp;
        temp = res;
        int i = 0;
        if (res != "") {

            while (i != -1) {
                i = (int)temp.find(' ');
                if (i != -1)
                    temp.erase(i, 1);
            }
            r_reservationId = findEras(temp,':');
            r_resName = findEras(temp, ',');
            r_email = findEras(temp, ',');
            r_numPeople = stoi(findEras(temp, ','));
            r_day = stoi(findEras(temp, ','));
            r_hour = stoi(findEras(temp, '\n'));

        }
        else {
            setEmpty();
        }
    }
    string Reservation::findEras(string& res, const char delimeter) {
        std::string temp;
        int i = 0;
        i = (int)res.find(delimeter);
        temp = res.substr(0, i);
        if (i != -1) {
            res.erase(0, i + 1);
        }
        return temp;
    }
    void Reservation::setEmpty() {
        r_reservationId = "";
        r_resName = "";
        r_email = "";
        r_numPeople = 0;
        r_day = 0;
        r_hour = 0;
    }
    void Reservation::setResv(const Reservation& resvCop) {
        r_reservationId = resvCop.r_reservationId;
        r_resName = resvCop.r_resName;
        r_email = resvCop.r_email;
        r_numPeople = resvCop.r_numPeople;
        r_day = resvCop.r_day;
        r_hour = resvCop.r_hour;
    }
    ostream& Reservation::display(ostream& os) const {
        os << "Reservation " << r_reservationId << ":";
        os.width(11);
        os.setf(ios::right);
        os << r_resName << "  ";
        os.unsetf(ios::right);
        os.width(24);
        os.setf(ios::left);
        os << "<" + r_email + ">";
        os.unsetf(ios::left);
        if (r_hour >= 6 && r_hour <= 9) {
            os << "Breakfast ";
        }
        else if (r_hour >= 11 && r_hour <= 15) {
            os << "Lunch ";
        }
        else if (r_hour >= 17 && r_hour <= 21) {
            os << "Dinner ";
        }
        else {
            os << "Drinks ";
        }

        os << "on day " << r_day << " @ " << r_hour << ":00 for " << r_numPeople << " people." << endl;
        return os;
    }
    Reservation& Reservation::operator=(const Reservation& resvCop){
        setResv(resvCop);
        return *this;
    }
    ostream& operator<<(ostream& os, const Reservation& resv){
        return resv.display();
    }
    Reservation::~Reservation() {};
}