// Copyright 2020 Dobrohotov Vitaly

#ifndef MODULES_POLYGON_AREA_INCLUDE_POLYGON_ENGINE_H_
#define MODULES_POLYGON_AREA_INCLUDE_POLYGON_ENGINE_H_
#include <vector>

namespace polygon_engine {

struct Point {
    double x;
    double y;
};

class Polygon {
 public:
    Polygon() = default;

    Polygon(const Polygon& other) = default;

    Polygon(Polygon&& other) = default;

    explicit Polygon(std::vector<Point> points);

    bool isConnectedness();

    double getPerimeter();

    double getArea();

 private:
    std::vector<Point> tops;
};

}  // namespace polygon_engine


#endif  // MODULES_POLYGON_AREA_INCLUDE_POLYGON_ENGINE_H_
