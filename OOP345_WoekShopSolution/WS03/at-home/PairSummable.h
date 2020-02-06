// Pair.h
// Name: Mehran Alipour
// Seneca Student ID: 126778182
// Seneca email: malipour7@myseneca.ca
// Date of completion: Feb 3,2020
//
// I confirm that the content of this file is created by me,
//   with the exception of the parts provided to me by my professor.
#ifndef SDDS_PAIRSUMMABLE_H__
#define SDDS_PAIRSUMMABLE_H__
#include <iostream>
#include <string>
#include "Pair.h"
namespace sdds {
    template<typename K, typename V>
    class PairSummable :public Pair<K, V> {
        static V ps_startingSum;
        static size_t ps_fieldWidth;
    public:
        PairSummable() {
        }

        PairSummable(const K& key, const V& value) : Pair<K, V>(key, value) {
            if (ps_fieldWidth < key.size())
                ps_fieldWidth = key.size();
        }

        static const V& getInitialValue() {
            return ps_startingSum;
        }

        V sum(const K& key, const V& val) const {
            return val + Pair<K, V>::value();

        }

        void display(std::ostream& os) const {
            os.setf(std::ios::left);
            os.width(ps_fieldWidth);
            Pair<K, V>::display(os);
            os.unsetf(std::ios::left);
        }
    };
    template <typename K, typename V>
    size_t PairSummable<K, V>::ps_fieldWidth = 0;

    template<>
    std::string PairSummable<std::string, std::string>::ps_startingSum = "";

    template<>
    int PairSummable<std::string, int>::ps_startingSum = 0;

    template<>
    std::string PairSummable<std::string, std::string>::sum(const std::string& key, const std::string& value)const {
        if (value == "") {
            return (Pair<std::string, std::string>::value());
        }
        else {
            return (value + ", " + Pair<std::string, std::string>::value());
        }
    }
}
#endif