// @copyright 2019 Günter Kolousek

#include "dictionary.h"

using namespace std;

size_t Dictionary::hash(const unsigned char* str) {
    size_t hash{5381};
    int c;

    while ((c = *str++)) {
        //           hash * 33      + c
        hash = ((hash << 5) + hash) + c;
    }
    return hash;
}

bool Dictionary::set_(string key, int value) {
    auto idx{hash(reinterpret_cast<const unsigned char*>(key.c_str())) % size};
    return nodes[idx].set(key, value);
}


bool Dictionary::search_(std::string key, int& value) {
    auto idx{hash(reinterpret_cast<const unsigned char*>(key.c_str())) % size};
    return nodes[idx].search(key, value);
}


bool Dictionary::remove_(std::string key) {
    auto idx{hash(reinterpret_cast<const unsigned char*>(key.c_str())) % size};
    return nodes[idx].remove(key);
}

void Dictionary::clear_() {
    for (size_t i{}; i < size; ++i)
        nodes[i].clear();
}
