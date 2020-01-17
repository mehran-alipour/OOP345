// EVENT_H
// Name: Mehran Alipour
// Seneca Student ID: 126778182
// Seneca email: malipour7@myseneca.ca
// Date of completion: Jan 16,2020
//
// I confirm that the content of this file is created by me,
//   with the exception of the parts provided to me by my professor.
// Workshop 1 - Linkage, Storage Duration, Namespaces, and OS Interface

#ifndef SDDS_EVENT_H__
#define SDDS_EVENT_H__
#include <iostream>
//time of day as the number of seconds since midnight range (0 - 86400)
extern unsigned int g_sysClock;
namespace sdds{
    class Event {
        //representing the description of the event
        char m_descEvent[128];
        //event start as the number of seconds since midnight range (0 - 86400)
        unsigned int m_eventTime;
        unsigned int m_hh;
        unsigned int m_mm;
        unsigned int m_ss;
    public:
        Event();
        void setEmpty();
        void setDescription(const char* desc);
        void convert();
        bool isEmpty()const;
        void display() const;
        ~Event();
    };
}
#endif // End of Safegard