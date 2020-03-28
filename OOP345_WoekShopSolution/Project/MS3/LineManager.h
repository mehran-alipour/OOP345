// LineManager.h
// Name: Mehran Alipour
// Seneca Student ID: 126778182
// Seneca email: malipour7@myseneca.ca
// Date of completion: Mar 21, 2020
//
// I confirm that I am the only author of this file
//   and the content was created entirely by me.

#ifndef LINEMANAGER_H
#define LINEMANAGER_H

#include <iostream>
#include <string>
#include <queue>
#include <vector>
#include "CustomerOrder.h"
#include "Workstation.h"

class LineManager {
    std::vector<Workstation*> AssemblyLine;
    std::deque<CustomerOrder> ToBeFilled;
    std::deque<CustomerOrder> Completed;
    unsigned int m_cntCustomerOrder;
public:
    LineManager(const std::string& myString, 
        std::vector<Workstation*>& workSP, 
        std::vector<CustomerOrder>& filcus);
    bool run(std::ostream& os);
    void displayCompletedOrders(std::ostream& os) const;
    void displayStations() const;
    void displayStationsSorted() const;
};

#endif // LINEMANAGER_H