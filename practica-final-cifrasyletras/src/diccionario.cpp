#include "diccionario.h"

#include <set>
#include <iostream>
#include <fstream>
#include <string>

using namespace std;

DICCIONARIO::DICCIONARIO(){
    palabras = set<string>();
}

DICCIONARIO::DICCIONARIO(const string& nombre_fichero){
    cargar_diccionario(nombre_fichero);
}

DICCIONARIO::~DICCIONARIO(){
    palabras.clear();
}

bool DICCIONARIO::cargar_diccionario(const string &nombre_fichero){
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

void DICCIONARIO::mostrar_diccionario() const{
    cout << this;
}

int DICCIONARIO::size() const {
    return palabras.size();
}

bool DICCIONARIO::Esta(const string& palabra) const{
    return palabras.find(palabra) != palabras.end();
}

vector<string> DICCIONARIO::PalabrasLongitud(int longitud) const{
    vector<string> resultado;
    for(auto palabra = palabras.cbegin(); palabra != palabras.cend(); ++palabra){
        if(int(palabra->length()) == longitud){
            resultado.push_back(*palabra);
        }
    }
    return resultado;
}

DICCIONARIO::iterator::iterator (){
    it = set<string>::iterator();
}
DICCIONARIO::iterator::iterator (set<string>::iterator i){
    it = i;
}
string DICCIONARIO::iterator::operator *(){
    return *it;
}
DICCIONARIO::iterator & DICCIONARIO::iterator::operator ++(){
    ++it;
    return *this;
}
bool DICCIONARIO::iterator::operator ==(const iterator &i){
    return it == i.it;
}
bool DICCIONARIO::iterator::operator !=(const iterator &i){
    return it != i.it;
}


DICCIONARIO::iterator DICCIONARIO::begin(){
    return DICCIONARIO::iterator(palabras.begin());
}

DICCIONARIO::iterator DICCIONARIO::end(){
    return DICCIONARIO::iterator(palabras.end());
}

ostream& operator<<(ostream& out, DICCIONARIO& dic){
    for(auto it = dic.begin(); it != dic.end(); ++it){
            out << *it << endl;
    }
    return out;
}

istream& operator>>(istream& in, DICCIONARIO& dic){
    dic.palabras.clear();
    string palabra;
    while(in >> palabra){
        dic.palabras.insert(palabra);
    }
    return in;
}