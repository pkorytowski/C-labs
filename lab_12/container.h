#pragma once
#include <cstdlib>
#include <iostream>




class Container{
public:
    
    Container();
    Container(int);  
    int& value();
    static void *operator new(std::size_t) throw();
    static void *operator new[](std::size_t) throw();
    static void operator delete(void* ptr);
    static void operator delete[](void* ptr, std::size_t);
private:
    int val;

};


class ContainerAutoCleaner{
public:
    ContainerAutoCleaner():wsk(nullptr){}
    ContainerAutoCleaner(Container *ptr){
        wsk=ptr;
    }
    ~ContainerAutoCleaner();
    Container* operator->(){
        return wsk;
    }

private:
    Container *wsk;
};
