#include <math.h>
#include <gtest/gtest.h>
#include "primitives/tuple.h"
#include "primitives/math.h"

TEST(CreateTupleTests, tuple_default_constructor) {
    Tuple t = Tuple();
    EXPECT_TRUE(epsilonEqual(0, t.x()));
    EXPECT_TRUE(epsilonEqual(0, t.y()));
    EXPECT_TRUE(epsilonEqual(0, t.z()));
    EXPECT_TRUE(epsilonEqual(0, t.w()));
}

TEST(CreateTupleTests, tuple_custom_constructor) {
    Tuple t = Tuple(1, 2, 3, W_POINT);
    EXPECT_TRUE(epsilonEqual(1, t.x()));
    EXPECT_TRUE(epsilonEqual(2, t.y()));
    EXPECT_TRUE(epsilonEqual(3, t.z()));
    EXPECT_TRUE(epsilonEqual(W_POINT, t.w()));
}

TEST(CreateTupleTests, point_custom_constructor) {
    Tuple p = Point(4, -4, 3);
    Tuple t = Tuple(4, -4, 3, 1);
    EXPECT_TRUE(epsilonEqual(p.x(), t.x()));
    EXPECT_TRUE(epsilonEqual(p.y(), t.y()));
    EXPECT_TRUE(epsilonEqual(p.z(), t.z()));
    EXPECT_TRUE(epsilonEqual(p.w(), t.w()));
}

TEST(CreateTupleTests, vector_custom_constructor) {
    Tuple p = Vector(4, -4, 3);
    Tuple t = Tuple(4, -4, 3, 0);
    EXPECT_TRUE(epsilonEqual(p.x(), t.x()));
    EXPECT_TRUE(epsilonEqual(p.y(), t.y()));
    EXPECT_TRUE(epsilonEqual(p.z(), t.z()));
    EXPECT_TRUE(epsilonEqual(p.w(), t.w()));
}

// Pg 4
TEST(TupleIsComparisonTests, tuple_is_point_vector_test) {
    Tuple p = Tuple(4.3, -4.2, 3.1, 1.0);
    EXPECT_TRUE(p.isPoint());
    Tuple v = Tuple(4.3, -4.2, 3.1, 0.0);
    EXPECT_TRUE(v.isVector());
}

TEST(TupleOperatorTests, tuple_equality_test) {
    Tuple t1 = Tuple(1, 2, 3, 0);
    Tuple t2 = Tuple(1, 2, 3, 0);
    EXPECT_TRUE(t1 == t2);
    EXPECT_FALSE(t1 != t2);
}

// Pg 6
TEST(TupleOperatorTests, tuple_sum_test) {
    Tuple t1 = Tuple(3, -2, 5, 1);
    Tuple t2 = Tuple(-2, 3, 1, 0);
    Tuple sum_t = t1 + t2;
    Tuple expected_t = Tuple(1, 1, 6, 1);
    EXPECT_TRUE(epsilonEqual(sum_t.x(), expected_t.x()));
    EXPECT_TRUE(epsilonEqual(sum_t.y(), expected_t.y()));
    EXPECT_TRUE(epsilonEqual(sum_t.z(), expected_t.z()));
    EXPECT_TRUE(epsilonEqual(sum_t.w(), expected_t.w()));
}

// Pg 6
TEST(TupleOperatorTests, subtract_two_points_test) {
    Tuple p1 = Point(3, 2, 1);
    Tuple p2 = Point(5, 6, 7);
    Tuple v = p1 - p2;
    Tuple expected_v = Vector(-2, -4, -6);
    EXPECT_TRUE(epsilonEqual(v.x(), expected_v.x()));
    EXPECT_TRUE(epsilonEqual(v.y(), expected_v.y()));
    EXPECT_TRUE(epsilonEqual(v.z(), expected_v.z()));
    EXPECT_TRUE(epsilonEqual(v.w(), expected_v.w()));
}

// Pg 6
TEST(TupleOperatorTests, subtract_vector_from_point_test) {
    Tuple p = Point(3, 2, 1);
    Tuple v = Vector(5, 6, 7);
    Tuple sub_v = p - v;
    Tuple expected_p = Point(-2, -4, -6);
    EXPECT_TRUE(epsilonEqual(sub_v.x(), expected_p.x()));
    EXPECT_TRUE(epsilonEqual(sub_v.y(), expected_p.y()));
    EXPECT_TRUE(epsilonEqual(sub_v.z(), expected_p.z()));
    EXPECT_TRUE(epsilonEqual(sub_v.w(), expected_p.w()));
}

// Pg 7
TEST(TupleOperatorTests, subtract_two_vectors_test) {
    Tuple v1 = Vector(3, 2, 1);
    Tuple v2 = Vector(5, 6, 7);
    Tuple sub_v = v1 - v2;
    Tuple expected_v = Vector(-2, -4, -6);
    EXPECT_TRUE(epsilonEqual(sub_v.x(), expected_v.x()));
    EXPECT_TRUE(epsilonEqual(sub_v.y(), expected_v.y()));
    EXPECT_TRUE(epsilonEqual(sub_v.z(), expected_v.z()));
    EXPECT_TRUE(epsilonEqual(sub_v.w(), expected_v.w()));
}

