#include <iostream>  // span.cpp
#include <syncstream>
#include <semaphore>

using namespace std;

int main() {
    {
        osyncstream synced_out(std::cout); // synchronized wrapper for std::cout
        synced_out << "Hello, ";
        synced_out << "World!";
        synced_out << std::endl; // flush is noted, but not yet performed
        synced_out << "and more!\n";
    } // right now, all will be written
    osyncstream(std::cout) << "Hello, " << "World!" << '\n';
}
