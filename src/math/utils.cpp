#include "math/utils.h"
#include "math/constants.h"
#include <cmath>

bool epsilonEqual(float a, float b)
{
    return abs(a - b) < EPSILON;
}
