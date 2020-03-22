// ConfirmationSender.cpp
// Name: Mehran Alipour
// Seneca Student ID: 126778182
// Seneca email: malipour7@myseneca.ca
// Date of completion: Feb 7,2020
//
// I confirm that the content of this file is created by me,
//   with the exception of the parts provided to me by my professor.
#include <iostream>
#include "ConfirmationSender.h"
using namespace std;
namespace sdds {
    ConfirmationSender::ConfirmationSender() : cs_restResv(nullptr) {
        setEmpty();
    }
    ConfirmationSender::ConfirmationSender(const ConfirmationSender& confcop) : cs_restResv(nullptr) {
        setConfi(confcop);
    }
    ConfirmationSender::ConfirmationSender(ConfirmationSender&& confcop) {
        *this = move(confcop);

    }
    ConfirmationSender& ConfirmationSender::operator=(ConfirmationSender&& confcop) {
        if (this != &confcop) {
            delete[] cs_restResv;
            cs_restResv = confcop.cs_restResv;
            cs_numbRecord = confcop.cs_numbRecord;
            confcop.cs_restResv = nullptr;
            confcop.cs_numbRecord = 0;
        }
        return *this;
    }
    void ConfirmationSender::setEmpty() {
        delete[] cs_restResv;
        cs_restResv = nullptr;
        cs_numbRecord = 0;
    }
    void ConfirmationSender::setConfi(const ConfirmationSender& confcop) {
        if (this != &confcop) {
            cs_numbRecord = confcop.cs_numbRecord;
            delete[] cs_restResv;
            cs_restResv = new Reservation * [cs_numbRecord];
            for (size_t i = 0; i < cs_numbRecord; i++) {
                cs_restResv[i] = confcop.cs_restResv[i];
            }
        }
    }
    ConfirmationSender& ConfirmationSender::operator+=(const Reservation& res) {
        size_t i;
        bool checker = true;
        for (i = 0; i < cs_numbRecord; i++) {
            if (cs_restResv[i] == &res) {
                checker = false;
            }
        }
        if (checker) {
            Reservation** temp;
            cs_numbRecord++;
            temp = new Reservation * [cs_numbRecord];
            for (i = 0; i < cs_numbRecord - 1; i++) {
                temp[i] = cs_restResv[i];
            }
            temp[cs_numbRecord - 1] = (Reservation*)&res;
            delete[] cs_restResv;
            cs_restResv = temp;
        }

        return *this;
    }
    ConfirmationSender& ConfirmationSender::operator-=(const Reservation& res) {
        size_t i, index, j = 0;
        bool checker = false;
        for (i = 0; i < cs_numbRecord; i++) {
            if (cs_restResv[i] == &res) {
                checker = true;
                index = i;
                cs_restResv[i] = nullptr;
            }
        }
        if (checker) {

            Reservation** temp = new Reservation * [cs_numbRecord - 1];

            for (i = 0; i < cs_numbRecord; i++) {
                if (i != index) {
                    temp[j] = cs_restResv[i];
                    j++;
                }
            }
            delete[] cs_restResv;
            cs_restResv = temp;
            cs_numbRecord -= 1;

        }
        return *this;
    }
    ostream& ConfirmationSender::display(ostream& os) const {
        os << "--------------------------\n";
        os << "Confirmations to Send\n";
        os << "--------------------------\n";
        if (cs_numbRecord == 0) {
            os << "The object is empty!\n";
            os << "--------------------------\n";
        }
        else {
            //os << "--------------------------\n";
            for (size_t i = 0; i < cs_numbRecord; i++) {
                if (cs_restResv[i] != nullptr) {
                    os << *cs_restResv[i];
                }
            }
            os << "--------------------------\n";
        }
        return os;
    }
    ConfirmationSender::~ConfirmationSender() {
        delete[] cs_restResv;
        cs_restResv = nullptr;
    }
    ostream& operator<<(std::ostream& os, const ConfirmationSender& rest) {
        return rest.display();
    }

}