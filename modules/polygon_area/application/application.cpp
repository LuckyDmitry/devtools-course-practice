// Copyright 2020 Lebedev Alexander

#include <iostream>

#include "include/user_interface.h"

int main(int argc, const char** argv) {
    PolygonUi ui;
    auto output = ui(argc, argv);
    std::cout << output;
    return 0;
}
