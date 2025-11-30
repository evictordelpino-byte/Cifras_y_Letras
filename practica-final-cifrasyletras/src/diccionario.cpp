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

set<string>::const_iterator DICCIONARIO::cbegin() const{
    return palabras.cbegin();
}

set<string>::const_iterator DICCIONARIO::cend() const{
    return palabras.cend();
}
set<string>::iterator DICCIONARIO::begin(){
    return palabras.begin();
}

set<string>::iterator DICCIONARIO::end(){
    return palabras.end();
}

ostream& operator<<(ostream& out, const DICCIONARIO& dic){
    for(auto it = dic.cbegin(); it != dic.cend(); ++it){
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