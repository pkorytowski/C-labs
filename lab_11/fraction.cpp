#include "fraction.h"


int nwd(int m, int n){
	int oldm, oldn;
    while( m % n != 0 ){
        oldm = m;
        oldn = n;
	    m = oldn;
	    n = oldm % oldn;
	}
    return n;
}
Fraction::Fraction(): _l(0),_m(0){

}

Fraction::Fraction(int a, int b):_l(a),_m(b){
    this->simplify();
}

void Fraction::simplify(){
    int n = nwd(_l,_m);
    _l=_l/n;
    _m=_m/n;
}
int Fraction::getL()const{
    return _l;
}
int Fraction::getM()const{
    return _m;
}

std::ostream& operator<<(std::ostream& os, const Fraction& ulamek){ ///funkcja wypisujaca ulamek w odpowiedniej postaci
    if(ulamek.getM()!=1){
    int a = ulamek.getL()/ulamek.getM();    
        if(a>0){
        os << a <<" ";
        
        os << ulamek.getL()-a*ulamek.getM();
        os<< "/"<<ulamek.getM();
        }
        else if(a<0){
        os << a <<" ";
        
        os << (ulamek.getL()-a*ulamek.getM());
        os<< "/"<<ulamek.getM()*(-1);
        }
        
        else{
        os<<ulamek.getL();
        os<< "/"<<ulamek.getM();
        }    
        
        
    }
    else{
        os<<ulamek.getL();
    }
    return os;      
}
Fraction Fraction::operator-(){///przeciazony operator - zamiana znaku

    Fraction tmp(_l*(-1),_m);
    return tmp;   
    
}
Fraction::operator double(){///metoda zamieniajaca ulamek na double
    double a = double(_l)/double(_m);
    return a;
}

Fraction operator+(const Fraction& first,const Fraction& second){///przeciazony operator + ulamek i ulamek
    Fraction tmp(first.getL()*second.getM()+second.getL()*first.getM(),first.getM()*second.getM());
    return tmp;

}
Fraction operator*(const Fraction& first,const Fraction& second){///przeciazony operator * ulamek i ulamek
    Fraction tmp(first.getL()*second.getL(),first.getM()*second.getM());
    return tmp;

}
Fraction operator*(int num,const Fraction& ulamek){///przeciazony operator * int i ulamek
    Fraction tmp(num*ulamek.getL(),ulamek.getM());
    return tmp;

}

Fraction& Fraction::operator=(const Fraction& old){///operator przypisania
    if(&old!=this){    
        this->_l=old._l;
        this->_m=old._m;
    }
    return *this;
}
Fraction& Fraction::operator+=(int num){///przeciazony operator +=
    _l=_l+num*_m;
    this->simplify();
    return *this;

}
























