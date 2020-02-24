#include "linkedList.h"
#include <iostream>
#include <cstring>
/*
Point::Point(){ ///Konstruktor bezparametrowy obiektu klasy Point
    next=nullptr;
}
Point::Point(int num): value{num}{ ///Konstruktor z parametrem value
    next=nullptr;
}
Point::Point(const Point & el){ ///Konstruktor kopiujący
    next=el.next;
    value=el.value;
}
Point::~Point(){    ///Destruktor obiektu klasy Point
}*/
LinkedList::LinkedList():head{nullptr},tail{nullptr}{ ///Konstruktor bezparametrowy obiektu klasy LinkedList
        strcpy(name,"LX");
 
}
LinkedList::LinkedList(const char *nazwa):head{nullptr},tail{nullptr}{ ///Konstruktor z parametrem nazwa obiektu klasy LinkedList
    strcpy(name,nazwa);
 
}
LinkedList::~LinkedList(){ ///Destruktor obiektu klasy LinkedList
    if(!isEmpty()){
        Point *ptr = head;
        Point *next_node = ptr;
        while(ptr!=tail){
            next_node=ptr->next;
            delete ptr;
            ptr=next_node;
        }
        delete tail;
        head= nullptr;
        tail=nullptr;
    }
    if(isEmpty()){
        std::cout << "Destruktor "<< name <<": Lista pusta" << std::endl;
    }
}
Point* LinkedList::przewin(Point *target) {///Metoda pomocnicza przewijajaca wskaznik na wskazana pozycje
    Point * ptr = head;
    while(ptr->next!=target){
        ptr=ptr->next;
    }
    return ptr;
}
 
bool LinkedList::isEmpty()const{///Metoda sprawdzajaca czy lista jest pusta
    if (head==nullptr){
        return true;
    }
    else{
        return false;
    }
}
bool LinkedList::contains(Point &p){///Metoda sprawdzajaca obecnosc w liscie obiektu o podanej wartosci
    if(!isEmpty()){
        Point *ptr = head;
        while((ptr!=nullptr)){
            if(*ptr==p){
                return true;
            }
            ptr=ptr->next;
        }
        return false;
    }
    else
        return false;
}
 
int LinkedList::size()const{///Metoda zwracajaca dlugosc listy
    if (isEmpty()){
        return 0;
    }
    else{
        Point * ptr = head;
        int counter = 0;
        while(ptr!=tail){
            counter++;
            ptr=ptr->next;
        }
        counter++;
        return counter;
    }
}

void print(LinkedList &lista){///Funkcja zaprzyjazniona drukujaca liste
       
 
}
 
void LinkedList::print() const{///Metoda drukująca liste
    
 
 
}
void LinkedList::append(Point &p){///Metoda dodająca Point na koniec listy
    if(isEmpty()){
        prepend(p);
    }
    else{
        Point *el=new Point(p);
        tail->next=el;
        tail=el;
    }
 
}
 
void LinkedList::append(LinkedList &lista){///Metoda dodajaca Pointy jednej listy na koniec drugiej listy
    Point *ptr = lista.head;
    for(int i=0;i<lista.size();i++){
        append(*ptr);
        ptr=ptr->next;
    }
}
 
 
void LinkedList::prepend(Point &p){///Metoda dodajaca Point na poczatek listy
    Point *el=new Point(p);
    if (isEmpty()){
        head=el;
        tail=el;
    }
    else{
        el->next=head;
        head=el;
    }
 
}
 /*
void LinkedList::prepend(int num){///Metoda tworzaca Point o wartosci num i dodajaca go na poczatku listy
                                        ///Powstała jako pierwsza na wczesniejszych zajeciach, gdyby nie to mogla by miec tylko dwie linijki
                                        ///(Wywolanie metody prepend(Point&)) jednak wolałem zostawić bez zmian
    Point *el=new Point(num);
    if (isEmpty()){
        head=el;
        tail=el;
    }
    else{
        el->next=head;
        head=el;
    }
}
 */
void LinkedList::addSorted(Point &p, bool uniq) {///Metoda dodajaca do posortowanej liczby Point
 
    if (!(uniq && contains(p))) {
 
        if (isEmpty() || p < *head) {
            prepend(p);
        } else if (p > *tail) {
            append(p);
        }
        else{
            Point *el=new Point(p);
            Point *ptr=head;
            while(el>ptr->next){
                ptr=ptr->next;
            }
            el->next=ptr->next;
            ptr->next=el;
        }
    }
}
 
void LinkedList::addSorted(LinkedList &lista){///Metoda dodajaca do posortowanej listy Pointy innej listy
    Point *ptr = lista.head;
    for(int i=0;i<lista.size();i++){
        Point el=Point(*ptr);
        addSorted(el);
        ptr=ptr->next;
    }
 
}
 /*
void LinkedList::addSorted(int num,bool uniq){///Metoda tworzaca Point o podanej wartosci i dodajaca go do listy rosnaco
                                                ///Sytuacja podobna jak w przypadku prepend(int)
    Point Point = Point(num);
    if (!(uniq && contains(Point.value))) {
 
        if (isEmpty() || Point.value < head->value) {
            prepend(Point);
        } else if (Point.value > tail->value) {
            append(Point);
        }
        else{
            Point *el=new Point(Point);
            Point *ptr=head;
            while(el->value>ptr->next->value){
                ptr=ptr->next;
            }
            el->next=ptr->next;
            ptr->next=el;
        }
    }
 
}
 */
void LinkedList::removeFirst(){///Metoda usuwajaca pierwszy Point listy
    if(!isEmpty()){
        Point *ptr = head->next;
        delete head;
        head=nullptr;
        head=ptr;
 
    }
 
}
void LinkedList::removeLast(){///Metoda usuwajaca ostatni Point listy
    if(!isEmpty()){
        if(size()==1){
            delete head;
            tail=nullptr;
            head=nullptr;
        }
        else{
            Point *ptr=przewin(tail);
            delete tail;
            tail = ptr;
            tail->next=nullptr;
        }
    }
}
/*
void LinkedList::removeValue(int num){///Metoda usuwajaca Point o podanej wartosci (o ile jest w liscie taki)
    if(!isEmpty() && contains(p)){
        Point *ptr = head;
        Point *before = ptr;
        while(ptr->value!=num){
            before=ptr;
            ptr=ptr->next;
        }
        if (ptr==tail){
            removeLast();
        }
        else if (ptr==head){
            ptr=ptr->next;
            delete head;
            head=ptr;
        }
        else{
            before->next=ptr->next;
            delete ptr;
        }
    }
}
*/
