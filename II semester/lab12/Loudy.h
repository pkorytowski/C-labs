#pragma once
#include <string>
#include <iostream>


///class with loud constructor and destructor
class Loudy{
public:

    Loudy()=default;
    
    
    ///Loudy loud constructor
    ///sets and says name of an object
    explicit Loudy(const std::string &str):m_str(str){
        std::cout<<"Laudy "<<m_str<<" is waking up!"<<std::endl;
    }


    ///Loud destructor 
    ///says name of an object
    ~Loudy(){
        std::cout<<"Laudy "<<m_str<<" is going to sleep..."<<std::endl;
    }


    ///Simple method to escape from try block
    void skip(){
        throw this;
    }
    
    
private:
    std::string m_str;
    
};


class LoudyArray;



class Handler{
public:
    Handler(LoudyArray *ptr = nullptr);
    ~Handler();

private:
    LoudyArray *m_ptr;
};




///array of Loudy objects
class LoudyArray{
public:


    ///LoudyArray constructor
    ///sets length of an array
    explicit LoudyArray(int len):m_len(len){
        
        m_arr = new Loudy*[m_len];
        
        for(int i=0;i<m_len;i++){
            m_arr[i]=nullptr;
        }
    }
    
    
    ///LoudyArray destructor
    ~LoudyArray(){
        for(int i=0;i<m_len;i++){
            delete m_arr[i];
        }
        delete [] m_arr;
    }
    
    
    ///sets item to array in chosen place
    ///when place is outside array then throws an exception
    void set(int i, Loudy* item){
        
        if(i>=m_len){
            delete item;
            throw Handler(this);
        }
       else{
           delete m_arr[i];
            m_arr[i]=item;
        }
        
    }
    
private:
    int m_len;
    Loudy** m_arr;
    
};



Handler::Handler(LoudyArray *ptr):m_ptr(ptr) {}

Handler::~Handler() {
    delete m_ptr;
}



