#include <iostream>
#include "intArrayList.h"

IntArrayList::IntArrayList(){
    tab = new int[100];
    maxSize = 100;
    size = 0;
}
IntArrayList::IntArrayList(int max){
    tab=new int[max];
    maxSize = max;
    size = 0;
}
IntArrayList::~IntArrayList(){
    delete [] tab;
}

void IntArrayList::print(){
    
    if(size>0){
        std::cout << "[ ";
    }
    for (int i=0;i<size;i++){
        
        std::cout << tab[i];
        if(i<size-1){
            std::cout <<", ";
        }
    }

    if (size>0){
        std::cout << "]\n";
    }
}

int IntArrayList::find(int num){
    for(int i=0;i<size;i++){
        if (num==tab[i]){
            return i;
        }
    }
    return -1;
}

void IntArrayList::printFind(int num){
    int ind = find(num);    
    if(ind>=0){
        std::cout << "wartosc=" << num << " Indeks="<< ind <<"\n";
    }
    else{
        std::cout << "wartosc=" << num << " Element nie znaleziony\n";
    }
}

void IntArrayList::add(int num){
    if (size<maxSize){   
        tab[size]=num;
        size++;
    }
}

void IntArrayList::add(int *arr, int num){
    if((size+num)<maxSize){
        for(int i=0;i<num;i++){
            tab[size] = arr[i];
            size++;
        }
    }
}

void IntArrayList::add(int ind, int num){
    if(size<maxSize){
        for(int i=size-1;i>=ind; i--){
            
            tab[i+1]=tab[i];           

        }
        tab[ind]=num;
        size++;
    }
}

void IntArrayList::add(int num,bool znak){
    if(size<maxSize){
        
        if(znak==true){
            if(size==0){
                add(num);

            }
            else{
                int i = 0;
                while(num>tab[i] && i<size){
                    i++;
                }
                add(i,num);
            }
        }
        else{
        add(num);
        }
    }
}
void IntArrayList::remove(int num){
    int f = find(num);    
    if (f>-1){
        for(int i=f;i<size;i++){
            tab[i] = tab[i+1];
        }
        size--;

    }  

}

void IntArrayList::remove(int num1,int num2){
      int f = find(num1);
      if ((f+num2)<size){

        for(int i=f;i<size;i++){
            tab[i] = tab[i+num2];
        }
        size = size-num2;
}
     

}






























