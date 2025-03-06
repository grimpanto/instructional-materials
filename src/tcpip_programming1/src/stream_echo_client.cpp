#include <iostream>  // stream_echo_client.cpp
#include <asio.hpp>
using namespace std;
using namespace asio::ip;
int main() {  // no error handling at all
    tcp::iostream strm{"localhost", "9999"};
    if (strm) {  // connected
       strm << "ping-pong" << endl;
       string data;
       getline(strm, data);
       cout << data << endl;
       strm.close();
    } else { cout << "no connection" << endl; } }
