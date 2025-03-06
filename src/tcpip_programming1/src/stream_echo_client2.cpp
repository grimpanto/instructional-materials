#include <iostream>  // stream_echo_client2.cpp
#include <chrono>
#include <asio.hpp>
using namespace std;  using namespace asio::ip;
int main() {
    tcp::iostream strm{"localhost", "9999"};
    strm.expires_after(10s);
    if (strm) {  // connected
       strm << "ping-pong" << endl;
       string data;    getline(strm, data);
       if (strm) cout << data << endl;
       // also:  if (strm.error())
       else cout << strm.error().message() << endl;
       strm.close();  } }
