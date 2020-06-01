// Copyright 2020 Loogin Mikhail

#include <gtest/gtest.h>

#include <string>
#include <vector>
#include <algorithm>
#include <functional>
#include <iterator>

#include "include/user_friendly_interface.h"

using ::testing::internal::RE;
using std::vector;
using std::string;

class intersectUI : public ::testing::Test {
 protected:
    // virtual void SetUp() {}

    void Act(vector<string> args_) {
        vector<const char*> options;

        options.push_back("appname");
        for (size_t i = 0; i < args_.size(); ++i) {
            options.push_back(args_[i].c_str());
        }

        const char** argv = &options.front();
        int argc = static_cast<int>(args_.size()) + 1;

        output_ = app_(argc, argv);
    }

    void Assert(std::string expected) {
        EXPECT_TRUE(RE::PartialMatch(output_, RE(expected)));
    }
 private:
    IntersectUI app_;
    string output_;
};

TEST_F(intersectUI, Do_Print_Help_Without_Arguments) {
    // Arrange
    vector<string> args = {};

    // Act
    Act(args);

    // Assert
    Assert("This is a line-pline intersect checker application\\..*");
}

TEST_F(intersectUI, Is_Checking_Number_Of_Arguments) {
    // Arrange
    vector<string> args = {"1", "2"};

    // Act
    Act(args);

    // Assert
    Assert("ERROR: Should be 10 arguments\\..*");
}

TEST_F(intersectUI, Can_Detect_Wrong_Number_Format) {
    // Arrange
    vector<string> args = {"1", "pi", "2", "4", "+", "1",
        "pi", "2", "4", "+" };

    // Act
    Act(args);

    // Assert
    Assert("Wrong number format!.*");
}

TEST_F(intersectUI, Can_Add_Params) {
    // Arrange
    vector<string> args = {"2.", "-5.", "4.", "1.", "3.", "2.",
        "7.", "-5.", "2.", "19." };

    // Act
    Act(args);

    // Assert
    Assert("Line and plane intersect");
}

TEST_F(intersectUI, Can_Check_Relative_Position_Parallel_Line_And_Plane) {
    // Arrange
    vector<string> args = {"-2.", "2.", "3.", "1.", "-5.", "4.",
        "6.", "2.", "1.", "7." };

    // Act
    Act(args);

    // Assert
    Assert("Line and plane parallel");
}

TEST_F(intersectUI, Can_Check_Relative_Position_Embedded_Line_And_Plane) {
    // Arrange
    vector<string> args = {"1.", "-5.", "8.", "2.", "-5.", "-1.",
        "2.", "1.", "-1.", "11." };

    // Act
    Act(args);

    // Assert
    Assert("Line and plane embedded");
}

TEST_F(intersectUI, Can_Check_Relative_Position_Intersect_Line_And_Plane) {
    // Arrange
    vector<string> args = { "2.", "-5.", "4.", "1.", "3.", "2.",
        "7.", "-5.", "2.", "19." };

    // Act
    Act(args);

    // Assert
    Assert("Line and plane intersect");
}
