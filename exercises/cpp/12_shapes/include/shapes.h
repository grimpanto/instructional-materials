// @copyright 2019 Günter Kolousek

#pragma once

#include <iostream>
#include <cmath>
#include <memory>

double to_radian(double degree) {
    return (degree / 360) * 2 * M_PI;
}


double to_degree(double radian) {
    return (radian * 360) / 2 / M_PI;
}


class Point {
  public:
    Point() = default;
    Point(double x, double y) : x{x}, y{y} {}
    Point move(double dx, double dy) const {
        return Point(x + dx, y + dy);
    }
	bool operator<(const Point& o) const {
		if (x < o.x)
            return true;
        else if (y < o.y)
            return true;
        return false;
    }

	bool operator==(const Point& o) const {
		return x == o.x && y == o.y;
    }

    const double x{};
    const double y{};
  private:
    friend std::ostream& operator<<(std::ostream&, const Point&);
};

template<>
struct std::hash<Point> {
    size_t operator()([[maybe_unused]]const Point& p) const {
        return std::hash<double>()(p.x) ^ std::hash<double>()(p.y);
    }
};


std::ostream& operator<<(std::ostream& os, const Point& p) {
    os << "Point(" << p.x << ", " << p.y << ")";
    return os;
}


class Shape {
  public:
    Shape(const Point& pos, double alpha) : pos{std::make_unique<Point>(pos.x, pos.y)} {
        set_alpha(alpha);
    }


    void set_alpha(double alpha) {
        this->alpha = fmod(alpha, 2 * M_PI);
    }


    void set_alpha_degree(double alpha) {
        set_alpha(to_radian(alpha));
    }


    [[nodiscard]]
    double get_alpha() const {
        return alpha;
    }


    [[nodiscard]]
    double get_alpha_degree() const {
        return to_degree(alpha);
    }


    Shape& move(double dx, double dy) {
        pos = std::make_unique<Point>(pos->x + dx, pos->y + dy);
        return *this;
    }


    Shape& rotate(double alpha) {
        this->alpha = fmod(this->alpha + alpha, 2 * M_PI);
        return *this;
    }


    Shape& rotate_degree(double alpha) {
        return rotate(to_radian(alpha));
    }


    virtual std::ostream& print(std::ostream&) const = 0;
    virtual ~Shape() = default;

    std::unique_ptr<Point> pos;
  protected:
    double alpha;
};


std::ostream& operator<<(std::ostream& os, const Shape& s) {
    return s.print(os);
}


class Line : public Shape {
  public:
    Line(const Point& pos, double alpha, double length) : Shape{pos, alpha} {
        set_length(length);
    }


    Line(const Point& start, const Point& end) : Shape{start, std::atan((end.y - start.y) / (end.x - start.x))} {
        set_length(std::sqrt(std::pow(end.x - start.x, 2) +
                             std::pow(end.y - start.y, 2)));
    }


    void set_length(double length) {
        if (length <= 0)
            throw std::invalid_argument("length of line must be greater than zero");
        this->length = length;
    }


    [[nodiscard]]
    double get_length() const {
        return length;
    }


    std::ostream& print(std::ostream& os) const override {
        os << "Line({" << pos->x << ", " << pos->y << "}, " <<
          get_length() << ", " << get_alpha_degree() << ")";
        return os;
    }
  private:
    double length;
};


class Shape2D : public Shape {
  public:
    Shape2D(const Point& pos, double alpha) : Shape{pos, alpha} {}
    virtual double get_area() const = 0;
    virtual ~Shape2D() = default;
};


class Square : public Shape2D {
  public:
    Square(const Point& pos, double alpha, double side) : Shape2D{pos, alpha} {
        set_side(side);
    }


    void set_side(double side) {
        if (side <= 0)
            throw std::invalid_argument("side of a square must be greater than zero");
        this->side = side;
    }


    [[nodiscard]]
    double get_side() const {
        return side;
    }


    double get_area() const override {
        return side * side;
    }


    std::ostream& print(std::ostream& os) const override {
        os << "Square({" << pos->x << ", " << pos->y << "}, " <<
          get_side() << ", " << get_alpha_degree() << ")";
        return os;
    }
  private:
    double side;
};


class Rectangle : public Shape2D {
  public:
    Rectangle(const Point& pos, double alpha, double side_a, double side_b) :
      Shape2D{pos, alpha} {
        set_side_a(side_a);
        set_side_b(side_b);
    }


    void set_side_a(double side_a) {
        if (side_a <= 0)
            throw std::invalid_argument("side_a of a rectangle must be greater than zero");
        this->side_a = side_a;
    }


    [[nodiscard]]
    double get_side_a() const {
        return side_a;
    }


    void set_side_b(double side_b) {
        if (side_b <= 0)
            throw std::invalid_argument("side_b of a rectangle must be greater than zero");
        this->side_b = side_b;
    }


    [[nodiscard]]
    double get_side_b() const {
        return side_b;
    }


    double get_area() const override {
        return side_a * side_b;
    }


    bool is_square() const {
        return abs(side_a - side_b) < EPS;
    }


    Square to_square() const {
        if (is_square())
            return Square(*pos, alpha, side_a);
        else
            throw std::domain_error("cannot transform a true rectangle to square");
    }

    std::ostream& print(std::ostream& os) const override {
        os << "Rectangle({" << pos->x << ", " << pos->y << "}, " <<
          get_side_a() << ", " << get_side_b() << ", " << get_alpha_degree() << ")";
        return os;
    }

  private:
    double side_a;
    double side_b;
    static constexpr double EPS{1e-5};
};
