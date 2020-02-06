// Pair.h
// Name: Mehran Alipour
// Seneca Student ID: 126778182
// Seneca email: malipour7@myseneca.ca
// Date of completion: Jan 24,2020
//
// I confirm that the content of this file is created by me,
//   with the exception of the parts provided to me by my professor.
#ifndef SDDS_Pair_H__
#define SDDS_Pair_H__
#include <iostream>
namespace sdds {
    template<typename K, typename V>
    class Pair {
        K p_Key;
        V p_Val;
    public:
        Pair() :p_Key{}, p_Val{} {
        }
        Pair(const K& Key, const V& value) {
            p_Key = Key;
            p_Val = value;
        }
        const K& key() const {
            return p_Key;
        }
        const V& value() const {
            return p_Val;
        }
        virtual void display(std::ostream& os = std::cout) const {
            os << p_Key << " : " << p_Val << std::endl;
        }
    };
    template<typename K, typename V>
    std::ostream& operator<<(std::ostream& os, const Pair<K, V>& pair) {
        pair.display(os);
        return os;
    }
}
#endif