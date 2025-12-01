#include "letras_set.h"
#include "letras.h"

Letras_Set::Letras_Set(const multiset<LETRASInfo>& letras_repetidas){
    letras = set<LETRASInfo>();
    LETRASInfo letra_insertar = *letras_repetidas.begin();
    for(auto it = ++letras_repetidas.begin(); it != letras_repetidas.end(); ++it){
        LETRASInfo letra_actual = *it;
        if(letra_actual.caracter() == letra_insertar.caracter()){
            letra_insertar.SetRepeticiones(letra_insertar.repeticiones() + 1);
        } else {
            letras.insert(letra_insertar);
            letra_insertar = letra_actual;
        }
    }
    letras.insert(letra_insertar);
}

Letras_Set::Letras_Set(const string& nombre_fichero){
    letras = set<LETRASInfo>();
    LETRASInfo Letra;
    ifstream in(nombre_fichero);
    if(!in){
        cerr << "Error al abrir el fichero " << nombre_fichero << endl;
        exit(1);
    }
    while(in >> Letra){
        letras.insert(Letra);
    }
    in.close();
}

set<LETRASInfo>::iterator Letras_Set::find(LETRASInfo letra){
    auto it = letras.find(letra);
    return it;
}

Letras_Set::iterator::iterator(){
    it = set<LETRASInfo>::iterator();
}

Letras_Set::iterator::iterator(const set<LETRASInfo>::iterator& other){
    it = other;
}

Letras_Set::iterator& Letras_Set::iterator::operator++(){
    ++it;
    return *this;
}

Letras_Set::iterator Letras_Set::iterator::operator++(int){
    iterator temp = *this;
    ++it;
    return temp;
}

bool Letras_Set::iterator::operator==(const iterator& other) const{
    return it == other.it;
}

bool Letras_Set::iterator::operator!=(const iterator& other) const{
    return it != other.it;
}

LETRASInfo Letras_Set::iterator::operator*() const{
    return *it;
}

Letras_Set::iterator Letras_Set::begin() const{
    return iterator(letras.begin());
}

Letras_Set::iterator Letras_Set::end() const{
    return iterator(letras.end());
}

ostream& operator<<(ostream& os, const Letras_Set& letras_){
    for(auto it = letras_.begin(); it != letras_.end(); ++it){
        os << (*it).caracter() << " " << (*it).repeticiones() << " " << (*it).puntuacion() << endl;
    }
    return os;
}