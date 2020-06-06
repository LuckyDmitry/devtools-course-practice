// Copyright 2020 Lebedev Alexander & Loogin

#ifndef MODULES_LINE_AND_PLANE_INTERSECT_INCLUDE_OBJECTS_H_
#define MODULES_LINE_AND_PLANE_INTERSECT_INCLUDE_OBJECTS_H_

namespace Objects3d {
    enum class RelativePosition {
        PARALLEL,
        EMBEDDED,
        INTERSECT
    };

struct Point {
 public:
    Point() = default;

    Point(const Point &other) = default;

    Point(Point &&other) = default;

    explicit Point(double n_x, double n_y, double n_z);

    ~Point() = default;

    double x;
    double y;
    double z;
};

class Line {
 public:
    Line() = default;

    explicit Line(double x, double y, double z,
                  double m, double n, double p);

    explicit Line(Point m0, Point m1);

    Line(const Line &other) = default;

    Line(Line &&other) = default;

    ~Line() = default;

    // Getters
    double getX() const;

    double getY() const;

    double getZ() const;

    double getM() const;

    double getN() const;

    double getP() const;

    // Setters
    void setX(double x);

    void setY(double y);

    void setZ(double z);

    void setM(double m);

    void setN(double n);

    void setP(double p);

 private:
    double m_x;
    double m_y;
    double m_z;
    double m_m;
    double m_n;
    double m_p;
};

class Plane {
 public:
    Plane() = default;

    explicit Plane(double a, double b, double c, double d);

    Plane(const Plane &other) = default;

    Plane(Plane &&other) = default;

    ~Plane() = default;

    // Getters
    double getA() const;

    double getB() const;

    double getC() const;

    double getD() const;

    // Setters
    void setA(double a);

    void setB(double b);

    void setC(double c);

    void setD(double d);

 private:
    double m_a;
    double m_b;
    double m_c;
    double m_d;
};
}  // namespace Objects3d

#endif  // MODULES_LINE_AND_PLANE_INTERSECT_INCLUDE_OBJECTS_H_
