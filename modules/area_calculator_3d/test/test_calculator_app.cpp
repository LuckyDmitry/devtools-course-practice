// Copyright 2020 Epremyan Norik
#include <gtest/gtest.h>
#define _USE_MATH_DEFINES
#include <math.h>
#include <string>
#include <vector>
#include "include/area_calculator_app.h"

TEST(Epremyan_Norik_Application, CanCreateObject) {
// Arrange
// Act
// Assert
    ASSERT_NO_THROW(area_calculator_app test());
}

TEST(Epremyan_Norik_Application, CanCreateFigureCube) {
// Arrange
    area_calculator_app test;
    std::vector<std::string> data3 = { "cube", "2" };
// Act
// Assert
    EXPECT_TRUE(test.CanCreateFigure(3, data3));
}

TEST(Epremyan_Norik_Application, CanCreateFigureCone) {
// Arrange
    area_calculator_app test;
    std::vector<std::string> data4 = { "cone", "2", "2" };
// Act
// Assert
    EXPECT_TRUE(test.CanCreateFigure(4, data4));
}

TEST(Epremyan_Norik_Application, CanCreateFigureCylinder) {
// Arrange
    area_calculator_app test;
    std::vector<std::string> data4 = { "cylinder", "2", "2" };
// Act
// Assert
    EXPECT_TRUE(test.CanCreateFigure(4, data4));
}

TEST(Epremyan_Norik_Application, CantCreateFigureCube) {
// Arrange
    area_calculator_app test;
    std::vector<std::string> data3 = { "cube", "2" };
// Act
// Assert
    EXPECT_FALSE(test.CanCreateFigure(2, data3));
}

TEST(Epremyan_Norik_Application, CantCreateFigureCylinder) {
// Arrange
    area_calculator_app test;
    std::vector<std::string> data4 = {"cylinder", "2", "2" };
// Act
// Assert
    EXPECT_FALSE(test.CanCreateFigure(3, data4));
}

TEST(Epremyan_Norik_Application, CantCreateFigureCone) {
// Arrange
    area_calculator_app test;
    std::vector<std::string> data4 = {  "cone", "2", "2" };
// Act
// Assert
    EXPECT_FALSE(test.CanCreateFigure(3, data4));
}
TEST(Epremyan_Norik_Application, CantCreateUnknownFigure) {
// Arrange
    area_calculator_app test;
    std::vector<std::string> data4 = {  "sphere", "2", "2" };
// Act
// Assert
    EXPECT_FALSE(test.CanCreateFigure(4, data4));
}
TEST(Epremyan_Norik_Application, CantCreateInOperator) {
// Arrange
    area_calculator_app test;
    const char* arr4[] = { "Program_name", "sphere", "2", "2" };
    const char** data4 = arr4;
// Act
// Assert
    EXPECT_EQ(test(4, data4), "Cant create figure. Invalid arguments.");
}

TEST(Epremyan_Norik_Application, CantCreatePointerUnknownFigure) {
// Arrange
    area_calculator_app test;
    std::vector<std::string> data4 = {"sphere", "2", "2" };
// Act
// Assert
    EXPECT_EQ(test.CreateFigure(data4), nullptr);
}
TEST(Epremyan_Norik_Application, CreateFigurePointerCube) {
// Arrange
    area_calculator_app test;
    std::vector<std::string> data3 = { "cube", "2" };
// Act
// Assert
    EXPECT_EQ(test.CreateFigure(data3)->GetName(), "cube");
}

TEST(Epremyan_Norik_Application, CreateFigurePointerCone) {
// Arrange
    area_calculator_app test;
    std::vector<std::string> data4 = {"cone", "2", "2" };
// Act
// Assert
    EXPECT_EQ(test.CreateFigure(data4)->GetName(), "cone");
}

TEST(Epremyan_Norik_Application, CreateFigurePointerCylinder) {
// Arrange
    area_calculator_app test;
    std::vector<std::string> data4 = { "cylinder", "2", "2" };
// Act
// Assert
    EXPECT_EQ(test.CreateFigure(data4)->GetName(), "cylinder");
}

TEST(Epremyan_Norik_Application, CantCalculateArea) {
// Arrange
    area_calculator_app test;
    const char* arr3[] = { "Program_name", "cubec", "2"};
    const char** data3 = arr3;
// Act
// Assert
    EXPECT_EQ(test(3, data3), "Cant create figure. Invalid arguments.");
}

TEST(Epremyan_Norik_Application, CanCalculateArea) {
// Arrange
    area_calculator_app test;
    const char* arr3[] = { "Program_name", "cube", "2" };
    const char** data3 = arr3;
// Act
// Assert
    EXPECT_EQ(test(3, data3), "Area of Figure cube 24");
}
