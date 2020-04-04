// LineManager.cpp
// Name: Mehran Alipour
// Seneca Student ID: 126778182
// Seneca email: malipour7@myseneca.ca
// Date of completion: Mar 21, 2020
//
// I confirm that I am the only author of this file
//   and the content was created entirely by me.
#include <iostream>
#include <fstream>
#include <string>
#include <queue>
#include <vector>
#include <algorithm>
#include <exception>
#include "CustomerOrder.h"
#include "Workstation.h"
#include "LineManager.h"

using namespace std;

LineManager::LineManager(const std::string& myString, std::vector<Workstation*>& workSP, std::vector<CustomerOrder>& filcus) {
    ifstream input(myString);
    string mystatoin;
    size_t count = 0;
    m_first = nullptr;
    if (!input)
    {
        std::cerr << "ERROR: Cannot open file [" << myString << "].\n";
    }
    do {
        if (input) {
            count++;
            getline(input, mystatoin);
            string str1 = "", str2 = "";
            size_t nextPose = mystatoin.find('|');
            if (nextPose == std::string::npos) {
                nextPose = mystatoin.find('\n');
                str1 = mystatoin.substr(0, nextPose++);
            }
            else {
                str1 = mystatoin.substr(0, nextPose++);
                str2 = mystatoin.substr(nextPose, mystatoin.find('\n'));
            }
            for (auto workstation : workSP) {
                if (workstation->getItemName().compare(str1) == 0) {
                    if (count == 1) {
                        m_first = workstation;
                    }
                    for (auto workstationNext : workSP) {
                        if (workstationNext->getItemName().compare(str2) == 0) {
                            workstation->setNextStation(*workstationNext);
                        }
                    }
                }
            }
        }
    } while (!input.eof());
    input.close();
    m_cntCustomerOrder = filcus.size();
    for (auto workstation : workSP) {
        AssemblyLine.push_back(workstation);
    }
    for (size_t i = 0; i < filcus.size(); i++) {
        ToBeFilled.push_back(move(filcus[i]));
    }

}
bool LineManager::run(std::ostream& os) {
    bool runComplete = false;
    static size_t iteration = 0;
    CustomerOrder TempCompleted;
    os << "Line Manager Iteration : " << ++iteration << endl;
    
    if (ToBeFilled.size() > 0) {
        *m_first += std::move(ToBeFilled.front());
        ToBeFilled.pop_front();
    }
    for (auto station : AssemblyLine) {
        station->runProcess(os);
    }
    for (auto station : AssemblyLine) {
        if (!station->moveOrder()) {
            if (station->getIfCompleted(TempCompleted)) {
                Completed.push_front(std::move(TempCompleted));
            }
        }
    }

    if (!Completed.empty() && Completed.size() == m_cntCustomerOrder) {
        runComplete = true;
    }

    return runComplete;
}
void LineManager::displayCompletedOrders(std::ostream& os) const {
    for (size_t i = 0; i < m_cntCustomerOrder; i++) {
        Completed[i].display(os);
    }
}
void LineManager::displayStations() const {
    for (auto station : AssemblyLine) {
        station->display(cout);
    }
}
void LineManager::displayStationsSorted() const {
    Workstation* temp;
    m_first->display(std::cout);
    temp = m_first;
    for (unsigned int i = 0; i < m_cntCustomerOrder; i++) {
        for (auto oneWorkstation : AssemblyLine) {
            if (temp->getNextStation() == oneWorkstation) {
                oneWorkstation->display(std::cout);
                temp = oneWorkstation;
            }

        }
    }
}