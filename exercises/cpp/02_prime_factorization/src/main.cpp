// @copyright 2019 Günter Kolousek

#include "prime_factorization.h"

#include "CLI11.hpp"

#include <iostream>

using namespace std;

int main(int argc, const char** argv) {
    CLI::App app{"Calculates the prime factors of the given number"};

    uint64_t num{};

    app.add_option("NUMBER", num, "The number")->required();

    app.get_formatter()->label("OPTIONS", "Options");

    CLI11_PARSE(app, argc, argv);

    auto prime_numbers{prime_factorization::calculate_primes(num)};

    for (auto num : prime_numbers) {
        cout << num << ' ';
    }
    cout << endl;
    return 0;
}
