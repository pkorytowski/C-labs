#pragma once
#include <iostream>
class Fraction{
public:
    Fraction();
    Fraction(int,int);
    void simplify();
    
    operator double();
    Fraction& operator=(const Fraction&);
    Fraction& operator+=(int);
    Fraction operator-();
    
    int getL()const;
    int getM()const;    
private:
    int _l;
    int _m;
};


std::ostream& operator<<(std::ostream&, const Fraction&);
Fraction operator+(const Fraction&,const Fraction&);
Fraction operator*(const Fraction&,const Fraction&);
Fraction operator*(int,const Fraction&);
