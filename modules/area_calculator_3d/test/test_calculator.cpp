// Copyright 2020 Epremyan Norik
#include <gtest/gtest.h>
#define _USE_MATH_DEFINES
#include <math.h>
#include <string>
#include <vector>
#include "include/calculator.h"

// -----------------------------TESTS FOR CUBE
TEST(Epremyan_Norik_Cube, CanCreateObject) {
// Arrange
// Act
// Assert
    ASSERT_NO_THROW(cube tmp);
}

TEST(Epremyan_Norik_Cube, CanFactoryCreateObject) {
// Arrange
    Factory* FactoryCube = new Factory();
    figure* tmpCube = FactoryCube->create("cube");
// Act
// Assert
    EXPECT_FALSE(tmpCube == nullptr);
}

TEST(Epremyan_Norik_Cube, CanGetValue) {
// Arrange
    Factory* FactoryCube = new Factory();
    std::vector<double> *value;
    figure* tmpCube = FactoryCube->create("cube");
// Act
    value = tmpCube->GetValue();
// Assert
    EXPECT_DOUBLE_EQ((*value)[0], 1);
}

TEST(Epremyan_Norik_Cube, CanSetValue) {
// Arrange
    Factory* FactoryCube = new Factory();
    figure* tmpCube = FactoryCube->create("cube");
    std::vector<double> value;
// Act
    value.push_back(2);
// Assert
    ASSERT_NO_THROW(tmpCube->SetValue(value));
}

TEST(Epremyan_Norik_Cube, CantSetNegativeValue) {
// Arrange
    Factory* FactoryCube = new Factory();
    figure* tmpCube = FactoryCube->create("cube");
    std::vector<double> value;
// Act
    value.push_back(-2);
// Assert
    EXPECT_ANY_THROW(tmpCube->SetValue(value));
}

TEST(Epremyan_Norik_Cube, CanCalculateArea) {
// Arrange
    Factory* FactoryCube = new Factory();
    figure* tmpCube = FactoryCube->create("cube");
    std::vector<double> value;
// Act
    value.push_back(2);
    tmpCube->SetValue(value);
// Assert
    EXPECT_DOUBLE_EQ(tmpCube->area(), 6*2*2);
}


// -----------------------------TESTS FOR CYLINDER
TEST(Epremyan_Norik_Cylinder, CanCreateObject) {
// Arrange
// Act
// Assert
    ASSERT_NO_THROW(cylinder tmp);
}

TEST(Epremyan_Norik_Cylinder, CanFactoryCreateObject) {
// Arrange
    Factory* FactoryCylinder = new Factory();
    figure* tmpCyl = FactoryCylinder->create("cylinder");
// Act
// Assert
    EXPECT_FALSE(tmpCyl == nullptr);
}

TEST(Epremyan_Norik_Cylinder, CanGetValue) {
// Arrange
    Factory* FactoryCylinder = new Factory();
    figure* tmpCyl = FactoryCylinder->create("cylinder");
    std::vector<double>* vals;
    double vals_sum = 0;
// Act
    vals = tmpCyl->GetValue();
    vals_sum = (*vals)[0] + (*vals)[1];
// Assert
    EXPECT_DOUBLE_EQ(vals_sum, 2);
}

TEST(Epremyan_Norik_Cylinder, CanSetValue) {
// Arrange
    Factory* FactoryCylinder = new Factory();
    figure* tmpCyl = FactoryCylinder->create("cylinder");
    std::vector<double> vals;
// Act
    vals.push_back(2);
    vals.push_back(2);
// Assert
    ASSERT_NO_THROW(tmpCyl->SetValue(vals));
}

TEST(Epremyan_Norik_Cylinder, CantSetNegativeValue1) {
// Arrange
    Factory* FactoryCylinder = new Factory();
    figure* tmpCyl = FactoryCylinder->create("cylinder");
    std::vector<double> vals;
// Act
    vals.push_back(-2);
    vals.push_back(2);
// Assert
    EXPECT_ANY_THROW(tmpCyl->SetValue(vals));
}

TEST(Epremyan_Norik_Cylinder, CantSetNegativeValue2) {
// Arrange
    Factory* FactoryCylinder = new Factory();
    figure* tmpCyl = FactoryCylinder->create("cylinder");
    std::vector<double> vals;
// Act
    vals.push_back(2);
    vals.push_back(-2);
// Assert
    EXPECT_ANY_THROW(tmpCyl->SetValue(vals));
}

TEST(Epremyan_Norik_Cylinder, CanCalculateArea) {
// Arrange
    Factory* FactoryCylinder = new Factory();
    figure* tmpCyl = FactoryCylinder->create("cylinder");
    std::vector<double> vals;
// Act
    vals.push_back(2);
    vals.push_back(2);
    tmpCyl->SetValue(vals);
// Assert
    EXPECT_DOUBLE_EQ(tmpCyl->area(), 2*M_PI*2*4);
}

// -----------------------------TESTS FOR CONE
TEST(Epremyan_Norik_Cone, CanCreateFactoryObject) {
// Arrange
// Act
// Assert
    ASSERT_NO_THROW(cone tmp);
}

TEST(Epremyan_Norik_Cone, CanFactoryCreateObject) {
// Arrange
    Factory* FactoryCone = new Factory();
// Act
// Assert
    ASSERT_NO_THROW(FactoryCone->create("cone"));
}

TEST(Epremyan_Norik_Cone, CanGetValue) {
// Arrange
    Factory* FactoryCone = new Factory();
    figure* tmpCone = FactoryCone->create("cone");
    std::vector<double>* vals;
    double vals_sum = 0;
// Act
    vals = tmpCone->GetValue();
    vals_sum = (*vals)[0] + (*vals)[1];
// Assert
    EXPECT_DOUBLE_EQ(vals_sum, 2);
}

TEST(Epremyan_Norik_Cone, CanSetValue) {
// Arrange
    Factory* FactoryCone = new Factory();
    figure* tmpCone = FactoryCone->create("cone");
    std::vector<double> vals;
// Act
    vals.push_back(2);
    vals.push_back(2);
// Assert
    ASSERT_NO_THROW(tmpCone->SetValue(vals));
}

TEST(Epremyan_Norik_Cone, CantSetNegativeValue1) {
// Arrange
    Factory* FactoryCone = new Factory();
    figure* tmpCone = FactoryCone->create("cone");
    std::vector<double> vals;
// Act
    vals.push_back(-2);
    vals.push_back(2);
// Assert
    EXPECT_ANY_THROW(tmpCone->SetValue(vals));
}

TEST(Epremyan_Norik_Cone, CantSetNegativeValue2) {
// Arrange
    Factory* FactoryCone = new Factory();
    figure* tmpCone = FactoryCone->create("cone");
    std::vector<double> vals;
// Act
    vals.push_back(2);
    vals.push_back(-2);
// Assert
    EXPECT_ANY_THROW(tmpCone->SetValue(vals));
}

TEST(Epremyan_Norik_Cone, CanCalculateArea) {
// Arrange
    Factory* FactoryCone = new Factory();
    figure* tmpCone = FactoryCone->create("cone");
    std::vector<double> vals;
    double forming = sqrt(exp2(2) + exp2(2));
// Act
    vals.push_back(2);
    vals.push_back(2);
    tmpCone->SetValue(vals);
// Assert
    EXPECT_DOUBLE_EQ(tmpCone->area(), M_PI * 2 *(2+forming));
}
