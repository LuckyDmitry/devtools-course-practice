// Copyright 2020 Epremyan Norik
#include "include/area_calculator_app.h"
#define _USE_MATH_DEFINES
#include <string>
#include <vector>
#include <sstream>

std::string area_calculator_app::operator()(int argc, const char** argv) {
    std::vector<std::string> s_vec;
    std::string err = "Cant create figure. Invalid arguments.";
    figure* _figure = nullptr;;
    if (argc < 2) return err;
    for (int i = 1; i < argc; i++) {
        s_vec.push_back(argv[i]);
    }
    try {
        _figure = parseArguments(s_vec);
    }
    catch(char* str) {
        return err;
    }
    if (_figure == nullptr) return err;
    double area = _figure->area();
    std::ostringstream strs;
    strs << "Area of Figure " << s_vec[0] << " " << area;;
    return strs.str();
}
figure* area_calculator_app::parseArguments(std::vector<std::string> argv) {
    figure* _figure = nullptr;
    std::vector<double> vec;
    _figure = Factory::create(argv[0]);
    if (_figure == nullptr) throw "invalid figure name";
    for (unsigned int i = 1; i < argv.size(); i++) {
        vec.push_back(std::stod(argv[i].c_str()));
    }
    _figure->SetValue(vec);
    return _figure;
}
