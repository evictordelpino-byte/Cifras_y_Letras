#include <iostream>
#include <string>

#include "diccionario.h"
#include "bolsa_letras.h"
#include "letras_set.h"
#include "letras.h"

using namespace std;

// MAIN PARA EL PROGRAMA DE LAS LETRAS
bool chequea_posible(const string& palabra, const Letras_Set& letras_sacadas);
int puntuacion_palabra(const string& palabra, const Letras_Set& letras);
set<string> SolucionesPosibles(const Letras_Set& letras_sacadas, const Diccionario& dic, char modo_juego);

int main(int argc, char** argv) {

    if(argc < 5) {
        cout << "Como jugar: " << endl;
        // cout << "Escribir: " << argv[0] << " <diccionario.txt> <letras.txt> <num_letras> <modo_juego>" << endl;
        cout << "Escribir: ./letras <diccionario.txt> <letras.txt> <num_letras> <modo_juego>" << endl;
        cout << "diccionario.txt: fichero de texto con el diccionario de palabras" << endl;
        cout << "letras.txt: fichero de texto con las letras y su información (puntuacion y repeticiones)" << endl;
        cout << "num_letras: número de letras a utilizar en la partida" << endl;
        cout << "modo_juego: P para jugar por puntos y L par jugar por cantidad de letras" << endl;
        return 1;
    }
    if(toupper(argv[4][0]) != 'P' && toupper(argv[4][0]) != 'L') {
        cout << "Modo de juego no válido. Usar P para puntos o L para letras." << endl;
        return 1;
    }

    Diccionario dic(argv[1]);
    Letras_Set letras(argv[2]);
    cout << "Letras leidas" << endl;
    int num_letras = stoi(argv[3]);
    char modo_juego = argv[4][0];

    bool jugando = true;
    while(jugando){
        BolsaLetras bolsa(letras);
        Letras_Set letras_sacadas(bolsa.saca(num_letras));

        string palabra_usuario;
        set<string> mejores_palabras;

        cout << "Diccionario cargado con " << dic.size() << " palabras." << endl;

        cout << "Letras sacadas: " << endl;
        for(auto it = letras_sacadas.begin(); it != letras_sacadas.end(); ++it) {
            cout << (*it).caracter() << " ";
        }
        cout << endl;

        do{
            cout << "Introduce una palabra formada con las letras sacadas: ";
            cin >> palabra_usuario;

            if(!dic.Esta(palabra_usuario)) {
                cout << "La palabra " << palabra_usuario << " no está en el diccionario." << endl;
            }else if(!chequea_posible(palabra_usuario, letras_sacadas))
                cout << "La palabra " << palabra_usuario << " no se puede formar con las letras sacadas." << endl;

        }while(!dic.Esta(palabra_usuario) || !chequea_posible(palabra_usuario, letras_sacadas));

        cout << "la punctuación de la palabra " << palabra_usuario << " es: ";
        
        if(modo_juego == 'P')
            cout << puntuacion_palabra(palabra_usuario, letras) << "puntos." << endl;
        else if(modo_juego == 'L')
            cout << palabra_usuario.length() << " letras." << endl;

        mejores_palabras = SolucionesPosibles(letras_sacadas, dic, modo_juego);

        cout << "Las mejores soluciones posibles son: " << endl;
        for(const string& palabra : mejores_palabras){
            cout << palabra << endl;
        }
        cout << "La puntuacion maxima era de: ";
        if(modo_juego == 'P')
            cout << puntuacion_palabra(*mejores_palabras.begin(), letras) << " puntos." << endl;
        else if(modo_juego == 'L')
            cout << (*mejores_palabras.begin()).length() << " letras." << endl;

        cout << "¿Quieres jugar otra partida? (s/n): ";
        char respuesta;
        do{
            cin >> respuesta;
            if(toupper(respuesta) != 'S' || std::toupper(respuesta) != 'N'){
                cout << "Introduzca una respuesta válida (s/n)." << endl;
            }else if(toupper(respuesta) == 'N'){
                jugando = false;
            }
        }while(toupper(respuesta) != 'S' && toupper(respuesta) != 'N');
    }

    return 0;
}

bool chequea_posible(const string& palabra, const Letras_Set& letras_sacadas) {
    Letras_Set letras_palabra;
    for(char c : palabra){
        letras_palabra.insert(c);
    }
    for(auto it = letras_palabra.begin(); it != letras_palabra.end(); ++it){
        if((*it).repeticiones() > (*letras_sacadas.find(*it)).repeticiones()){
            return false;
        }
    }
    return true;
}

set<string> SolucionesPosibles(const Letras_Set& letras_sacadas, const Diccionario& dic, char modo_juego) {
    set<string> soluciones;
    int mejor_puntuacion = 0;
    vector<string> palabras_candidatas;
    for(int len = 1; len <= letras_sacadas.size(); ++len){
        palabras_candidatas.insert(palabras_candidatas.end(), dic.PalabrasLongitud(len).begin(), dic.PalabrasLongitud(len).end());
    }
    // Para cada palabra evaluamos si se puede formar con las letras sacadas y seleccionamos las mejores
    for(const string& palabra : palabras_candidatas){
        Letras_Set letras_palabra;
        for(char c : palabra){
            letras_palabra.insert(c);
        }
        bool puede_formarse = true;
        for(auto it = letras_palabra.begin(); it != letras_palabra.end(); ++it){
            if((*it).repeticiones() > (*letras_sacadas.find(*it)).repeticiones()){
                puede_formarse = false;
            }
        }
        if(puede_formarse){
            int puntuacion_actual = 0;
            if(modo_juego == 'P'){
                puntuacion_actual = puntuacion_palabra(palabra, letras_sacadas);
                if(puntuacion_actual > mejor_puntuacion){
                    mejor_puntuacion = puntuacion_actual;
                    soluciones.clear();
                    soluciones.insert(palabra);
                } else if(puntuacion_actual == mejor_puntuacion){
                    soluciones.insert(palabra);
                }
            } else if(modo_juego == 'L'){
                if(int(palabra.length()) > mejor_puntuacion){
                    mejor_puntuacion = palabra.length();
                    soluciones.clear();
                    soluciones.insert(palabra);
                } else if(int(palabra.length()) == mejor_puntuacion){
                    soluciones.insert(palabra);
                }
            }
        }
    }
    return soluciones;
}

// en el directorio practica-final-cifrasyletras/
// compilar con: g++ -std=c++17 -Wall -Wextra -I include -o letras src/Main_letras.cpp src/diccionario.cpp src/letras.cpp src/letras_set.cpp src/bolsa_letras.cpp