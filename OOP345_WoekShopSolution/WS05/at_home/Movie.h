// Movie.h
// Name: Mehran Alipour
// Seneca Student ID: 126778182
// Seneca email: malipour7@myseneca.ca
// Date of completion: Feb 13,2020
//
// I confirm that the content of this file is created by me,
//   with the exception of the parts provided to me by my professor.
#ifndef SDDS_MOVIE_H__
#define SDDS_MOVIE_H__
#include <string>
#include <iostream>
namespace sdds {
    class Movie {
        std::string m_title;
        size_t m_relYear;
        std::string m_description;
    public:

        Movie();
        Movie(const Movie& copCunMovie);
        Movie(Movie&& movCunMovie);
        Movie(const std::string& strMovie);

        Movie& operator=(const Movie& assignOpMovie);
        Movie& operator=(Movie&& assignMoOpMovie);

        const std::string& title() const;

        template<typename T>
        void fixSpelling(T spellChecker) {
            spellChecker(m_title);
            spellChecker(m_description);
        }
        void setEmpty();
        std::ostream& display(std::ostream& os = std::cout) const;
        std::string findEras(std::string& Movie, const char delimeter);
        void ltrim(std::string& s);
        void rtrim(std::string& s);
        std::string trim(std::string& s);
        ~Movie();
    };
    std::ostream& operator<<(std::ostream& os, const Movie& library);

}
#endif // !SDDS_Movie_H__