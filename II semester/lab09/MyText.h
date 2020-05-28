#pragma once
#include "MyPrintable.h"
#include "Attributes.h"


///Printable class with format and color Attributes
class MyText:public MyPrintable, public AttFormat, public AttColor{
public:

    ///Mytext class constructor
    ///Sets string, format and color Attribute
    MyText(std::string str, AttFormat::Attribute optF, AttColor::Attribute optC):
    AttFormat(optF),
    AttColor(optC),
    m_str(str)
    {}
    
    
    ///Overriden method return plain string
    std::string rawString()const override{
        return m_str;
    }
    
    
    ///Sets current string
    void setText(std::string str){
        m_str=str;
    }

private:
    std::string m_str;
};