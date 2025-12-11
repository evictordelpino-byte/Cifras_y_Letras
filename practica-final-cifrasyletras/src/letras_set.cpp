#include "letras_set.h"
#include "letras.h"

Letras_Set::Letras_Set(){
    letras = set<LETRASInfo>();
}

Letras_Set::Letras_Set(const multiset<LETRASInfo>& letras_repetidas){
    letras = set<LETRASInfo>();
   // si vacia nada
    if (letras_repetidas.empty())
    return;
    //tomamos primera letra
    LETRASInfo letra_insertar = *letras_repetidas.begin();
    //recorremos resto para agrupar repeticiones
    for(auto it = ++letras_repetidas.begin(); it != letras_repetidas.end(); ++it){
        LETRASInfo letra_actual = *it;
        //si misma letra aumentamos repeticiones
        if(letra_actual.caracter() == letra_insertar.caracter()){
            letra_insertar.SetRepeticiones(letra_insertar.repeticiones() + 1);
        } else {
            // Si cambia la letra, insertamos la agrupada y empezamos una nueva
            letras.insert(letra_insertar);
            letra_insertar = letra_actual;
        }
    }
    //insertamos el ultimo grupo de letras
    letras.insert(letra_insertar);
}

Letras_Set::Letras_Set(const string& nombre_fichero){
    letras.clear();

    ifstream in(nombre_fichero);
    if (!in) {
        cerr << "Error al abrir el fichero " << nombre_fichero << endl;
        exit(1);
    }

    string header;
    getline(in, header);  // Saltamos la primera línea "Letra Cantidad Puntos"

    LETRASInfo L;
    while (in >> L) {
        letras.insert(L);
    }
}




Letras_Set::~Letras_Set(){
    letras.clear();
}

int Letras_Set::puntuacion(char letra) const{
    auto it = letras.find(LETRASInfo(letra, 0, 0));
    if(it != letras.end()){
        return (*it).puntuacion();
    } else {
        return 0;
    }
}

void Letras_Set::insert(LETRASInfo letra){
    letras.insert(letra);
}

void Letras_Set::insert(char letra){
    if(find(LETRASInfo(letra, 0, 0)) == letras.end()){
        letras.insert(LETRASInfo(letra, 1, 1));
    } else {
        // Si ya existe, aumentar las repeticiones
        auto it = find(LETRASInfo(letra, 0, 0));
        LETRASInfo letra_actual = *it;
        letras.erase(it);
        letra_actual.SetRepeticiones(letra_actual.repeticiones() + 1);
        letras.insert(letra_actual);
    }
}

int Letras_Set::size() const{
    return letras.size();
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

set<LETRASInfo>::iterator Letras_Set::find(LETRASInfo letra){
    auto it = letras.find(letra);
    return it;
}

const set<LETRASInfo>::iterator Letras_Set::find(LETRASInfo letra) const{
    auto it = letras.find(letra);
    return it;
}

ostream& operator<<(ostream& os, const Letras_Set& letras_){
    for(auto it = letras_.begin(); it != letras_.end(); ++it){
        os << (*it).caracter() << " " << (*it).repeticiones() << " " << (*it).puntuacion() << endl;
    }
    return os;
}

int puntuacion_palabra(const string& palabra, const Letras_Set& letras){
    int puntos = 0;
    for(char c : palabra){
        puntos += letras.puntuacion(c);
    }
    return puntos;
}

bool Letras_Set::isEmpty() const {
    return letras.empty();
}

void Letras_Set::erase(LETRASInfo letra){
    letras.erase(letra);
}
