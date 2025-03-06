#include <iostream>  // invresolver.cpp
#include <asio.hpp>
using namespace std;
using namespace asio;
using namespace asio::ip;
int main() {  asio::io_context ctx;
    tcp::resolver resolver{ctx};
    tcp::endpoint ep{address_v4::loopback(), 80};
    auto results = resolver.resolve(ep);
    auto entry = *results.begin();
    cout << entry.host_name() << endl; }
