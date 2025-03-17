// @copyright 2019 Günter Kolousek

#pragma once

#include <string>
#include <unordered_map>
#include <iostream>

#include "json.hpp"

class PhoneDict {
  public:
    auto begin() {
        return dict.begin();
    }
    auto end() {
        return dict.end();
    }
    auto find(const std::string& key) {
        return dict.find(key);
    }
    auto erase(const std::string& key) {
        return dict.erase(key);
    }
    auto& operator[](const std::string& key) {
        return dict[key];
    }
  private:
    std::unordered_map<std::string,int> dict;
    friend std::ostream& operator<<(std::ostream&, const PhoneDict& pd);
    friend std::istream& operator>>(std::istream&, PhoneDict& pd);
};

std::ostream& operator<<(std::ostream& os, const PhoneDict& pd) {
    nlohmann::json dict;
    dict = pd.dict;
    os << dict;
    return os;
}

std::istream& operator>>(std::istream& is, PhoneDict& pd) {
    nlohmann::json dict;
    is >> dict;
    pd.dict.clear();
    for (auto& [key, value] : dict.items())
        pd.dict[key] = value;
    return is;
}
