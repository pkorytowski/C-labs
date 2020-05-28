#include "Fun.h"
#include "Elementarne.h"




Fun* Liniowa::clone()const{
    Liniowa *tmp = new Liniowa;
    tmp->m_a = m_a;
    tmp->m_b = m_b;
    return tmp;
}

Liniowa* Liniowa::a(double a){
    this->m_a=a;
    return this;
}

Liniowa* Liniowa::b(double b){
    this->m_b=b;
    return this;
}

Kwadratowa* Kwadratowa::a(double a){
     this->m_a=a;
     return this;
}

Kwadratowa* Kwadratowa::b(double b){
     this->m_b=b;
     return this;
}

Kwadratowa* Kwadratowa::c(double c){
     this->m_c=c;
     return this;
}


Fun* Kwadratowa::clone()const{
    Kwadratowa *tmp = new Kwadratowa;
    tmp->m_a = m_a;
    tmp->m_b = m_b;
    tmp->m_c = m_c;
    return tmp;
}