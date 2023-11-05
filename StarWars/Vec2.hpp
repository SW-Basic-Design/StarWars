#include "includes.hpp"

#ifndef VEC2_HPP
#define VEC2_HPP

class Vec2;
std::istream& operator>>(std::istream&, Vec2&);
std::ostream& operator<<(std::ostream&, const Vec2&);

class Vec2 {
public:
    Vec2() = default;
    Vec2(const Vec2&);
    Vec2(double);
    Vec2(double, double);
    Vec2 operator+(const Vec2&) const;
    Vec2 operator-(const Vec2&) const;
    Vec2 operator*(const Vec2&) const;
    Vec2 operator/(const Vec2&) const;
    Vec2& operator+=(const Vec2&);
    Vec2& operator-=(const Vec2&);
    Vec2& operator*=(const Vec2&);
    Vec2& operator/=(const Vec2&);
    bool operator==(const Vec2&) const;
    bool operator!=(const Vec2&) const;
    friend std::istream& operator>>(std::istream&, Vec2&);
    friend std::ostream& operator<<(std::ostream&, const Vec2&);
    double dot(const Vec2&) const;
    double cross(const Vec2&) const;
    double norm() const;
    void normalize();
    double area() const;
    static Vec2 LEFT();
    static Vec2 RIGHT();
    static Vec2 UP();
    static Vec2 DOWN();
    void setX(const double);
    void setY(const double);
    double getX();
    double getY();

private:
    double x;
    double y;
};

#endif