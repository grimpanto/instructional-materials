#include <iostream>  // sync_eof_echo_client.cpp
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

// sync_eof_echo_client.cpp
    const char request[]{"ping-pong\n"};
    asio::write(sock, asio::buffer(request,
        strlen(request)));
    cout << "sent" << endl;
    char reply[20];  error_code ec;
    size_t reply_length = asio::read(sock,
      asio::buffer(reply), ec);  // ←
    if (ec.value() != asio::error::eof) {
    cout<<ec.message()<<':'<< ec.value()<<endl;
        return 1; }
    cout << "Reply is: ";
    cout.write(reply, reply_length);
    cout << "\n";
} catch (asio::system_error& e) {
    std::cerr << e.what() << std::endl; } }
