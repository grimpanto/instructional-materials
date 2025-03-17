// @copyright 2019 Günter Kolousek

#include "shapes.h"

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

    Point p1{3, 4};

    cout << p1 << endl;

    vector<Point> points(10);
    for (auto& p : points)
        cout << p << endl;

    set<Point> points2;
    points2.insert(Point{});

    unordered_set<Point> points3;
    points3.insert(Point{});

    Line l1{{0, 0}, 0, 1};
    cout << l1.get_alpha() << endl;

    vector<unique_ptr<Shape>> shapes;
    shapes.push_back(make_unique<Line>(Point{1, 1}, Point{2, 2}));
    shapes.push_back(make_unique<Square>(Point{2, 2}, 0, 2));
    shapes.push_back(make_unique<Rectangle>(Point{3, 3}, to_radian(45), 3, 3));

    for (auto& o : shapes) {
        cout << *o;
        if (Shape2D* s{dynamic_cast<Shape2D*>(o.get())}) {
            cout << ", Area=" << s->get_area();
        }
        cout << endl;
        o->move(1, 1);
        cout << "    move it by (1, 1): " << *o << endl;
        o->rotate_degree(45);
        cout << "    rotate it by 45°: " << *o << endl;
    }

    return 0;
}
