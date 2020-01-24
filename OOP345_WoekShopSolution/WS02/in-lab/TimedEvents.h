// TimedEvents.h
// Name: Mehran Alipour
// Seneca Student ID: 126778182
// Seneca email: malipour7@myseneca.ca
// Date of completion: Jan 24,2020
//
// I confirm that the content of this file is created by me,
//   with the exception of the parts provided to me by my professor.

#ifndef SDDS_TIMEDEVENTS_H__
#define SDDS_TIMEDEVENTS_H__
#include <iomanip>
#include <ctime>
#include <chrono>
#include <iostream>
#include <string>

namespace sdds {
    const unsigned int MAX_REC = 7;
    class TimedEvents {
        // Stors number of records currently stored
        unsigned int t_numRec {0};
        std::chrono::steady_clock::time_point t_startTime;
        std::chrono::steady_clock::time_point t_endTime;
        struct {
            std::string t_s_eveName;
            std::string t_s_uniTime;
            std::chrono::steady_clock::duration t_s_duraiton{0};
        }t_event[MAX_REC];
    public:
        TimedEvents();
        //TimedEvents(const TimedEvents&);
        void startClock();
        void stopClock();
        void recordEvent(const char* setEventRec);
        TimedEvents& operator=(const TimedEvents&) = delete;
        friend std::ostream& operator<<(std::ostream& os, const TimedEvents& events);
        virtual ~TimedEvents();
    };
}
#endif // End of Safegard
