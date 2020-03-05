// SpellChecker.h
// Name: Mehran Alipour
// Seneca Student ID: 126778182
// Seneca email: malipour7@myseneca.ca
// Date of completion: Feb 13,2020
//
// I confirm that the content of this file is created by me,
//   with the exception of the parts provided to me by my professor.
#ifndef SDDS_SPELLCHECKER_H__
#define SDDS_SPELLCHECKER_H__
#include <string>
namespace sdds {
    const int MAX_ARR_SIZE = 5;
    class SpellChecker {
        int m_numRecords{ 0 };
        std::string m_badWords[MAX_ARR_SIZE];
        std::string m_goodWords[MAX_ARR_SIZE];
    public:
        // Constructors destructor
        SpellChecker();
        SpellChecker(const SpellChecker& copySpeCheck);
        SpellChecker(SpellChecker&& MovSpeCheck);
        SpellChecker(const char* filesname); //
        virtual ~SpellChecker();

        // Other function
        auto setEmpty() -> void;

        //opertor Overloeads
        void operator=(const SpellChecker& copySpell);
        void operator=(SpellChecker&& moveSpell);
        void operator()(std::string& text) const; // search and replace

        //Utilities
        auto setbadWordGoodWord(const std::string& spell)->void;
        auto findAndErase(std::string& spell, const char delimiter)->std::string;
        auto ltrim(std::string& left) -> void;
        auto rtrim(std::string& righ) -> void;
        auto trim(std::string& trim)->std::string;
    };
}
#endif // !SDDS_SPELLCHECKER_H__
