#include "container.h"

int mem_max = 100;
Container *mem_ptr=0;
int mem_size=0;


Container::Container():val(0){}
Container::Container(int i):val(i){
    std::cout<<"Container(int) "<<i<<std::endl;
}

void* Container::operator new(std::size_t size) throw(){
    if(mem_size==0 && mem_ptr==0){
        mem_ptr = ::new Container[mem_max];
        std::cout<<"Pierwszy obiekt na stercie - alokuje kontener na "<<mem_max << " elementow"<<std::endl;
    }
    if (mem_size<mem_max){
        mem_size++;
        std::cout<<"--- Alokuje 1 --- Wolne miejsca: "<<mem_max-mem_size<<std::endl;

        return mem_ptr+mem_size-1;
    }
    else{
        std::cout<< "Przepelnienie pamieci"<<std::endl;
        return NULL;
    }
}

void* Container::operator new[](std::size_t size) throw(){
    int num = (size/sizeof(Container))-2;
    if((mem_size+num)<=mem_max){
        if(mem_size==0 && mem_ptr==0){
            mem_ptr = ::new Container[mem_max];
            std::cout<<"Pierwszy obiekt na stercie - alokuje kontener na "<<mem_max << "elementow"<<std::endl;
        }
        mem_size+=num;
        std::cout<<"--- Alokuje "<<num<< " --- Wolne miejsca: "<<mem_max-mem_size<<std::endl;
        return mem_ptr+mem_size-num;
    }
    else{
        std::cout<< num <<" wieksze od pozostalego miejsca ("<<mem_max-mem_size<<")"<<std::endl;
        return NULL;
    }
    
    
    

}

void Container::operator delete(void* ptr){
    
    if(mem_size>0){
            mem_size--;
            std::cout<<"--- Zwalniam 1 --- Wolne miejsca: "<<mem_max-mem_size<<std::endl;
        
        if(mem_size==0){
            std::cout<<"Ostatni obiekt na stercie, zwalniam kontener"<<std::endl;
            ::delete [] mem_ptr;
            mem_ptr=0;
            mem_size=0;
        }
    }
    else{

        std::cout << "Pamiec niezaalokowana, brak akcji"<<std::endl;
    }
}

void Container::operator delete[](void* ptr,size_t size){
    int num = (size/sizeof(Container))-2;
    if(mem_size-num>=0){
        mem_size-=num;
        std::cout<<"--- Zwalniam "<<num<<"  --- Wolne miejsca: "<<mem_max-mem_size<<std::endl;
    
        if(mem_size==0){
            std::cout<<"Ostatni obiekt na stercie, zwalniam kontener"<<std::endl;
            ::delete [] mem_ptr;
            mem_ptr=0;
            mem_size=0;
        }
    }
    else{
        std::cout<<"Nie mozna zwolnic takiej ilosci pamieci"<<std::endl;
    }
}

int& Container::value(){
    return val;
} 

ContainerAutoCleaner::~ContainerAutoCleaner(){
    std::cout<<"~ContainerAutoClean"<<std::endl;
    if(mem_ptr!=0){
        delete mem_ptr;
    }
}