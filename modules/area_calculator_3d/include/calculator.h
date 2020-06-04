// Copyright 2020 Epremyan Norik
#ifndef MODULES_AREA_CALCULATOR_3D_INCLUDE_CALCULATOR_H_
#define MODULES_AREA_CALCULATOR_3D_INCLUDE_CALCULATOR_H_
#include <string>
#include <vector>

// Figures types:
class figure {
 protected:
    std::string name;
 public:
    virtual double area() = 0;
    virtual std::string GetName() = 0;
    virtual bool SetValue(std::vector<double> _vals) = 0;
    virtual std::vector<double>* GetValue() = 0;
};

class cone : public figure {
 public:
    cone();
    std::string GetName();
    bool SetValue(std::vector<double> _vals);
    std::vector<double>* GetValue();
    double area();
 private:
    double Radius;
    double Height;
};

class cube : public figure {
 public:
    cube();
    std::string GetName();
    bool SetValue(std::vector<double> _vals);
    std::vector<double>* GetValue();
    double area();
 private:
    double edge;
};

class cylinder : public figure {
 public:
    cylinder();
    std::string GetName();
    bool SetValue(std::vector<double> _vals);
    std::vector<double>* GetValue();
    double area();
 private:
    double Radius;
    double Height;
};

// Factories
class figureFactory {
 public:
    virtual figure* createFigure() = 0;
    virtual ~figureFactory() {}
};

class ConeFactory : public figureFactory {
 public:
    figure* createFigure();
};

class CubeFactory : public figureFactory {
 public:
    figure* createFigure();
};

class CylinderFactory : public figureFactory {
 public:
    figure* createFigure();
};
#endif  // MODULES_AREA_CALCULATOR_3D_INCLUDE_CALCULATOR_H_
