#include <cstring>
#include "point.h"
#include <functional>


Point::Point():_x{0},_y{0},_name{nullptr},next{nullptr}{}
Point::Point(double x,double y):_x{x},_y{y},next{nullptr}{
    _name = new char[17];
    strcpy(_name,"Miejsce nieznane");
}

Point::Point( const char *name,double x,double y):_x{x},_y{y},next{nullptr}{
    int len = strlen(name);
    _name = new char[len+1];
    strcpy(_name,name);
}

Point::Point(const Point &drugi){
    _name = new char[strlen(drugi._name)+1];
    strcpy(_name,drugi._name);
    _x=drugi._x;
    _y=drugi._y;
    next=drugi.next;
}
/*
Point::Point(Point&& drugi){
    _name =new char[strlen(drugi._name)+1];
    strcpy(_name,drugi._name);
    delete [] drugi._name;
    drugi._name=nullptr;
    _x = std::exchange(drugi._x,0);
    _y = std::exchange(drugi._y,0);
    next=
    //std::cout << "przenoszacy "<<drugi._name;
}*/
Point::~Point(){
    if(_name!=nullptr){
    delete []_name;
    _name=nullptr;
    next=nullptr;}    
}

int Point::getX(){
    return _x;

}
int Point::getY(){
    return _y;
}    
char* Point::getName(){
    return _name;
}
void Point::changeName(const char *name){
    int newLen = strlen(name);
    delete []_name;
    _name = new char[newLen+1];
    strcpy(_name, name);
}
void Point::fullPrint(){
    if (_name==nullptr){
        std::cout << "NULL";
    }
    else{
        std::cout << _name;   
    }
    std::cout <<" ("<< _x << ", "<< _y<<")"<<std::endl;
}
void Point::move(double x, double y){
    _x+=x;
    _y+=y;

}


int compareX(Point &first, Point &second){
    if(first.getX()>second.getX()){
        return -1;
    }
    else if(first.getX()<second.getX()){
        return 1;
    }
    else{
        return 0;
    }
}

int compareY(Point &first, Point &second){
    if(first.getY()>second.getY()){
        return -1;
    }
    else if(first.getY()<second.getY()){
        return 1;
    }
    else{
        return 0;
    }
}

int compareXY(Point &first,Point &second){
    int x = compareX(first,second);
    int y = compareY(first,second);
    return 10*x+y;
}

void directions(Point& first,Point& second,int (*fun)(Point&, Point&)){
    int dir = fun(first,second);
    if(fun==compareX){
    switch (dir){
    case 1:{
        std::cout << first.getName()<< " jest na zachód od "<< second.getName()<<std::endl;
    break;
    }
    case -1:{
        std::cout << first.getName()<< " jest na polnoc od "<< second.getName()<<std::endl;
break;
    }
    case 9:{
        std::cout << first.getName()<< " jest na polnocny-zachod od "<< second.getName()<<std::endl;
break;
    }
}
    
    }
    else if(fun==compareY){
    switch(dir){
    case 1:{
        std::cout << first.getName()<< " jest na zachód od "<< second.getName()<<std::endl;
    break;
    }
    case -1:{
        std::cout << first.getName()<< " jest na polnoc od "<< second.getName()<<std::endl;
break;
    }
    case 9:{
        std::cout << first.getName()<< " jest na polnocny-zachod od "<< second.getName()<<std::endl;
break;

}
}
}
   
}

bool operator==(Point &P1,Point &P2){
    if((P1.getX()==P2.getX()) && (P1.getY()==P2.getY())){
        return true;
    }
    else 
        return false;

}
bool operator<(Point &P1,Point &P2){
    if(P1.getX()<P2.getX()){
        return true;

    }
    else if (P1.getX()>P2.getX()){

    return false;
    }
    else{

    if(P1.getY()<P2.getY()){
        return true;
    }
    else {
        return false;
    }
    
}
}

bool operator>(Point &P1,Point &P2){
    if(P1.getX()>P2.getX()){
        return true;

    }
    else if (P1.getX()<P2.getX()){

    return false;
    }
    else{

    if(P1.getY()>P2.getY()){
        return true;
    }
    else {
        return false;
    }
    
}
}
















































