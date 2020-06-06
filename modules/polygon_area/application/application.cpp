// Copyright 2020 Lebedev Alexander

#include <iostream>
#include <exception>

#include "include/user_interface.h"

int main(int argc, const char** argv) {
    try {
        PolygonUi ui;
        if (argc == 1) {
            std::cout << ui.help();
        } else {
            std::cout << "\nResult: " << ui(argc, argv) << "\n\n";
        }
    } catch (std::exception &e) {
        std::cerr << e.what();
    }
    return 0;
}
