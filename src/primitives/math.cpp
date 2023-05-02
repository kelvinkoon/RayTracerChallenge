#include "primitives/math.h"
#include "primitives/math_constants.h"
#include <cmath>

bool epsilonEqual(float a, float b)
{
    return abs(a - b) < EPSILON;
}
