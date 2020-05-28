// Copyright 2020 Lebedev Alexander

#ifndef MODULES_LINE_AND_PLANE_INTERSECT_INCLUDE_MATH_H_
#define MODULES_LINE_AND_PLANE_INTERSECT_INCLUDE_MATH_H_

#include "include/objects.h"

RelativePosition getRelativePosition(const Line &line, const Plane &plane);

Point intersect(const Line &line, const Plane &plane);

#endif  // MODULES_LINE_AND_PLANE_INTERSECT_INCLUDE_MATH_H_
