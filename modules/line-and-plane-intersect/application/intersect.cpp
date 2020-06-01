// Copyright 2020 Loogin Mikhail

#include <iostream>
#include <string>

#include "include/user_friendly_interface.h"

int main(int argc, const char** argv) {
    IntersectUI app;
    std::string output = app(argc, argv);
    std::cout << output << std::endl;
    return 0;
}
