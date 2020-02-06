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

            i = (int)temp.find(':');
            r_reservationId = temp.substr(0, i);

            temp.erase(0, i+1);
            i = (int)temp.find(',');
            r_resName = temp.substr(0, i);

            temp.erase(0, i+1);
            i = (int)temp.find(',');
            r_email = temp.substr(0, i);

            temp.erase(0, i+1);
            i = (int)temp.find(',');
            r_numPeople = stoi(temp.substr(0, i));


            temp.erase(0, i+1);
            i = (int)temp.find(',');
            r_day = stoi(temp.substr(0, i));

            temp.erase(0, i+1);
            r_hour = stoi(temp.substr(0, temp.size()));

        }
        else {
            setEmpty();
        }
    }
    void Reservation::setEmpty() {
        r_reservationId = "";
        r_resName = "";
        r_email = "";
        r_numPeople = 0;
        r_day = 0;
        r_hour = 0;
    }

    ostream& operator<<(ostream& os, const Reservation& resv) {
        os << "Reservation " << resv.r_reservationId << ":";
        os.width(11);
        os.setf(ios::right);
        os << resv.r_resName << "  ";
        os.unsetf(ios::right);
        os.width(24);
        os.setf(ios::left);
        os<< "<" + resv.r_email + ">";
        os.unsetf(ios::left);
        if (resv.r_hour >= 6 && resv.r_hour <= 9) {
            os << "Breakfast ";
        }
        else if (resv.r_hour >= 11 && resv.r_hour <= 15) {
            os << "Lunch ";
        }
        else if (resv.r_hour >= 17 && resv.r_hour <= 21) {
            os << "Dinner ";
        }
        else {
            os << "Drinks ";
        }

        os << "on day " << resv.r_day << " @ " << resv.r_hour << ":00 for " << resv.r_numPeople << " people." << endl;
        return os;
    }
    Reservation::~Reservation() {};
}