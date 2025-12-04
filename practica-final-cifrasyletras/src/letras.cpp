#include "letras.h"
#include <iostream>

using namespace std;
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

LETRASInfo::LETRASInfo(const LETRASInfo& otro) {
    c = otro.c;
    r = otro.r;
    p = otro.p;
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

LETRASInfo& LETRASInfo::operator=(const LETRASInfo& otro) {
    if (this != &otro) {
        c = otro.c;
        r = otro.r;
        p = otro.p;
    }
    return *this;
}

bool LETRASInfo::operator==(const LETRASInfo& otro) const {
    return c == otro.c && r == otro.r && p == otro.p;
}

bool LETRASInfo::operator==(char otro) const {
    return c == otro;
}

bool LETRASInfo::operator<(const LETRASInfo& otro) const {
    return c < otro.c;
}

bool LETRASInfo::operator<(char otro) const {
    return c < otro;
}

istream& operator>>(istream& is, LETRASInfo& letra) {
    char car;
    int rep, punt;

    if (is >> car >> rep >> punt) {
        letra.c = car;
        letra.r = rep;
        letra.p = punt;
    }

    return is;
}

ostream& operator<<(ostream& os, const LETRASInfo& letra) {
    os << letra.c << " " << letra.r << " " << letra.p;
    return os;
}
