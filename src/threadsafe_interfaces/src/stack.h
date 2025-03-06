#include <exception>  // stack.h
#include <mutex>
#include <stack>
struct EmptyStack : public std::exception {};

template<typename T>
class ThreadsafeStack {
    std::stack<T> data;
    mutable std::mutex m;
  public:
    ThreadsafeStack() {}
    ThreadsafeStack(const ThreadsafeStack& o) {
        std::lock_guard<std::mutex> lock(o.m);
        // don't do it in member initializer list!
        // don't forget: you need the lock!
        data = o.data;  }

ThreadsafeStack& operator=(
  const ThreadsafeStack&) = delete;
void push(T value) {
    std::lock_guard<std::mutex> lock(m);
    data.push(value);
}
std::shared_ptr<T> pop() {
    std::lock_guard<std::mutex> lock(m);
    if (data.empty()) throw EmptyStack();
    auto const res{std::make_shared<T>(
      data.top())};
    data.pop();
    return res;
}

void pop(T& value) {
        std::lock_guard<std::mutex> lock(m);
        if (data.empty()) throw EmptyStack();
        value = data.top();
        data.pop();
    }
    // not recommended:
    // if (!s.empty())
    //   s.pop(); // exc. EmptyStack may occur!
    bool empty() const {
        std::lock_guard<std::mutex> lock(m);
        return data.empty();
    }
};
