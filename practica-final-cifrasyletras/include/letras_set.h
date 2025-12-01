#include "bolsa_letras.h"
#include "letras.h"
#include "diccionario.h"
#include <random>
#include <set>
#include <iostream>

using namespace std;

#ifndef __LETRAS_SET_H__
#define __LETRAS_SET_H__


/**
 * @brief TDA LettersSet
 *
 * Este TDA representa un conjunto de letras, con la información necesaria para
 * jugar una partida al juego de las letras, es decir, el número de repeticiones
 * que tenemos de la letra y la puntuación que dicha letra otorga cuando se
 * utiliza en una palabra
 */

 class Letras_Set {
    private:
        set<LETRASInfo> letras;

        set<LETRASInfo>::iterator find(LETRASInfo letra);
    public:
        // Constructor por defecto
        Letras_Set();

        // Constructor con parámetros
        Letras_Set(const multiset<LETRASInfo>& letras_repetidas);

        // Constructor a partir de un fichero
        Letras_Set(const string& nombre_fichero);

        // Destructor
        ~Letras_Set();

        // Métodos de consulta
        bool isEmpty() const;
        int size() const;
        bool contains(LETRASInfo letra) const;

        // Métodos de modificación
        void insert(LETRASInfo letra);
        void erase(LETRASInfo letra);
        
        // Sobrecarga de operadores
        friend ostream& operator<<(ostream& os, const Letras_Set& letrasSet);

        class iterator {
            private:
                set<LETRASInfo>::iterator it;
            public:
                iterator();
                iterator(const set<LETRASInfo>::iterator& other);
                iterator& operator++();
                iterator operator++(int);
                bool operator==(const iterator& other) const;
                bool operator!=(const iterator& other) const;
                LETRASInfo operator*() const;
                friend class Letras_Set;
        };
        iterator begin() const;
        iterator end() const;

 };
#endif

