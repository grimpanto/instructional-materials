// @copyright 2019 Günter Kolousek

#pragma once

#include <string>

struct Node {
    std::string key;
    int value{};
    Node* next{};
};

class List final {
  public:
    ~List();
    bool set(std::string key, int value);
    bool search(std::string key, int& value);
    bool remove(std::string key);
    void clear();
  private:
    Node* anchor{};
};
