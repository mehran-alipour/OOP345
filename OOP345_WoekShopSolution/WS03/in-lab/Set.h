// Set.h
// Name: Mehran Alipour
// Seneca Student ID: 126778182
// Seneca email: malipour7@myseneca.ca
// Date of completion: Jan 24,2020
//
// I confirm that the content of this file is created by me,
//   with the exception of the parts provided to me by my professor.
#ifndef SDDS_SET_H__
#define SDDS_SET_H__
namespace sdds {
    template < class T, unsigned int N>
    class Set {
        T s_arr[N];
        size_t s_numMem{ 0 };
    public:
        // return number of element set
        size_t size() {
            return s_numMem;
        }
        // return element at index
        const T& operator[](size_t indexNum) const {
            // if the index is byond the number of record set loop from the start
            return s_arr[indexNum % s_numMem];
        }
        // add item if in range
        void operator+=(const T& item) {
            if (s_numMem < N)
                s_arr[s_numMem++] = item;
        }
    };
}
#endif
