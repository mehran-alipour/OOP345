// CustomerOrder.h
// Name: Mehran Alipour
// Seneca Student ID: 126778182
// Seneca email: malipour7@myseneca.ca
// Date of completion: Mar 21, 2020
//
// I confirm that I am the only author of this file
//   and the content was created entirely by me.
#include <iostream>
#include <vector>
#include <iomanip>
#include <algorithm>
#include "CustomerOrder.h"
#include "Station.h"
#include "Utilities.h"

using namespace std;
size_t CustomerOrder::m_widthField = 1;
CustomerOrder::CustomerOrder() :m_lstItem(nullptr) {
    setEmpty();
}
CustomerOrder::CustomerOrder(const std::string order) : m_lstItem(nullptr) {
    Utilities obj;
    bool check = false;
    size_t next_pos = 0;
    if (order != "") {
        m_name = obj.extractToken(order, next_pos, check);
        m_product = obj.extractToken(order, next_pos, check);
        m_cntItem = count(order.begin(), order.end(), obj.getDelimiter()) - 1;

        m_lstItem = new Item * [m_cntItem];

        if (m_cntItem >= 1) {
            for (size_t i = 0; i < m_cntItem; i++) {
                m_lstItem[i] = new Item(obj.extractToken(order, next_pos, check));
            }
        }
        m_widthField = obj.getFieldWidth() < m_widthField ? m_widthField : obj.getFieldWidth();
    }
    else {
        setEmpty();
    }
}
CustomerOrder::CustomerOrder(const CustomerOrder& copyConst) {
    throw "Cant Copy this";
}
CustomerOrder::CustomerOrder(CustomerOrder&& moveConst) noexcept {
    m_lstItem = nullptr;
    setEmpty();
    *this = move(moveConst);
}
CustomerOrder& CustomerOrder::operator=(CustomerOrder&& moveOperator) noexcept {
    if (this != &moveOperator) {
        for (size_t i = 0; i < m_cntItem; i++) {
            delete m_lstItem[i];
        }
        delete[] m_lstItem;
        m_name = moveOperator.m_name;
        m_product = moveOperator.m_product;
        m_cntItem = moveOperator.m_cntItem;
        m_lstItem = moveOperator.m_lstItem;
        moveOperator.m_lstItem = nullptr;
        moveOperator.setEmpty();
    }
    return *this;
}
CustomerOrder::~CustomerOrder() {
    for (size_t i = 0; i < m_cntItem; i++) {
        delete m_lstItem[i];
    }
    delete[] m_lstItem;
}
bool CustomerOrder::isOrderFilled() const {
    size_t i = 0, count = 0;
    bool check = false;
    for (i = 0; i < m_cntItem; i++) {
        if (isItemFilled(m_lstItem[i]->m_itemName)) {
            count++;
        }
    }
    if (count == m_cntItem) {
        check = true;
    }
    return check;
}
bool CustomerOrder::isItemFilled(const string& itemName) const {
    size_t i = 0;
    bool check = false;
    for (i = 0; i < m_cntItem; i++) {
        if (m_lstItem[i]->m_itemName.compare(itemName) == 0) {
            check = m_lstItem[i]->m_isFilled;
        }
    }
    return check;
}
void CustomerOrder::fillItem(Station& station, ostream& os) {
    size_t i = 0;
    for (i = 0; i < m_cntItem; i++) {
        if (m_lstItem[i]->m_itemName == station.getItemName()) {
            if (station.getQuantity() > 0) {
                m_lstItem[i]->m_isFilled = true;
                m_lstItem[i]->m_serialNumber = station.getNextSerialNumber();
                station.updateQuantity();
                os << "    Filled " << m_name << ", " << m_product << " [" << m_lstItem[i]->m_itemName << "]" << endl;
            }
            else {
                os << "    Unable to Filled " << m_name << ", " << m_product << " [" << m_lstItem[i]->m_itemName << "]" << endl;
            }
        }
    }
}
void CustomerOrder::display(ostream& os) const {
    size_t i = 0;
    os << m_name << " - " << m_product << endl;
    for (i = 0; i < m_cntItem; i++) {
        os.setf(ios::right);
        os << "[" << setw(6) << setfill('0') << m_lstItem[i]->m_serialNumber << "] " << setfill(' ');
        os.unsetf(ios::right);
        os.setf(ios::left);
        os << setw(m_widthField) << m_lstItem[i]->m_itemName << "- ";
        os.unsetf(ios::left);
        if (m_lstItem[i]->m_isFilled)
            os << "FILLED";
        else
            os << "MISSING";
        os << endl;
    }
}
void CustomerOrder::setEmpty() {
    delete[] m_lstItem;
    m_name = "";
    m_product = "";
    m_cntItem = 0;
    m_lstItem = nullptr;
}