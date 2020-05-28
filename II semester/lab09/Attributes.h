#pragma once

class AttFormat{
public:

    ///Enum of available format attributes list
    enum Attribute{
        BOLD,
        DIM,
        UNDERLINED,
        NORMAL
    };
    
    ///AttFormat class constructor
    ///Sets current Format Attribute
    AttFormat(AttFormat::Attribute opt):m_opt(opt){}
    
    
    ///Returns current Attribute
    AttFormat::Attribute getFormat()const{
        return m_opt;
    }
    
    
    ///Sets current Attribute
    void setFormat(AttFormat::Attribute opt){
        m_opt=opt;
    }
    
private:
    AttFormat::Attribute m_opt;
};



class AttColor{
public:
    ///Enum of available colors attributes list
    enum Attribute{
        BLACK,
        RED,
        GREEN,
        YELLOW,
        BLUE,
        MAGENTA,
        CYAN,
        GRAY,
        WHITE
    };
    
    
    ///AttColor class constructor
    ///Sets current Color Attribute
    AttColor(AttColor::Attribute opt):m_opt(opt){}
    
    
    ///Returns current Attribute
    AttColor::Attribute getColor()const{
        return m_opt;
    }
    
    
    ///Sets current Attribute
    void setColor(AttColor::Attribute opt){
        m_opt=opt;
    }
private:
    AttColor::Attribute m_opt;
};