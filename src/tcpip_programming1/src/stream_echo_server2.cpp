#include <iostream>  // stream_echo_server2.cpp
#include <chrono>
#include <thread>
#include <asio.hpp>
using namespace std;
using namespace asio::ip;
int main() {  // no error handling at all
    asio::io_context ctx;
    tcp::endpoint ep{tcp::v4(), 9999};
    tcp::acceptor acceptor{ctx, ep};
    acceptor.listen();
    tcp::iostream strm{acceptor.accept()};
    string data;
    strm >> data;
    while (1) { this_thread::sleep_for(1s); }
    strm.close();  }
