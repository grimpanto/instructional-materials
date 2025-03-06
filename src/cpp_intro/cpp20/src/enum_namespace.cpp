#include <iostream>  // enum_namespace.cpp
using namespace std;
enum class Permission {
    read, write, execute
};

int main() {
    Permission perm{Permission::write};
    switch (perm) {
        // sadly, currently not with g++!!
        using enum Permission;
        case read:
            cout << "read" << endl;  break;
        case write:
            cout << "write" << endl; break;
        case execute:
            cout << "execute" << endl;  break;
    }
}
