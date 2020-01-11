// External Linkage
// Module_a.cpp

#include <iostream>
extern int share_me; // external linkage declaration

void display() {
    std::cout << "share_me at " << &share_me << '\n';
    std::cout << "share_me is " << share_me++ << '\n';
}