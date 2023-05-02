#include "colour/colour.h"
#include "math/utils.h"

Colour::Colour() : r_(0.0), g_(0.0), b_(0.0) {}

Colour::Colour(float r, float g, float b) : 
    r_(r), g_(g), b_(b) {}

float Colour::red() const
{
    return r_;
}

float Colour::green() const
{
    return g_;
}

float Colour::blue() const
{
    return b_;
}

bool operator==(const Colour &a, const Colour &b)
{
    return
        epsilonEqual(a.red(), b.red()) &&
        epsilonEqual(a.green(), b.green()) &&
        epsilonEqual(a.blue(), b.blue());
}

bool operator!=(const Colour &a, const Colour &b)
{
    return !(a == b);
}

Colour operator+(const Colour &a, const Colour &b)
{
    return Colour(
        a.red() + b.red(),
        a.green() + b.green(),
        a.blue() + b.blue()
    );
}

Colour operator-(const Colour &a, const Colour &b)
{
    return Colour(
        a.red() - b.red(),
        a.green() - b.green(),
        a.blue() - b.blue()
    );
}

Colour operator*(const Colour &a, const float &s)
{
    return Colour(
        a.red()*s,
        a.green()*s,
        a.blue()*s
    );
}

Colour operator*(const Colour &a, const Colour &b)
{
    return Colour(
        a.red()*b.red(),
        a.green()*b.green(),
        a.blue()*b.blue()
    );
}
