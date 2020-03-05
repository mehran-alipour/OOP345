// Movie.cpp
// Name: Mehran Alipour
// Seneca Student ID: 126778182
// Seneca email: malipour7@myseneca.ca
// Date of completion: Feb 12,2020
//
// I confirm that the content of this file is created by me,
//   with the exception of the parts provided to me by my professor.
#include <iostream>
#include <string>
#include "Movie.h"
using namespace std;
namespace sdds {
    Movie::Movie() {
        setEmpty();
    }
    Movie::Movie(const Movie& copCunMovie) {
        *this = copCunMovie;
    }
    Movie::Movie(Movie&& movCunMovie) {
        *this = move(movCunMovie);
    }
    Movie::Movie(const std::string& strMovie) {
        string temp;
        temp = strMovie;
        if (strMovie != "") {
            m_title = findEras(temp, ',');
            m_relYear = stoul(findEras(temp, ','));
            m_description = findEras(temp, '\n');
        }
        else {
            setEmpty();
        }
    }
    // operators \/
    Movie& Movie::operator=(const Movie& assignOpMovie) {
        if (this != &assignOpMovie) {
            m_title = assignOpMovie.m_title;
            m_relYear = assignOpMovie.m_relYear;
            m_description = assignOpMovie.m_description;
        }
        return *this;
    }
    Movie& Movie::operator=(Movie&& assignMoOpMovie) {
        if (this != &assignMoOpMovie) {
            *this = assignMoOpMovie;
            assignMoOpMovie.setEmpty();
        }
        return *this;
    }
    // return content of the Movie \/
    const string& Movie::title() const {
        return m_title;
    }
    // Utility Functions \/
    void Movie::setEmpty() {
        m_title = "";
        m_relYear = 0;
        m_description = "";
    }
    std::ostream& Movie::display(std::ostream& os) const {
        os.setf(ios::right);
        os.width(40);
        os << m_title << " | ";
        os.width(4);
        os << m_relYear << " | ";
        os.unsetf(ios::right);
        os.setf(ios::left);
        os << m_description;
        os.unsetf(ios::left);
        os << endl;

        return os;
    }
    string Movie::findEras(string& res, const char delimeter) {
        string temp;
        int i = 0;
        i = (int)res.find(delimeter);
        temp = res.substr(0, i);
        if (i != -1) {
            res.erase(0, i + 1);
        }
        return trim(temp);
    }
    void Movie::ltrim(string& s) {
        const string WHITESPACE = " \r\t\f\v";
        size_t start = s.find_first_not_of(WHITESPACE);
        s = start == string::npos ? "" : s.substr(start);
    }
    void Movie::rtrim(string& s) {
        const string WHITESPACE = " \r\t\f\v";
        size_t end = s.find_last_not_of(WHITESPACE);
        s = end == string::npos ? "" : s.substr(0, end + 1);
    }
    string Movie::trim(string& s) {
        ltrim(s);
        rtrim(s);
        return s;
    }
    Movie::~Movie() {

    }
    ostream& operator<<(ostream& os, const Movie& Movie) {
        return Movie.display();
    }
}