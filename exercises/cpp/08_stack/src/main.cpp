// @copyright 2019 Günter Kolousek

#include "stack.h"

#include "CLI11.hpp"

#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wpedantic"
#include "fmt/format.h"
#include "fmt/ranges.h"
#pragma GCC diagnostic pop

#include "json.hpp"

#include "spdlog/spdlog.h"
#include "spdlog/fmt/bin_to_hex.h"

#include <iostream>
#include <vector>
#include <fstream>

using namespace std;
using json = nlohmann::json;


Stack test_move_ctor([[maybe_unused]]bool mark) {
    if (mark) {
        Stack r1;
        return r1;
    } else {
        Stack r2;
        return r2;
    }

    //    Stack r;
    //    return r;
}



int main(int argc, const char** argv) {
    CLI::App app{"An RPN calculator"};

    string stack_file{"stack.json"};
    string name;
    int number{};
    bool erase_it{};
    bool list_it{};

    app.add_option("-f,--file", stack_file, "The persistent stack file (default: stack.json)")->envname("STACK_FILE");
    CLI::Option* list_flag{app.add_flag("-l", list_it, "List the content of the phone dictionary")};
    CLI::Option* erase_flag{app.add_flag("-e", erase_it, "Erase the entry for the given NAME")};
    CLI::Option* name_opt{app.add_option("NAME", name, "name to query or set")};
    CLI::Option* num_opt{app.add_option("NUMBER", number, "phone number to set")};
    erase_flag->excludes(num_opt);
    list_flag->excludes(erase_flag);
    list_flag->excludes("NAME");
    //list_flag->excludes(num_opt);
    erase_flag->needs(name_opt);
    num_opt->needs(name_opt);

    app.get_formatter()->label("OPTIONS", "Options");

    CLI11_PARSE(app, argc, argv);

    //Stack s1{Stack{1,2,3}};

    //test_move_ctor(true);

    Stack s;
    s = Stack{1, 2, 3};

    /*
    cout << "s1:\n";
    cout << s1 << endl;
    s2.pop();
    cout << "s2:\n";
    cout << s2 << endl;
    s2.pop();
    cout << "s2:\n";
    cout << s2 << endl;
    cout << "s1:\n";
    cout << s1 << endl;
    s1.clear();

    spdlog::info(fmt::format("s1.top_ == {}", static_cast<void*>(s1.top_)));
    spdlog::info(fmt::format("s2.top_ == {}", static_cast<void*>(s2.top_)));
    //cout << s1.top_ << endl;
    //cout << s2.top_ << endl;
    */

    /*
    Stack s3;
    s3 = s1;
    */

    return 0;
}
