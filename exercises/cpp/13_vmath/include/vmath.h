// @copyright 2019 Günter Kolousek

#pragma once

#include <iostream>
#include <cmath>
#include <memory>


template <typename T>
class Vector3D final {
  public:
    Vector3D() = default;
    //Vector3D(T a) : x{a}, y{a}, z{a} {}  // XXX
    Vector3D(T x, T y, T z) : x{x}, y{y}, z{z} {}
    T x{};
    T y{};
    T z{};

    Vector3D<T> operator+() const {
        return Vector3D<T>(x, y, z);
    }


    Vector3D<T> operator-() const {
        return Vector3D<T>(-x, -y, -z);
    }


    Vector3D<T>& operator++() {
        x++;
        y++;
        z++;
        return *this;
    }


    Vector3D<T> operator++(int) {
        auto old{*this};
        ++(*this);
        return old;
    }


    Vector3D<T>& operator--() {
        x--;
        y--;
        z--;
        return *this;
    }


    Vector3D<T> operator--(int) {
        auto old{*this};
        --(*this);
        return old;
    }


    Vector3D<T>& operator+=(const Vector3D<T>& o) {
        x += o.x;
        y += o.y;
        z += o.z;
        return *this;
    }


    Vector3D<T>& operator-=(const Vector3D<T>& o) {
        x -= o.x;
        y -= o.y;
        z -= o.z;
        return *this;
    }


    Vector3D<T>& operator*=(const Vector3D<T>& o) {
        Vector3D<T> tmp;
        tmp.x = y * o.y - z * o.y;
        tmp.y = z * o.x - x * o.z;
        tmp.z = x * o.y - y * o.x;
        *this = tmp;
        return *this;
    }

    explicit operator T() const {
        return abs(*this);
    }
};


template <typename T>
std::ostream& operator<<(std::ostream& os, const Vector3D<T>& v) {
    os << "Vector3D(" << v.x << ", " << v.y << ", " << v.z << ")";
    return os;
}


template <typename T>
Vector3D<T> operator+(const Vector3D<T>& op1, const Vector3D<T>& op2) {
    Vector3D<T> tmp{op1};
    tmp += op2;
    return tmp;
}


template <typename T>
Vector3D<T> operator-(const Vector3D<T>& op1, const Vector3D<T>& op2) {
    Vector3D<T> tmp{op1};
    tmp -= op2;
    return tmp;
}


template <typename T>
Vector3D<T> operator*(const Vector3D<T>& op1, const Vector3D<T>& op2) {
    Vector3D<T> tmp{op1};
    tmp *= op2;
    return tmp;
}


template <typename T>
Vector3D<T> operator*(const Vector3D<T>& op1, T c) {
    Vector3D<T> tmp{op1};
    tmp.x *= c;
    tmp.y *= c;
    tmp.z *= c;
    return tmp;
}


template <typename T>
Vector3D<T> operator*(T c, const Vector3D<T>& op1) {
    Vector3D<T> tmp{op1};
    tmp.x *= c;
    tmp.y *= c;
    tmp.z *= c;
    return tmp;
}


template <typename T>
T operator%(const Vector3D<T>& op1, const Vector3D<T>& op2) {
    return op1.x * op2.x + op1.y * op2.y + op1.z * op2.z;
}


template <typename T>
T abs(const Vector3D<T>& op) {
    return std::sqrt(op.x * op.x + op.y * op.y + op.z * op.z);
}


template <typename T>
bool operator==(const Vector3D<T>& op1, const Vector3D<T>& op2) {
    return op1.x == op2.x && op1.y == op2.y && op1.z ==op2.z;
}


template <typename T>
bool operator!=(const Vector3D<T>& op1, const Vector3D<T>& op2) {
    return !(op1 == op2);
}


template <typename T>
bool operator<(const Vector3D<T>& op1, const Vector3D<T>& op2) {
    if (op1.x < op2.x)
        return true;
    else if (op1.x > op2.x)
        return false;
    else if (op1.y < op2.y)
        return true;
    else if (op1.y > op2.y)
        return false;
    else if (op1.z < op2.z)
        return true;
    else
        return false;
}


template <typename T>
bool operator>=(const Vector3D<T>& op1, const Vector3D<T>& op2) {
    return !(op1 < op2);
}


template <typename T>
bool operator>(const Vector3D<T>& op1, const Vector3D<T>& op2) {
    return !(op1 < op2) && !(op1 == op2);
}


template <typename T>
bool operator<=(const Vector3D<T>& op1, const Vector3D<T>& op2) {
    return !(op1 > op2);
}
