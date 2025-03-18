// @copyright 2016 Günter Kolousek

#ifndef PIPE_H
#define PIPE_H

#include <queue>
#include <mutex>
#include <condition_variable>
#include <future>
#include <thread>

template <typename T>
class Pipe {
    std::queue<T> backend;
    std::mutex mtx;
    std::condition_variable not_empty;
    bool closed{false};
    long latency{};
  public:
    Pipe& operator<<(T value) {
        {
            std::lock_guard<std::mutex> lg{mtx};
            if (closed)
                return *this;
            if (latency != 0) {
                std::thread t{[this, value]() {
                    std::lock_guard<std::mutex> lg{mtx};
                    std::this_thread::sleep_for(std::chrono::milliseconds(latency));
                    backend.push(value);
                }};
                t.detach();
            } else
                backend.push(value);
        }
        not_empty.notify_one();
        return *this;
    }

    Pipe& operator>>(T& value) {
        {
            std::unique_lock<std::mutex> lck{mtx};
            if (closed)
                return *this;
            not_empty.wait(lck, [this](){ return !backend.empty(); });
            value = backend.front();
            backend.pop();
        }
        return *this;
    }

    void close() {
        std::lock_guard<std::mutex> lg{mtx};
        closed = true;
    }

    explicit operator bool() {
        std::lock_guard<std::mutex> lg{mtx};
        return !closed;
    }

    void set_latency(long val) {
        latency = val;
    }
};
#endif
