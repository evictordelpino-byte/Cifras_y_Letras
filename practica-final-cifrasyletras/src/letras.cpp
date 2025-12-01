#include "letras.h"
#include <iostream>

LETRASInfo::LETRASInfo(){
    c = ' ';
    r = 0;
    p = 0;
}

LETRASInfo::LETRASInfo(char carac, int rep, int punt){
    c = carac;
    r = rep;
    p = punt;
}

char LETRASInfo::caracter() const{
    return c;
}

int LETRASInfo::repeticiones() const{
    return r;
}

int LETRASInfo::puntuacion() const{
    return p;
}

void LETRASInfo::SetRepeticiones(int rep){
    r = rep;
}

LETRASInfo& LETRASInfo::operator=(const LETRASInfo& otro){
    if(this != &otro){
        c = otro.c;
        r = otro.r;
        p = otro.p;
    }
    return *this;
}

bool LETRASInfo::operator==(const LETRASInfo& otro) const{
    return c == otro.c;
}

bool LETRASInfo::operator==(char otro) const{
    return c == otro;
}

bool LETRASInfo::operator<(const LETRASInfo& otro) const{
    return c < otro.c;
}

bool LETRASInfo::operator<(char otro) const{
    return c < otro;
}

std::istream& operator>>(std::istream& is, LETRASInfo& letra){
    char carac;
    int rep, punt;
    is >> carac >> rep >> punt;
    letra = LETRASInfo(carac, rep, punt);
    return is;
}

std::ostream& operator<<(std::ostream& os, const LETRASInfo& letra){
    os << letra.caracter() << " " << letra.repeticiones() << " " << letra.puntuacion() << std::endl;
    return os;
}