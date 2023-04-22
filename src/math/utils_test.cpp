#include "math/utils.h"

#include <gtest/gtest.h>

TEST(EpsilonEqualTests, equal_epsilon_default_test)
{
    EXPECT_TRUE(epsilonEqual(1.0, 1.0));
}
