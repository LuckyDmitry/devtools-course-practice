// Copyright 2020 Epremyan Norik

#include <iostream>
#include <string>
#include "include/area_calculator_app.h"

int main(int argc, const char** argv) {
    area_calculator_app app;
    std::string out1 = app(argc, argv);
    std::cout << out1;
    return 0;
}
