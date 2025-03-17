// @copyright 2019 Günter Kolousek

#pragma once

#include <iostream>
#include <optional>
#include <variant>
#include <deque>

#include "pystring.h"

enum class Command {
                    add, sub, mul, div,
                    chs,
                    print, clst, swap, rot,
                    sqrt, pow, exp,
                    log, ln, ld,
                    sin, cos, tan, asin, acos, atan,
                    deg, rad,
                    help, quit
};

using Value=std::variant<double, Command>;

Value input(std::string prompt=">>> ");

using iter=std::deque<double>::const_iterator;

class Calc {
  public:
    std::pair<iter, iter> eval(Value val);
  private:
    std::pair<double, double> get_arguments(Command cmd);
    std::deque<double> stack;
};
