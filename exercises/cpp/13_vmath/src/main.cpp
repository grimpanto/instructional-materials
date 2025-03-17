// @copyright 2019 Günter Kolousek

#include "vmath.h"

#include "CLI11.hpp"

#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wpedantic"
#include "fmt/format.h"
#include "fmt/ranges.h"
#pragma GCC diagnostic pop

#include "json.hpp"

#include "spdlog/spdlog.h"
#include "spdlog/fmt/bin_to_hex.h"

#include "magic_enum.hpp"

#include <iostream>
#include <vector>
#include <fstream>
#include <set>
#include <unordered_set>
#include <memory>

using namespace std;
using json = nlohmann::json;
//using namespace literals;


int main([[maybe_unused]]int argc, [[maybe_unused]]const char** argv) {

    Vector3D<double> v1{1, 1, 1};
    cout << v1 << endl;

    Vector3D<double> v2{v1};
    cout << v2 << endl;

    Vector3D<double> v3{2, 2, 2};
    v2 = v3;
    cout << v2 << endl;

    Vector3D<double> v4{Vector3D<double>{3,3,3}};
    cout << v4 << endl;

    cout << +v1 << endl;
    cout << ++v1 << endl;
    cout << v1-- << endl;
    cout << v1 << endl;

    cout << v1 * 4. << endl;
    cout << 4. * v1 << endl;

    cout << v1 % v3 << endl;

    cout << abs(v1) << ' ' << (double)v1 << ' ' << static_cast<double>(v1) << endl;

    return 0;
}
