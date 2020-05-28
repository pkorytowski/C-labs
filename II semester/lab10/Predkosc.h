#pragma once
#include <iostream>


///class for storing max speed
class PredkoscMaksymalna{
public:
    PredkoscMaksymalna()=default;
    
    
    ///Constructor sets speed as max speed (m_speed)
    PredkoscMaksymalna(int speed):m_speed(speed){}
    
    ///returns max speed
    int getSpeed()const{
        return m_speed;
    }
    
private:
    int m_speed;
};


///operator returns formatted text (max speed in km/h)
std::ostream& operator<<(std::ostream& os,const PredkoscMaksymalna &p){
    os << p.getSpeed() << " km/h";
    return os;
}