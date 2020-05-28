#pragma once
#include "point.h"

class LinkedList{
friend class Point;
    public:
        
        friend void print(LinkedList&);
        LinkedList();
        LinkedList(const char*);
        ~LinkedList();
        bool isEmpty() const;
        int size() const;
        
        void print() const;
        void append(Point&);
        Point *przewin(Point*);
        //void prepend(int);
        void prepend(Point&);
        void addSorted(LinkedList &);
        void addSorted(Point &, bool=false);
        //void addSorted(int, bool=false);
        void removeFirst();
        void removeLast();
        //void removeValue(int);
        bool contains(Point&);
        void append(LinkedList &lista);
    private:
        Point *head;
        Point *tail;
        char name[20];    
};
