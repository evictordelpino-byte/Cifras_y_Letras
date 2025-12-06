#ifndef __BOLSA_LETRAS_H__
#define __BOLSA_LETRAS_H__

#include <set>
#include <iostream>
#include <string>

#include "letras.h"
#include "letras_set.h"

using namespace std;

/**
 * @brief TDA BolsaLetras
 *
 */

 class BolsaLetras {
    private:
        multiset<LETRASInfo> Letras;
    public:
        /**
         * @brief Construye una bolsa vacia
         * 
         */
        BolsaLetras();

        /**
         * @brief Construye una bolsa de letras con un Letras_Set
         * 
         * @param letras Letras_Set del que sacar la bolsa
         */
        BolsaLetras(const Letras_Set& letras);

        /**
         * @brief Construye una bolsa a partir de un multiset de letras
         * 
         * @param letras multiset del que sacar las letras
         */
        BolsaLetras(const multiset<LETRASInfo>& letras);

        /**
         * @brief Destructor
         * 
         */
        ~BolsaLetras();

        // Métodos de consulta
        /**
         * @brief Comprueba si la bolsa esta vacia
         * 
         * @return true si esta vacia
         * @return false si no esta vacia
         */
        bool EstaVacia() const;

        /**
         * @brief Devuelve la cantidad de letras de la bolsa
         * 
         * @return int cantidad de letras de la bolsa
         */
        int size() const;

        /**
         * @brief Coprueba si una letra esta en la bolsa
         * 
         * @param letra letra a comprobar
         * @return true si existe la letra
         * @return false si no existe la letra
         */
        bool Pertenece(LETRASInfo letra) const;

        /**
         * @brief Saca una determinada cantidad de letras de la bolsa
         * 
         * @param n numero de letras que sacar
         * @return multiset<LETRASInfo> letras sacadas de la bolsa
         */
        multiset<LETRASInfo> saca(int n);

        // Métodos de modificación
        /**
         * @brief Inserta una letra en la bolsa
         * 
         * @param letra letra a insertar
         */
        void Insertar(LETRASInfo letra);

        /**
         * @brief Borra la primera aparicion de una letra en la bolsa
         * 
         * @param letra letra a borrar
         */
        void Borrar(LETRASInfo letra);
        
        // Sobrecarga de operadores
        /**
         * @brief muestra en un flujo de salida una bolsa
         * 
         * @param os flujo de salida
         * @param bolsa bolsa a mostrar
         * @return ostream& flujo de salida
         */
        friend ostream& operator<<(ostream& os, const BolsaLetras& bolsa);
 };
#endif
