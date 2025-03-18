// @copyright 2016 Günter Kolousek

#include "asio.hpp"

#include "spdlog/spdlog.h"
#include "spdlog/sinks/stdout_color_sinks.h"

#include <iostream>

using namespace std;
using namespace asio::ip;

int main() {
    // stdout_logger_st, stderr_logger_mt, stderr_logger_st
    auto console = spdlog::stderr_color_mt("console");

    console->set_level(spdlog::level::warn);

    /*
    console->critical("Welcome to spdlog!");
    console->error("Welcome to spdlog!");
    console->warn("Welcome to spdlog!");
    console->info("Welcome {}!", "Maxi");
    console->debug("Welcome to spdlog!");
    console->trace("Welcome to spdlog!");
    */

    int port{1113};
    //    bool help{};


    tcp::iostream strm{"localhost", to_string(port)};
    if (strm) {
        string data;
        getline(strm, data);
        if (strm)
            cout << data << endl;
        else
            console->error("Failure while reading the answer: ", strm.error().message());
        strm.close();
    } else
        console->error("Could not connect to server!");
}
