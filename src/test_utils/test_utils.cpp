#include "test_utils/test_utils.h"
#include "test_utils/test_constants.h"
#include <cmath>

bool testEpsilonEqual(float a, float b)
{
    return abs(a - b) < EPSILON;
}
