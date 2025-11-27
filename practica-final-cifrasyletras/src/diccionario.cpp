#include "diccionario.h"

#include <set>
#include <iostream>
#include <iofstream>
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
    istream in = ifstream(nombre_fichero);
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
    for(auto it = palabras.begin(); it != palabras.end(); ++it){
        cout << *it << endl;
    }
}

bool DICCIONARIO::buscar(const string& palabra) const{
    return palabras.find(palabra) != palabras.end();
}

set<string>::const_iterator DICCIONARIO::begin() const{
    return palabras.cbegin();
}

set<string>::const_iterator DICCIONARIO::end() const{
    return palabras.cend();
}
set<string>::iterator DICCIONARIO::begin(){
    return palabras.begin();
}

set<string>::iterator DICCIONARIO::end(){
    return palabras.end();
}