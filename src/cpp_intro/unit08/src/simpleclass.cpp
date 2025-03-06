#include <iostream>  // simpleclass.cpp
#include <tuple>
using namespace std;
class Circle {
    double r{1};  double x;  double y;
  public:
    Circle()=default;  // no POD!
    Circle(double r, double x, double y)
      : r{r}, x{x}, y{y} {}
    auto data() const { return make_tuple(r, x, y); } };
int main() {
    auto [r, x, y] = Circle{}.data();
    cout << r <<  ' ' << x << ' ' << y << ", ";
    tie(r, x, y) = Circle{3, 2, 1}.data();
    cout << r <<  ' ' << x << ' ' << y << ", ";
    auto circ = Circle{3, 2, 1}.data();
    cout << get<0>(circ) << ' ' << get<1>(circ) << ' '
      << get<2>(circ)<<endl;
}
