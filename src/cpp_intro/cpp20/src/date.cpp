#include <chrono>  // date.cpp
#include <iostream>

using namespace std;
using namespace std::chrono;
using namespace std::literals;

// later on, not needed anymore:
#include "date.h"
using namespace date;  

int main() {
    auto today = floor<days>(system_clock::now());
    cout << today << '\n';
    constexpr auto date = 2016_y/May/29;
    //later on: constexpr auto date = 2016y/May/29;
    cout << date << endl;
}
