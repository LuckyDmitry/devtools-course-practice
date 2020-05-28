// Copyright 2020 Lebedev Alexander

#include "include/objects.h"

Point::Point(double n_x, double n_y, double n_z) 
        : x(n_x), y(n_y), z(n_z) {
    // Empty constructor
}

Line::Line(double x, double y, double z, double m, double n, double p) 
        : m_x(x), m_y(y), m_z(z), m_m(m), m_n(n), m_p(p) {
    // Empty constructor
}

Line::Line(Point m0, Point m1)
        : m_x(m0.x), m_y(m0.y), m_z(m0.z),
          m_m(m1.x - m0.x),
          m_n(m1.y - m0.y),
          m_p(m1.z - m0.z) {
    // Empty constructor
}

double Line::getX() const {
    return m_x;
}

double Line::getY() const {
    return m_y;
}

double Line::getZ() const {
    return m_z;
}

double Line::getM() const {
    return m_m;
}

double Line::getN() const {
    return m_n;
}

double Line::getP() const {
    return m_p;
}

void Line::setX(double x) {
    m_x = x;
}

void Line::setY(double y) {
    m_y = y;
}

void Line::setZ(double z) {
    m_z = z;
}

void Line::setM(double m) {
    m_m = m;
}

void Line::setN(double n) {
    m_n = n;
}

void Line::setP(double p) {
    m_p = p;
}

Plane::Plane(double A, double B, double C, double D)
        : m_A(A), m_B(B), m_C(C), m_D(D) {

}

double Plane::getA() const {
    return m_A;
}

double Plane::getB() const {
    return m_B;
}

double Plane::getC() const {
    return m_C;
}

double Plane::getD() const {
    return m_D;
}

// Setters
void Plane::setA(double A) {
    m_A = A;
}

void Plane::setB(double B) {
    m_B = B;
}

void Plane::setC(double C) {
    m_C = C;
}

void Plane::setD(double D) {
    m_D = D;
}
