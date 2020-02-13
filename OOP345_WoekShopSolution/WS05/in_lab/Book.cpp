// Book.cpp
// Name: Mehran Alipour
// Seneca Student ID: 126778182
// Seneca email: malipour7@myseneca.ca
// Date of completion: Feb 12,2020
//
// I confirm that the content of this file is created by me,
//   with the exception of the parts provided to me by my professor.
#include <iostream>
#include <string>
#include "Book.h"
using namespace std;
namespace sdds {
    Book::Book() {
        setEmpty();
    }
    Book::Book(const Book& copCunBook) {
        *this = copCunBook;
    }
    Book::Book(Book&& movCunBook) {
        *this = move(movCunBook);
    }
    Book::Book(const std::string& strBook) {
        string temp;
        temp = strBook;
        if (strBook != "") {
            b_author = findEras(temp, ',');
            b_title = findEras(temp, ',');
            b_countryOfPublication = findEras(temp, ',');
            b_price = stod(findEras(temp, ','));
            b_pubYear = stoul(findEras(temp, ','));
            b_description = findEras(temp, '\n');
        }
        else {
            setEmpty();
        }
    }
    // operators \/
    Book& Book::operator=(const Book& assignOpBook) {
        if (this != &assignOpBook) {
            b_author = assignOpBook.b_author;
            b_title = assignOpBook.b_title;
            b_countryOfPublication = assignOpBook.b_countryOfPublication;
            b_pubYear = assignOpBook.b_pubYear;
            b_price = assignOpBook.b_price;
            b_description = assignOpBook.b_description;
        }
        return *this;
    }
    Book& Book::operator=(Book&& assignMoOpBook) {
        if (this != &assignMoOpBook) {
            *this = assignMoOpBook;
            assignMoOpBook.setEmpty();
        }
        return *this;
    }
    // return content of the book \/
    const std::string& Book::title() const {
        return b_title;
    }
    const std::string& Book::country() const {
        return b_countryOfPublication;
    }
    const size_t& Book::year() const {
        return b_pubYear;
    }
    double& Book::price() {
        return b_price;
    }
    // Utility Functions \/
    void Book::setEmpty() {
        b_author = "";
        b_title = "";
        b_countryOfPublication = "";
        b_pubYear = 0;
        b_price = 0;
        b_description = "";
    }
    std::ostream& Book::display(std::ostream& os) const {
        os.setf(ios::right);
        os.width(20);
        os << b_author << " | ";
        os.width(22);
        os << b_title << " | ";
        os.width(5);
        os << b_countryOfPublication << " | ";
        os.width(4);
        os << b_pubYear << " | ";
        os.width(6);
        os.setf(ios::fixed);
        os.precision(2);
        os << b_price << " | ";
        os.unsetf(ios::fixed);
        os.unsetf(ios::right);
        os.setf(ios::left);
        os << b_description;
        os.unsetf(ios::left);
        os << endl;

        return os;
    }
    string Book::findEras(string& res, const char delimeter) {
        string temp;
        int i = 0;
        i = (int)res.find(delimeter);
        temp = res.substr(0, i);
        if (i != -1) {
            res.erase(0, i + 1);
        }
        return trim(temp);
    }



    void Book::ltrim(string& s) {
        const string WHITESPACE = " \r\t\f\v";
        size_t start = s.find_first_not_of(WHITESPACE);
        s = start == string::npos ? "" : s.substr(start);
    }
    void Book::rtrim(string& s) {
        const string WHITESPACE = " \r\t\f\v";
        size_t end = s.find_last_not_of(WHITESPACE);
        s = end == string::npos ? "" : s.substr(0, end + 1);
    }
    string Book::trim(string& s) {
        ltrim(s);
        rtrim(s);
        return s;
    }


    Book::~Book() {

    }
    ostream& operator<<(ostream& os, const Book& book) {
        return book.display();
    }
}