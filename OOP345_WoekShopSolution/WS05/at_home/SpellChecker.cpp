// SpellChecker.cpp
// Name: Mehran Alipour
// Seneca Student ID: 126778182
// Seneca email: malipour7@myseneca.ca
// Date of completion: Feb 13,2020
//
// I confirm that the content of this file is created by me,
//   with the exception of the parts provided to me by my professor.
#include <iostream>
#include <string>
#include <fstream>
#include "SpellChecker.h"
using namespace std;

namespace sdds {
    SpellChecker::SpellChecker() {
        setEmpty();
    }
    SpellChecker::SpellChecker(const SpellChecker& copySpeCheck) {
        *this = copySpeCheck;
    }
    SpellChecker::SpellChecker(SpellChecker&& MovSpeCheck) {
        *this = move(MovSpeCheck);
    }
    SpellChecker::SpellChecker(const char* filesname) {
        int cnt{ 0 };
        ifstream file(filesname);
        if (!file) {
            throw "Bad file name!";
        }
        string strBookLine;
        do {
            getline(file, strBookLine);
            if (file) {
                setbadWordGoodWord(strBookLine);
                ++cnt;
            }
        } while (file && cnt < MAX_ARR_SIZE);
        file.close();
    }
    SpellChecker::~SpellChecker() {

    }
    //Other Functions
    auto SpellChecker::setEmpty() -> void {
        m_numRecords = 0;
        for (int i = 0; i < MAX_ARR_SIZE; i++) {
            m_badWords[i] = "";
            m_goodWords[i] = "";
        }
    }
    //opertor Overloeads
    void SpellChecker::operator=(const SpellChecker& copySpell) {
        if (this != &copySpell) {
            for (int i = 0; i < copySpell.m_numRecords; i++) {
                m_badWords[i] = copySpell.m_badWords[i];
                m_goodWords[i] = copySpell.m_goodWords[i];
            }
            m_numRecords = copySpell.m_numRecords;
        }
    }
    void SpellChecker::operator=(SpellChecker&& moveSpell) {
        if (this != &moveSpell) {
            for (int i = 0; i < moveSpell.m_numRecords; i++) {
                m_badWords[i] = moveSpell.m_badWords[i];
                m_goodWords[i] = moveSpell.m_goodWords[i];
            }
            m_numRecords = moveSpell.m_numRecords;
            moveSpell.m_numRecords = 0;
            for (int i = 0; i < MAX_ARR_SIZE; i++) {
                moveSpell.m_badWords[i] = "";
                moveSpell.m_goodWords[i] = "";
            }
        }
    }
    void SpellChecker::operator()(std::string& text) const {
        for (int i = 0; i < m_numRecords; i++) {
            int pos = -1;
            do {
                pos = text.find(m_badWords[i], ++pos);
                if (pos != -1) {
                    text.replace(pos, m_badWords[i].length(), m_goodWords[i]);
                }
            } while (pos != -1);
        }
    }
    //Utilities
    auto SpellChecker::setbadWordGoodWord(const string& spell)->void {
        string temp;
        temp = spell;
        m_badWords[m_numRecords] = findAndErase(temp, ' ');
        m_goodWords[m_numRecords] = findAndErase(temp, '\n');
        m_numRecords++;
    }
    auto SpellChecker::findAndErase(std::string& spell, const char delimiter)->std::string {
        string temp;
        int i = 0;
        i = (int)spell.find(delimiter);
        temp = spell.substr(0, i);
        if (i != -1) {
            spell.erase(0, i + 1);
        }
        return trim(temp);
    }
    auto SpellChecker::ltrim(std::string& left) -> void {
        const string WHITESPACE = " \r\t\f\v";
        size_t start = left.find_first_not_of(WHITESPACE);
        left = start == string::npos ? "" : left.substr(start);
    }
    auto SpellChecker::rtrim(std::string& righ) -> void {
        const string WHITESPACE = " \r\t\f\v";
        size_t end = righ.find_last_not_of(WHITESPACE);
        righ = end == string::npos ? "" : righ.substr(0, end + 1);
    }
    auto SpellChecker::trim(std::string& trim)->std::string {
        ltrim(trim);
        rtrim(trim);
        return trim;
    }
}