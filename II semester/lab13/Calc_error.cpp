#include "Calc_error.h"
#include <iostream>

Calc_error::Calc_error(std::runtime_error *err, const char *info, const char *file, int line):
    std::runtime_error(info),
    m_err(err),
    m_file(file),
    m_line(line){}



void Calc_error::handler(){
    
    try{
        throw;
    }
    catch(Calc_error *err){
        std::cout<<"Zlapano wyjatek:"<<std::endl;
        err->printError();
        delete err;
    }
    
}



void Calc_error::printError(){
    
    std::cout<<"-- z powodu: "<<std::runtime_error::what()<<", [plik = "<<m_file<<", linia = "<<m_line<<"]"<<std::endl;
    
    
    auto ptr = dynamic_cast<Calc_error*>(m_err);
    if(ptr){
        ptr->printError();
    }
    else{
        std::cout<<"-- z powodu: "<<m_err->what()<<std::endl;
    }
    
    
    delete m_err;
    
}