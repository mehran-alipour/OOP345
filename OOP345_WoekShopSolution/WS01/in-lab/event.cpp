// EVENT_CPP
// Name: Mehran Alipour
// Seneca Student ID: 126778182
// Seneca email: malipour7@myseneca.ca
// Date of completion: Jan 16,2020
//
// I confirm that the content of this file is created by me,
//   with the exception of the parts provided to me by my professor.
// Workshop 1 - Linkage, Storage Duration, Namespaces, and OS Interface
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstring>
#include "event.h"
using namespace std;
namespace sdds{
    Event::Event() {
        setEmpty();
    }
    void Event::setEmpty() {
        m_descEvent[0] = '\0';
        m_eventTime = 99999u;
        m_hh = 99999u;
        m_mm = 99999u;
        m_ss = 99999u;
    }
    void Event::setDescription(const char* desc) {
        if (desc == NULL || desc[0] == 0) {
            setEmpty();
        }
        else {
            strncpy(m_descEvent, desc, 128);
            m_eventTime = g_sysClock;
            convert();
        }
    }
    void Event::convert() {
        m_hh = m_eventTime / 3600u;
        m_mm = (m_eventTime - (m_hh * 3600u)) / 60u;
        m_ss = (m_eventTime - (m_hh * 3600u) + (m_mm * 60u)) > 0;
    }
    bool Event::isEmpty() const {
        return m_descEvent[0] == '\0';
    }
    void Event::display() const {
        static int counter = 1;
        cout << counter++ << ". ";
        if (isEmpty()) {
            cout << "[No Event]" << endl;
        }
        else {
            cout.width(2);
            cout.fill('0');
            cout.setf(ios::right);
            cout << m_hh << ":";
            cout.width(2);
            cout << m_mm << ":";
            cout.width(2);
            cout << m_ss;
            cout.fill(' ');
            cout.unsetf(ios::right);
            cout << " -> " << m_descEvent << endl;
        }
    }
    /*
    ostream Event::display(ostream& os) const {
        static int counter = 1;
        os << counter++ << ". ";
        if (isEmpty()) {
            os << "[No Event]" << endl;
        }
        else {
            os << m_hh << ":" << m_mm << ":" << m_ss << " -> " << m_descEvent << endl;
        }
        return coutos;
    }*/
    Event::~Event() {
        // No dynamic memory allocation
    }
}