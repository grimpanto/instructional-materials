#include <iostream>  // sync_echo_client2.cpp
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

// sync_echo_client2.cpp
    const char request[]{"ping-pong\n"};  // ←
    size_t request_length = strlen(request);

    asio::write(sock, asio::buffer(request,
      request_length));
    cout << "sent" << endl;

    char reply[20];
    size_t reply_length = asio::read(sock,
      asio::buffer(reply, request_length));
    cout << "Reply is: ";
    cout.write(reply, reply_length);
    // → no output of \n necessary, isn't it?
} catch (asio::system_error& e) {
    std::cerr << e.what() << std::endl; } }
