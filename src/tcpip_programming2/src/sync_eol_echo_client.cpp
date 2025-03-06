#include <iostream>  // sync_eol_echo_client.cpp
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

// sync_sentinel_echo_client.cpp
    const char request[]{"ping-pong\n"};
    asio::write(sock, asio::buffer(request,
        strlen(request)));
    cout << "sent" << endl;

    asio::streambuf buf;  // ← var. length!
    string reply;
    // read until server sends '\n'
    asio::read_until(sock, buf, '\n');  // ←
    istream is{&buf};
    getline(is, reply);

    cout << "Reply is: " << reply << endl;
} catch (asio::system_error& e) {
    std::cerr << e.what() << std::endl; } }
