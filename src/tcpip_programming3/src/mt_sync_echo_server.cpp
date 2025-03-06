#include <iostream>  // mt_sync_echo_server.cpp
#include <thread>
#include <asio.hpp>
using namespace std; using namespace asio::ip;
void serve_client(tcp::socket&& sock) {
    asio::streambuf buf;
    asio::read_until(sock, buf, '\n');
    string reply;
    istream is{&buf};
    getline(is, reply);
    asio::write(sock, asio::buffer(reply,
        reply.size()));
    cout << "sent: " << reply << endl;
    sock.close();
}

int main() { asio::io_context ctx;
    tcp::endpoint ep{tcp::v4(), 9999};
    tcp::acceptor acceptor{ctx, ep};
    acceptor.listen();
    while (true) {
        tcp::socket sock{ctx};
        acceptor.accept(sock);
        thread thd{serve_client, move(sock)};
        thd.detach();
    }
  }
