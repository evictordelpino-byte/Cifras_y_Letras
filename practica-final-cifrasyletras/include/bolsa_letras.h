#ifndef __BOLSA_LETRAS_H__
#define __BOLSA_LETRAS_H__

#include <set>
#include <iostream>
#include <string>

#include "letras.h"

using namespace std;

/**
 * @brief TDA BolsaLetras
 *
 */

 class BolsaLetras {
    private:
        set<LETRASInfo> Letras;
    public:
        // Constructor por defecto
        BolsaLetras();

        // Constructor con parámetros
        BolsaLetras(const set<LETRASInfo>& letras);

        // Destructor
        ~BolsaLetras();

        // Métodos de consulta
        bool EstaVacia() const;
        int size() const;
        bool Pertenece(LETRASInfo letra) const;

        // Métodos de modificación
        void Insertar(LETRASInfo letra);
        void Borrar(LETRASInfo letra);
        
        // Sobrecarga de operadores
        friend ostream& operator<<(ostream& os, const BolsaLetras& bolsa);

 };
#endif
