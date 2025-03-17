// @copyright 2019 Günter Kolousek

#pragma once

#include <memory>
#include <iostream>
#include <initializer_list>

struct Node {
    int value{};
    Node* next{};
};

class Stack final {
  public:
    Stack() = default;
    //    Stack();
    Stack(int);
    Stack(std::initializer_list<int>);
    Stack(const Stack&);
    Stack(Stack&&) noexcept;
    ~Stack() noexcept;
    Stack& operator=(const Stack&);
    Stack& operator=(Stack&&) noexcept;
    int& top() const;
    int pop();
    void push(int);
    void clear() noexcept;
    bool empty() const noexcept;
  private:
    Node* top_{};
    friend std::ostream& operator<<(std::ostream&, const Stack&);
    friend void swap(Stack& first, Stack& second) noexcept;
};

std::ostream& operator<<(std::ostream&, const Stack&);
void swap(Stack& first, Stack& second) noexcept;
