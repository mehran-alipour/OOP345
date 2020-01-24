// TimedEvents.cpp
// Name: Mehran Alipour
// Seneca Student ID: 126778182
// Seneca email: malipour7@myseneca.ca
// Date of completion: Jan 24,2020
//
// I confirm that the content of this file is created by me,
//   with the exception of the parts provided to me by my professor.
#include <iostream>
#include "TimedEvents.h"

using namespace std;
namespace sdds {
    TimedEvents::TimedEvents() {
        t_numRec = 0;
    }
    void TimedEvents::startClock() {
        t_startTime = chrono::steady_clock::now();
    }
    void TimedEvents::stopClock() {
        t_endTime = chrono::steady_clock::now();
    }
    void TimedEvents::recordEvent(const char* eventName) {
        auto timeUnit = chrono::duration_cast<chrono::nanoseconds>
             (t_endTime - t_startTime);
        if (t_numRec < MAX_REC) {
            this->t_event[t_numRec].t_s_eveName = eventName;
            this->t_event[t_numRec].t_s_uniTime = "nanosecond";
            this->t_event[t_numRec].t_s_duraiton = timeUnit;
            t_numRec++;
        }
    }
    ostream& operator<<(ostream& os, const TimedEvents& events){
        unsigned int i;
        os  << "--------------------------" << endl
           << "Execution Times:" << endl
           << "--------------------------" << endl;
        for (i = 0; i < events.t_numRec; i++) {
            os << setw(20) << left
                << events.t_event[i].t_s_eveName << ' ' << setw(12) << right
                << events.t_event[i].t_s_duraiton.count() << ' '
                << events.t_event[i].t_s_uniTime << endl;
        }
        os << "--------------------------" << endl;
        return os;
    }
    TimedEvents::~TimedEvents() {

    }
}