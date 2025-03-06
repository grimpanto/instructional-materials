#include <iostream>  // sync_echo_server.cpp
#include <asio.hpp>
using namespace std; using namespace asio::ip;
int main() { asio::io_context ctx;
    tcp::endpoint ep{tcp::v4(), 9999};
    tcp::acceptor acceptor{ctx, ep};
    acceptor.listen();
    tcp::socket sock{ctx};
    acceptor.accept(sock);
    // from now no further accept possible
    acceptor.close();

    asio::streambuf buf;
    asio::read_until(sock, buf, '\n');
    string reply;
    istream is{&buf};
    getline(is, reply);
    asio::write(sock, asio::buffer(reply,
        reply.size()));
    cout << "sent: " << reply << endl;
    cout << "local port: "  // → 9999
      << sock.local_endpoint().port() << endl;
    cout << "remote port: "
      << sock.remote_endpoint().port() << endl;
    sock.close();  }
