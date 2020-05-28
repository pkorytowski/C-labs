#pragma once
#include <cmath>

class Liniowa: public Fun{
public:
    ///Named constructor, returns a pointer to Liniowa
    static Liniowa* utworz(){
        return new Liniowa;
    }
    double wartosc(double x)const{
        return m_a*x+m_b;
    }
    Fun* clone()const;
    
    ///sets coefficient a of linear function
    Liniowa* a(double a);
    
    ///sets coefficient b of linear function
    Liniowa* b(double b);
    
private:
    Liniowa()=default;
    double m_a,m_b;
};


class Sinus: public Fun{
    public:
    Fun* clone()const{
        return new Sinus;
    }
  
    double wartosc(double x)const{
        return sin(x);
    }
};


class Kwadratowa: public Fun{
    public:
    ///Named constructor, returns a pointer to Kwadratowa
    static Kwadratowa* utworz(){
        return new Kwadratowa;
    }
  
    double wartosc(double x)const{
        return m_a*x*x+m_b*x+m_c;
    }
  
    Fun* clone()const;
    
    ///sets coefficient a of quadratic function
    Kwadratowa* a(double a);
    
    ///sets coefficient b of quadratic function
    Kwadratowa* b(double b);
    
    ///sets coefficient c of quadratic function
    Kwadratowa* c(double c);
  
private:
    Kwadratowa()=default;
    double m_a,m_b,m_c;
};





