#include "LicznikPoziomow.h"
#include <iostream>


int LicznikPoziomow::counter=0;



LicznikPoziomow::LicznikPoziomow(){
    
    counter++;
    std::cout<<"Rozpoczynamy poziom numer "<<counter<<"."<<std::endl;
}



LicznikPoziomow::~LicznikPoziomow(){
    
    std::cout<<"Konczymy poziom numer "<<counter<<"."<<std::endl;
    counter--;
}