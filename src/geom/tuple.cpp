#include <stdexcept>
#include <string>
#include <math.h>
#include "geom/tuple.h"
#include "math/utils.h"

Tuple::Tuple() : x_(0.0), y_(0.0), z_(0.0), w_(0.0) {}

Tuple::Tuple(float x, float y, float z, float w) : 
    x_(x), y_(y), z_(z), w_(w) {}

float Tuple::x() const
{
    return x_;
}

float Tuple::y() const
{
    return y_;
}

float Tuple::z() const
{
    return z_;
}

float Tuple::w() const
{
    return w_;
}

bool Tuple::isPoint() const
{
    return epsilonEqual(w_, W_POINT);
}

bool Tuple::isVector() const
{
    return epsilonEqual(w_, W_VECTOR);
}

float Tuple::magnitude() const
{
    return sqrt(
        pow(x_, 2) + pow(y_, 2) + pow(z_, 2) + pow(w_, 2)
    );
}

Tuple Tuple::normalize() const
{
    float mag = this->magnitude();
    return Tuple(
        x_ / mag,
        y_ / mag,
        z_ / mag,
        w_ / mag
    );
}

float Tuple::dot(Tuple a) const
{
    return this->x_ * a.x() + this->y_ * a.y() + this->z_ * a.z() + this->w_ * a.w();
}

Tuple Tuple::cross(Tuple a) const
{
    return Vector(
        this->y_ * a.z() - this->z_ * a.y(),
        this->z_ * a.x() - this->x_ * a.z(),
        this->x_ * a.y() - this->y_ * a.x()
    );
}

Tuple Point(float x, float y, float z) 
{
    return Tuple(x, y, z, W_POINT);
}

Tuple Vector(float x, float y, float z) 
{
    return Tuple(x, y, z, W_VECTOR);
}

bool operator==(const Tuple &a, const Tuple &b)
{
    return
        epsilonEqual(a.x(), b.x()) &&
        epsilonEqual(a.y(), b.y()) &&
        epsilonEqual(a.z(), b.z()) &&
        epsilonEqual(a.w(), b.w());
}

bool operator!=(const Tuple &a, const Tuple &b)
{
    return !(a == b);
}

Tuple operator+(const Tuple &a, const Tuple &b)
{
    return Tuple(
        a.x() + b.x(),
        a.y() + b.y(),
        a.z() + b.z(),
        a.w() + b.w()
    );
}

Tuple operator-(const Tuple &a, const Tuple &b)
{
    return Tuple(
        a.x() - b.x(),
        a.y() - b.y(),
        a.z() - b.z(),
        a.w() - b.w()
    );
}

Tuple operator-(const Tuple &a)
{
    return Tuple(
        -a.x(),
        -a.y(),
        -a.z(),
        -a.w()
    );
}

Tuple operator*(const Tuple &a, const float &b)
{
    return Tuple(
        a.x()*b,
        a.y()*b,
        a.z()*b,
        a.w()*b
    );
}

Tuple operator/(const Tuple &a, const float &b)
{
    return Tuple(
        a.x()/b,
        a.y()/b,
        a.z()/b,
        a.w()/b
    );
}
