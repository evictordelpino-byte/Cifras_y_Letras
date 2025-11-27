#include "bolsa_letras.h"

BolsaLetras::BolsaLetras(){
    Letras = multiset<char>();
}

BolsaLetras::BolsaLetras(const multiset<char>& letras){
    Letras = letras;
}

BolsaLetras::~BolsaLetras(){
    Letras.clear();
}

bool BolsaLetras::EstaVacia() const{
    return Letras.empty();
}

int BolsaLetras::Tam() const{
    return Letras.size();
}

bool BolsaLetras::Pertenece(char letra) const{
    return Letras.find(letra) != Letras.end();
}

void BolsaLetras::Insertar(char letra){
    Letras.insert(letra);
}

void BolsaLetras::Borrar(char letra){
    Letras.erase(letra);
}

ostream& operator<<(ostream& os, const BolsaLetras& bolsa){
    for(auto it = bolsa.Letras.begin(); it != bolsa.Letras.end(); ++it){
        os << *it << " ";
    }
    return os;
}