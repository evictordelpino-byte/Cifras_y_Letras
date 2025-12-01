#include <iostream>
#include <string>
#include "diccionario.h"
#include "bolsa_letras.h"
#include "letras_set.h"

using namespace std;

// MAIN PARA EL PROGRAMA DE LAS LETRAS

int main(int argc, char** argv) {

    if(argc < 5) {
        cout << "Como jugar: " << endl;
        cout << "Escribir: " << argv[0] << " <diccionario.txt> <letras.txt> <num_letras> <modo_juego>" << endl;
        cout << "diccionario.txt: fichero de texto con el diccionario de palabras" << endl;
        cout << "letras.txt: fichero de texto con las letras y su información (puntuacion y repeticiones)" << endl;
        cout << "num_letras: número de letras a utilizar en la partida" << endl;
        cout << "modo_juego: P para jugar por puntos y L par jugar por cantidad de letras" << endl;
        return 1;
    }

    DICCIONARIO dic(argv[1]);
    Letras_Set letras(argv[2]);
    BolsaLetras bolsa(letras);
    int num_letras = stoi(argv[3]);
    char modo_juego = argv[4][0];

    Letras_Set letras_sacadas(bolsa.saca(num_letras));

    string palabra_usuario;

    cout << "Diccionario cargado con " << dic.size() << " palabras." << endl;

    cout << "Letras sacadas: " << endl;
    for(auto it = letras_sacadas.begin(); it != letras_sacadas.end(); ++it) {
        cout << (*it).caracter() << " ";
    }
    cout << endl;

    cin >> palabra_usuario;
}