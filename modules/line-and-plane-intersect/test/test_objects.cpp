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
    Point point(x, y, z);

    // Assert
    EXPECT_NEAR(x, point.x, ObjectsTest::epsilon);
    EXPECT_NEAR(y, point.y, ObjectsTest::epsilon);
    EXPECT_NEAR(z, point.z, ObjectsTest::epsilon);
}

TEST_F(ObjectsTest, can_copy_point) {
    // Arrange 
    Point expected(0., 1., 2.);

    // Act
    Point point(expected);

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
    Point point(Point(x, y, z));

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
    Line line(x, y, z, m, n, p);

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
    Line expected(x, y, z, m, n, p);
    
    // Act
    Line line(Point(x, y, z), Point(x1, y1, z1));

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
    Line expected(x, y, z, m, n, p);
    
    // Act
    Line line(expected);

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
    Line line(Line(x, y, z, m, n, p));

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
    double A = 0.;
    double B = 1.2;
    double C = 2.3;
    double D = 1.1;
    
    // Act
    Plane plane(A, B, C, D);

    // Assert
    EXPECT_NEAR(A, plane.getA(), ObjectsTest::epsilon);
    EXPECT_NEAR(B, plane.getB(), ObjectsTest::epsilon);
    EXPECT_NEAR(C, plane.getC(), ObjectsTest::epsilon);
    EXPECT_NEAR(D, plane.getD(), ObjectsTest::epsilon);
}

TEST_F(ObjectsTest, can_copy_plane) {
    // Arrange 
    double A = 0.;
    double B = 1.2;
    double C = 2.3;
    double D = 1.1;
    Plane expected(A, B, C, D);
    
    // Act
    Plane plane(expected);

    // Assert
    EXPECT_NEAR(expected.getA(), plane.getA(), ObjectsTest::epsilon);
    EXPECT_NEAR(expected.getB(), plane.getB(), ObjectsTest::epsilon);
    EXPECT_NEAR(expected.getC(), plane.getC(), ObjectsTest::epsilon);
    EXPECT_NEAR(expected.getD(), plane.getD(), ObjectsTest::epsilon);
}

TEST_F(ObjectsTest, can_copy_rvalue_plane) {
    // Arrange 
    double A = 0.;
    double B = 1.2;
    double C = 2.3;
    double D = 1.1;
    Plane expected(A, B, C, D);
    
    // Act
    Plane plane(Plane(A, B, C, D));

    // Assert
    EXPECT_NEAR(expected.getA(), plane.getA(), ObjectsTest::epsilon);
    EXPECT_NEAR(expected.getB(), plane.getB(), ObjectsTest::epsilon);
    EXPECT_NEAR(expected.getC(), plane.getC(), ObjectsTest::epsilon);
    EXPECT_NEAR(expected.getD(), plane.getD(), ObjectsTest::epsilon);
}
