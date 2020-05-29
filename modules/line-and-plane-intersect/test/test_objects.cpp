// Copyright 2020 Lebedev Alexander

#include <gtest/gtest.h>

#include "include/objects.h"

class ObjectsTest : public ::testing::Test {
 protected:
    double epsilon = 0.0000001;
};

TEST_F(ObjectsTest, can_crate_point) {
    // Arrange
    double x = 0.;
    double y = 1.2;
    double z = 2.3;

    // Act
    Objects3d::Point point(x, y, z);

    // Assert
    EXPECT_NEAR(x, point.x, ObjectsTest::epsilon);
    EXPECT_NEAR(y, point.y, ObjectsTest::epsilon);
    EXPECT_NEAR(z, point.z, ObjectsTest::epsilon);
}

TEST_F(ObjectsTest, can_copy_point) {
    // Arrange
    Objects3d::Point expected(0., 1., 2.);

    // Act
    Objects3d::Point point(expected);

    // Assert
    EXPECT_NEAR(expected.x, point.x, ObjectsTest::epsilon);
    EXPECT_NEAR(expected.y, point.y, ObjectsTest::epsilon);
    EXPECT_NEAR(expected.z, point.z, ObjectsTest::epsilon);
}

TEST_F(ObjectsTest, can_copy_rvalue_point) {
    // Arrange
    double x = 0.;
    double y = 1.2;
    double z = 2.3;

    // Act
    Objects3d::Point point(Objects3d::Point(x, y, z));

    // Assert
    EXPECT_NEAR(x, point.x, ObjectsTest::epsilon);
    EXPECT_NEAR(y, point.y, ObjectsTest::epsilon);
    EXPECT_NEAR(z, point.z, ObjectsTest::epsilon);
}

TEST_F(ObjectsTest, can_crate_line_by_point_and_vector) {
    // Arrange
    double x = 0.;
    double y = 1.2;
    double z = 2.3;
    double m = 1.1;
    double n = 1.4;
    double p = 1.8;

    // Act
    Objects3d::Line line(x, y, z, m, n, p);

    // Assert
    EXPECT_NEAR(x, line.getX(), ObjectsTest::epsilon);
    EXPECT_NEAR(y, line.getY(), ObjectsTest::epsilon);
    EXPECT_NEAR(z, line.getZ(), ObjectsTest::epsilon);
    EXPECT_NEAR(n, line.getN(), ObjectsTest::epsilon);
    EXPECT_NEAR(m, line.getM(), ObjectsTest::epsilon);
    EXPECT_NEAR(p, line.getP(), ObjectsTest::epsilon);
}

TEST_F(ObjectsTest, can_create_line_by_two_points) {
    // Arrange
    double x  = 0.;
    double y  = 1.2;
    double z  = 2.3;
    double x1 = 1.1;
    double y1 = 2.6;
    double z1 = 2.9;
    double m  = 1.1;
    double n  = 1.4;
    double p  = 0.6;
    Objects3d::Line expected(x, y, z, m, n, p);

    // Act
    Objects3d::Line line(Objects3d::Point(x, y, z),
                         Objects3d::Point(x1, y1, z1));

    // Assert
    EXPECT_NEAR(expected.getX(), line.getX(), ObjectsTest::epsilon);
    EXPECT_NEAR(expected.getY(), line.getY(), ObjectsTest::epsilon);
    EXPECT_NEAR(expected.getZ(), line.getZ(), ObjectsTest::epsilon);
    EXPECT_NEAR(expected.getN(), line.getN(), ObjectsTest::epsilon);
    EXPECT_NEAR(expected.getM(), line.getM(), ObjectsTest::epsilon);
    EXPECT_NEAR(expected.getP(), line.getP(), ObjectsTest::epsilon);
}

TEST_F(ObjectsTest, can_copy_line) {
    // Arrange
    double x = 0.;
    double y = 1.2;
    double z = 2.3;
    double m = 1.1;
    double n = 1.4;
    double p = 1.8;
    Objects3d::Line expected(x, y, z, m, n, p);

    // Act
    Objects3d::Line line(expected);

    // Assert
    EXPECT_NEAR(expected.getX(), line.getX(), ObjectsTest::epsilon);
    EXPECT_NEAR(expected.getY(), line.getY(), ObjectsTest::epsilon);
    EXPECT_NEAR(expected.getZ(), line.getZ(), ObjectsTest::epsilon);
    EXPECT_NEAR(expected.getN(), line.getN(), ObjectsTest::epsilon);
    EXPECT_NEAR(expected.getM(), line.getM(), ObjectsTest::epsilon);
    EXPECT_NEAR(expected.getP(), line.getP(), ObjectsTest::epsilon);
}

