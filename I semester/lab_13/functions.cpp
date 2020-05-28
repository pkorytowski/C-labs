#include "functions.h"


Linear::Linear(double x,double y):a(x),b(y){}
double Linear::operator()(double x) const {
    return (a*x+b);
}

double Sqrt::operator()(double x) const{
    return sqrt(x);
}
Sin::Sin(double x, double y):a(x),b(y){}

double Sin::operator()(double x) const {
    return sin(a*x+b);
}

