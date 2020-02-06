// Set.h
// Name: Mehran Alipour
// Seneca Student ID: 126778182
// Seneca email: malipour7@myseneca.ca
// Date of completion: Feb 3,2020
//
// I confirm that the content of this file is created by me,
//   with the exception of the parts provided to me by my professor.
#ifndef SDDS_SETSUMMABLE_H__
#define SDDS_SETSUMMABLE_H__
#include "Set.h"
namespace sdds {
    template <typename T, int N, typename K, typename V>
    class SetSummable : public Set<T, N> {

    public:
        V accumulate(const K& key) const {
            
            T currentSummable;
            V sumOfElements = currentSummable.getInitialValue();

            for (size_t i = 0; i < ((Set<T, N>&)* this).size(); ++i){
                // If the labels match, append the values
                if (key == ((Set<T, N>&)* this)[i].key())
                    sumOfElements = ((Set<T, N>&) * this)[i].sum(key, sumOfElements);
            }

            return sumOfElements;
        }
    };
}
#endif
