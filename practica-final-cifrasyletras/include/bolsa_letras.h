#ifndef __BOLSA_LETRAS_H__
#define __BOLSA_LETRAS_H__

#include <set>
#include <iostream>
#include <string>

using namespace std;

/**
 * @brief TDA BolsaLetras
 *
 */

 class BolsaLetras {
    private:
        multiset<char> Letras;
    public:
        // Constructor por defecto
        BolsaLetras();

        // Constructor con parámetros
        BolsaLetras(const multiset<char>& letras);

        // Destructor
        ~BolsaLetras();

        // Métodos de consulta
        bool EstaVacia() const;
        int Tam() const;
        bool Pertenece(char letra) const;

        // Métodos de modificación
        void Insertar(char letra);
        void Borrar(char letra);
        
        // Sobrecarga de operadores
        friend ostream& operator<<(ostream& os, const BolsaLetras& bolsa);

 };
#endif
