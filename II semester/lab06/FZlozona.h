#pragma once


class FZlozona:public Fun{
public:
    FZlozona()=default;
    
    ///Constructor FZlozona,
    ///it assigns to m_f1 and m_f2 copies of objects 
    FZlozona(Fun* f1, Fun* f2){
        m_f1 = f1->clone();
        m_f2 = f2->clone();
    }
    ~FZlozona(){
        delete m_f1;
        delete m_f2;
    }
    double wartosc(double x)const{
        return m_f2->wartosc(m_f1->wartosc(x));
    }
    
    ///return a copy of FZlozona object including copies of Fun* objects
    Fun* clone()const{
       FZlozona *tmp = new FZlozona(m_f1,m_f2);
       return tmp;
    }
    
private:
    Fun* m_f1;
    Fun* m_f2;
};