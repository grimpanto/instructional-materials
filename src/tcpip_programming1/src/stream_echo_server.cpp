#include <iostream>  // stream_echo_server.cpp
#include <asio.hpp>
using namespace std; using namespace asio::ip;
int main() {  // no error handling at all
    asio::io_context ctx;
    tcp::endpoint ep{tcp::v4(), 9999};
    tcp::acceptor acceptor{ctx, ep}; // IO object
    acceptor.listen();

    tcp::socket sock{ctx};
    acceptor.accept(sock);
    tcp::iostream strm{std::move(sock)};
    //shorter: tcp::iostream strm{acceptor.accept()};

    string data;
    strm >> data;  // also: getline(strm, data)
    strm << data;
    strm.close();  }
