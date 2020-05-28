#include "ArithmeticMean.h"


Mean& ArithmeticMean::operator<<(double val){
    add(val);
    return *this;
}

const Mean& ArithmeticMean::operator<<(double val)const{
    std::cout<<"ERROR: cannot add value "<<val<<" to const Arithmetic Mean"<<std::endl;
    return *this;
}

double ArithmeticMean::result()const{
    if(getN()>0)
        return getSum()/getN();
    else 
        return 0;
}

std::string ArithmeticMean::name()const{
    return "Arithmetic";
}