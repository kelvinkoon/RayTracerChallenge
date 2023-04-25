#include <stdexcept>
#include <string>
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