TEST_F(ObjectsTest, can_copy_rvalue_line) {
    // Arrange
    double x = 0.;
    double y = 1.2;
    double z = 2.3;
    double m = 1.1;
    double n = 1.4;
    double p = 1.8;

    // Act
    Objects3d::Line line(Objects3d::Line(x, y, z, m, n, p));

    // Assert
    EXPECT_NEAR(x, line.getX(), ObjectsTest::epsilon);
    EXPECT_NEAR(y, line.getY(), ObjectsTest::epsilon);
    EXPECT_NEAR(z, line.getZ(), ObjectsTest::epsilon);
    EXPECT_NEAR(n, line.getN(), ObjectsTest::epsilon);
    EXPECT_NEAR(m, line.getM(), ObjectsTest::epsilon);
    EXPECT_NEAR(p, line.getP(), ObjectsTest::epsilon);
}


TEST_F(ObjectsTest, can_create_plane) {
    // Arrange
    double a = 0.;
    double b = 1.2;
    double c = 2.3;
    double d = 1.1;

    // Act
    Objects3d::Plane plane(a, b, c, d);

    // Assert
    EXPECT_NEAR(a, plane.getA(), ObjectsTest::epsilon);
    EXPECT_NEAR(b, plane.getB(), ObjectsTest::epsilon);
    EXPECT_NEAR(c, plane.getC(), ObjectsTest::epsilon);
    EXPECT_NEAR(d, plane.getD(), ObjectsTest::epsilon);
}

TEST_F(ObjectsTest, can_copy_plane) {
    // Arrange
    double a = 0.;
    double b = 1.2;
    double c = 2.3;
    double d = 1.1;
    Objects3d::Plane expected(a, b, c, d);

    // Act
    Objects3d::Plane plane(expected);

    // Assert
    EXPECT_NEAR(expected.getA(), plane.getA(), ObjectsTest::epsilon);
    EXPECT_NEAR(expected.getB(), plane.getB(), ObjectsTest::epsilon);
    EXPECT_NEAR(expected.getC(), plane.getC(), ObjectsTest::epsilon);
    EXPECT_NEAR(expected.getD(), plane.getD(), ObjectsTest::epsilon);
}

TEST_F(ObjectsTest, can_copy_rvalue_plane) {
    // Arrange
    double a = 0.;
    double b = 1.2;
    double c = 2.3;
    double d = 1.1;
    Objects3d::Plane expected(a, b, c, d);

    // Act
    Objects3d::Plane plane(Objects3d::Plane(a, b, c, d));

    // Assert
    EXPECT_NEAR(expected.getA(), plane.getA(), ObjectsTest::epsilon);
    EXPECT_NEAR(expected.getB(), plane.getB(), ObjectsTest::epsilon);
    EXPECT_NEAR(expected.getC(), plane.getC(), ObjectsTest::epsilon);
    EXPECT_NEAR(expected.getD(), plane.getD(), ObjectsTest::epsilon);
}

TEST_F(ObjectsTest, can_use_setter_line) {
    // Arrange
    double x = 0.;
    double y = 1.2;
    double z = 2.3;
    double m = 1.1;
    double n = 1.4;
    double p = 1.8;
    Objects3d::Line line;

    // Act
    line.setX(x);
    line.setY(y);
    line.setZ(z);
    line.setM(m);
    line.setN(n);
    line.setP(p);

    // Assert
    EXPECT_NEAR(x, line.getX(), ObjectsTest::epsilon);
    EXPECT_NEAR(y, line.getY(), ObjectsTest::epsilon);
    EXPECT_NEAR(z, line.getZ(), ObjectsTest::epsilon);
    EXPECT_NEAR(n, line.getN(), ObjectsTest::epsilon);
    EXPECT_NEAR(m, line.getM(), ObjectsTest::epsilon);
    EXPECT_NEAR(p, line.getP(), ObjectsTest::epsilon);
}

TEST_F(ObjectsTest, can_use_settrs_plane) {
    // Arrange
    double a = 0.;
    double b = 1.2;
    double c = 2.3;
    double d = 1.1;
    Objects3d::Plane plane;

    // Act
    plane.setA(a);
    plane.setB(b);
    plane.setC(c);
    plane.setD(d);

    // Assert
    EXPECT_NEAR(a, plane.getA(), ObjectsTest::epsilon);
    EXPECT_NEAR(b, plane.getB(), ObjectsTest::epsilon);
    EXPECT_NEAR(c, plane.getC(), ObjectsTest::epsilon);
    EXPECT_NEAR(d, plane.getD(), ObjectsTest::epsilon);
}
