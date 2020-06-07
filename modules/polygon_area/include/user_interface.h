// Copyright 2020 Lebedev Alexander

#ifndef MODULES_POLYGON_AREA_INCLUDE_USER_INTERFACE_H_
#define MODULES_POLYGON_AREA_INCLUDE_USER_INTERFACE_H_
#include <vector>
#include <string>

#include "include/polygon_engine.h"

class PolygonUi {
 public:
    PolygonUi() = default;

    PolygonUi(const PolygonUi &other) = default;

    ~PolygonUi() = default;

    auto operator()(int argc, const char** argv) -> std::string;

 private:
    auto help() -> std::string;
};

#endif  // MODULES_POLYGON_AREA_INCLUDE_USER_INTERFACE_H_
