// Copyright 2020 Lebedev Alexander

#ifndef MODULES_POLYGON_AREA_INCLUDE_USER_INTERFACE_H_
#define MODULES_POLYGON_AREA_INCLUDE_USER_INTERFACE_H_
#include <vector>
#include <string>
#include <utility>

#include "include/polygon_engine.h"

class PolygonUi {
 public:
    PolygonUi() = default;

    PolygonUi(const PolygonUi &other) = default;

    ~PolygonUi() = default;

    auto operator()(int argc, const char** argv) -> int;

    auto help() -> std::string;

 private:
    void parseArguments(int argc, const char** argv);

    std::vector<polygon_engine::Point> points;
    polygon_engine::Operation          operation;
};

#endif  // MODULES_POLYGON_AREA_INCLUDE_USER_INTERFACE_H_
