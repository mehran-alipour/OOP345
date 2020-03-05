// Book.h
// Name: Mehran Alipour
// Seneca Student ID: 126778182
// Seneca email: malipour7@myseneca.ca
// Date of completion: Feb 13,2020
//
// I confirm that the content of this file is created by me,
//   with the exception of the parts provided to me by my professor.
#ifndef SDDS_BOOK_H__
#define SDDS_BOOK_H__
#include <string>
#include <iostream>
namespace sdds {
    class Book {
        // the title and author is selected as string because it allows 
        // used of the functionality in string library which simplify search
        // and memory handeling \/
        std::string b_author;
        std::string b_title;
        std::string b_countryOfPublication;
        size_t b_pubYear;
        double b_price;
        std::string b_description;
    public:
        // constructors \/
        Book();
        Book(const Book& copCunBook);
        Book(Book&& movCunBook);
        Book(const std::string& strBook);
        // operators \/
        Book& operator=(const Book& assignOpBook);
        Book& operator=(Book&& assignMoOpBook);
        // return content of the book \/
        const std::string& title() const; // returns the title of the book
        const std::string& country() const; // return the publication country
        const size_t& year() const; // return the publication year
        double& price(); // return the price by refrence allows changes to price
        // Utility Functions \/
        template<typename T>
        void fixSpelling(T spellChecker) {
            spellChecker(b_description);
        }
        void setEmpty();
        std::ostream& display(std::ostream& os = std::cout) const;
        std::string findEras(std::string& book, const char delimeter);
        void ltrim(std::string& s);
        void rtrim(std::string& s);
        std::string trim(std::string& s);
        ~Book();
    };
    std::ostream& operator<<(std::ostream& os, const Book& library);

}
#endif // !SDDS_BOOK_H__
