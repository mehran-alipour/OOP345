// SongCollection.h
// Name: Mehran Alipour
// Seneca Student ID: 126778182
// Seneca email: malipour7@myseneca.ca
// Date of completion: Mar 12,2020
//
// I confirm that the content of this file is created by me,
//   with the exception of the parts provided to me by my professor.
#ifndef SDDS_SONGCOLLECTION_H__
#define SDDS_SONGCOLLECTION_H__
#include <iostream>
#include <string>
#include <fstream> 
#include <vector>
namespace sdds {
    struct Song {
        std::string s_artist = "";
        std::string s_title = "";
        std::string s_album = "";
        int         s_year = 0;
        int         s_songLen = 0;
        double      s_price= 0;
    };
    class SongCollection {
        std::vector<Song> sc_songColle;
    public:
        SongCollection(const char* fileName);
        Song SetSong(std::string rec);
        void display(std::ostream& out = std::cout) const;

        // Utility
        std::string find(std::string& rec, int len);
        void ltrim(std::string& s);
        void rtrim(std::string& s);
        std::string trim(std::string& s);
    };
    std::ostream& operator<<(std::ostream& out, const Song& theSong);
}
#endif // !SDDS_SONGCOLLECTION_H__