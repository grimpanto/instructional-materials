// @copyright 2019 Günter Kolousek

#include "primes.h"

#include <cmath>

using namespace std;

namespace prime_factorization {
  vector<uint64_t> calculate_primes(uint64_t n) {
      vector<uint64_t> factors;

      while (n % 2 == 0) {
          factors.push_back(2);
          n /= 2;
      }

      for (uint64_t i{3}; i <= sqrt(n); i += 2) {
          while (n % i == 0) {
              factors.push_back(i);
              n /= i;
          }
      }

      if (n > 2)
          factors.push_back(n);

      return factors;
  }
}
