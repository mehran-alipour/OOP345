// External Linkage
// Module_b.cpp

#include <iostream>
void display();
int share_me = 0; // variable definition

int main() {
    display();
    display();
    std::cout << "share_me at " << &share_me << '\n';
    std::cout << "share_me is " << share_me++ << '\n';
}