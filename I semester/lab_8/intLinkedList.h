#pragma once

class Element{
    friend class IntLinkedList;
public:
    Element();    
    Element(int);
    Element(const Element&);
    ~Element();
    int value;
    Element * next;
};

class IntLinkedList{
    public:
        friend void print(IntLinkedList&);
        IntLinkedList();
        IntLinkedList(const char*);
        ~IntLinkedList();
        bool isEmpty()const;
        int size() const;
        void print() const;
        void append(Element&);
        Element *przewin(Element *);
        void prepend(int);
        void prepend(Element&);
        void addSorted(IntLinkedList &);
        void addSorted(Element &, bool=false);
        void addSorted(int, bool=false);
        void removeFirst();
        void removeLast();
        void removeValue(int);
        bool contains(int);
        void append(IntLinkedList &lista);
    private:
        Element *head;
        Element *tail;
        char name[20];    
};
