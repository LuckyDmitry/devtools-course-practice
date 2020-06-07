// Copyright 2020 Lebedev Alexander

#include <stdexcept>
#include <string>
#include <vector>

#include "include/user_interface.h"
#include "include/polygon_engine.h"

auto PolygonUi::operator()(int argc, const char** argv) -> std::string {
    std::string output;

    if (argc == 1) {
        output = help();
    } else {
        try {
            auto points = parseArguments(argc, argv);

            polygon_engine::Polygon polygon(points);
            std::string             result;

                switch (argv[1][0]) {
                    case 'c':
                        result =  std::to_string(polygon.isConnectedness());
                        break;
                    case 'p':
                        result = std::to_string(polygon.getPerimeter());
                        break;
                    case 'a':
                        result = std::to_string(polygon.getArea());
                        break;
                    default:
                        throw std::invalid_argument("Invalid operation type.");
                }

            output = "\nResult: " + result + "\n\n";
        } catch (std::exception &e) {
            output = e.what();
        }
    }
    return output;
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

auto PolygonUi::parseArguments(int argc,
                               const char** argv)
                               -> std::vector<polygon_engine::Point> {
    std::vector<polygon_engine::Point> points;
    if (argc % 2 != 0) {
        throw std::invalid_argument("Invalid params count.");
    }

    for (int i = 2; i < argc; i += 2) {
        polygon_engine::Point p;
        p.x = std::stod(argv[i]);
        p.y = std::stod(argv[i + 1]);
        points.push_back(p);
    }
    return points;
}
