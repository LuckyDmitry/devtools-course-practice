// Copyright 2020 Loogin Mikhail

#include <gtest/gtest.h>

#include <utility>
#include <vector>
#include "include/polygon_engine.h"

using Point = polygon_engine::Point;
using Polygon = polygon_engine::Polygon;

/*
    1. throw_in_isConnectedness_when_tops_count_less_3
    2. throw_in_getPerimeter_when_tops_count_less_3
    3. throw_in_getArea_when_tops_count_less_3
    4. check_isConnectedness_when_is_intersect
    5. throw_when_is_intersect
    6. check_isConnectedness_when_is_not_intersect
    7. check_perimeter_for_from_3_to_100_tops_polygon
    8. check_area_for_from_3_to_100_tops_polygon
*/

TEST(polygon, throw_in_isConnectedness_when_tops_count_less_3) {
    // Arrange
    std::vector<Point> points = {{0, 0}, {1, 0}, {0, 1}};

    // Assert & Act
    while (points.size() > 0) {
        points.pop_back();
        auto p = Polygon(points);
        ASSERT_ANY_THROW(p.isConnectedness());
    }
}

TEST(polygon, throw_in_getPerimeter_when_tops_count_less_3) {
    // Arrange
    std::vector<Point> points = { {0, 0}, {1, 0}, {0, 1} };

    // Assert & Act
    while (points.size() > 0) {
        points.pop_back();
        auto p = Polygon(points);
        ASSERT_ANY_THROW(p.getPerimeter());
    }
}

TEST(polygon, throw_in_getArea_when_tops_count_less_3) {
    // Arrange
    std::vector<Point> points = { {0, 0}, {1, 0}, {0, 1} };

    // Assert & Act
    while (points.size() > 0) {
        points.pop_back();
        auto p = Polygon(points);
        ASSERT_ANY_THROW(p.getArea());
    }
}

TEST(polygon, check_connectedness_when_is_intersect) {
    // Arrange
    std::vector<Point> points = { {0, 0}, {1, 1}, {1, 0}, {0, 1} };
    auto p = Polygon(points);
    // Assert & Act
    EXPECT_FALSE(p.isConnectedness());
}

TEST(polygon, throw_when_is_intersect) {
    // Arrange
    std::vector<Point> points = { {0, 0}, {1, 1}, {1, 0}, {0, 1} };
    auto p = Polygon(points);
    // Assert & Act
    ASSERT_ANY_THROW(p.getPerimeter());
    ASSERT_ANY_THROW(p.getArea());
}

TEST(polygon, check_isConnectedness_when_is_not_intersect) {
    // Arrange
    std::vector<Point> points = { {0, 0}, {1, 0}, {1, 1}, {0, 1} };
    auto p = Polygon(points);
    // Assert & Act
    EXPECT_TRUE(p.isConnectedness());
}

TEST(polygon, check_perimeter_for_from_3_to_100_tops_polygon) {
    // Arrange
    std::vector<Point> points = { {0, 0}, {0, 1}, {1, 1} };

    // Assert & Act
    for (auto h = 1.; points.size() < 100; h++) {
        points.push_back({h, 0});
        auto p = Polygon(points);
        EXPECT_EQ(4 * h, p.getPerimeter());
        points.pop_back();
        points.push_back({h, points[points.size() - 1].y + 1});
        points.push_back({ h + 1, points[points.size() - 1].y});
    }
}

TEST(polygon, check_area_for_from_3_to_100_tops_polygon) {
    // Arrange
    std::vector<Point> points = { {0, 0}, {0, 1}, {1, 2} };

    // Assert & Act
    for (auto h = 1.; points.size() < 100; h++) {
        points.push_back({ h, 0 });
        auto p = Polygon(points);
        EXPECT_EQ(1.5 * h, p.getArea());
        points.pop_back();
        points.push_back({ h + 1, points[points.size() - 1].y == 1.
            ? 2. : 1.});
    }
}
