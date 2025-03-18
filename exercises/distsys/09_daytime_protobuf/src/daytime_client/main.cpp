// @copyright 2016 Günter Kolousek

#include "msg.pb.h"
#include <google/protobuf/util/delimited_message_util.h>

#include "asio.hpp"

#include <iostream>

using namespace std;
using namespace asio::ip;


void receive(google::protobuf::io::ZeroCopyInputStream* zcis) {
    bool clean_eof{};

    TimeInfo* ti{new TimeInfo};
    google::protobuf::util::ParseDelimitedFromZeroCopyStream(ti, zcis, &clean_eof);

    cout << "eof: " << clean_eof << "; id: " << ti->id()
         << "; time: " << ti->time() << endl;

    delete ti;
}

int main() {
    int port{1113};
    tcp::iostream strm{"localhost", to_string(port)};
    if (strm) {
        istream is(strm.rdbuf());
        google::protobuf::io::ZeroCopyInputStream* zcis = new google::protobuf::io::IstreamInputStream(&is);

        receive(zcis);
        receive(zcis);
        receive(zcis);

        strm.close();

        delete zcis;
    } else
        cerr << "Could not connect to server!" << endl;
}
