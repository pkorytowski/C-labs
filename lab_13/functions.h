#pragma once
#include <cmath>


class Linear{
public:
    Linear()=default;///konstruktor domyslny
    Linear(double,double);///konstruktor przyjmujacy dwa parametry
    double operator()(double) const ;///przeciazony operator ()
private:
    double a;
    double b;
};

class Sqrt{
public:
    Sqrt()=default;///konstruktor domyslny
    double operator()(double) const;///przeciazony operator ()
};

class Sin{
public:
    Sin()=default;///konstruktor domyslny
    Sin(double, double);///konstruktor przyjmujacy dwa parametry
    double operator()(double) const;///przeciazony operator ()
private:
    double a;
    double b;
};


