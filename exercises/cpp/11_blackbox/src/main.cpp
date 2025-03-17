
#include "ringbuffer.h"
#include "measurement.h"

//#include "CLI11.hpp"

#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wpedantic"
#include "fmt/format.h"
#include "fmt/ranges.h"
#pragma GCC diagnostic pop

#include "process.hpp"

#include "json.hpp"

#include "pystring.h"

//#include "spdlog/spdlog.h"
//#include "spdlog/fmt/bin_to_hex.h"

//#include "magic_enum.hpp"

#include <iostream>
#include <vector>
#include <fstream>

using namespace std;
using json = nlohmann::json;
//using namespace literals;


int main([[maybe_unused]]int argc, [[maybe_unused]]const char** argv) {

    Ringbuffer<json, 5> buffer;
    string line;
    while (cin) {
        getline(cin, line);
        if (!cin) {
            if (!cin.eof())
                cerr << "stdin in bad state. aborting." << endl;
            break;
        } else {
            try {
                json value;
                value = json::parse(line);
                buffer.put(value);
            } catch (const json::parse_error& e) {
                cerr << fmt::format("parsing '{}' failed", e.what()) << endl;
            }
        }
    }
    
    while (buffer.size() != 0) {
        json j=buffer.get().value();
        if (j.is_object()) {
            auto m{j.get<measurement::Measurement>()};
            cout << m << endl;
        } else if (j.is_number()) {
                cout << j.get<double>() << endl;
        } else if (j.is_boolean()) {
            cout << boolalpha << j.get<bool>() << endl;
        }
    }
    return 0;
}
