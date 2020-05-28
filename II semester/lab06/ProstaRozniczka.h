#pragma once


class ProstaRozniczka{
public:
    ///ProstaRozniczka constructor, sets step from given value
    ProstaRozniczka(double step):m_step(step){}
    
    ///returns pointer to ProstaRozniczka object and sets Fun pointer
    ///It doesn't make a copy of Fun object, it only assigns a pointer
    ProstaRozniczka* z(Fun *f){
        m_f = f;
        return this;
    }
    
    double w(double x){
        double wynik = (m_f->wartosc(x+m_step)-m_f->wartosc(x-m_step))/(2*m_step);
        return wynik;
    }
    
private:
    double m_step;
    Fun* m_f;
};