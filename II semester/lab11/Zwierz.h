#pragma once

#include <string>
#include <iostream>

///base Animal class
class Zwierz{
public:

    ///Zwierz constructor 
    ///Sets animal's name
    Zwierz(const std::string & name):m_name(name){}
    
    virtual ~Zwierz()=default;
    
    ///Returns animal's name
    std::string imie()const{
        return m_name;
    }
    
    ///virtual method describes animal
    virtual void opisz()const=0;
private:
    std::string m_name;
    
};


class Owca:public Zwierz{
public:
    ///Owca constructor 
    ///Sets animal's name
    Owca(const std::string& name):Zwierz(name),m_ostrzyzona(false){}
    
    
    ///Loud destructor
    ~Owca(){
        std::cout<<"Owca "<<imie()<<" wrocila do zagrody"<<std::endl;
    }
    
  
    ///Overridden method describes Owca   
    void opisz()const override{
        std::cout<<"Owca "<<imie()<<" - "<<getStrzyzenie();
    }
  
    ///Returns info if Owca is shorn or not
    std::string getStrzyzenie()const{
        if (m_ostrzyzona)
            return std::string("ostrzyzona");
    return std::string("nieostrzyzona");
    }
  
  
    ///Owca shearing - sets m_ostrzyzona to true
    void ostrzyz(){
        m_ostrzyzona=true;
    }
  
  
private:
    bool m_ostrzyzona;
};



class Krowa:public Zwierz{
public:
    ///Krowa constructor 
    ///Sets animal's name
    Krowa(const std::string& name):Zwierz(name){}
    
    
    ///Loud destructor
    ~Krowa(){
        std::cout<<"Krowa "<<imie()<<" wrocila do obory"<<std::endl;
    }
  
    
    ///Overridden method describes Krowa  
    void opisz()const override{
        std::cout<<"Krowa "<<imie();
    }
  
    
};




class Kon:public Zwierz{
public:

    ///Kron constructor 
    ///Sets animal's name
    Kon(const std::string& name):Zwierz(name){}
    
    ///Loud destructor
    ~Kon(){
        std::cout<<"Kon "<<imie()<<" wrocil do stajni"<<std::endl;
  }
  
  ///Overridden method describes Kon
    void opisz()const override{
        std::cout<<"Kon "<<imie();
    }
  
    
};






