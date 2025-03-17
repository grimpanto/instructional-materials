// @copyright 2019 Günter Kolousek

#include "gcd.h"

namespace greatest_common_divisor {

  namespace recursive {
    unsigned int gcd(unsigned long long a, unsigned long long b) {
        if (b != 0)
            return gcd(b, a % b);
        else
            return a;
    }
  }

  namespace iterative {
    unsigned int gcd(unsigned long long a, unsigned long long b) {
        while (b) {
            auto tmp{a};
            a = b;
            b = tmp % b;
        }
        return a;
    }
  }
}
