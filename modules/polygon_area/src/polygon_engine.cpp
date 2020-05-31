// Copyright 2020 Loogin Mikhail
#include "include/polygon_engine.h"
#include <algorithm>
#include <vector>

polygon_engine::Polygon::Polygon(std::vector<Point> points) {
    tops = points;
    if (!points.empty()) tops.push_back(points[0]);
}

static inline int triangleArea(
    polygon_engine::Point a,
    polygon_engine::Point b,
    polygon_engine::Point c) {
    return (b.x - a.x) * (c.y - a.y) - (b.y - a.y) * (c.x - a.x);
}

static inline bool intersect(int a, int b, int c, int d) {
    if (a > b)  std::swap(a, b);
    if (c > d)  std::swap(c, d);
    return std::max(a, c) < std::min(b, d);
}

static inline bool isIntersect(
    polygon_engine::Point a,
    polygon_engine::Point b,
    polygon_engine::Point c,
    polygon_engine::Point d) {
    return intersect(a.x, b.x, c.x, d.x)
        && intersect(a.y, b.y, c.y, d.y)
        && triangleArea(a, b, c) * triangleArea(a, b, d) <= 0
        && triangleArea(c, d, a) * triangleArea(c, d, b) <= 0;
}

bool polygon_engine::Polygon::isConnectedness() {
    const int size = tops.size();
    if (size < 4) throw ("It's not a polygon");
    for (int i = 0; i < size - 2; i++) {
        for (int j = i + 1; j < size - 1; j++) {
            std::vector<Point> cp = {tops[i], tops[i+1], tops[j], tops[j + 1]};
            if (isIntersect(cp[0], cp[1], cp[2], cp[3])) return false;
        }
    }

    return true;
}

double polygon_engine::Polygon::getPerimeter() {
    if (!isConnectedness()) throw ("Not connectedness");
    double perimeter = 0.;
    const int size = tops.size();
    for (int i = 0; i < size - 1; i++) {
        perimeter += sqrt(
        (tops[i].x - tops[i + 1].x) * (tops[i].x - tops[i + 1].x)
        + (tops[i].y - tops[i + 1].y) * (tops[i].y - tops[i + 1].y));
    }
    return perimeter;
}

double polygon_engine::Polygon::getArea() {
    if (!isConnectedness()) throw ("Not connectedness");
    double area = 0.;
    if (tops.size() > 2) {
        int size = tops.size();
        for (int i = 0; i < size - 1; i++) {
            area += tops[i].x * tops[i + 1].y;
            area -= tops[i + 1].x * tops[i].y;
        }
    }
    return abs(area) * 0.5;
}
