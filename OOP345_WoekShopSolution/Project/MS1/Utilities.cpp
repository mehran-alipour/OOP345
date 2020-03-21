// Utilities.cpp
// Name: Mehran Alipour
// Seneca Student ID: 126778182
// Seneca email: malipour7@myseneca.ca
// Date of completion: Mar 21, 2020
//
// I confirm that I am the only author of this file
//   and the content was created entirely by me.
#include <string>
#include <iostream>
#include "Utilities.h"

namespace sdds {
    char Utilities::m_delimiter = '\0';
    Utilities::Utilities() {
        m_widthField = 1;
    }
    void Utilities::setFieldWidth(size_t newWidth) {
        m_widthField = newWidth > 0 ? newWidth : 1;
    }
    const size_t Utilities::getFieldWidth() const {
        return m_widthField;
    }
    std::string Utilities::extractToken(const std::string& str, size_t& next_pos, bool& more) {
        size_t i = 0, len = 0;
        std::string extracted = "";
        more = true;
        i = str.find(m_delimiter, next_pos);
        if (i == std::string::npos) {
            i = str.find('\n', next_pos);
            len = i - next_pos;
        }
        else {
            len = i - next_pos;
            m_widthField = len + 1 > m_widthField ? len + 1 : m_widthField;
        }
        extracted = str.substr(next_pos, len);
        next_pos = len + next_pos + 1;
        if (extracted.size() == 0) {
            more = false;
            throw "No Token";
        }
        return extracted;
    }
    void Utilities::setDelimiter(char newDelimiter) {
        m_delimiter = newDelimiter;
    }
    char Utilities::getDelimiter() {
        return m_delimiter;
    }
}