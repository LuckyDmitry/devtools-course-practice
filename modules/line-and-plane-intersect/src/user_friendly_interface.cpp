// Copyright 2020 Loogin Mikhail

#include "../include/user_friendly_interface.h"
#include "../include/objects.h"
#include "../include/intersection.h"

#include <string>

using std::string;
using Objects3d::RelativePosition;

void IntersectUI::help(const char* appname, const char* message) {
    message_ =
        std::string(message) +
          "This is a line-pline intersect checker application.\n\n" +
          "Please provide arguments in the following format:\n\n"+

          "  $ " + appname + " <x1_line> <y1_line> <z1_line>" +
          "<x2_line> <y2_line> <z2_line> <A_pline> <B_pline>" +
          "<C_pline> <D_pline>\n\n" +

          "Where all arguments are double-precision numbers\n";
}

bool IntersectUI::validateNumberOfArguments(int argc, const char** argv) {
    if (argc == 1) {
        help(argv[0]);
        return false;
    } else if (argc != 11) {
        help(argv[0], "ERROR: Should be 10 arguments.\n\n");
        return false;
    }
    return true;
}

double parseDouble(const char* arg) {
    char* end;
    double value = strtod(arg, &end);

    if (end[0]) {
        throw std::string("Wrong number format!");
    }

    return value;
}

string IntersectUI::operator()(int argc, const char** argv) {
    Arguments args;

    if (!validateNumberOfArguments(argc, argv)) {
        return message_;
    }
    try {
        args.lx1      = parseDouble(argv[1]);
        args.ly1 = parseDouble(argv[2]);
        args.lz1      = parseDouble(argv[3]);
        args.lx2 = parseDouble(argv[4]);
        args.ly2    = parseDouble(argv[5]);
        args.lz2      = parseDouble(argv[6]);
        args.a = parseDouble(argv[7]);
        args.b      = parseDouble(argv[8]);
        args.c = parseDouble(argv[9]);
        args.d    = parseDouble(argv[10]);
    }
    catch(string& str) {
        return str;
    }

    auto line = Objects3d::Line(args.lx1, args.ly1, args.lz1,
        args.lx2, args.ly2, args.lz2);
    auto plane = Objects3d::Plane(args.a, args.b, args.c, args.d);

    auto position = math::getPosition(line, plane);
    string result = "Line and plane ";

    switch (position) {
        case RelativePosition::EMBEDDED: {result += "embedded"; break;}
        case RelativePosition::PARALLEL: {result += "parallel"; break;}
        case RelativePosition::INTERSECT: result += "intersect";
    }

    return result;
}
