#include "bolsa_letras.h"
#include <set>
#include <fstream>
#include <random>

#include "letras.h"
#include "letras_set.h"

BolsaLetras::BolsaLetras(){
    Letras = multiset<LETRASInfo>();
}

BolsaLetras::BolsaLetras(const multiset<LETRASInfo>& letras){
    Letras = letras;
}

BolsaLetras::BolsaLetras(const Letras_Set& letras){
    Letras = multiset<LETRASInfo>();
    for(auto it = letras.begin(); it != letras.end(); ++it){
        for(int i = 0; i < (*it).repeticiones(); ++i){
            Letras.insert(LETRASInfo((*it).caracter(), 1, (*it).puntuacion()));
        }
    }
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

multiset<LETRASInfo> BolsaLetras::saca(int n){
    multiset<LETRASInfo> sacadas;
    for(int i = 0; i < n; ++i){
        if(Letras.empty()){
            break;
        }
        // Generar un índice aleatorio
        auto it = Letras.begin();
        std::advance(it, rand() % Letras.size());
        // Insertar la letra en el conjunto sacadas
        sacadas.insert(*it);
        // Borrar la letra de la bolsa
        Letras.erase(it);
    }
    return sacadas;
}

ostream& operator<<(ostream& os, const BolsaLetras& bolsa){
    for(auto it = bolsa.Letras.begin(); it != bolsa.Letras.end(); ++it){
        os << *it << endl;
    }
    return os;
}