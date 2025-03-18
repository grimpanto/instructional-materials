// @copyright 2019 Günter Kolousek

#include "account.h"

#include <CLI11.hpp>

#include <iostream>
#include <thread>

using namespace std;

int main(int argc, const char* argv[]) {
    CLI::App app("Account app");

    int balance{0};
    app.add_option("balance", balance, "Initial balance")->required();

    int deposits{5};
    app.add_option("-d,--deposits", deposits, "Count of deposits")->capture_default_str();

    CLI11_PARSE(app, argc, argv);

    Account a;
    /* Punkt 1
       a.deposit(15);
       cout << a.withdraw(6) << endl;
       cout << a.withdraw(10) << endl;
       cout << a.get_balance() << endl;
    */

    /* Punkt 2
       a.deposit(1);
       thread withdrawer1{[&a]() { cout << a.withdraw(1) << endl;}};
       thread withdrawer2{[&a]() { cout << a.withdraw(1) << endl;}};
       withdrawer1.join();
       withdrawer2.join();
       cout << a.get_balance() << endl;
    */

    a.deposit(balance);
    thread depositer1{Depositer{a}, deposits};
    thread depositer2{Depositer{a}, deposits};
    depositer1.join();
    depositer2.join();
    cout << a.get_balance() << endl;
}
