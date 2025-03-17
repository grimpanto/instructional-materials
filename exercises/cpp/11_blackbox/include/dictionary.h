
#pragma once

#include "sll.h"

#include "json.hpp"

#include <iterator>
#include <algorithm>

class Dictionary {
  public:
    auto begin() {
        return v.begin();
    }
    auto cbegin() const {
        return v.cbegin();
    }
    auto end() {
        return v.end();
    }
    auto cend() const {
        return v.cend();
    }
    auto find(const std::string& key) {
        int value;
        if (search(key, value))
            return std::find_if(std::begin(v), std::end(v),
              [key](std::pair<std::string, int>& p) {
                  return (p.first == key) ? true : false; });
        else
            return end();
    }
    auto erase(const std::string& key) {
        if (remove(key))
            return v.erase(
              std::find_if(std::begin(v), std::end(v),
                [key](std::pair<std::string, int>& p) {
                    return (p.first == key) ? true : false; }));
        else
            return end();
    }
    auto& operator[](const std::string& key) {
        if (auto it{find(key)}; it != end())
            return it->second;
        else {
            set(key, 0);
            // v.push_back(std::pair<std::string,int>{key, 0});
            v.push_back(std::make_pair(key, 0));
            return find(key)->second;
        }
    }
    void clear() {
        v.clear();
        clear_();
    }
        
  private:
    static size_t hash(const unsigned char* str);
    std::vector<std::pair<std::string,int>> v;
    static constexpr size_t size{13};
    List nodes[size];

    bool set_(std::string key, int value);
    bool search_(std::string key, int& value);
    bool remove_(std::string key);
    void clear_();
    
    friend std::ostream& operator<<(std::ostream&, const Dictionary& pd);
    friend std::istream& operator>>(std::istream&, Dictionary& pd);
};


inline std::ostream& operator<<(std::ostream& os, const Dictionary& pd) {
    nlohmann::json dict;
    dict = std::unordered_map(pd.cbegin(), pd.cend());
    os << dict;
    return os;
}

inline std::istream& operator>>(std::istream& is, Dictionary& pd) {
    nlohmann::json dict;
    is >> dict;
    pd.clear();
    for (auto& [key, value] : dict.items())
        pd[key] = value;
    return is;
}
