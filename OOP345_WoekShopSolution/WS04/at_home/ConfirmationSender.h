// ConfirmationSender.h
// Name: Mehran Alipour
// Seneca Student ID: 126778182
// Seneca email: malipour7@myseneca.ca
// Date of completion: Feb 7,2020
//
// I confirm that the content of this file is created by me,
//   with the exception of the parts provided to me by my professor.

#pragma once
#include <iostream>
#include "Restaurant.h"
namespace sdds {
    class ConfirmationSender {
        Reservation** cs_restResv;
        size_t cs_numbRecord;
    public:
        ConfirmationSender();
        ConfirmationSender(const ConfirmationSender& confcop);
        ConfirmationSender(ConfirmationSender&& confcop);
        ConfirmationSender& operator=(ConfirmationSender&& res);
        void setEmpty();
        void setConfi(const ConfirmationSender& confcop);
        ConfirmationSender& operator+=(const Reservation& res);
        ConfirmationSender& operator-=(const Reservation& res);
        std::ostream& display(std::ostream& os = std::cout) const;
        virtual ~ConfirmationSender();
    };
    std::ostream& operator<<(std::ostream& os, const ConfirmationSender& rest);
}