// Workshop 8 - Smart Pointers
// 2019/11 - Cornel


#include <memory>
#include "List.h"
#include "Element.h"
#include "Utilities.h"

// Utilities.cpp
// Name: Mehran Alipour
// Seneca Student ID: 126778182
// Seneca email: malipour7
// Date of completion: Mar 20, 2020
//
// I confirm that the content of this file is created by me,
//   with the exception of the parts provided to me by my professor.

using namespace std;

namespace sdds {
    List<Product> mergeRaw(const List<Description>& desc, const List<Price>& price) {
        List<Product> priceList;
        // TODO: Add your code here to build a list of products
        //         using raw pointers
        for (size_t i = 0; i < desc.size(); i++) {
            for (size_t j = 0; j < price.size(); j++) {
                if (desc[i].code == price[j].code) {
                    Product* p = new Product(desc[i].desc, price[j].price);
                    try {
                        p->validate();
                        priceList += p;
                    }
                    catch (const string& err){
                        //delete p;
                        throw err;
                    }
                    delete p;	// deallocate p
                    p = nullptr;
                }
            }
        }
        return priceList;
    }

    List<Product> mergeSmart(const List<Description>& desc, const List<Price>& price) {
        List<Product> priceList;
        // TODO: Add your code here to build a list of products
        //         using smart pointers
        for (size_t i = 0; i < desc.size(); i++) {
            for (size_t j = 0; j < price.size(); j++) {
                if (desc[i].code == price[j].code) {
                    std::unique_ptr<Product> p{ new Product(desc[i].desc, price[j].price) };
                    try {
                        p->validate();
                        priceList += p;
                    }
                    catch (const string & err) {
                        throw err;
                    }
                }

            }
        }
        return priceList;
    }
}
