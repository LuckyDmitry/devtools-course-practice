// Copyright 2020 Loogin Mikhail

#ifndef MODULES_LINE_AND_PLANE_INTERSECT_INCLUDE_USER_FRIENDLY_INTERFACE_H_
#define MODULES_LINE_AND_PLANE_INTERSECT_INCLUDE_USER_FRIENDLY_INTERFACE_H_

#include <string>
#include <vector>
#include <utility>

class IntersectUI {
 public:
    std::string operator()(int argc, const char** argv);
 private:
    void help(const char* appname, const char* message = "");
    bool validateNumberOfArguments(int argc, const char** argv);
    std::string message_;
    typedef struct {
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
    } Arguments;
};

#endif  // MODULES_LINE_AND_PLANE_INTERSECT_INCLUDE_USER_FRIENDLY_INTERFACE_H_
