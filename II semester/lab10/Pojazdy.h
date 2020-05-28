#pragma once

///base class of all vehicles
class Pojazd{
public:
    Pojazd()=default;
    
    ///Pojazd class constructor
    ///Sets rej as license plate text (m_rej)
    Pojazd(std::string rej):m_rej(rej){}
    
    virtual ~Pojazd()=default;
    
    
    ///Returns license plate text (m_rej)
    std::string getRej()const{
        return m_rej;
    }
    
    
    ///virtual method return type of current vehicle
    virtual std::string getVehicleType()const{
        return "Pojazd";
    }
    
private:
    std::string m_rej;
    
};


class Motorowka:virtual public Pojazd{
public:
    Motorowka()=default;
    
    ///Motorowka class constructor
    ///Sets rej as license plate text (m_rej) and speed as max speed in water (m_speed)
    Motorowka(std::string rej, PredkoscMaksymalna speed):Pojazd(rej), m_speed(speed){}
    
    
    ///Returns vehicle type (Motorowka)
    std::string getVehicleType()const override{
        return "Motorowka";
    }
    
    
    ///Returns max speed (m_speed)
    PredkoscMaksymalna predkoscMaksymalna()const{
        return m_speed;
    }

private:
    PredkoscMaksymalna m_speed;
};



///class for group land vehicles 
class PojazdLadowy:virtual public Pojazd{
public:
    PojazdLadowy()=default;
    PojazdLadowy(std::string rej):Pojazd(rej){}
    
    ///Returns vehicle type (Pojazd ladowy)
    std::string getVehicleType()const override{
        return "Pojazd ladowy";
    }
};



class Samochod: public PojazdLadowy{
public: 
    Samochod()=default;
    
    ///Samochod class constructor
    ///Sets rej as license plate text (m_rej) and speed as max speed on land (m_speed)
    Samochod(std::string rej, PredkoscMaksymalna speed): 
        Pojazd(rej), 
        PojazdLadowy(rej), 
        m_speed(speed)
        {}
    
    
    ///Returns vehicle type (Samochod)
    std::string getVehicleType()const override{
        return "Samochod";
    }
    
    
    ///Returns max speed (m_speed)
    PredkoscMaksymalna predkoscMaksymalna()const{
        return m_speed;
    }
private:
    PredkoscMaksymalna m_speed;
    
};


///class Rower doesn't include max speed variable
class Rower: public PojazdLadowy{
public: 
    Rower()=default;
    
    //Rower class constructor
    ///Sets rej as license plate text (m_rej)
    Rower(std::string rej):
        Pojazd(rej), 
        PojazdLadowy(rej)
        {}
    
    
    ///Returns vehicle type (Rower)
    std::string getVehicleType()const override{
        return "Rower";
    }
};



///Vehicle that can run on land and in the water
class Amfibia:public Samochod, public Motorowka{
public:
    Amfibia()=default;
    
    ///Amfibia class constructor
    ///rej - license plate text
    ///speed1 - max speed on land
    ///speed2 - max speed in water
    Amfibia(std::string rej, PredkoscMaksymalna speed1, PredkoscMaksymalna speed2):
        Pojazd(rej), 
        Samochod(rej, speed1), 
        Motorowka(rej, speed2)
        {}
        
        
    ///Returns vehicle type (Amfibia)
    std::string getVehicleType()const override{
        return "Amfibia";
    }
    
    ///Returns max speed on land
    PredkoscMaksymalna predkoscMaksymalna_Lad()const{
        return Samochod::predkoscMaksymalna();
    }
    
    
    ///returns max speed in water
    PredkoscMaksymalna predkoscMaksymalna_Woda()const{
        return Motorowka::predkoscMaksymalna();
    }
};



///operator returns formatted text (vehicle type and license plate)
std::ostream& operator<<(std::ostream& os,const Pojazd &p){
    os << p.getVehicleType() << " <" << p.getRej()<<">";
    return os;
}








