// Station.h
// Name: Mehran Alipour
// Seneca Student ID: 126778182
// Seneca email: malipour7@myseneca.ca
// Date of completion: Mar 21, 2020
//
// I confirm that I am the only author of this file
//   and the content was created entirely by me.
//#ifndef SDDS_STATION_H
//#define SDDS_STATION_H
#ifndef STATION_H
#define STATION_H
#include <iostream>
#include <string>
//namespace sdds {
class Station {
    size_t m_id{ 0 };
    std::string m_itemName{ "" };
    std::string m_desc{ "" };
    size_t m_serialNum{ 0 };
    size_t m_quan{ 0 };
    static size_t m_widthField;
    static size_t id_generator;
public:
    Station(const std::string& stationRecord);
    const std::string& getItemName() const;
    unsigned int getNextSerialNumber();
    unsigned int getQuantity() const;
    void updateQuantity();
    void display(std::ostream& os, bool full) const;
};
//}
#endif // SDDS_UTILITIES_H