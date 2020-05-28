#pragma once
#include "MyPrintable.h"
#include "Attributes.h"


///printable class with color Attribute
class MyLine:public MyPrintable, public AttColor{
public:

    ///MyLine class constructor
    ///Sets current char, length of string, color Attribute
    MyLine(char c, unsigned int count, AttColor::Attribute opt):
    AttColor(opt),
    m_c(c),
    m_count(count)
    {}
    
    ///Overriden method return plain string (m_c "m_count" times)
    std::string rawString()const override{
        return std::string(m_count, m_c);
    };
    
    
    ///Sets length of string
    void setLength(unsigned int len){
        m_count=len;
    }
    
    
    ///Sets current char
    void setChar(char c){
        m_c=c;
    }
    
private:
    char m_c;
    unsigned int m_count;
};