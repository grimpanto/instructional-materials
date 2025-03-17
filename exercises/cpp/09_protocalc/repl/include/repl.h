// @copyright 2019 Günter Kolousek

#pragma once

#include <iostream>
#include <optional>
#include <variant>

#include "stack.h"
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

class Calc {
  public:
    std::optional<double> eval(Value val);
  private:
    Stack stack;
};
