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
    strs << "Area of Figure ";
    strs << s_vec[0];
    strs << " ";
    strs << area;
    return strs.str();
}
bool area_calculator_app::CanCreateFigure(
        int argc,
        std::vector<std::string> argv) {
    if (argc < 3) return false;  // Not enough arguments
    if (argv[0] == "cube") {
        return true;
    } else {
        if (argv[0] == "cylinder") {
            if (argc < 4) return false;  // Not enough arguments
            return true;
        } else {
            if (argv[0] == "cone") {
                if (argc < 4) return false;  // Not enough arguments
                return true;
            } else {
                return false;  // lib don't know this figure
            }
        }
    }
}
figure* area_calculator_app::CreateFigure(std::vector<std::string> argv) {
    figure* _figure = nullptr;
    std::vector<double> vec;
    if (argv[0] == "cube") {
        Factory* FactoryCube = new Factory();
        _figure = FactoryCube->create("cube");
        vec.push_back(std::stod(argv[1].c_str()));
        _figure->SetValue(vec);
    } else {
        if (argv[0] == "cylinder") {
            Factory* FactoryCube = new Factory();
            _figure = FactoryCube->create("cylinder");
            vec.push_back(std::stod(argv[1].c_str()));
            vec.push_back(std::stod(argv[2].c_str()));
            _figure->SetValue(vec);
        } else {
            if (argv[0] == "cone") {
                Factory* FactoryCube = new Factory();
                _figure = FactoryCube->create("cone");
                vec.push_back(std::stod(argv[1].c_str()));
                vec.push_back(std::stod(argv[2].c_str()));
                _figure->SetValue(vec);
            }
        }
    }
    return _figure;
}
