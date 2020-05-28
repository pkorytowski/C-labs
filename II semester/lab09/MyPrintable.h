#pragma once

#include <string>

///Abstract class for group all printable objects
class MyPrintable{
public:

    ///virtual method returns plain string
    virtual std::string rawString()const=0;
    
};