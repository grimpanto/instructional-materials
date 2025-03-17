// @copyright 2019 Günter Kolousek

#include "stack.h"

#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wpedantic"
#include "fmt/format.h"
#include "fmt/ranges.h"
#pragma GCC diagnostic pop

#include <string>
#include <stdexcept>

using namespace std;

Stack::Stack(int value) {
    push(value);
}


Stack::Stack(initializer_list<int> list) {
    for (auto i : list)
        push(i);
}


Stack::Stack([[maybe_unused]]const Stack& other) {
    Node** prev_ptr{const_cast<Node**>(&(top_))};
    Node* curr{other.top_};
    while (curr) {
        *prev_ptr = new Node{curr->value, nullptr};
        curr = curr->next;
        prev_ptr = &(*prev_ptr)->next;
    }
}


Stack::Stack([[maybe_unused]]Stack&& other) noexcept {
    swap(*this, other);
}


Stack::~Stack() noexcept {
    clear();
}


int& Stack::top() const {
    if (top_)
        return top_->value;
    throw domain_error{"could not access top of an empty stack"};
}


int Stack::pop() {
    if (top_) {
        auto value{top_->value};
        auto tmp{top_};
        top_ = top_->next;
        delete tmp;
        return value;
    }
    throw domain_error{"could not pop from an empty stack"};
}


void Stack::push(int value) {
    Node* tmp{top_};
    top_ = new Node{value, tmp};
}


void Stack::clear() noexcept {
    Node* curr{top_};
    Node* next{};
    while (curr) {
        next = curr->next;
        delete curr;
        curr = next;
    }
    top_ = nullptr;
}


bool Stack::empty() const noexcept {
    return !top_;
}


std::ostream& operator<<(std::ostream& os, [[maybe_unused]]const Stack& stack) {
    Node* curr{stack.top_};
    while (curr) {
        os << curr->value << "\n";
        curr = curr->next;
    }
    os << endl;
    return os;
}


void swap(Stack& first, Stack& second) noexcept {
    using std::swap;

    swap(first.top_, second.top_);
}


Stack& Stack::operator=(const Stack& rhs) {
    if (this == &rhs)
        return *this;
    Stack tmp{rhs};
    swap(*this, tmp);
    return *this;
}


Stack& Stack::operator=(Stack&& rhs) noexcept {
    Stack tmp{std::move(rhs)};
    swap(*this, tmp);
    return *this;
}
