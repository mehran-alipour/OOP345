// Utilities.h
// Name: Mehran Alipour
// Seneca Student ID: 126778182
// Seneca email: malipour7@myseneca.ca
// Date of completion: Mar 21, 2020
//
// I confirm that I am the only author of this file
//   and the content was created entirely by me.

#ifndef SDDS_UTILITIES_H
#define SDDS_UTILITIES_H
#include <string>
namespace sdds{
    class Utilities {
        size_t m_widthField; // used for lenght of the display default 1
        static char m_delimiter;
    public:
        Utilities();
        void setFieldWidth(size_t newWidth);
        const size_t getFieldWidth() const;
        std::string extractToken(const std::string& str, size_t& next_pos, bool& more);
        static void setDelimiter(char newDelimiter);
        static char getDelimiter();
    };
}
#endif // SDDS_UTILITIES_H