// Copyright 2020 Epremyan Norik
#ifndef MODULES_AREA_CALCULATOR_3D_INCLUDE_CALCULATOR_H_
#define MODULES_AREA_CALCULATOR_3D_INCLUDE_CALCULATOR_H_
#include <string>
#include <vector>

// Figures types:
class figure {
 public:
    virtual double area() = 0;
    virtual void SetValue(std::vector<double> _vals) = 0;
    virtual std::vector<double>* GetValue() = 0;
};

class cone : public figure {
 public:
    cone();
    void SetValue(std::vector<double> _vals);
    std::vector<double>* GetValue();
    double area();
 private:
    double Radius;
    double Height;
};

class cube : public figure {
 public:
    cube();
    void SetValue(std::vector<double> _vals);
    std::vector<double>* GetValue();
    double area();
 private:
    double edge;
};

class cylinder : public figure {
 public:
    cylinder();
    void SetValue(std::vector<double> _vals);
    std::vector<double>* GetValue();
    double area();
 private:
    double Radius;
    double Height;
};

// Factories
class Factory {
 public:
    static figure* Factory::create(std::string name);
};
#endif  // MODULES_AREA_CALCULATOR_3D_INCLUDE_CALCULATOR_H_
