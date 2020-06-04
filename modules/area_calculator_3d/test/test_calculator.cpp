// Copyright 2020 Epremyan Norik
#include <gtest/gtest.h>
#define _USE_MATH_DEFINES
#include <math.h>
#include <string>
#include <vector>
#include "include/calculator.h"

// -----------------------------TESTS FOR CUBE
TEST(Epremyan_Norik_Cube, CanCreateFactoryObject) {
// Arrange
// Act
// Assert
    ASSERT_NO_THROW(CubeFactory tmp);
}

TEST(Epremyan_Norik_Cube, CanDeleteFactoryObject) {
// Arrange
    CubeFactory* tmpCube = new CubeFactory;
// Act
// Assert
    ASSERT_NO_THROW(delete tmpCube);
}

TEST(Epremyan_Norik_Cube, CanCreateObject) {
// Arrange
    CubeFactory* tmpCube = new CubeFactory;
// Act
// Assert
    ASSERT_NO_THROW(tmpCube->createFigure());
}

TEST(Epremyan_Norik_Cube, CanGetName) {
// Arrange
    CubeFactory* tmpCube = new CubeFactory;
    figure* _Cube;
// Act
    _Cube = tmpCube->createFigure();
// Assert
    EXPECT_EQ(_Cube->GetName(), "cube");
}

TEST(Epremyan_Norik_Cube, CanGetValue) {
// Arrange
    CubeFactory* tmpCube = new CubeFactory;
    figure* _Cube;
    std::vector<double> *value;
    double _edge;
// Act
    _Cube = tmpCube->createFigure();
    value = _Cube->GetValue();
    _edge = (*value)[0];
// Assert
    EXPECT_DOUBLE_EQ(_edge, 1);
}

TEST(Epremyan_Norik_Cube, CanSetValue) {
// Arrange
    CubeFactory* tmpCube = new CubeFactory;
    figure* _Cube;
    std::vector<double> value;
// Act
    _Cube = tmpCube->createFigure();
    value.push_back(2);
// Assert
    EXPECT_TRUE(_Cube->SetValue(value));
}

TEST(Epremyan_Norik_Cube, CantSetNegativeValue) {
// Arrange
    CubeFactory* tmpCube = new CubeFactory;
    figure* _Cube;
    std::vector<double> value;
// Act
    _Cube = tmpCube->createFigure();
    value.push_back(-2);
// Assert
    EXPECT_ANY_THROW(_Cube->SetValue(value));
}

TEST(Epremyan_Norik_Cube, CanCalculateArea) {
// Arrange
    CubeFactory* tmpCube = new CubeFactory;
    figure* _Cube;
    std::vector<double> value;
// Act
    _Cube = tmpCube->createFigure();
    value.push_back(2);
    _Cube->SetValue(value);
// Assert
    EXPECT_DOUBLE_EQ(_Cube->area(), 6*2*2);
}


// -----------------------------TESTS FOR CYLINDER
TEST(Epremyan_Norik_Cylinder, CanCreateFactoryObject) {
// Arrange
// Act
// Assert
    ASSERT_NO_THROW(CylinderFactory tmp);
}

TEST(Epremyan_Norik_Cylinder, CanDeleteFactoryObject) {
// Arrange
    CylinderFactory* templ = new CylinderFactory;
// Act
// Assert
    ASSERT_NO_THROW(delete templ);
}

TEST(Epremyan_Norik_Cylinder, CanCreateObject) {
// Arrange
    CylinderFactory* templ = new CylinderFactory;
// Act
// Assert
    ASSERT_NO_THROW(templ->createFigure(););
}

TEST(Epremyan_Norik_Cylinder, CanGetName) {
// Arrange
    CylinderFactory* templ = new CylinderFactory;
    figure* _Cylndr;
// Act
    _Cylndr = templ->createFigure();
// Assert
    EXPECT_EQ(_Cylndr->GetName(), "cylinder");
}

TEST(Epremyan_Norik_Cylinder, CanGetValue) {
// Arrange
    CylinderFactory* templ = new CylinderFactory;
    figure* _Cylndr;
    std::vector<double>* vals;
    double vals_sum = 0;
// Act
    _Cylndr = templ->createFigure();
    vals = _Cylndr->GetValue();
    vals_sum = (*vals)[0] + (*vals)[1];
// Assert
    EXPECT_DOUBLE_EQ(vals_sum, 2);
}

