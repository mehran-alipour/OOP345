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
        char* m_descEvent;
        //event start as the number of seconds since midnight range (0 - 86400)
        unsigned int m_eventTime;
        // Hours
        unsigned int m_hh;
        // min
        unsigned int m_mm;
        // second
        unsigned int m_ss;
        // set the event desc and time
        void setEvent(const char* desc, unsigned int time);
        // convert the event time provided in second to Hour:min:sec
        void convert();
        // if the discription 
        bool isEmpty()const;
        // set the object to safeEmpty state all times are set to 99999
        void setEmpty();
    public:
        // connstructor
        Event();
        // copy constructor
        Event(const Event&);
        // set the object discription and event ty
        void setDescription(const char* desc);
        // chech if the object is empty
        void display() const;
        Event& operator=(const Event& copyEvent);
        ~Event();

    };
}
#endif // End of Safegard