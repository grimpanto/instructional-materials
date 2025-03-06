#include <iostream>  // sync_echo_client1.cpp
#include <asio.hpp>
using namespace std;  using namespace asio::ip;
int main() { // simple error handling with exc.
    asio::io_context ctx;
    tcp::resolver resolver{ctx};
    try {
        auto results =
          resolver.resolve("localhost", "9999");
        tcp::socket sock{ctx};  // IO object
 // try each endpoint until connected (blocking):
        asio::connect(sock, results); //→ function!
        cout << "connected" << endl;

const char request[]{"ping-pong"};
    size_t request_length = strlen(request);
    asio::write(sock,
      asio::buffer(request, request_length));
    cout << "sent" << endl;

    char reply[20];
    size_t reply_length = asio::read(sock,
      asio::buffer(reply, request_length));

    cout << "reply is: ";
    cout.write(reply, reply_length);
    cout << "\n";
} catch (asio::system_error& e) {
    cerr << e.what() << endl; } }
