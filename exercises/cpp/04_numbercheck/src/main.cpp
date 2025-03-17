// @copyright 2019 Günter Kolousek

#include "numbercheck.h"

#include "CLI11.hpp"

#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wpedantic"
#define FMT_HEADER_ONLY
#include "fmt/format.h"
#include "fmt/ranges.h"
#pragma GCC diagnostic pop

#include <iostream>
#include <vector>

using namespace std;

int main(int argc, const char** argv) {
    CLI::App app{"Checks if word from stdin is correct floating point number"};

    string num;
    string stdin;

    app.add_option("STDIN", stdin, "stdin marker (must be '-')");
    app.add_option("-v,--value", num, "The number to check");

    app.get_formatter()->label("OPTIONS", "Options");

    CLI11_PARSE(app, argc, argv);

    if (stdin == "-")
        getline(cin, num);

    numbercheck::FloatingPointChecker fpc{};

    cout << boolalpha << fpc.check(num) << endl;

    return 0;
}
