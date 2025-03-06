#include <iostream>


int main() {

    std::cout << std::endl;

    std::cout << std::boolalpha;

    int x = -3;                  // (1)
    unsigned int y = 7;          // (2)

    std::cout << "-3 < 7:  " << (x < y) << std::endl;
    std::cout << "-3 <= 7: " << (x <= y) << std::endl;
    std::cout << "-3 > 7:  " << (x > y) << std::endl;
    std::cout << "-3 => 7: " << (x >= y) << std::endl;

    std::cout << std::endl;  
}
