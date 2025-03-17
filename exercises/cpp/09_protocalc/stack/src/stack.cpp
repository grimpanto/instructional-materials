// @copyright 2019 Günter Kolousek

#include "stack.h"

#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wpedantic"
#include "fmt/format.h"
#include "fmt/ranges.h"
#pragma GCC diagnostic pop

#include <string>
#include <stdexcept>
#include <utility>

using namespace std;


Stack::Stack(double value) {
    push(value);
}


Stack::Stack(initializer_list<double> list) {
    for (auto i : list)
        push(i);
}


double& Stack::top() const {
    if (top_)
        return top_->value;
    throw domain_error{"could not access top of an empty stack"};
}


double Stack::pop() {
    if (top_) {
        auto tmp{top_->value};
        top_ = move(top_->next);
        return tmp;
    }
    throw domain_error{"could not pop from an empty stack"};
}


void Stack::push(double value) {
    if (top_) {
        top_ = make_unique<Node>(value, move(top_));
        /* // alternativ, aber nicht so performant und speichereffizient
        unique_ptr<Node> tmp{move(top_)};
        top_ = make_unique<Node>();
        top_->value = value;
        top_->next = move(tmp);*
        */
    } else {
        top_ = make_unique<Node>(value, nullptr);
        /*
        top_ = make_unique<Node>();
        top_->value = value;
        */
    }
}


bool Stack::empty() const noexcept {
    return !top_;
}


std::ostream& operator<<(std::ostream& os, [[maybe_unused]]const Stack& stack) {
    Stack::Node* curr{stack.top_.get()};
    while (curr) {
        os << curr->value << "\n";
        curr = curr->next.get();
    }
    os << endl;
    return os;
}
