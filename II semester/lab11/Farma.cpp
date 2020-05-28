#include "Farma.h"


void Farma::wypisz(const std::string &str)const{
        
        std::cout<<" -- "<<str<<" -- "<<std::endl;
        for(const auto &zwierze: m_farma){
            zwierze->opisz();
            std::cout<<std::endl;
        }
    }
    
    
int Farma::zliczImie(const std::string& name)const{
    
        int i = count_if(m_farma.begin(),m_farma.end(),[name](const std::unique_ptr<Zwierz> &zwierze){
           return name==zwierze->imie(); 
        });
        return i;
    }
    
    
void Farma::statystykaImion()const{
        std::vector<std::string> names;
        
        for(const auto& zwierze:m_farma){
            names.push_back(zwierze->imie());
        }
        
        std::sort(names.begin(),names.end());
        names.erase(std::unique(names.begin(),names.end()),names.end());
        
        for(const auto& name:names){
            int i = count_if(m_farma.begin(),m_farma.end(),[name](const std::unique_ptr<Zwierz> &zwierze){
                return name==zwierze->imie(); 
            });
            
            std::cout<<name<<": "<<i<<std::endl;
        }
    }
    
    
std::vector<Owca*> Farma::wyprowadzOwce()const{
    
        std::vector<Owca*> stado;
        for(const auto& zwierze: m_farma){
            auto owca = dynamic_cast<Owca*>(zwierze.get());
            if(owca)
                stado.push_back(owca);
        }
        
        return stado;
    }
    
    
    
    
    
    