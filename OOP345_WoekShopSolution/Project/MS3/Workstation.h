// Workstation.h
// Name: Mehran Alipour
// Seneca Student ID: 126778182
// Seneca email: malipour7@myseneca.ca
// Date of completion: Mar 21, 2020
//
// I confirm that I am the only author of this file
//   and the content was created entirely by me.
#ifndef WORKSTATION_H
#define WORKSTATION_H
#include <iostream>
#include <queue>
#include <string>
#include "Station.h"
#include "CustomerOrder.h"
//monitor
class Workstation :public Station {
    std::deque<CustomerOrder> m_orders;
    Workstation* m_pNextStation;
public:
    Workstation(const std::string& conWorkS);
    Workstation(const Workstation& copy) = delete;
    Workstation(Workstation&& move) = delete;
    Workstation& operator=(const Workstation& copy) = delete;
    Workstation& operator=(Workstation&& move) = delete;
    void runProcess(std::ostream& os = std::cout);
    bool moveOrder();
    void setNextStation(Workstation& station);
    const Workstation* getNextStation() const;
    bool getIfCompleted(CustomerOrder& order);
    void display(std::ostream&)const;
    Workstation& operator+=(CustomerOrder&&);
};
#endif // WORKSTATION_H