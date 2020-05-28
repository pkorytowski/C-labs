#pragma once
#include "Mean.h"



class HarmonicMean:public Mean{
public:
    ///overridden operator<< adding new val to calculate harmonic mean (1/val)
    Mean& operator<<(double val);
    
    ///overridden operator<< prevents adding new val to const object
    const Mean& operator<<(double val)const;
    
    ///overridden method returns calculated harmonic mean from given values
    double result()const;
    
    ///overridden method returns "Harmonic"
    std::string name()const;
};