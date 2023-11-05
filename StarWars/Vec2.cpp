#include "Vec2.hpp"

Vec2::Vec2(double v) : x(v), y(v) {}

Vec2::Vec2(double x, double y) : x(x), y(y) {}

Vec2::Vec2(const Vec2& o) : x(o.x), y(o.x) {}

Vec2 Vec2::operator+(const Vec2& rhs) const 
{
    return { this->x + rhs.x, this->y + rhs.y };
}

Vec2 Vec2::operator-(const Vec2& rhs) const 
{
    return { this->x - rhs.x, this->y - rhs.y };
}

Vec2 Vec2::operator*(const Vec2& rhs) const 
{
    return { this->x * rhs.x, this->y * rhs.y };
}

Vec2 Vec2::operator/(const Vec2& rhs) const 
{
    return { this->x / rhs.x, this->y / rhs.y };
}

Vec2& Vec2::operator+=(const Vec2& rhs) 
{
    this->x += rhs.x;
    this->y += rhs.y;
    return *this;
}

Vec2& Vec2::operator-=(const Vec2& rhs) 
{
    this->x -= rhs.x;
    this->y -= rhs.y;
    return *this;
}

Vec2& Vec2::operator*=(const Vec2& rhs) 
{
    this->x *= rhs.x;
    this->y *= rhs.y;
    return *this;
}

Vec2& Vec2::operator/=(const Vec2& rhs) 
{
    this->x /= rhs.x;
    this->y /= rhs.y;
    return *this;
}

bool Vec2::operator==(const Vec2& rhs) const 
{
    return this->x == rhs.x && this->y == rhs.y;
}

bool Vec2::operator!=(const Vec2& rhs) const 
{
    return this->x != rhs.x || this->y != rhs.y;
}

std::istream& operator>>(std::istream& is, Vec2& self) 
{
    return is >> self.x >> self.y;
}

std::ostream& operator<<(std::ostream& os, const Vec2& self) 
{
    return os << '[' << self.x << ',' << self.y << ']';
}

double Vec2::dot(const Vec2& rhs) const 
{
    return this->x * rhs.x + this->y * rhs.y;
}

double Vec2::cross(const Vec2& rhs) const 
{
    return this->x * rhs.y - this->y * rhs.x;
}

double Vec2::norm() const 
{
    return hypot(this->x, this->y);
}

void Vec2::normalize() 
{
    *this /= norm();
}

double Vec2::area() const 
{
    return x * y;
}

Vec2 Vec2::LEFT() 
{
    return { -1, 0 };
}

Vec2 Vec2::RIGHT() 
{
    return { 1, 0 };
}

Vec2 Vec2::UP() 
{
    return { 0, -1 };
}

Vec2 Vec2::DOWN() 
{
    return { 0, 1 };
}

void Vec2::setX(const double x) 
{
    this->x = x;
}

void Vec2::setY(const double y)
{
    this->y = y;
}

double Vec2::getX() 
{
    return this->x;
}

double Vec2::getY() 
{
    return this->y;
}