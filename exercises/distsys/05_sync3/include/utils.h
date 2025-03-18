// @copyright 2019 Günter Kolousek

#ifndef UTILS_H
#define UTILS_H

#include <mutex>
#include <iostream>

extern std::recursive_mutex out_mtx;

void println();

template<typename T, typename... Rest>
void println(const T& word, const Rest&... rest) {
    std::lock_guard<std::recursive_mutex> lg{out_mtx};
    std::cout << word << ' ';
    println(rest...);
}
#endif
