#include <iostream>  // format.cpp
#include <chrono>
#include <vector>
using namespace std;
using namespace std::literals;
#define FMT_HEADER_ONLY // use lib 'fmt' in header-only
#include <fmt/format.h>// later: <format>
#include <fmt/chrono.h>// formatting chrono...
#include <fmt/ranges.h>// formatting vector and the like

int main() {  // later: namespace std!
    cout << fmt::format("Hello {}!", "World") << endl;
    cout << fmt::format("{1} than {0}", "two", "one")
      << endl;  // one than two
    fmt::print("chrono literals: {} {}\n", 42s, 100ms);
      // chrono literals: 42s 100ms
    fmt::print("strftime-format: {:%H:%M:%S}\n",
      3h+15min+30s); // strftime-format: 03:15:30
    fmt::print("{}\n", vector<int>{1,2,3}); // {1, 2, 3}
}
