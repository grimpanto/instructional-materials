#include <iostream>  // ranges2.cpp
#include <ranges>
#include <charconv>
using namespace std;

int main() {
    std::string s = "1.2.3.4";
    
    auto ints =
        s | views::split('.')
          | views::transform([](auto v){
                int i = 0;
                from_chars(v.begin(), v.end(), &i);
                return i;
            });
}
