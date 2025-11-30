#include "letras.h"

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