#include "diccionario.h"

#include <set>
#include <iostream>
#include <fstream>
#include <string>

using namespace std;

Diccionario::Diccionario(){
    palabras = set<string>();
}

Diccionario::Diccionario(const string& nombre_fichero){
    cargar_diccionario(nombre_fichero);
}

Diccionario::~Diccionario(){
    palabras.clear();
}

bool Diccionario::cargar_diccionario(const string &nombre_fichero){
    palabras.clear();
    ifstream in(nombre_fichero);
    if (in.fail()) {
        cerr << "Error al abrir el fichero: " << nombre_fichero << endl;
        return false;
    }

    in >> *this;   
    return true;
}

void Diccionario::mostrar_diccionario() const{
    cout << *this;   // antes tenías cout << this;
}                    // <-- FALTABA ESTA LLAVE DE CIERRE

int Diccionario::size() const {
    return palabras.size();
}

bool Diccionario::Esta(const string& palabra) const{
    //palabras.find(palabra) devuelve iterator al elemento 
    //si no encuentra devuelve palabras.end()
    return palabras.find(palabra) != palabras.end();
}

vector<string> Diccionario::PalabrasLongitud(int longitud) const{
    vector<string> resultado;
    for(auto it = palabras.cbegin(); it != palabras.cend(); ++it){
        if (int(it->length()) == longitud){
            resultado.push_back(*it);
        }
    }
    return resultado;
}

// ===== Implementación del iterador =====

Diccionario::iterator::iterator (){
    it = set<string>::iterator();
}

Diccionario::iterator::iterator (set<string>::iterator i){
    it = i;
}

string Diccionario::iterator::operator *(){
    return *it;
}

Diccionario::iterator & Diccionario::iterator::operator ++(){
    ++it;
    return *this;
}

bool Diccionario::iterator::operator ==(const iterator &i){
    return it == i.it;
}

bool Diccionario::iterator::operator !=(const iterator &i){
    return it != i.it;
}

Diccionario::iterator Diccionario::begin(){
    return Diccionario::iterator(palabras.begin());
}

Diccionario::iterator Diccionario::end(){
    return Diccionario::iterator(palabras.end());
}

// ===== Operadores de flujo =====

ostream& operator<<(ostream& out, const Diccionario& dic){
    // como es friend, puede acceder a dic.palabras
    for(auto it = dic.palabras.begin(); it != dic.palabras.end(); ++it){
        out << *it << endl;
    }
    return out;
}

istream& operator>>(istream& in, Diccionario& dic){
    dic.palabras.clear();
    string palabra;
    while (in >> palabra){
        dic.palabras.insert(palabra);
    }
    return in;
}
