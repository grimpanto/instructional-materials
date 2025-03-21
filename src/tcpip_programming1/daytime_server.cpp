#include <ctime>
#include <iostream>
#include <string>
#include <asio.hpp>

using asio::ip::tcp;
using namespace std;

string make_daytime_string() {
    time_t now = time(0);
    return ctime(&now);
}

int main() {
    try {
        asio::io_context io_context;

        tcp::endpoint endpoint(tcp::v4(), 10013);
        tcp::acceptor acceptor(io_context, endpoint);

        for (;;) {
            tcp::iostream stream;
            asio::error_code ec;
            acceptor.accept(*stream.rdbuf(), ec);
            if (!ec) {
                stream << make_daytime_string();
            }
        }
    } catch (std::exception& e) {
        cerr << e.what() << endl;
    }
    return 0;
}
