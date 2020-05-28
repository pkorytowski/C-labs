#pragma once
#include <stdexcept>


///keeps pointer to a previous error
///and info, file, line about current error
class Calc_error:public std::runtime_error{
public:

    ///Calc_error constructor
    ///sets error properties
    Calc_error(std::runtime_error *err, const char *info, const char *file, int line);
    
    
    
    ///catches a pointer to a top level exception and executes printError method in it
    ///deletes a top level exception at the end
    static void handler();
    
    
    
    ///displays info about current and lower level exception
    ///deletes a lower level exception if exists
    void printError();
    
private:
    
    ///pointer to the lower level exception
    std::runtime_error *m_err;
    
    
    ///file of the current level exception
    std::string m_file;
    
    
    ///line of the current level exception
    int m_line;
};