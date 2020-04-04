// Workstation.cpp
// Name: Mehran Alipour
// Seneca Student ID: 126778182
// Seneca email: malipour7@myseneca.ca
// Date of completion: Mar 21, 2020
//
// I confirm that I am the only author of this file
//   and the content was created entirely by me.

#include <iostream>
#include <string>
#include "Workstation.h"
using namespace std;

Workstation::Workstation(const string& conWorkS) :Station(conWorkS) {
    m_pNextStation = nullptr;
}
void Workstation::runProcess(std::ostream& os) {
    if (!m_orders.empty()) {
        m_orders.front().fillItem(*this, os);
    }
}
bool Workstation::moveOrder() {
    bool checker = false;
    if (!m_orders.empty() && m_orders.front().isItemFilled(getItemName())) {
        if (m_pNextStation != nullptr) {
            *m_pNextStation += move(m_orders.front());
            m_orders.pop_front();
            checker = true;
        }
    }
    return checker;
}
void Workstation::setNextStation(Workstation& station) {
    m_pNextStation = &station;
}
const Workstation* Workstation::getNextStation() const {
    return m_pNextStation;
}
bool Workstation::getIfCompleted(CustomerOrder& order) {
    bool checker = false;
    if (!m_orders.empty() && m_orders.front().isOrderFilled()) {
        order = move(m_orders.front());
        m_orders.pop_front();
        checker = true;
    }
    return checker;
}
void Workstation::display(std::ostream&) const {
    cout << this->getItemName() << " --> ";
    if (m_pNextStation != nullptr) {
        cout << m_pNextStation->getItemName() << endl;
    }
    else {
        cout << "END OF LINE" << endl;
    }
}
Workstation& Workstation::operator+=(CustomerOrder&& customerOrder) {
    m_orders.push_back(move(customerOrder));
    return *this;
}
