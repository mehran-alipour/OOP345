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
#include <numeric>
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
        mySong.s_artist = find(rec, 25);
        mySong.s_title = find(rec, 25);
        mySong.s_album = find(rec, 25);
        try {
            mySong.s_year = stoi(find(rec, 5));
        }
        catch (...) {
            mySong.s_year = 0;
        }
        mySong.s_songLen = stoi(find(rec, 5));
        mySong.s_price = stod(find(rec, 5));
        return mySong;
    }
    void SongCollection::display(std::ostream& out) const {
        for_each(sc_songColle.begin(), sc_songColle.end(), [&](const Song i) { out << i; });
        int hr, min, sec, totalSec;
        totalSec = sum();
        sec = totalSec % 60;
        min = (totalSec - sec) % 60;
        hr = (totalSec - sec - (min * 60)) % 360;
        cout << "----------------------------------------------------------------------------------------" << endl;
        cout << "|" << setw(85) << "Total Listening Time: " << hr << ":" << setw(2) << setfill('0') << min << ":" << sec << " |" << endl;
        cout << "----------------------------------------------------------------------------------------" << endl;
    }
    int SongCollection::sum() const {
        int n = this->sc_songColle.size(), i = 0;
        int* a = new int[n];
        copy(this->sc_songColle.begin(), this->sc_songColle.end(), a[i++]);
        n = accumulate(a, &a[n], (int)0);
        delete[] a;
        return n;
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
        out << "| " << setw(20) << theSong.s_artist << " | ";
        out << setw(15) << theSong.s_title << " | ";
        out << setw(20) << theSong.s_album << " | ";
        out.unsetf(ios::left);
        out.setf(ios::right);
        if (theSong.s_year == 0) {
            out << setw(6) << " " << " | ";
        }
        else {
            out << setw(6) << theSong.s_year << " | ";
        }
        int sec = (theSong.s_songLen % 60);
        int min = ((theSong.s_songLen - sec) / 60);
        out << min << ":"<< setw(2) << setfill('0') << sec << " | " << setfill(' ');
        out << setw(4) << theSong.s_price << " |";
        out << endl;
        return out;
    }

}