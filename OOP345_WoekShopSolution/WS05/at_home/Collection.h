// Collection.h
// Name: Mehran Alipour
// Seneca Student ID: 126778182
// Seneca email: malipour7@myseneca.ca
// Date of completion: Feb 13,2020
//
// I confirm that the content of this file is created by me,
//   with the exception of the parts provided to me by my professor.
#ifndef SDDS_COLLECTION_H__
#define SDDS_COLLECTION_H__
#include <string>
#include <iostream>
namespace sdds {
    template<typename T>
    class Collection {
        std::string c_collectionName;
        T* c_arr = nullptr;
        size_t c_numElement{ 0 };
        void (*m_observer)(const Collection<T>&, const T&) = nullptr;
    public:
        Collection(std::string name) {
            c_collectionName = name;
        }

        Collection(const Collection&) = delete;
        Collection& operator=(const Collection&) = delete;
        Collection(Collection&&) = delete;
        Collection& operator=(Collection&&) = delete;

        const std::string& name() const {
            return c_collectionName;
        }
        size_t size() const {
            return c_numElement;
        }
        void setObserver(void (*observer)(const Collection<T>&, const T&)) {
            m_observer = observer;
        }
        ~Collection() {
            delete[] c_arr;
            c_arr = nullptr;
        }
        Collection<T>& operator+=(const T& item) {
            bool checker = true;
            for (size_t i = 0; i < c_numElement; i++) {
                if (c_arr[i].title() == item.title())
                    checker = false;
            }
            if (checker) {
                ++c_numElement;
                T* temp = new T[c_numElement];
                for (size_t i = 0; i < c_numElement - 1; i++) {
                    temp[i] = c_arr[i];
                }
                temp[c_numElement - 1] = item;
                delete[] c_arr;
                c_arr = temp;
                if (m_observer != nullptr)
                    m_observer(*this, item);
            }
            return *this;
        }

        T& operator[](size_t idx) const {
            if (idx >= c_numElement || idx < 0) {
                std::string message = "Bad index [" + std::to_string(idx) + "]. Collection has [" + std::to_string(c_numElement) + "] items.";
                throw std::out_of_range(message);
            }
            return c_arr[idx];
        }
        T* operator[](std::string title) const {
            T* temp;
            temp = nullptr;
            for (size_t i = 0; i < c_numElement; i++) {
                if (c_arr[i].title() == title)
                    temp = &c_arr[i];
            }
            return temp;
        }
        friend std::ostream& operator<<(std::ostream& os, const Collection<T>& myobj) {
            //return myobj.display();
            for (unsigned i = 0; i < myobj.size(); i++) {
                os << myobj.c_arr[i];
            }
            return os;
        }
    };
}
#endif