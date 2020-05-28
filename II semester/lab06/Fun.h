#pragma once


class Fun{
    public:
    virtual ~Fun(){}
    
    ///returns value of function for given x
    virtual double wartosc(double x)const=0;
    
    ///creates a copy of Fun object
    virtual Fun* clone()const=0;
};