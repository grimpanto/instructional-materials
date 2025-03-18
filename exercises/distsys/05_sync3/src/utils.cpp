// @copyright 2019 Günter Kolousek

#include "utils.h"

#include <mutex>
#include <iostream>

using namespace std;

recursive_mutex out_mtx;

void println() {
    lock_guard<recursive_mutex> lg{out_mtx};
    cout << endl;
}
