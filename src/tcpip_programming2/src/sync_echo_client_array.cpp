#include <iostream>  // sync_echo_client_array.cpp
#include <array>
#include <asio.hpp>
using namespace std;
using namespace asio::ip;
int main() {
    asio::io_context ctx;
    tcp::resolver resolver{ctx};
    try {
        auto results =
          resolver.resolve("localhost", "9999");
        tcp::socket sock{ctx};
        asio::connect(sock, results);
        cout << "connected" << endl;

// sync_echo_client_array.cpp
    const char request[]{"ping-pong\n"};
    size_t request_length = strlen(request);
    asio::write(sock, asio::buffer(request,
        request_length));
    cout << "sent" << endl;
    array<char, 20> reply;
    size_t reply_length = asio::read(sock,//↓
      asio::buffer(reply, request_length - 1));
    cout << "Reply is: ";
    //cout << string(reply.begin(), reply.begin() + reply_length) << endl;
    cout << string(begin(reply), begin(reply) + reply_length) << endl;
    cout << "\n";
} catch (asio::system_error& e) {
    std::cerr << e.what() << std::endl; } }
