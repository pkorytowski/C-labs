#pragma once
#include <iostream>
class Point{
    friend class LinkedList;
    public:    
    Point();
    Point(double,double);
    Point(const char*,double,double);
    Point(const Point&);
    ~Point();
    int getX();
    int getY();
    char* getName();
    void changeName(const char *);
    void fullPrint();
    void move(double, double);
    private:
    double _x;
    double _y;
    char *_name;
    Point *next;
};
bool operator==(Point &,Point &);
bool operator>(Point &,Point &);
bool operator<(Point &,Point &);

int compareX(Point&, Point&);
int compareY(Point&, Point&);
int compareXY(Point&, Point&);
void directions(Point&,Point&,int (*fun)(Point&, Point&));
