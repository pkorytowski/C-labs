#pragma once
#include "Mean.h"



class ArithmeticMean:public Mean{
public:
    ///overridden operator<< adding new val to calculate arithmetic mean
    Mean& operator<<(double val);
    
    ///overridden operator<< prevents adding new val to const object
    const Mean& operator<<(double val)const;
    
    ///overridden method returns calculated arithmetic mean from given values
    double result()const;
    
    ///overridden method returns "Arithmetic"
    std::string name()const;
};