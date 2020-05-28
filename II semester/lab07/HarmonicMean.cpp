#include "HarmonicMean.h"


Mean& HarmonicMean::operator<<(double val){
    if(val!=0){
       add(1/val);
    }
    return *this;
}

const Mean& HarmonicMean::operator<<(double val)const{
    std::cout<<"ERROR: cannot add value "<<val<<" to const Harmonic Mean"<<std::endl;
    return *this;
}

double HarmonicMean::result()const{
    if(getSum()!=0)
        return getN()/getSum();
    else 
        return 0;
}

std::string HarmonicMean::name()const{
    return "Harmonic";
}