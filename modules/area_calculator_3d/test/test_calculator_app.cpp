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

TEST(Epremyan_Norik_Application, CantCreateInOperator) {
// Arrange
    area_calculator_app test;
    const char* arr4[] = { "Program_name", "sphere", "2", "2" };
    const char** data4 = arr4;
// Act
// Assert
    EXPECT_ANY_THROW(test(4, data4));
}

TEST(Epremyan_Norik_Application, CantCalculateArea) {
// Arrange
    area_calculator_app test;
    const char* arr3[] = { "Program_name", "cubec", "2"};
    const char** data3 = arr3;
// Act
// Assert
    ASSERT_ANY_THROW(test(3, data3));
}

TEST(Epremyan_Norik_Application, CanCalculateCubeArea) {
// Arrange
    area_calculator_app test;
    const char* arr3[] = { "Program_name", "cube", "2" };
    const char** data3 = arr3;
// Act
// Assert
    EXPECT_EQ(test(3, data3), "Area of Figure cube 24");
}

TEST(Epremyan_Norik_Application, CanCalculateConeArea) {
// Arrange
    area_calculator_app test;
    const char* arr4[] = { "Program_name", "cone", "2", "2" };
    const char** data4 = arr4;
// Act
// Assert
    EXPECT_EQ(test(4, data4), "Area of Figure cone 30.3379");
}

TEST(Epremyan_Norik_Application, CanCalculateCylinderArea) {
// Arrange
    area_calculator_app test;
    const char* arr4[] = { "Program_name", "cylinder", "2", "2" };
    const char** data4 = arr4;
// Act
// Assert
    EXPECT_EQ(test(4, data4), "Area of Figure cylinder 50.2655");
}

TEST(Epremyan_Norik_Application, CantCalculateCylinderArea) {
// Arrange
    area_calculator_app test;
    const char* arr4[] = { "Program_name", "cylinder", "2"};
    const char** data4 = arr4;
// Act
// Assert
	EXPECT_ANY_THROW(test(3, data4));
}

TEST(Epremyan_Norik_Application, CantCalculateConeArea) {
// Arrange
    area_calculator_app test;
    const char* arr4[] = { "Program_name", "cone", "2" };
    const char** data4 = arr4;
// Act
// Assert
	EXPECT_ANY_THROW(test(3, data4));
}

TEST(Epremyan_Norik_Application, CantCalculateCubeArea) {
// Arrange
    area_calculator_app test;
    const char* arr4[] = { "Program_name", "cube"};
    const char** data4 = arr4;
// Act
// Assert
    EXPECT_ANY_THROW(test(2, data4));
}
