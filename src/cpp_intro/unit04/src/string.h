#pragma once
#include <iostream>

struct String {  // string.h
    String(std::string s) : s{s} {};
    std::string s;
    String(const String& o) {
        s = o.s;
        std::cout << "copy" << std::endl;
    }
    String(String&& o) {
        s = o.s;
        std::cout << "move" << std::endl;
    }
};
