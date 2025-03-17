// @copyright 2019 Günter Kolousek

#include "sll.h"

#include <string>

using namespace std;

List::~List() {
    clear();
}

bool List::set(string key, int value) {
    if (search(key, value))
        return false;
    Node* first{anchor};
    anchor = new Node{key, value};
    anchor->next = first;
    return true;
}

bool List::search(string key, int& value) {
    Node* curr{anchor};
    while (curr != nullptr) {
        if (curr->key == key) {
            value = curr->value;
            return true;
        }
        curr = curr->next;
    }
    return false;
}

bool List::remove(string key) {
    Node* curr{anchor};
    Node* prev{};
    bool found{};
    while (curr != nullptr) {
        if (curr->key == key) {
            found = true;
            break;
        }
        prev = curr;
        curr = curr->next;
    }

    if (found) {
        if (prev != nullptr) {
            prev->next = curr->next;
        } else {
            anchor = curr->next;
        }
        delete curr;
        return true;
    } else
        return false;
}

void List::clear() {
    Node* curr{anchor};
    while (curr != nullptr) {
        Node* next{curr->next};
        delete curr;
        curr = next;
    }
}