// Pg 7
TEST(TupleOperatorTests, negate_tuple_test) {
    Tuple zero_v = Vector(0, 0, 0);
    Tuple v = Vector(1, -2, 3);
    Tuple sub_v = zero_v - v;
    Tuple expected_sub_v = Vector(-1, 2, -3);
    EXPECT_TRUE(epsilonEqual(sub_v.x(), expected_sub_v.x()));
    EXPECT_TRUE(epsilonEqual(sub_v.y(), expected_sub_v.y()));
    EXPECT_TRUE(epsilonEqual(sub_v.z(), expected_sub_v.z()));
    EXPECT_TRUE(epsilonEqual(sub_v.w(), expected_sub_v.w()));
    Tuple neg_v = -Tuple(1, -2, 3, -4);
    Tuple expected_neg_v = Tuple(-1, 2, -3, 4);
    EXPECT_TRUE(epsilonEqual(neg_v.x(), expected_neg_v.x()));
    EXPECT_TRUE(epsilonEqual(neg_v.y(), expected_neg_v.y()));
    EXPECT_TRUE(epsilonEqual(neg_v.z(), expected_neg_v.z()));
    EXPECT_TRUE(epsilonEqual(neg_v.w(), expected_neg_v.w()));
}

// Pg 8
TEST(TupleOperatorTests, multiply_tuple_test) {
    Tuple t = Tuple(1, -2, 3, -4);
    Tuple mult_scalar_t = t*3.5;
    Tuple expected_scalar_t = Tuple(3.5, -7, 10.5, -14);
    EXPECT_TRUE(epsilonEqual(mult_scalar_t.x(), expected_scalar_t.x()));
    EXPECT_TRUE(epsilonEqual(mult_scalar_t.y(), expected_scalar_t.y()));
    EXPECT_TRUE(epsilonEqual(mult_scalar_t.z(), expected_scalar_t.z()));
    EXPECT_TRUE(epsilonEqual(mult_scalar_t.w(), expected_scalar_t.w()));

    Tuple mult_fraction_t = t*0.5;
    Tuple expected_fraction_t = Tuple(0.5, -1, 1.5, -2);
    EXPECT_TRUE(epsilonEqual(mult_fraction_t.x(), expected_fraction_t.x()));
    EXPECT_TRUE(epsilonEqual(mult_fraction_t.y(), expected_fraction_t.y()));
    EXPECT_TRUE(epsilonEqual(mult_fraction_t.z(), expected_fraction_t.z()));
    EXPECT_TRUE(epsilonEqual(mult_fraction_t.w(), expected_fraction_t.w()));
}

// Pg 8
TEST(TupleOperatorTests, divide_tuple_test) {
    Tuple t = Tuple(1, -2, 3, -4);
    Tuple div_scalar_t = t/2;
    Tuple expected_scalar_t = Tuple(0.5, -1, 1.5, -2);
    EXPECT_TRUE(epsilonEqual(div_scalar_t.x(), expected_scalar_t.x()));
    EXPECT_TRUE(epsilonEqual(div_scalar_t.y(), expected_scalar_t.y()));
    EXPECT_TRUE(epsilonEqual(div_scalar_t.z(), expected_scalar_t.z()));
    EXPECT_TRUE(epsilonEqual(div_scalar_t.w(), expected_scalar_t.w()));
}

// Pg 8
TEST(TupleMagnitudeTests, magnitude_tuple_test) {
    Tuple v = Vector(1, 0, 0);
    float expected_mag = 1;
    EXPECT_TRUE(epsilonEqual(v.magnitude(), expected_mag));

    v = Vector(0, 1, 0);
    EXPECT_TRUE(epsilonEqual(v.magnitude(), expected_mag));

    v = Vector(0, 0, 1);
    EXPECT_TRUE(epsilonEqual(v.magnitude(), expected_mag));

    v = Vector(1, 2, 3);
    expected_mag = sqrt(14);
    EXPECT_TRUE(epsilonEqual(v.magnitude(), expected_mag));

    v = Vector(-1, -2, -3);
    expected_mag = sqrt(14);
    EXPECT_TRUE(epsilonEqual(v.magnitude(), expected_mag));
}

// Pg 10
TEST(TupleNormalizeTests, normalize_tuple_test) {
    Tuple v = Vector(4, 0, 0);
    Tuple expected_v = Vector(1, 0, 0);
    EXPECT_TRUE(v.normalize() == expected_v);

    v = Vector(1, 2, 3);
    expected_v = Vector(1/sqrt(14), 2/sqrt(14), 3/sqrt(14));
    Tuple norm_v = v.normalize();
    EXPECT_TRUE(norm_v == expected_v);
    EXPECT_TRUE(epsilonEqual(norm_v.magnitude(), 1));
}

// Pg 10
TEST(TupleDotTests, dot_tuple_test) {
    Tuple a = Vector(1, 2, 3);
    Tuple b = Vector(2, 3, 4);
    float expected_dot = 20;
    EXPECT_TRUE(a.dot(b) == expected_dot);
}

// Pg 10
TEST(TupleCrossTests, cross_tuple_test) {
    Tuple a = Vector(1, 2, 3);
    Tuple b = Vector(2, 3, 4);
    Tuple expected_ab_v = Vector(-1, 2, -1);
    Tuple expected_ba_v = Vector(1, -2, 1);
    EXPECT_TRUE(a.cross(b) == expected_ab_v);
    EXPECT_TRUE(b.cross(a) == expected_ba_v);
}