TEST(Epremyan_Norik_Cylinder, CanSetValue) {
// Arrange
    CylinderFactory* templ = new CylinderFactory;
    figure* _Cylndr;
    std::vector<double> vals;
// Act
    _Cylndr = templ->createFigure();
    vals.push_back(2);
    vals.push_back(2);
// Assert
    EXPECT_TRUE(_Cylndr->SetValue(vals));
}

TEST(Epremyan_Norik_Cylinder, CantSetNegativeValue) {
// Arrange
    CylinderFactory* templ = new CylinderFactory;
    figure* _Cylndr;
    std::vector<double> vals;
// Act
    _Cylndr = templ->createFigure();
    vals.push_back(-2);
    vals.push_back(2);
// Assert
    EXPECT_ANY_THROW(_Cylndr->SetValue(vals));
}

TEST(Epremyan_Norik_Cylinder, CanCalculateArea) {
// Arrange
    CylinderFactory* templ = new CylinderFactory;
    figure* _Cylndr;
    std::vector<double> vals;
// Act
    _Cylndr = templ->createFigure();
    vals.push_back(2);
    vals.push_back(2);
    _Cylndr->SetValue(vals);
// Assert
    EXPECT_DOUBLE_EQ(_Cylndr->area(), 2*M_PI*2*4);
}



// -----------------------------TESTS FOR CONE
TEST(Epremyan_Norik_Cone, CanCreateFactoryObject) {
// Arrange
// Act
// Assert
    ASSERT_NO_THROW(ConeFactory tmp);
}

TEST(Epremyan_Norik_Cone, CanDeleteFactoryObject) {
// Arrange
    ConeFactory* templ = new ConeFactory;
// Act
// Assert
    ASSERT_NO_THROW(delete templ);
}

TEST(Epremyan_Norik_Cone, CanCreateObject) {
// Arrange
    ConeFactory* templ = new ConeFactory;
// Act
// Assert
    ASSERT_NO_THROW(templ->createFigure());
}

TEST(Epremyan_Norik_Cone, CanGetName) {
// Arrange
    ConeFactory* templ = new ConeFactory;
    figure* _Cone;
// Act
    _Cone = templ->createFigure();
// Assert
    EXPECT_EQ(_Cone->GetName(), "cone");
}

TEST(Epremyan_Norik_Cone, CanGetValue) {
// Arrange
    ConeFactory* templ = new ConeFactory;
    figure* _Cone;
    std::vector<double>* vals;
    double vals_sum = 0;
// Act
    _Cone = templ->createFigure();
    vals = _Cone->GetValue();
    vals_sum = (*vals)[0] + (*vals)[1];
// Assert
    EXPECT_DOUBLE_EQ(vals_sum, 2);
}

TEST(Epremyan_Norik_Cone, CanSetValue) {
// Arrange
    ConeFactory* templ = new ConeFactory;
    figure* _Cone;
    std::vector<double> vals;
// Act
    _Cone = templ->createFigure();
    vals.push_back(2);
    vals.push_back(2);
// Assert
    EXPECT_TRUE(_Cone->SetValue(vals));
}

TEST(Epremyan_Norik_Cone, CantSetNegativeValue) {
// Arrange
    ConeFactory* templ = new ConeFactory;
    figure* _Cone;
    std::vector<double> vals;
// Act
    _Cone = templ->createFigure();
    vals.push_back(-2);
    vals.push_back(2);
// Assert
    EXPECT_ANY_THROW(_Cone->SetValue(vals));
}

TEST(Epremyan_Norik_Cone, CanCalculateArea) {
// Arrange
    ConeFactory* templ = new ConeFactory;
    figure* _Cone;
    std::vector<double> vals;
    double forming = sqrt(exp2(2) + exp2(2));
// Act
    _Cone = templ->createFigure();
    vals.push_back(2);
    vals.push_back(2);
    _Cone->SetValue(vals);
// Assert
    EXPECT_DOUBLE_EQ(_Cone->area(), M_PI * 2 *(2+forming));
}
