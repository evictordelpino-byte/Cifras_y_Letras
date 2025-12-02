#include "Diccionario.h"

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
    string palabra = "";
    ifstream in(nombre_fichero);
    if (in.fail()) {
        cerr << "Error al abrir el fichero: " << nombre_fichero << endl;
        return false;
    }

    while(in >> palabra){
        palabras.insert(palabra);
    }
    in.close();

    return true;
}

void Diccionario::mostrar_diccionario() const{
    cout << this;
}

int Diccionario::size() const {
    return palabras.size();
}

bool Diccionario::Esta(const string& palabra) const{
    return palabras.find(palabra) != palabras.end();
}

vector<string> Diccionario::PalabrasLongitud(int longitud) const{
    vector<string> resultado;
    for(auto palabra = palabras.cbegin(); palabra != palabras.cend(); ++palabra){
        if(int(palabra->length()) == longitud){
            resultado.push_back(*palabra);
        }
    }
    return resultado;
}

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

ostream& operator<<(ostream& out, Diccionario& dic){
    for(auto it = dic.begin(); it != dic.end(); ++it){
            out << *it << endl;
    }
    return out;
}

istream& operator>>(istream& in, Diccionario& dic){
    dic.palabras.clear();
    string palabra;
    while(in >> palabra){
        dic.palabras.insert(palabra);
    }
    return in;
}