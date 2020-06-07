// Copyright 2020 Lebedev Alexander

#include <stdexcept>
#include <string>
#include <iostream>

#include "include/user_interface.h"
#include "include/polygon_engine.h"

auto PolygonUi::operator()(int argc, const char** argv) -> int {
    if (argc == 1) {
        std::cout << help();
        return 0;
    }
    try {
        parseArguments(argc, argv);

        polygon_engine::Polygon polygon(points);
        std::string             result;

        switch (operation) {
            case polygon_engine::Operation::CONNECTEDNESS:
                result =  std::to_string(polygon.isConnectedness());
                break;
            case polygon_engine::Operation::PERIMETER:
                result = std::to_string(polygon.getPerimeter());
                break;
            case polygon_engine::Operation::AREA:
                result = std::to_string(polygon.getArea());
                break;
            }

        std::cout << "\nResult: " << result << "\n\n";
    } catch (std::exception &e) {
        std::cerr << e.what();
        return 1;
    }
    return 0;
}

auto PolygonUi::help() -> std::string {
    return std::string("Welcom to polygon area calculator!\n\n") +
            "Using this app you can solve three operations with polygon:\n" +
            "    Connectedness\n" +
            "    Perimeter\n" +
            "    Area\n\n" +
            "To run app simply use comand line arguments by the same way" +
            " as shown below:\n" +
            "<operation> <x1> <y1> <x2> <y2> <x3> <y3> <x4> <y4> and so on\n" +
            "The number of points should be not less then 4.\n\n";
}

void PolygonUi::parseArguments(int argc, const char** argv) {
    if (argc % 2 != 0) {
        throw std::invalid_argument("Invalid params count.");
    }

    switch (argv[1][0]) {
    case 'c':
        operation = polygon_engine::Operation::CONNECTEDNESS;
        break;
    case 'p':
        operation = polygon_engine::Operation::PERIMETER;
        break;
    case 'a':
        operation = polygon_engine::Operation::AREA;
        break;
    default:
        throw std::invalid_argument("Invalid operation type.");
    }

    for (int i = 2; i < argc; i += 2) {
        points.push_back({std::stod(argv[i]), std::stod(argv[i + 1])});
    }
}
