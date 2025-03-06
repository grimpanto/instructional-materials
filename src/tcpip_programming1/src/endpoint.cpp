#include <iostream>  // endpoint.cpp
#include <asio.hpp>  // server-side
// AF_*, SOCK_STREAM, SOCK_DGRAM
#include <sys/socket.h>
using namespace std;
using namespace asio;
int main() {
    ip::tcp::endpoint ep1{
      ip::address_v4::any(), 80};
    // also:
    // ip::tcp::endpoint ep1{ip::tcp::v4(), 80};
    cout << ep1 << endl;
    cout<< ep1.address()<< ":"<< ep1.port()<< endl;

    auto proto{ep1.protocol()};
    cout << proto.family() << " = "
      << AF_INET << endl;
    cout << proto.type() << " = "
      << SOCK_STREAM << endl;
    cout << proto.protocol() << endl;
}
