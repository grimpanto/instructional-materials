// @copyright 2019 Günter Kolousek

#include "repl.h"

#include <iostream>
#include <optional>
#include <variant>
#include <stdexcept>
#include <fstream>
#include <utility>
#include <cmath>

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


class StackException : public ReplException {
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
        else {
            try {
                size_t pos;
                double res{stod(value.value(), &pos)};
                if (pos != value.value().size())
                    throw ParseException("'" + value.value() + "' not a correct number!");
                return res;
            } catch (const out_of_range& ex) {
                throw ParseException("value out of range!");
            } catch (const invalid_argument& ex) {
                throw ParseException("'" + value.value() + "' not a correct number!");
            }
        }
    } else {  // raw input failed
        return Command::quit;
    }
}

pair<double, double> Calc::get_arguments(Command cmd) {
    double arg1{};
    double arg2{};
    switch (cmd) {
      case Command::add:
        [[fallthrough]];
      case Command::sub:
        [[fallthrough]];
      case Command::mul:
        [[fallthrough]];
      case Command::div:
        [[fallthrough]];
      case Command::pow:
        [[fallthrough]];
      case Command::swap:
        if (stack.size() < 2)
            throw StackException{"not enough elements on stack"};
        arg1=stack.front();
        stack.pop_front();
        arg2=stack.front();
        stack.pop_front();
        break;
      case Command::chs:
        [[fallthrough]];
      case Command::sqrt:
        [[fallthrough]];
      case Command::log:
        [[fallthrough]];
      case Command::ln:
        [[fallthrough]];
      case Command::ld:
        [[fallthrough]];
      case Command::sin:
        [[fallthrough]];
      case Command::cos:
        [[fallthrough]];
      case Command::tan:
        [[fallthrough]];
      case Command::asin:
        [[fallthrough]];
      case Command::acos:
        [[fallthrough]];
      case Command::atan:
        [[fallthrough]];
      case Command::deg:
        [[fallthrough]];
      case Command::rad:
        arg1=stack.front();
        stack.pop_front();
        break;
      default:
        break;
    }
    return pair(arg1, arg2);
}


double to_rad(double arg) {
    return (arg / 360) * 2 * M_PI;
}


double to_deg(double arg) {
    return (arg * 360) / 2 / M_PI;
}


pair<iter, iter> Calc::eval(Value value) {
    //    optional<double> Calc::eval(Value value) {
    if (holds_alternative<Command>(value)) {
        Command cmd{get<Command>(value)};
        auto [arg1, arg2]{get_arguments(cmd)};
        switch (cmd) {
          case Command::add:
            stack.push_front(arg1 + arg2);
            return pair(stack.cbegin(), stack.cbegin() + 1);
          case Command::sub:
            stack.push_front(arg2 - arg1);
            return pair(stack.cbegin(), stack.cbegin() + 1);
          case Command::mul:
            stack.push_front(arg1 * arg2);
            return pair(stack.cbegin(), stack.cbegin() + 1);
          case Command::div:
            stack.push_front(arg2 / arg1);
            return pair(stack.cbegin(), stack.cbegin() + 1);
          case Command::pow:
            stack.push_front(pow(arg2, arg1));
            return pair(stack.cbegin(), stack.cbegin() + 1);
          case Command::swap:
            stack.push_front(arg1);
            stack.push_front(arg2);
            return pair(stack.cbegin(), stack.cbegin());
          case Command::chs:
            stack.push_front(-arg1);
            return pair(stack.cbegin(), stack.cbegin() + 1);
          case Command::sqrt:
            stack.push_front(std::sqrt(arg1));
            return pair(stack.cbegin(), stack.cbegin() + 1);
          case Command::exp:
            stack.push_front(std::exp(arg1));
            return pair(stack.cbegin(), stack.cbegin() + 1);
          case Command::log:
            stack.push_front(std::log10(arg1));
            return pair(stack.cbegin(), stack.cbegin() + 1);
          case Command::ln:
            stack.push_front(std::log(arg1));
            return pair(stack.cbegin(), stack.cbegin() + 1);
          case Command::ld:
            stack.push_front(std::log2(arg1));
            return pair(stack.cbegin(), stack.cbegin() + 1);
          case Command::sin:
            stack.push_front(std::sin(to_rad(arg1)));
            return pair(stack.cbegin(), stack.cbegin() + 1);
          case Command::cos:
            stack.push_front(std::cos(to_rad(arg1)));
            return pair(stack.cbegin(), stack.cbegin() + 1);
          case Command::tan:
            stack.push_front(std::tan(to_rad(arg1)));
            return pair(stack.cbegin(), stack.cbegin() + 1);
          case Command::asin:
            stack.push_front(to_deg(std::asin(arg1)));
            return pair(stack.cbegin(), stack.cbegin() + 1);
          case Command::acos:
            stack.push_front(to_deg(std::acos(arg1)));
            return pair(stack.cbegin(), stack.cbegin() + 1);
          case Command::atan:
            stack.push_front(to_deg(std::atan(arg1)));
            return pair(stack.cbegin(), stack.cbegin() + 1);
          case Command::deg:
            stack.push_front(to_deg(arg1));
            return pair(stack.cbegin(), stack.cbegin() + 1);
          case Command::rad:
            stack.push_front(to_rad(arg1));
            return pair(stack.cbegin(), stack.cbegin() + 1);
          case Command::print:
            return pair(stack.cbegin(), stack.cend());
          case Command::clst:
            stack.clear();
            return pair(stack.cbegin(), stack.cbegin());
          case Command::rot:
            if (stack.size() >= 1) {
                auto last{stack.back()};
                stack.pop_back();
                stack.push_front(last);
            }
            return pair(stack.cbegin(), stack.cbegin());
          default:
            return pair(stack.cbegin(), stack.cbegin());
        }
    } else {
        stack.push_front(get<double>(value));
        return pair(stack.cbegin(), stack.cbegin());
    }
}
