// @copyright 2019 Günter Kolousek

#pragma once

#include <memory>
#include <iostream>
#include <initializer_list>


class Stack final {
  public:
    Stack() = default;
    Stack(double);
    Stack(std::initializer_list<double>);
    double& top() const;
    double pop();
    void push(double);
    void clear() noexcept;
    bool empty() const noexcept;
  private:
    struct Node {
        Node(double value, std::unique_ptr<Node>&& next) : value{value}, next{move(next)} {}
        double value{};
        std::unique_ptr<Node> next{};
    };

    std::unique_ptr<Node> top_{};
    friend std::ostream& operator<<(std::ostream&, const Stack&);
};

std::ostream& operator<<(std::ostream&, const Stack&);
