// CustomerOrder.cpp
// Name: Mehran Alipour
// Seneca Student ID: 126778182
// Seneca email: malipour7@myseneca.ca
// Date of completion: Mar 21, 2020
//
// I confirm that I am the only author of this file
//   and the content was created entirely by me.

#ifndef CUSTOMERORDER_H
#define CUSTOMERORDER_H
#include <string>
#include "Station.h"
struct Item
{
    std::string m_itemName;
    unsigned int m_serialNumber = 0;
    bool m_isFilled = false;
    Item(const std::string& src) : m_itemName(src) {};
};
class CustomerOrder {
    std::string m_name;
    std::string m_product;
    unsigned int m_cntItem;
    Item** m_lstItem;
    static size_t m_widthField;
public:
    CustomerOrder();
    CustomerOrder(const std::string);
    CustomerOrder(const CustomerOrder& copyConst);
    CustomerOrder& operator=(const CustomerOrder& copyOperator) = delete;
    CustomerOrder(CustomerOrder&& moveConst) noexcept;
    CustomerOrder& operator=(CustomerOrder&& moveOperator) noexcept;
    ~CustomerOrder();
    bool isOrderFilled() const;
    bool isItemFilled(const std::string& itemName) const;
    void fillItem(Station& station, std::ostream& os);
    void display(std::ostream& os = std::cout) const;
    void setEmpty();
};
#endif // SDDS_UTILITIES_H