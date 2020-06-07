// Copyright 2020 Lebedev Alexander

#ifndef MODULES_POLYGON_AREA_INCLUDE_USER_INTERFACE_H_
#define MODULES_POLYGON_AREA_INCLUDE_USER_INTERFACE_H_
#include <vector>
#include <string>
#include <utility>

#include "include/polygon_engine.h"

class PolygonUi {
    using Point = polygon_engine::Point;

 public:
    PolygonUi() = default;

    PolygonUi(const PolygonUi &other) = default;

    ~PolygonUi() = default;

    auto operator()(int argc, const char** argv) -> std::string;

 private:
    auto help() -> std::string;

    auto parseArguments(int argc, const char** argv) -> std::vector<Point>;
};

#endif  // MODULES_POLYGON_AREA_INCLUDE_USER_INTERFACE_H_
