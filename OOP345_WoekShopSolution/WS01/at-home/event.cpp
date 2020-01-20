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
    Event::Event(const Event& copy):m_descEvent(nullptr){
        setEvent(copy.m_descEvent, copy.m_eventTime);
    }
    void Event::setEmpty() {
        m_descEvent = nullptr;
        m_eventTime = 99999u;
        m_hh = 99999u;
        m_mm = 99999u;
        m_ss = 99999u;
    }
    void Event::setEvent(const char* desc, unsigned int time) {
        size_t len;
        if (desc != nullptr) {
            len = strlen(desc);
            m_descEvent = new char[len + 1u];
            strcpy(m_descEvent, desc);
        }
        m_eventTime = time;
        convert();
    }
    void Event::setDescription(const char* desc) {
        delete[] m_descEvent;
        if (  desc == NULL || desc[0] == '\0' || desc == nullptr) {
            setEmpty();
        }
        else if (g_sysClock <= 0 && g_sysClock >= 86400) {
            cout << "check the g_sysClock variable value it must remain between 0 and 86400";
        }
        else {
            setEvent(desc, g_sysClock);
        }
    }
    void Event::convert() {
        m_hh = m_eventTime / 3600u;
        m_mm = (m_eventTime - (m_hh * 3600u)) / 60u;
        m_ss = m_eventTime - m_hh * 3600u - m_mm * 60u;
    }
    bool Event::isEmpty() const {
        return m_descEvent == nullptr;
    }
    void Event::display() const {
        static int counter = 1;
        cout.width(3);
        cout.setf(ios::right);
        cout << counter++ << ". ";
        cout.unsetf(ios::right);
        if (isEmpty()) {
            cout << "[ No Event ]" << endl;
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

    Event& Event::operator=(const Event& copy) {
        // Preventing self copy
        if (this != &copy) {
            this->setEvent(copy.m_descEvent, copy.m_eventTime);
        }
        return *this;
    }
    Event::~Event() {
        delete[] m_descEvent;
    }
}