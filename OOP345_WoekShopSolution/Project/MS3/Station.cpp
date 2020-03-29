// Station.cpp
// Name: Mehran Alipour
// Seneca Student ID: 126778182
// Seneca email: malipour7@myseneca.ca
// Date of completion: Mar 21, 2020
//
// I confirm that I am the only author of this file
//   and the content was created entirely by me.

#include <iostream>
#include <string>
#include <iomanip>
#include "Station.h"
#include "Utilities.h"

using namespace std;
size_t Station::m_widthField = 1;
size_t Station::id_generator{ 0 };
Station::Station(const string& stationRecord) {
    Utilities obj;
    bool check = false;
    size_t next_pos = 0;
    try {
        m_id = ++id_generator;
        m_itemName = obj.extractToken(stationRecord, next_pos, check);
        m_serialNum = stoi(obj.extractToken(stationRecord, next_pos, check));
        m_quan = stoi(obj.extractToken(stationRecord, next_pos, check));
        m_desc = obj.extractToken(stationRecord, next_pos, check);
        m_widthField = obj.getFieldWidth() < m_widthField ? m_widthField : obj.getFieldWidth();
    }
    catch (const char* err) {
        cout << err << endl;
    }
}
const string& Station::getItemName() const {
    return m_itemName;
}
unsigned int Station::getNextSerialNumber() {
    return m_serialNum++;
}
unsigned int Station::getQuantity() const {
    return m_quan;
}
void Station::updateQuantity() {
    if (m_quan > 0)
        m_quan--;
}
void Station::display(ostream& os, bool full) const {
    os.setf(ios::right);
    os << '[' << setw(3) << setfill('0') << m_id << ']';
    os.unsetf(ios::right);
    os.setf(ios::left);
    os << setfill(' ');
    os << " Item: " << setw(m_widthField) << m_itemName;
    os.unsetf(ios::left);
    os.setf(ios::right);
    os << "[" << setw(6) << setfill('0') << m_serialNum << "]" << setfill(' ');
    os.unsetf(ios::right);
    os.setf(ios::left);
    if (full) {
        os << " Quantity: " << setw(m_widthField) << m_quan << "Description: " << m_desc;
    }
    os.unsetf(ios::left);
    os << endl;
}