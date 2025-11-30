#include "bolsa_letras.h"
#include <set>

#include "letras.h"

BolsaLetras::BolsaLetras(){
    Letras = set<LETRASInfo>();
}

BolsaLetras::BolsaLetras(const set<LETRASInfo>& letras){
    Letras = letras;
}

BolsaLetras::~BolsaLetras(){
    Letras.clear();
}

bool BolsaLetras::EstaVacia() const{
    return Letras.empty();
}

int BolsaLetras::size() const{
    return Letras.size();
}

bool BolsaLetras::Pertenece(LETRASInfo letra) const{
    return Letras.find(letra) != Letras.end();
}

void BolsaLetras::Insertar(LETRASInfo letra){
    Letras.insert(letra);
}

void BolsaLetras::Borrar(LETRASInfo letra){
    Letras.erase(letra);
}

ostream& operator<<(ostream& os, const BolsaLetras& bolsa){
    for(auto it = bolsa.Letras.begin(); it != bolsa.Letras.end(); ++it){
        os << (*it).caracter() << " " << (*it).repeticiones() << " " << (*it).puntuacion() << endl;
    }
    return os;
}