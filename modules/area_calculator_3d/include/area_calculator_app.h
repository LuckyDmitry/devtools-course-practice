// Copyright 2020 Epremyan Norik
#ifndef MODULES_AREA_CALCULATOR_3D_INCLUDE_AREA_CALCULATOR_APP_H_
#define MODULES_AREA_CALCULATOR_3D_INCLUDE_AREA_CALCULATOR_APP_H_
#include <include/calculator.h>
#include <string>
#include <iostream>
#include <vector>

class area_calculator_app {
 public:
    std::string operator()(int argc, const char** argv);
    bool CanCreateFigure(int argc, std::vector<std::string> argv);
    figure* CreateFigure(std::vector<std::string> argv);
};
#endif  // MODULES_AREA_CALCULATOR_3D_INCLUDE_AREA_CALCULATOR_APP_H_
