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
