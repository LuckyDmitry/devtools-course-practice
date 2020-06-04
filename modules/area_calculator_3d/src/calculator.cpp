// Copyright 2020 Epremyan Norik
#include "include/calculator.h"
#define _USE_MATH_DEFINES
#include <math.h>
#include <string>
#include <vector>

// cone
cone::cone() {
    name = "cone";
    Radius = 1;
    Height = 1;
}
std::string cone::GetName() {
    return this->name;
}
bool cone::SetValue(std::vector<double> _vals) {
    if (_vals.size() < 2) throw "Empty vector";
    double _radius = _vals[0];
    double _height = _vals[1];
    if (_radius <= 0) throw "Radius should be positive";
    if (_height <= 0) throw "Height should be positive";
    this->Height = _height;
    this->Radius = _radius;
    return true;
}
std::vector<double>* cone::GetValue() {
    std::vector<double> *vals = new std::vector<double>;
    vals->push_back(Radius);
    vals->push_back(Height);
    return vals;
}
double cone::area() {
    double rad = this->Radius;
    double Hei = this->Height;
    double forming = sqrt(exp2(rad) + exp2(Hei));
    double _area = M_PI * rad * (rad + forming);
    return _area;
}

// cube
cube::cube() {
    name = "cube";
    edge = 1;
}
std::string cube::GetName() {
    return this->name;
}
bool cube::SetValue(std::vector<double> _vals) {
    if (_vals.size() == 0) throw "Empty vector";
    double _edge = _vals[0];
    if (_edge <= 0) throw "Edge should be positive";
    this->edge = _edge;
    return true;
}
std::vector<double>* cube::GetValue() {
    std::vector<double> *vals = new std::vector<double>;
    vals->push_back(edge);
    return vals;
}
double cube::area() {
    double _area = 6 * edge * edge;
    return _area;
}

// Cylinder

cylinder::cylinder() {
    this->name = "cylinder";
    this->Height = 1;
    this->Radius = 1;
}
std::string cylinder::GetName() {
    return this->name;
}
bool cylinder::SetValue(std::vector<double> _vals) {
    if (_vals.size() < 2) throw "Empty vector";
    double _radius = _vals[0];
    double _height = _vals[1];
    if (_radius <= 0) throw "Radius should be positive";
    if (_height <= 0) throw "Height should be positive";
    this->Height = _height;
    this->Radius = _radius;
    return true;
}
std::vector<double>* cylinder::GetValue() {
    std::vector<double> *vals = new std::vector<double>;
    vals->push_back(Radius);
    vals->push_back(Height);
    return vals;
}

double cylinder::area() {
    double rad = this->Radius;
    double Hei = this->Height;
    double _area = 2 * M_PI * rad * (rad + Hei);
    return _area;
}

// Factories
figure* ConeFactory::createFigure() {
    return new cone;
}

figure* CubeFactory::createFigure() {
    return new cube;
}

figure* CylinderFactory::createFigure() {
    return new cylinder;
}
