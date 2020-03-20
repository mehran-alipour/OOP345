// SongCollection.cpp
// Name: Mehran Alipour
// Seneca Student ID: 126778182
// Seneca email: malipour7@myseneca.ca
// Date of completion: Mar 12,2020
//
// I confirm that the content of this file is created by me,
//   with the exception of the parts provided to me by my professor.
#include <iostream>
#include <iomanip>
#include <exception>
#include <fstream>
#include <algorithm>
#include <functional>
#include <numeric>
#include <list>
#include <cstring>
#include "SongCollection.h"
using namespace std;
namespace sdds {
    SongCollection::SongCollection(const char* fileName) {
        string errorString;
        ifstream file(fileName);
        if (!file)
        {
            errorString += fileName;
            throw "ERROR: Cannot open file [" + errorString + "].\n";
        }
        else {
            file.clear();
            file.seekg(std::ios::beg);
            string sonrecord;
            Song setSong;
            do {
                getline(file, sonrecord);
                // if the previous operation failed, the "file" object is
                //   in error mode
                if (file) {
                    sc_songColle.push_back(SetSong(sonrecord));
                }
            } while (file);
        }
        file.close();
    }
    Song SongCollection::SetSong(std::string rec) {
        Song mySong;
        mySong.m_title = find(rec, 25);
        mySong.m_artist = find(rec, 25);
        mySong.m_album = find(rec, 25);
        try {
            mySong.m_year = stoi(find(rec, 5));
        }
        catch (...) {
            mySong.m_year = 0;
        }
        mySong.m_songLen = stoi(find(rec, 5));
        mySong.m_price = stod(find(rec, 5));
        return mySong;
    }
    void SongCollection::display(std::ostream& out) const {
        for_each(sc_songColle.begin(), sc_songColle.end(), [&](const Song i) { out << i << endl; });
        int hr, min, sec, totalSec;
        totalSec = sum();
        hr = (int)totalSec / 3600;
        min = (int)(totalSec - (hr * 3600)) / 60;
        sec = totalSec - ((hr * 3600) + (min * 60));
        cout << "----------------------------------------------------------------------------------------" << endl;
        cout << "|" << setw(78) << "Total Listening Time: " << hr << ":" << setw(2) << setfill('0') << min << ":" << sec << " |" << endl;
    }
    int SongCollection::sum() const {
        return accumulate(sc_songColle.begin(), sc_songColle.end(), 0,
            [](int sum, const Song& curr) { return sum + curr.m_songLen; });
    }
    void  SongCollection::sort(const char* title) {
        if (!strcmp(title, "length")) {
            std::sort(sc_songColle.begin(), sc_songColle.end(),
                [](const Song& A, const Song& B) {
                    return A.m_songLen < B.m_songLen;
                });
        }
        else if (!strcmp(title, "album")) {
            std::sort(sc_songColle.begin(), sc_songColle.end(),
                [](const Song& A, const Song& B) {
                    return (A.m_album < B.m_album);
                });
        }
        else if (!strcmp(title, "title")) {
            std::sort(sc_songColle.begin(), sc_songColle.end(),
                [](const Song& A, const Song& B) {
                    return (A.m_title < B.m_title);
                });
        }
        else {
            cout << "sort only organazie based on album, songlen or title" << endl;
        }
    }
    void SongCollection::cleanAlbum() {
        std::for_each(this->sc_songColle.begin(), this->sc_songColle.end(),
            [](Song& A) {
                if (A.m_album == "[None]") {
                    A.m_album = "";
                }
                return A;
            });
    }
    bool SongCollection::inCollection(const char* artist) {
        string art = artist;
        int n = 0;
        n = std::count_if(sc_songColle.begin(), sc_songColle.end(),
            [=](Song A) {
                return !A.m_artist.compare(art);
            });
        return n > 0;
    }
    list<Song> SongCollection::getSongsForArtist(const char* artist) const {
        int n = std::count_if(sc_songColle.begin(), sc_songColle.end(),
            [=](const Song A) {
                return !A.m_artist.compare(artist);
            });
        list<Song> mySong(n);
        std::copy_if(sc_songColle.begin(), sc_songColle.end(), mySong.begin(), [=](const Song A) {
            return !A.m_artist.compare(artist);
            });

        return mySong;
    }

    string SongCollection::find(string& rec, int len) {
        string temp;
        temp = rec.substr(0, len - 1);
        rec.erase(0, len);
        return trim(temp);
    }
    void SongCollection::ltrim(string& s) {
        const string WHITESPACE = " \r\t\f\v";
        size_t start = s.find_first_not_of(WHITESPACE);
        s = start == string::npos ? "" : s.substr(start);
    }
    void SongCollection::rtrim(string& s) {
        const string WHITESPACE = " \r\t\f\v";
        size_t end = s.find_last_not_of(WHITESPACE);
        s = end == string::npos ? "" : s.substr(0, end + 1);
    }
    string SongCollection::trim(string& s) {
        ltrim(s);
        rtrim(s);
        return s;
    }
    ostream& operator<<(ostream& out, const Song& theSong) {
        out.unsetf(ios::right);
        out.setf(ios::left);
        out << "| " << setw(20) << theSong.m_title << " | ";
        out << setw(15) << theSong.m_artist << " | ";
        out << setw(20) << theSong.m_album << " | ";
        out.unsetf(ios::left);
        out.setf(ios::right);
        if (theSong.m_year == 0) {
            out << setw(6) << " " << " | ";
        }
        else {
            out << setw(6) << theSong.m_year << " | ";
        }
        int min = (int)(theSong.m_songLen / 60);
        int sec = (theSong.m_songLen - (min * 60));
        out << min << ":" << setw(2) << setfill('0') << sec << " | " << setfill(' ');
        out << setw(4) << theSong.m_price << " |";
        return out;
    }

}