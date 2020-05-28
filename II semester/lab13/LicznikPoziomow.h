#pragma once


///Level counter with loud constructor and destructor
class LicznikPoziomow{
public:

    ///static counter for levels
    static int counter;
    
    
    
    ///loud constructor
    ///signalizes current level
    LicznikPoziomow();
    
    
    
    ///loud destructor
    ///signalizes which level is currently being destroyed
    ~LicznikPoziomow();
    
};