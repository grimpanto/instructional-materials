// @copyright 2016 Günter Kolousek

#include "printutils.h"

#include <mutex>
#include <iostream>

using namespace std;

recursive_mutex out_mtx;

void println() {
    lock_guard<recursive_mutex> lg{out_mtx};
    cout << endl;
}
