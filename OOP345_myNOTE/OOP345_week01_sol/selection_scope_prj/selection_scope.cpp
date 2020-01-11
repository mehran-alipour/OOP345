// Selection Constructs - Block Scope
// selection_scope.cpp

#include <iostream>

int main() {
    unsigned i;
    std::cout << "Enter i : ";
    std::cin >> i;

    if (unsigned j = i % 10u; j < 5u) { // C++17
        i -= j;      // round down
    }
    else {
        i += 10u - j; // round up
    }
    std::cout << i << std::endl;

    std::cout << "Enter i : ";
    std::cin >> i;
    switch (unsigned j = i % 10u; j / 5u) { // C++17
    case 0u: // round down
        i -= j;
        break;
    case 1u: // round up
        i += 10u - j;
    }
    std::cout << i << std::endl;
}