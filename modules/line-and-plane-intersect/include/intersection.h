// Copyright 2020 Lebedev Alexander & Loogin Mikhail

#ifndef MODULES_LINE_AND_PLANE_INTERSECT_INCLUDE_INTERSECTION_H_
#define MODULES_LINE_AND_PLANE_INTERSECT_INCLUDE_INTERSECTION_H_

#include "include/objects.h"

namespace math {
    Objects3d::RelativePosition getPosition(const Objects3d::Line &line,
                                            const Objects3d::Plane &plane);

    Objects3d::Point intersect(const Objects3d::Line &line,
                               const Objects3d::Plane &plane);
}  // namespace math

#endif  // MODULES_LINE_AND_PLANE_INTERSECT_INCLUDE_INTERSECTION_H_
