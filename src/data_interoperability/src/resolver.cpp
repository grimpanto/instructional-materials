#include <iostream>  // resolver.cpp
#include <asio.hpp>
using namespace std;
using namespace asio;
using namespace asio::ip;
int main() {
    io_service service;
    tcp::resolver resolver(service);
    tcp::resolver::query query("localhost", "80");
    tcp::resolver::iterator iter = resolver.resolve(query);
    tcp::endpoint ep = *iter;
    cout << ep.address().to_string() << endl;
    cout << ep.port() << endl;
}
