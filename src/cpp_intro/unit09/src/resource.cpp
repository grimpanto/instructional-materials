#include <iostream>  // resource.cpp
using namespace std;
struct Resource {
    Resource() noexcept {}
    ~Resource() noexcept {}
    Resource(Resource&& o) noexcept {}
    Resource& operator=(Resource&& o) noexcept {
        return *this;
    }
};
int main() {
    Resource r;
    r = Resource{};
}
