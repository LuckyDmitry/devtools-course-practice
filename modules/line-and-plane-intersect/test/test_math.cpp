// Copyright 2020 Lebedev Alexander

#include <gtest/gtest.h>

#include "include/math.h"
#include "include/objects.h"

class MathTest : public ::testing::Test {
 protected:
    double epsilon = 0.0000001;
};

TEST_F(MathTest, can_intersect_line_and_plane) {
    // Arrange
    double x = 2.;
    double y = -5.;
    double z = 4.;
    double m = 1.;
    double n = 3.;
    double p = 2.;
    double a = 7.;
    double b = -5.;
    double c = 2.;
    double d = 19.;

    Line line(x, y, z, m, n, p);
    Plane plane(a, b, c, d);
    Point expected(37. / 2., 89. / 2., 37.);

    // Act
    Point point = intersect(line, plane);

    // Assert
    EXPECT_NEAR(expected.x, point.x, MathTest::epsilon);
    EXPECT_NEAR(expected.y, point.y, MathTest::epsilon);
    EXPECT_NEAR(expected.z, point.z, MathTest::epsilon);
}

TEST_F(MathTest, can_check_relative_position_parallel_line_and_plane) {
    // Arrange
    double x = -2.;
    double y = 2.;
    double z = 3.;
    double m = 1.;
    double n = -5.;
    double p = 4.;
    double a = 6.;
    double b = 2.;
    double c = 1.;
    double d = 7.;

    Line line(x, y, z, m, n, p);
    Plane plane(a, b, c, d);
    RelativePosition expected = RelativePosition::PARALLEL;

    // Act
    RelativePosition position = getRelativePosition(line, plane);

    // Assert
    EXPECT_EQ(expected, position);
}

TEST_F(MathTest, can_check_relative_position_embedded_line_and_plane) {
    // Arrange
    double x = 1.;
    double y = -5.;
    double z = 8.;
    double m = 2.;
    double n = -5.;
    double p = -1.;
    double a = 2.;
    double b = 1.;
    double c = -1.;
    double d = 11.;

    Line line(x, y, z, m, n, p);
    Plane plane(a, b, c, d);
    RelativePosition expected = RelativePosition::EMBEDDED;

    // Act
    RelativePosition position = getRelativePosition(line, plane);

    // Assert
    EXPECT_EQ(expected, position);
}

TEST_F(MathTest, can_check_relative_position_intersect_line_and_plane) {
    // Arrange
    double x = 2.;
    double y = -5.;
    double z = 4.;
    double m = 1.;
    double n = 3.;
    double p = 2.;
    double a = 7.;
    double b = -5.;
    double c = 2.;
    double d = 19.;

    Line line(x, y, z, m, n, p);
    Plane plane(a, b, c, d);
    RelativePosition expected = RelativePosition::INTERSECT;

    // Act
    RelativePosition position = getRelativePosition(line, plane);

    // Assert
    EXPECT_EQ(expected, position);
}

TEST_F(MathTest, can_throw_on_intersection_of_embedded_line_and_plane) {
    // Arrange
    double x = 1.;
    double y = -5.;
    double z = 8.;
    double m = 2.;
    double n = -5.;
    double p = -1.;
    double a = 2.;
    double b = 1.;
    double c = -1.;
    double d = 11.;

    Line line(x, y, z, m, n, p);
    Plane plane(a, b, c, d);

    // Act & Assert
    EXPECT_ANY_THROW(intersect(line, plane));
}
