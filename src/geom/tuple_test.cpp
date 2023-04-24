#include "geom/tuple.h"

#include <gtest/gtest.h>

TEST(CreateTupleTests, tuple_default_constructor) {
    Tuple t = Tuple();
    EXPECT_EQ(0, t.x());
    EXPECT_EQ(0, t.y());
    EXPECT_EQ(0, t.z());
    EXPECT_EQ(0, t.w());
}

TEST(CreateTupleTests, tuple_custom_constructor) {
    Tuple t = Tuple(1, 2, 3, W_POINT);
    EXPECT_EQ(1, t.x());
    EXPECT_EQ(2, t.y());
    EXPECT_EQ(3, t.z());
    EXPECT_EQ(W_POINT, t.w());
}

TEST(CreateTupleTests, point_custom_constructor) {
    Tuple p = Point(4, -4, 3);
    Tuple t = Tuple(4, -4, 3, 1);
    EXPECT_EQ(p.x(), t.x());
    EXPECT_EQ(p.y(), t.y());
    EXPECT_EQ(p.z(), t.z());
    EXPECT_EQ(p.w(), t.w());
}

TEST(CreateTupleTests, vector_custom_constructor) {
    Tuple p = Vector(4, -4, 3);
    Tuple t = Tuple(4, -4, 3, 0);
    EXPECT_EQ(p.x(), t.x());
    EXPECT_EQ(p.y(), t.y());
    EXPECT_EQ(p.z(), t.z());
    EXPECT_EQ(p.w(), t.w());
}

TEST(CreateTupleTests, tuple_invalid_input) {
    EXPECT_THROW(Tuple(1, 2, 3, 3), std::invalid_argument);
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
    EXPECT_EQ(sum_t.x(), expected_t.x());
    EXPECT_EQ(sum_t.y(), expected_t.y());
    EXPECT_EQ(sum_t.z(), expected_t.z());
    EXPECT_EQ(sum_t.w(), expected_t.w());
}

// Pg 6
TEST(TupleOperatorTests, subtract_two_points_test) {
    Tuple p1 = Point(3, 2, 1);
    Tuple p2 = Point(5, 6, 7);
    Tuple v = p1 - p2;
    Tuple expected_v = Vector(-2, -4, -6);
    EXPECT_EQ(v.x(), expected_v.x());
    EXPECT_EQ(v.y(), expected_v.y());
    EXPECT_EQ(v.z(), expected_v.z());
    EXPECT_EQ(v.w(), expected_v.w());
}

// Pg 6
TEST(TupleOperatorTests, subtract_vector_from_point_test) {
    Tuple p = Point(3, 2, 1);
    Tuple v = Vector(5, 6, 7);
    Tuple sub_v = p - v;
    Tuple expected_p = Point(-2, -4, -6);
    EXPECT_EQ(sub_v.x(), expected_p.x());
    EXPECT_EQ(sub_v.y(), expected_p.y());
    EXPECT_EQ(sub_v.z(), expected_p.z());
    EXPECT_EQ(sub_v.w(), expected_p.w());
}

// Pg 7
TEST(TupleOperatorTests, subtract_two_vectors_test) {
    Tuple v1 = Vector(3, 2, 1);
    Tuple v2 = Vector(5, 6, 7);
    Tuple sub_v = v1 - v2;
    Tuple expected_v = Vector(-2, -4, -6);
    EXPECT_EQ(sub_v.x(), expected_v.x());
    EXPECT_EQ(sub_v.y(), expected_v.y());
    EXPECT_EQ(sub_v.z(), expected_v.z());
    EXPECT_EQ(sub_v.w(), expected_v.w());
}
