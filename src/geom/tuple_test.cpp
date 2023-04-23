#include "geom/tuple.h"

#include <gtest/gtest.h>

TEST(CreateTupleTests, tuple_default_constructor) {
    Tuple t = Tuple();
    EXPECT_EQ(0.0, t.x());
    EXPECT_EQ(0.0, t.y());
    EXPECT_EQ(0.0, t.z());
    EXPECT_EQ(0.0, t.w());
}

TEST(CreateTupleTests, tuple_point_custom_constructor) {
    Tuple t = Tuple(1.0F, 2.0F, 3.0F, W_POINT);
    EXPECT_EQ(1.0, t.x());
    EXPECT_EQ(2.0, t.y());
    EXPECT_EQ(3.0, t.z());
    EXPECT_EQ(W_POINT, t.w());
}

TEST(CreateTupleTests, tuple_vector_custom_constructor) {
    Tuple t = Tuple(1.0F, 2.0F, 3.0F, W_VECTOR);
    EXPECT_EQ(1.0, t.x());
    EXPECT_EQ(2.0, t.y());
    EXPECT_EQ(3.0, t.z());
    EXPECT_EQ(W_VECTOR, t.w());
}

TEST(CreateTupleTests, tuple_invalid_input) {
    EXPECT_THROW(Tuple(1.0F, 2.0F, 3.0F, 3.0F), std::invalid_argument);
}

TEST(TuplePointTests, tuple_is_point) {
    Tuple t = Tuple(1.0F, 2.0F, 3.0F, W_POINT);
    EXPECT_TRUE(t.isPoint());
}

TEST(TuplePointTests, tuple_is_vector) {
    Tuple t = Tuple(1.0F, 2.0F, 3.0F, W_VECTOR);
}
