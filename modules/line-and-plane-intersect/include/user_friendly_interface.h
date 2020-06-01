// Copyright 2020 Loogin Mikhail

#ifndef MODULES_LINE_AND_PLANE_INTERSECT_INCLUDE_USER_FRIENDLY_INTERFACE_H_
#define MODULES_LINE_AND_PLANE_INTERSECT_INCLUDE_USER_FRIENDLY_INTERFACE_H_

#include <string>

class IntersectUI {
 public:
    IntersectUI() = default;
    std::string operator()(int argc, const char** argv);
 private:
    void help(const char* appname, const char* message = "");
    bool validateNumberOfArguments(int argc, const char** argv);
    std::string message_;
    using Arguments = struct {
        double lx1;
        double ly1;
        double lz1;
        double lx2;
        double ly2;
        double lz2;
        double a;
        double b;
        double c;
        double d;
    };
};

#endif  // MODULES_LINE_AND_PLANE_INTERSECT_INCLUDE_USER_FRIENDLY_INTERFACE_H_
