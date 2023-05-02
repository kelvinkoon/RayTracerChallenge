#include <gtest/gtest.h>
#include "primitives/colour.h"
#include "test_utils/test_utils.h"

TEST(CreateColourTests, colour_default_constructor) {
    Colour c = Colour();
    EXPECT_TRUE(testEpsilonEqual(0, c.red()));
    EXPECT_TRUE(testEpsilonEqual(0, c.green()));
    EXPECT_TRUE(testEpsilonEqual(0, c.blue()));
}

// Pg 16
TEST(CreateColourTests, colour_custom_constructor) {
    Colour c = Colour(-0.5, 0.4, 1.7);
    EXPECT_TRUE(testEpsilonEqual(-0.5, c.red()));
    EXPECT_TRUE(testEpsilonEqual(0.4, c.green()));
    EXPECT_TRUE(testEpsilonEqual(1.7, c.blue()));
}

TEST(ColourOperatorTests, colour_equality_tests) {
    Colour c1 = Colour(0.9, 0.6, 0.75);
    Colour c1_copy = Colour(0.9, 0.6, 0.75);

    EXPECT_TRUE(c1 == c1_copy);
    EXPECT_FALSE(c1 != c1_copy);
}

// Pg 17
TEST(ColourOperatorTests, colour_add_sub_mult_tests) {
    Colour c1_add_sub = Colour(0.9, 0.6, 0.75);
    Colour c2_add_sub = Colour(0.7, 0.1, 0.25);
    Colour c_scalar_mult = Colour(0.2, 0.3, 0.4);
    Colour c1_mult = Colour(1, 0.2, 0.4);
    Colour c2_mult = Colour(0.9, 1, 0.1);

    Colour expected_add_c = Colour(1.6, 0.7, 1.0);
    Colour expected_sub_c = Colour(0.2, 0.5, 0.5);
    Colour expected_mult_scalar_c = Colour(0.4, 0.6, 0.8);
    Colour expected_mult_c = Colour(0.9, 0.2, 0.04);

    EXPECT_TRUE(c1_add_sub+c2_add_sub == expected_add_c);
    EXPECT_TRUE(c1_add_sub-c2_add_sub == expected_sub_c);
    EXPECT_TRUE(c_scalar_mult*2 == expected_mult_scalar_c);
    EXPECT_TRUE(c1_mult*c2_mult == expected_mult_c);
}
