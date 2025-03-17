// @copyright 2019 Günter Kolousek

#include "repl.h"

#include <iostream>
#include <optional>
#include <variant>
#include <stdexcept>
#include <fstream>

#include "pystring.h"
#include "magic_enum.hpp"

using namespace std;

class ReplException : public exception {
    string what_arg;
  public:
    ReplException(const string& what_arg) : what_arg{what_arg} {
    }
    const char* what() const noexcept {
        return what_arg.data();
    }
};

class IOException : public ReplException {
  public:
    IOException(const string& what_arg) : ReplException(what_arg) {}
};

std::optional<std::string> raw_input(std::string prompt=">>> ");

optional<string> raw_input(string prompt) {
    string value;
    while (cin) {
        cout << prompt;
        if (!getline(cin, value))
            break;
        value = pystring::strip(value, " ");
        if (value != "")
            return value;
    }
    if (cin.eof())
        return nullopt;
    else
        throw IOException("reading from input stream failed");
}


class ParseException : public ReplException {
    using ReplException::ReplException;
};


Value input(string prompt) {
    if (auto value{raw_input(prompt)}) {
        value = pystring::lower(pystring::strip(value.value()));
        value = pystring::replace(value.value(), "+", "add");
        value = pystring::replace(value.value(), "-", "sub");
        value = pystring::replace(value.value(), "*", "mul");
        value = pystring::replace(value.value(), "/", "div");
        value = pystring::replace(value.value(), "**", "pow");
        auto cmd{magic_enum::enum_cast<Command>(value.value().data())};
        if (cmd.has_value())
            return cmd.value();
        /*
        if (value == "add" || value == "+")
            return Command::add;
        else if (value == "sub" || value == "=")
            return Command::sub;
        else if (value == "mul" || value == "*")
            return Command::mul;
        else if (value == "div" || value == "/")
            return Command::div;
        else if (value == "chs")
            return Command::chs;
        else if (value == "print")
            return Command::print;
        else if (value == "clst")
            return Command::clst;
        else if (value == "swap")
            return Command::swap;
        else if (value == "rot")
            return Command::rot;
        else if (value == "sqrt" || value == "**")
            return Command::pow;
        else if (value == "exp")
            return Command::exp;
        else if (value == "log")
            return Command::log;
        else if (value == "ln")
            return Command::ld;
        else if (value == "sin")
            return Command::sin;
        else if (value == "cos")
            return Command::cos;
        else if (value == "tan")
            return Command::tan;
        else if (value == "asin")
            return Command::asin;
        else if (value == "acos")
            return Command::acos;
        else if (value == "atan")
            return Command::atan;
        else if (value == "deg")
            return Command::deg;
        else if (value == "rad")
            return Command::rad;
        else if (value == "help")
            return Command::help;
        else if (value == "quit")
            return Command::quit;
        */
        else {
            try {
                size_t pos;
                double res{stod(value.value(), &pos)};
                if (pos != value.value().size())
                throw ParseException(value.value() + " not a correct number!");
                return res;
            } catch (const out_of_range& ex) {
                throw ParseException("value out of range!");
            }
        }
    } else {  // raw input failed
        return Command::quit;
    }
}

std::optional<double> Calc::eval(Value value) {
    if (holds_alternative<Command>(value)) {
        Command cmd{get<Command>(value)};
        if (cmd == Command::add) {
            auto arg1{stack.pop()};
            auto arg2{stack.pop()};
            stack.push(arg1 + arg2);
        }
        return stack.top();
    } else {
        stack.push(get<double>(value));
        return nullopt;
    }
}
