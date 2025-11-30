#include "bolsa_letras.h"
#include "letras.h"

using namespace std;

#ifndef __LETRAS_SET_H__
#define __LETRAS_SET_H__

// MAIN PARA EL PROGRAMA DE LAS LETRAS

/**
 * @brief TDA LetterInfo
 *
 * Contiene información sobre un determinado carácter del juego de las
 * letras. En concreto, almacena información sobre el número de repeticiones de
 * la letra en la partida y de la puntuación que otorga al utilizarse en una
 * palabra
 */



/**
 * @brief TDA LettersSet
 *
 * Este TDA representa un conjunto de letras, con la información necesaria para
 * jugar una partida al juego de las letras, es decir, el número de repeticiones
 * que tenemos de la letra y la puntuación que dicha letra otorga cuando se
 * utiliza en una palabra
 */

 class LettersSet {
    private:
        set<LETRASInfo> letras;
    public:
        // Constructor por defecto
        LettersSet();

        // Constructor con parámetros
        LettersSet(const set<LETRASInfo>& letras);

        // Destructor
        ~LettersSet();

        // Métodos de consulta
        bool isEmpty() const;
        int size() const;
        bool contains(LETRASInfo letra) const;

        // Métodos de modificación
        void insert(LETRASInfo letra);
        void erase(LETRASInfo letra);
        
        // Sobrecarga de operadores
        friend ostream& operator<<(ostream& os, const LettersSet& letrasSet);

 };
#endif
