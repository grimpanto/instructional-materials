// @copyright 2019 Günter Kolousek

#include "gcd.h"

#include <iostream>
#include <limits>

using namespace std;

constexpr string_view usage_msg{"Computes the greates common divisor of two the numbers FIRST and SECOND\n"
                                "Usage: gcd [Options] FIRST SECOND\n\n"
                                "Positionals:\n"
                                "  FIRST UINT REQUIRED       First number\n"
                                "  SECOND UINT REQUIRED      Second number\n\n"
                                "Options:\n"
                                "  -h,--help                 Print this help message and exit"
};

constexpr string_view tip_msg{"Run with --help for more information."};

void usage(string msg="") {
    if (msg != "") {
        cerr << msg << "\n";
        cerr << tip_msg << endl;
    } else
        cerr << usage_msg << endl;
    exit(1);
}

int main(int argc, const char** argv) {
    argv = argv;

    if (argc == 2) {
        string tmp{argv[1]};
        if (tmp == "--help" || tmp == "-h")
            usage();
        else
            usage(string{"SECOND is required"});
    } else if (argc != 3) {
        usage(string{"exactly 2 arguments needed, but "} + to_string(argc - 1) + " given");
    }

    size_t pos;
    string first_arg{argv[1]};
    string second_arg{argv[2]};
    unsigned long long first_num;
    unsigned long long second_num;

    try {
        first_num = stoull(first_arg, &pos);
    } catch (invalid_argument&) {
        usage("Could not convert: FIRST = " + first_arg);
    } catch (out_of_range&) {
        usage("FIRST has to be ≤ " + to_string(numeric_limits<unsigned long long>::max()) + ": FIRST = " + first_arg);
    }

    if (pos != first_arg.size())
        usage("Could not convert: FIRST = " + first_arg);

    try {
        second_num = stoull(second_arg, &pos);
    } catch (invalid_argument&) {
        usage("Could not convert: SECOND = " + second_arg);
    } catch (out_of_range&) {
        usage("SECOND has to be ≤ " + to_string(numeric_limits<unsigned long long>::max()) + ": SECOND = " + second_arg);
    }

    if (pos != second_arg.size())
        usage("Could not convert: SECOND = " + second_arg);

    cout << "computed iterative: " << greatest_common_divisor::iterative::gcd(first_num, second_num) << endl;
    cout << "computed recursive: " << greatest_common_divisor::recursive::gcd(first_num, second_num) << endl;
}
