#include <iostream>  // resolver.cpp
#include <asio.hpp>
using namespace std; using namespace asio::ip;
int main() {   asio::io_context ctx;
    tcp::resolver resolver{ctx};
    // type of results: resolver::results_type
    auto results = resolver.resolve("localhost",
                                    "80");
    // type of curr is a "basic_resolver_entry"
    // → resolver::results_type::value_type
    auto curr{results.begin()};
    auto end{results.end()};
    while (curr != end) { auto entry = *curr++;
        cout << entry.endpoint() << " | "
        << entry.host_name() << endl; }}
