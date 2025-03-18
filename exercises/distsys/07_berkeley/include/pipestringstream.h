// @copyright 2016 Günter Kolousek

#ifndef PIPE_H
#define PIPE_H

#include <iostream>
#include <sstream>
#include <mutex>
#include <condition_variable>

template <typename T>
class Pipe {
    std::stringstream stream;
    std::mutex mtx;
    std::condition_variable not_empty;
  public:
    Pipe& operator<<(T value) {
        {
            std::lock_guard<std::mutex> lg{mtx};
            stream.clear();
            stream << value << ' ';
        }
        not_empty.notify_one();
        return *this;
    }

    Pipe& operator>>(T& value) {
        {
            std::unique_lock<std::mutex> lck{mtx};
            if (!(stream >> value)) {  // nothing available or broken
                stream.str("");  // flush the backend
                stream.clear();
                not_empty.wait(lck, [this, &value](){
                    bool done{stream >> value};
                    stream.clear();
                    return done;
                });
            }
        }
        return *this;
    }
    explicit operator bool() {
        return stream.good();
    }
};
#endif
