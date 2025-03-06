#include <iostream>  // stream_eol_echo_server.cpp
#include <asio.hpp>
using namespace std; using namespace asio::ip;
int main() {  // no error handling at all
    asio::io_context ctx;
    tcp::endpoint ep{tcp::v4(), 9999};
    tcp::acceptor acceptor{ctx, ep}; // IO object
    acceptor.listen();
    tcp::iostream strm{acceptor.accept()};
    string data;
    strm >> data;
    strm << data << '\n';  // ←
    strm.close();  }
