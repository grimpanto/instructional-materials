// @copyright 2019 Günter Kolousek

#include "stack.h"
#include "repl.h"

#include "CLI11.hpp"

#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wpedantic"
#include "fmt/format.h"
#include "fmt/ranges.h"
#pragma GCC diagnostic pop

#include "json.hpp"

#include "spdlog/spdlog.h"
#include "spdlog/fmt/bin_to_hex.h"

#include "magic_enum.hpp"

#include <iostream>
#include <vector>
#include <fstream>

using namespace std;
using json = nlohmann::json;
//using namespace literals;


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

    Calc calc;

    while (true) {
        auto value{input()};
        if (holds_alternative<Command>(value) && get<Command>(value) == Command::quit)
            break;
        auto res{calc.eval(value)};
        if (res.has_value())
            cout << res.value() << endl;

        /*
        if (holds_alternative<double>(value))
            cout << get<double>(value) << endl;
        else if (holds_alternative<Command>(value))
            cout << magic_enum::enum_name(get<Command>(value)) << endl;
        */
    }


    Stack s1;
    //Stack s2{s1};
    Stack s2{move(s1)};
    s2 = move(s1);

    return 0;
}
