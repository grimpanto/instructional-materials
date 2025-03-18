// @copyright 2019 Günter Kolousek

#include "calc_factors.h"

#include <CLI11.hpp>

#include <iostream>
#include <vector>
#include <limits>
#include <future>

#define INFINT_USE_EXCEPTIONS

#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wsign-compare"
#pragma GCC diagnostic ignored "-Wmisleading-indentation"
#include "InfInt.h"
#pragma GCC diagnostic pop


using namespace std;

/*
  void print_results(vector<InfInt> const& numbers, vector<future<vector<InfInt>>>& results) {
  for (int i{0}; i < numbers.size(); ++i) {
  cout << numbers[i] << ": ";
  for (auto& fact : results[i].get())
  cout << fact << ' ';
  cout << endl;
  }
  }
*/

void print_results(vector<InfInt> const& numbers, vector<shared_future<vector<InfInt>>> results) {
    for (size_t i{0}; i < numbers.size(); ++i) {
        cout << numbers[i] << ": ";
        for (auto& fact : results[i].get())
            cout << fact << ' ';
        cout << endl;
    }
}


void verify_results(vector<InfInt> const& numbers, vector<shared_future<vector<InfInt>>> results) {
    for (size_t i{0}; i < numbers.size(); ++i) {
        InfInt res{1};
        for (auto& fact : results[i].get()) {
            res = res * fact;
        }

        if (numbers[i] != res)
            cerr << "Factoring failed for " << numbers[i] << endl;
    }
}


int main(int argc, char* argv[]) {
    vector<string> inputs;
    bool async_mode{};

    CLI::App app("Factor numbers");

    app.add_option("number", inputs, "numbers to factor")->required()
      ->check([](const std::string &str) {
          if (str.find_first_not_of("0123456789") != string::npos)
              return std::string(str + " contains not numeric character");
          else
              return std::string();
      });
    app.add_flag("-a,--async", async_mode, "async");

    CLI11_PARSE(app, argc, argv);

    vector<InfInt> numbers;

    for (const string& curr : inputs) {
        numbers.push_back(InfInt{curr});
    }
    vector<shared_future<vector<InfInt>>> results;

    // measuring time part 1
    auto start = chrono::system_clock::now();

    if (async_mode)
        for (auto& num : numbers) {
            results.push_back(shared_future<vector<InfInt>>(async(launch::async, get_factors, ref(num))));
        }
    else
        for (auto& num : numbers) {
            results.push_back(shared_future<vector<InfInt>>(async(get_factors, ref(num))));
        }

    thread print_results_trd{print_results, ref(numbers), results};
    thread verify_results_trd{verify_results, ref(numbers), results};

    for (size_t i{0}; i < results.size(); ++i) {
        results[i].wait();
    }

    // measuring time part 2
    auto duration = chrono::duration_cast<chrono::milliseconds>
        (std::chrono::system_clock::now() - start);
    this_thread::sleep_for(100ms);
    cout << "Time elapsed used for factoring: " << duration.count() << "ms";

    print_results_trd.join();
    verify_results_trd.join();
}
