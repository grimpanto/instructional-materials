
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

    Ringbuffer<double, 5> buffer;
    string line;
    double value;
    size_t pos;
    while (cin) {
        getline(cin, line);
        if (!cin) {
            if (!cin.eof())
                cerr << "stdin in bad state. aborting." << endl;
            break;
        } else {
            try {
                value = stod(line, &pos);
                if (pos != line.size()) {
                    cerr << fmt::format("'{}' not a correct number", line) << endl;
                } else
                    buffer.put(value);
            } catch (const std::invalid_argument& e) {
                cerr << fmt::format("'{}' not a correct number", line) << endl;
            } catch (const std::out_of_range& e) {
                cerr << fmt::format("'{}' is not in range of valid floating point numbers", line) << endl;
            }
        }
    }
    
    while (buffer.size() != 0)
        cout << buffer.get().value() << endl;
    return 0;
}
