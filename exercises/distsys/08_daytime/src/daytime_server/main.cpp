// @copyright 2016 Günter Kolousek

#include <iostream>
#include <chrono>

//#pragma GCC diagnostic push
//#pragma GCC diagnostic ignored "-Wsign-conversion"
//#pragma GCC diagnostic ignored "-Wconversion"
#include "asio.hpp"
//#pragma GCC diagnostic pop

#include "spdlog/spdlog.h"
#include "spdlog/sinks/stdout_color_sinks.h"

#include "timeutils.h"

using namespace std;
using namespace asio::ip;

int main() {
    auto console = spdlog::stderr_color_mt("console");

    //    int port{};
    //bool help{};

    /*
    auto cli = (
      clipp::required("-p") & clipp::value("port", port) % "server port",
      clipp::option("-h", "--help").set(help) % "help"
    );

    if (!clipp::parse(argc, argv, cli)) {
        cout << clipp::make_man_page(cli, argv[0]) << endl;
        return 1;
    }

    if (help) {
        cout << clipp::make_man_page(cli, argv[0]) << endl;
        return 0;
        }*/


    asio::io_context ctx;
    tcp::endpoint ep{tcp::v4(), 1113};
    tcp::acceptor acceptor{ctx, ep}; // IO object
    acceptor.listen();

    while (true) {
        //tcp::socket sock{ctx};
        //acceptor.accept(sock);
        //tcp::iostream strm{std::move(sock)};
        tcp::iostream strm{acceptor.accept()};

        if (strm) {
            chrono::system_clock::time_point now = chrono::system_clock::now();
            strm << now << endl;
            if (!strm)
                console->error("Failure while sending the answer: ", strm.error().message());
            strm.close();
        }
    }
}
