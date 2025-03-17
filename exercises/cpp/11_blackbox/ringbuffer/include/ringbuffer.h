
#pragma once

#include <optional>
#include <array>
#include <iostream>

template <typename T, size_t N>
class Ringbuffer {
  public:
    std::optional<T> get() noexcept {
        if (read_idx == write_idx)
            return std::nullopt;
        //auto res{contents[read_idx]};  // could not be used because of nlohmann::json!
        auto res=contents[read_idx];
        read_idx = (read_idx + 1) % CAPACITY;
        return res;
    }
    void put(T val) noexcept {
        if (read_idx == (write_idx + 1) % CAPACITY)
            read_idx = (read_idx + 1) % CAPACITY;
        contents[write_idx] = val;
        write_idx = (write_idx + 1) % CAPACITY;
    }
    size_t size() noexcept {
        int res{static_cast<int>(write_idx - read_idx)};
        if (res < 0)
            res += CAPACITY;
        return res;
    }
  private:
    static constexpr size_t CAPACITY{N + 1};
    std::array<T, CAPACITY> contents;
    size_t read_idx{};
    size_t write_idx{};
};
