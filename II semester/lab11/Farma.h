#pragma once
#include <vector>
#include <memory>
#include <algorithm>

#include "Zwierz.h"

class Farma{
public:
    ~Farma();
    
    ///Adds new zwierze to farm 
    ///No need to delete in destructor - unique_ptr
    void dodaj(std::unique_ptr<Zwierz> zwierze){
        m_farma.push_back(std::move(zwierze));
    }
    
    ///Prints all animals in farm
    void wypisz(const std::string &str)const;
    
    ///Counts occurences of name in farm
    int zliczImie(const std::string& name)const;
    
    
    ///Counts occurences of all unique names in farm
    void statystykaImion()const;
    
    ///Returns all Owca animals from farma
    std::vector<Owca*> wyprowadzOwce()const;
    
private:
    std::vector<std::unique_ptr<Zwierz>> m_farma;
    
};









