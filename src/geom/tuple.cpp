#include <stdexcept>
#include <string>
#include "geom/tuple.h"
#include "math/utils.h"

Tuple::Tuple() : x_(0.0), y_(0.0), z_(0.0), w_(0.0) {}

Tuple::Tuple(float x, float y, float z, float w) : 
    x_(x), y_(y), z_(z), w_(w) {
        if (!(epsilonEqual(w_, W_POINT) || epsilonEqual(w_, W_VECTOR))) {
            throw std::invalid_argument("Tuple 'w' must be either 0.0 or 1.0, given: " +
                std::to_string(w));
        }
    }

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

Tuple Point(float x, float y, float z) {
    return Tuple(x, y, z, W_POINT);
}

Tuple Vector(float x, float y, float z) {
    return Tuple(x, y, z, W_VECTOR);
}
