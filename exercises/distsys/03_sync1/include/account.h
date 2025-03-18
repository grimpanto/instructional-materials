
#ifndef ACCOUNT_H
#define ACCOUNT_H

#include <thread>
#include <iostream>
#include <mutex>

using namespace std::literals;

class Account;

class Account {
    int balance{};
    std::mutex mtx;
  public:
    void deposit(int);
    bool withdraw(int);
    int get_balance();
};


class Depositer {
    Account& account;
  public:
    Depositer(Account& account) : account{account} {}
    void operator()(int deposits) {
        for (; deposits > 0; --deposits) {
            account.deposit(1);
        }
    }
};
#endif
