// Copyright 2020 Lebedev Alexander

#include <stdexcept>
#include <cmath>

#include "include/intersection.h"

namespace internal {
    double getNominator(const Objects3d::Line &line,
                        const Objects3d::Plane &plane) {
        return plane.getD() + plane.getA() * line.getX() +
               plane.getB() * line.getY() + plane.getC() * line.getZ();
    }

    double getDenominator(const Objects3d::Line &line,
                          const Objects3d::Plane &plane) {
        return plane.getA() * line.getM() + plane.getB() * line.getN() +
               plane.getC() * line.getP();
    }
}  // namespace internal

namespace math {
    double globalEpsilon = 1e-9;

    Objects3d::RelativePosition getPosition(const Objects3d::Line &line,
                                            const Objects3d::Plane &plane) {
        auto denominator = internal::getDenominator(line, plane);
        auto nominator   = internal::getNominator(line, plane);

        if (std::fabs(denominator) < globalEpsilon) {
            if (std::fabs(nominator) < globalEpsilon) {
                return Objects3d::RelativePosition::EMBEDDED;
            } else {
                return Objects3d::RelativePosition::PARALLEL;
            }
        } else {
            return Objects3d::RelativePosition::INTERSECT;
        }
    }

    Objects3d::Point intersect(const Objects3d::Line &line,
                               const Objects3d::Plane &plane) {
        auto denominator = internal::getDenominator(line, plane);
        auto nominator   = internal::getNominator(line, plane);

        if (std::fabs(denominator) < globalEpsilon) {
            throw std::runtime_error("Can't be intersected");
        }

        auto t = -nominator / denominator;

        Objects3d::Point result;
        result.x = line.getX() + line.getM() * t;
        result.y = line.getY() + line.getN() * t;
        result.z = line.getZ() + line.getP() * t;

        return result;
    }
}  // namespace math
