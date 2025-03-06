#include <iostream>  // problem.cpp
#include <thread>
using namespace std;
int balance{15};

void withdraw(int amount, bool& success) {
    if (balance >= amount) {
        balance -= amount;
        success = true;
    } else {
        success = false;
    }
}

int main() {
    bool success1{};
    bool success2{};
    thread t1{withdraw, 10, ref(success1)};
    thread t2{withdraw, 6, ref(success2)};
    t1.join();
    t2.join();
    cout << balance << ' ' << success1 << ' ';
    cout << success2 << endl;
}
