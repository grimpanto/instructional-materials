// @copyright 2016 Günter Kolousek

#include "msg.pb.h"
#include <google/protobuf/util/delimited_message_util.h>

#include "timeutils.h"

#include "asio.hpp"

#include <iostream>
#include <chrono>


using namespace std;
using namespace asio::ip;


void send(google::protobuf::io::ZeroCopyOutputStream* zcos, int id) {
    chrono::system_clock::time_point now = chrono::system_clock::now();

    TimeInfo* ti{new TimeInfo};
    ti->set_id(id);
    std::ostringstream oss;
    oss << now;
    ti->set_time(oss.str());

    bool res = google::protobuf::util::SerializeDelimitedToZeroCopyStream(*ti, zcos);
    if (!res) {
        cerr << "Failer while sending answer " << id << endl;
        exit(1);
    }
    delete ti;
}


int main() {
    GOOGLE_PROTOBUF_VERIFY_VERSION;

    asio::io_context ctx;
    tcp::endpoint ep{tcp::v4(), 1113};
    tcp::acceptor acceptor{ctx, ep};
    acceptor.listen();

    int id{};

    while (true) {
        tcp::iostream strm{acceptor.accept()};
        google::protobuf::io::ZeroCopyOutputStream* zcos = new google::protobuf::io::OstreamOutputStream(&strm);

        if (strm) {
            id++;
            send(zcos, id);
            id++;
            send(zcos, id);
            id++;
            send(zcos, id);

//            strm.close();
        }
        delete zcos;
    }
}
