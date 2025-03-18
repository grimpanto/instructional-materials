// @copyright 2019 Günter Kolousek

#include <iostream>
#include <chrono>
#include <thread>

#include <unistd.h>
#include <signal.h>

using namespace std;

int main(int argc, char* argv[]) {
    if (argc > 1) {
        std::chrono::milliseconds sleeptime(500);
        char letter;
        letter = argv[1][0];
        while (true) {
            cout << letter << flush;
            std::this_thread::sleep_for(sleeptime);
        }
    }
}
