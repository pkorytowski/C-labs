#pragma once 
#include <iostream>
#include <string>


class Mean{
public:
    ///operator <<(const Mean&) returns value of name() virtual method
    friend std::ostream& operator<<(std::ostream &os, const Mean& m);
    
    ///default constructor sets default values for m_suma=0.0 and m_N=0
    Mean():m_suma(0.0),m_N(0){}
    
    ///virtual destructor of base class does nothing (base class without dynamic allocated variables)
    virtual ~Mean(){};
    
    ///virtual operator<< add new val to calculate mean, returns Mean& for next operations
    virtual  Mean& operator<<(double val)=0;
    
    ///virtual operator<< prevents adding new values to const Mean object 
    virtual const Mean& operator<<(double val)const=0;
    
    ///returns calculated mean
    virtual double result()const=0;
    
    ///resets values to default
    void reset(){
        m_suma=0.0;
        m_N=0;
    };
    
    ///virtual method returns mean type
    virtual std::string name()const=0;
    
    ///private members handler
    void add(double val){
        m_N++;
        m_suma+=val;
    }
    
    ///Getters
    double getSum()const{
        return m_suma;
    }
    double getN()const{
        return m_N;
    }
    
private:
    double m_suma; //sum of indices
    int m_N;    //count of indices
};

