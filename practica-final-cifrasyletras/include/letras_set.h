#include "bolsa_letras.h"
#include "letras.h"
#include "diccionario.h"
#include <random>
#include <set>
#include <iostream>
#include <fstream>


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
        /**
         * @brief Construye un Letras_Set por defecto
         * 
         */
        Letras_Set();

        /**
         * @brief Construye un Letras_Set con unas letras repetidas
         * 
         * @param letras_repetidas letras a introducir en letras
         */
        Letras_Set(const multiset<LETRASInfo>& letras_repetidas);

        /**
         * @brief Construye un Letras_Set a partir del nombre de un fichero
         * 
         * @param nombre_fichero nombre del fichero que contiene las letras
         */
        Letras_Set(const string& nombre_fichero);

        /**
         * @brief Destructor
         * 
         */
        ~Letras_Set();

        // Métodos de consulta
        /**
         * @brief Comprueba si esta vacion
         * 
         * @return true si esta vacion
         * @return false si no esta vacio
         */
        bool isEmpty() const;

        /**
         * @brief devuelve el numero de letras del Letras_Set
         * 
         * @return int numero de letras
         */
        int size() const;

        /**
         * @brief Devuelve la puntuacion de una letra
         * 
         * @param letra letra de la que se desea saber la puntuacion
         * @return int puntuacion de la letra
         */
        int puntuacion(char letra) const;

        /**
         * @brief Busca una letra en el Letras_Set
         * 
         * @param letra letra a buscar
         * @return const set<LETRASInfo>::iterator ubicacion de la letra
         */
        const set<LETRASInfo>::iterator find(LETRASInfo letra) const;

        // Métodos de modificación
        /**
         * @brief Inserta una letra
         * 
         * @param letra letra a insertar
         */
        void insert(LETRASInfo letra);

        /**
         * @brief Inserta una letra
         * 
         * @param letra letra a insertar
         */
        void insert(char letra);

        /**
         * @brief Borra una letra
         * 
         * @param letra letra a borrar
         */
        void erase(LETRASInfo letra);
        
        // Sobrecarga de operadores
        /**
         * @brief Operador usado para representar Letras_Set
         * 
         * @param os flujo de salida
         * @param letrasSet Letras_Set a representar
         * @return ostream& flujo de salida
         */
        friend ostream& operator<<(ostream& os, const Letras_Set& letrasSet);

        class iterator {
            private:
                set<LETRASInfo>::iterator it;
            public:
                /**
                 * @brief Construye un iterador por defecto
                 * 
                 */
                iterator();

                /**
                 * @brief Construye un iterador a partir de otro
                 * 
                 * @param other iterador base
                 */
                iterator(const set<LETRASInfo>::iterator& other);

                /**
                 * @brief Avanza a la siguiente posicion
                 * 
                 * @return iterator& siguiente posicion del iterador
                 */
                iterator& operator++();

                /**
                 * @brief Avanza a la siguiente posicion del iterador
                 * 
                 * @return iterator posicion del iterador antes de avanzar
                 */
                iterator operator++(int);

                /**
                 * @brief Comprueba si un iterador es igual a otro
                 * 
                 * @param other iterador a comparar
                 * @return true si es igual
                 * @return false si no es igual
                 */
                bool operator==(const iterator& other) const;

                /**
                 * @brief Comprueba si un iterador no es igual a otro
                 * 
                 * @param other iterador a comparar
                 * @return true si no es igual
                 * @return false si es igual
                 */
                bool operator!=(const iterator& other) const;

                /**
                 * @brief devuelve la letra apuntada por el iterador
                 * 
                 * @return LETRASInfo letra apuntada por el iterador
                 */
                LETRASInfo operator*() const;
                friend class Letras_Set;
        };

        /**
         * @brief Devuelve un iterador al principio del Letras_Set
         * 
         * @return iterator 
         */
        iterator begin() const;

        /**
         * @brief Devuelve un iterador al final del Letras_Set
         * 
         * @return iterator 
         */
        iterator end() const;

 };
#endif

