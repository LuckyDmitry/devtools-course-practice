// Copyright 2020 Lebedev Alexander

#include <stdexcept>
#include <cmath>

#include "include/math.h"

double globalEpsilon = 1e-9;

namespace internal {
    double getNominator(const Line &line, const Plane &plane) {
        return plane.getD() + plane.getA() * line.getX() +
               plane.getB() * line.getY() + plane.getC() * line.getZ();
    }

    double getDenominator(const Line &line, const Plane &plane) {
        return plane.getA() * line.getM() + plane.getB() * line.getN() +
               plane.getC() * line.getP();
    }
} // namespace internal

RelativePosition getRelativePosition(const Line &line, const Plane &plane) {
    auto denominator = internal::getDenominator(line, plane);
    auto nominator = internal::getNominator(line, plane);

    if (std::fabs(denominator) < globalEpsilon) {
        if (std::fabs(nominator) < globalEpsilon) {
            return RelativePosition::EMBEDDED;
        } else {
            return RelativePosition::PARALLEL;
        }
    } else {
        return RelativePosition::INTERSECT;
    }
}

Point intersect(const Line &line, const Plane &plane) {
    auto denominator = internal::getDenominator(line, plane);
    auto nominator = internal::getNominator(line, plane);

    if (std::fabs(denominator) < globalEpsilon) {
        throw std::runtime_error("Can't be intersected. Check relative pos");
    }

    auto t = -nominator / denominator;

    Point result;
    result.x = line.getX() + line.getM() * t;
    result.y = line.getY() + line.getN() * t;
    result.z = line.getZ() + line.getP() * t;

    return result;
}
