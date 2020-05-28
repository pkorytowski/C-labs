#include "intLinkedList.h"
#include <iostream>
#include <cstring>

Element::Element(){ ///Konstruktor bezparametrowy obiektu klasy Element
    next=nullptr;
}
Element::Element(int num): value{num}{ ///Konstruktor z parametrem value
    next=nullptr;
}
Element::Element(const Element & el){ ///Konstruktor kopiujący
    next=el.next;
    value=el.value;
}
Element::~Element(){    ///Destruktor obiektu klasy Element
}
IntLinkedList::IntLinkedList():head{nullptr},tail{nullptr}{ ///Konstruktor bezparametrowy obiektu klasy IntLinkedList
        strcpy(name,"LX");

}
IntLinkedList::IntLinkedList(const char *nazwa):head{nullptr},tail{nullptr}{ ///Konstruktor z parametrem nazwa obiektu klasy IntLinkedList
    strcpy(name,nazwa);

}
IntLinkedList::~IntLinkedList(){ ///Destruktor obiektu klasy IntLinkedList
    if(!isEmpty()){
        Element *ptr = head;
        Element *next_node = ptr;
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
Element *IntLinkedList::przewin(Element *target) {///Metoda pomocnicza przewijajaca wskaznik na wskazana pozycje
    Element * ptr = head;
    while(ptr->next!=target){
        ptr=ptr->next;
    }
    return ptr;
}

bool IntLinkedList::isEmpty()const{///Metoda sprawdzajaca czy lista jest pusta
    if (head==nullptr){
        return true;
    }
    else{
        return false;
    }
}
bool IntLinkedList::contains(int num){///Metoda sprawdzajaca obecnosc w liscie obiektu o podanej wartosci
    if(!isEmpty()){
        Element *ptr = head;
        while((ptr!=nullptr)){
            if(ptr->value==num){
                return true;
            }
            ptr=ptr->next;
        }
        return false;
    }
    else
        return false;
}

int IntLinkedList::size()const{///Metoda zwracajaca dlugosc listy
    if (isEmpty()){
        return 0;
    }
    else{
        Element * ptr = head;
        int counter = 0;
        while(ptr!=tail){
            counter++;
            ptr=ptr->next;
        }
        counter++;
        return counter;
    }
}
void print(IntLinkedList &lista){///Funkcja zaprzyjazniona drukujaca liste
       lista.print();

}

void IntLinkedList::print() const{///Metoda drukująca liste
    std::cout <<name << "=[";
    if(!isEmpty()){

        int size = this->size();
        Element *ptr = head;
        for(int i=0;i<size-1;i++){
            std::cout << ptr->value << ", ";
            ptr=ptr->next;
        }
        std::cout << tail->value;
    }
    std::cout << "]" << std::endl;


}
void IntLinkedList::append(Element &element){///Metoda dodająca element na koniec listy
    if(isEmpty()){
        prepend(element);
    }
    else{
        Element *el=new Element(element);
        tail->next=el;
        tail=el;
    }

}

void IntLinkedList::append(IntLinkedList &lista){///Metoda dodajaca elementy jednej listy na koniec drugiej listy
    Element *ptr = lista.head;
    for(int i=0;i<lista.size();i++){
        append(*ptr);
        ptr=ptr->next;
    }
}


void IntLinkedList::prepend(Element &element){///Metoda dodajaca element na poczatek listy
    Element *el=new Element(element);
    if (isEmpty()){
        head=el;
        tail=el;
    }
    else{
        el->next=head;
        head=el;
    }

}

void IntLinkedList::prepend(int num){///Metoda tworzaca element o wartosci num i dodajaca go na poczatku listy
                                        ///Powstała jako pierwsza na wczesniejszych zajeciach, gdyby nie to mogla by miec tylko dwie linijki
                                        ///(Wywolanie metody prepend(Element&)) jednak wolałem zostawić bez zmian
    Element *el=new Element(num);
    if (isEmpty()){
        head=el;
        tail=el;
    }
    else{
        el->next=head;
        head=el;
    }
}

void IntLinkedList::addSorted(Element &element, bool uniq) {///Metoda dodajaca do posortowanej liczby element

    if (!(uniq && contains(element.value))) {

        if (isEmpty() || element.value < head->value) {
            prepend(element);
        } else if (element.value > tail->value) {
            append(element);
        }
        else{
            Element *el=new Element(element);
            Element *ptr=head;
            while(el->value>ptr->next->value){
                ptr=ptr->next;
            }
            el->next=ptr->next;
            ptr->next=el;
        }
    }
}

void IntLinkedList::addSorted(IntLinkedList &lista){///Metoda dodajaca do posortowanej listy elementy innej listy
    Element *ptr = lista.head;
    for(int i=0;i<lista.size();i++){
        Element el=Element(*ptr);
        addSorted(el);
        ptr=ptr->next;
    }

}

void IntLinkedList::addSorted(int num,bool uniq){///Metoda tworzaca element o podanej wartosci i dodajaca go do listy rosnaco
                                                ///Sytuacja podobna jak w przypadku prepend(int)
    Element element = Element(num);
    if (!(uniq && contains(element.value))) {

        if (isEmpty() || element.value < head->value) {
            prepend(element);
        } else if (element.value > tail->value) {
            append(element);
        }
        else{
            Element *el=new Element(element);
            Element *ptr=head;
            while(el->value>ptr->next->value){
                ptr=ptr->next;
            }
            el->next=ptr->next;
            ptr->next=el;
        }
    }

}

void IntLinkedList::removeFirst(){///Metoda usuwajaca pierwszy element listy
    if(!isEmpty()){
        Element *ptr = head->next;
        delete head;
        head=nullptr;
        head=ptr;

    }

}
void IntLinkedList::removeLast(){///Metoda usuwajaca ostatni element listy
    if(!isEmpty()){
        if(size()==1){
            delete head;
            tail=nullptr;
            head=nullptr;
        }
        else{
            Element *ptr=przewin(tail);
            delete tail;
            tail = ptr;
            tail->next=nullptr;
        }
    }
}
void IntLinkedList::removeValue(int num){///Metoda usuwajaca element o podanej wartosci (o ile jest w liscie taki)
    if(!isEmpty() && contains(num)){
        Element *ptr = head;
        Element *before = ptr;
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



