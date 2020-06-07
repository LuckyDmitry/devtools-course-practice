// Copyright 2020 Epremyan Norik
#include "include/area_calculator_app.h"
#define _USE_MATH_DEFINES
#include <string>
#include <vector>
#include <sstream>

std::string area_calculator_app::operator()(int argc, const char** argv) {
    std::vector<std::string> s_vec;
    for (int i = 1; i < argc; i++) {
        s_vec.push_back(argv[i]);
    }
    if (!(CanCreateFigure(argc, s_vec))) {
        return "Cant create figure. Invalid arguments.";
    }
    figure* _figure = CreateFigure(s_vec);
    double area = _figure->area();
    std::ostringstream strs;
    strs << "Area of Figure " << s_vec[0] << " " << area;;
    return strs.str();
}
bool area_calculator_app::isValidArguments(
        int argc,
        std::vector<std::string> argv) {
    if (argc < 3) return false;  // Not enough arguments
    if (argv[0] == "cube") {
        return true;
    }
    if (argv[0] == "cylinder") {
        if (argc < 4) return false;  // Not enough arguments
        return true;
    }
    if (argv[0] == "cone") {
        if (argc < 4) return false;  // Not enough arguments
        return true;
    }
    return false;  // lib don't know this figure
}
figure* area_calculator_app::CreateFigure(std::vector<std::string> argv) {
    figure* _figure = nullptr;
    std::vector<double> vec;
    _figure = Factory::create(argv[0]);
    for (unsigned int i = 1; i < argv.size(); i++) {
        vec.push_back(std::stod(argv[i].c_str()));
    }
    _figure->SetValue(vec);
    return _figure;
}
