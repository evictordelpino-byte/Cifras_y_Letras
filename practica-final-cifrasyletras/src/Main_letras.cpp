#include <iostream>
#include <string>
#include <map>
#include <cctype>

#include "diccionario.h"
#include "bolsa_letras.h"
#include "letras_set.h"
#include "letras.h"

using namespace std;

// Helpers para normalizar mayúsculas/minúsculas
string a_minusculas(string s) {
    for (char &c : s) c = tolower(c);
    return s;
}

string a_mayusculas(string s) {
    for (char &c : s) c = toupper(c);
    return s;
}

// MAIN PARA EL PROGRAMA DE LAS LETRAS
bool chequea_posible(const string& palabra_mayus, const Letras_Set& letras_sacadas);
int puntuacion_palabra(const string& palabra, const Letras_Set& letras); // ya definida en letras_set.cpp
set<string> SolucionesPosibles(const Letras_Set& letras_sacadas, const Diccionario& dic, char modo_juego);

int main(int argc, char** argv) {

    if(argc < 5) {
        cout << "Como jugar: " << endl;
        cout << "Escribir: ./letras <diccionario.txt> <letras.txt> <num_letras> <modo_juego>" << endl;
        cout << "diccionario.txt: fichero de texto con el diccionario de palabras" << endl;
        cout << "letras.txt: fichero de texto con las letras y su información (puntuacion y repeticiones)" << endl;
        cout << "num_letras: número de letras a utilizar en la partida" << endl;
        cout << "modo_juego: P para jugar por puntos y L para jugar por cantidad de letras" << endl;
        return 1;
    }
    if(toupper(argv[4][0]) != 'P' && toupper(argv[4][0]) != 'L') {
        cout << "Modo de juego no válido. Usar P para puntos o L para letras." << endl;
        return 1;
    }

    Diccionario dic(argv[1]);
    Letras_Set letras(argv[2]);  // conjunto completo de letras del juego
    cout << "Letras leidas" << endl;
    int num_letras = stoi(argv[3]);
    char modo_juego = toupper(argv[4][0]);

    bool jugando = true;
    while(jugando){
        // Creamos bolsa y sacamos letras aleatorias
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

        // Pedimos una palabra válida
        while (true) {
            cout << "Introduce una palabra formada con las letras sacadas: ";
            cin >> palabra_usuario;

            string palabra_dic   = a_minusculas(palabra_usuario);  // para el diccionario
            string palabra_mayus = a_mayusculas(palabra_usuario);  // para comprobar letras/puntuación

            if (!dic.Esta(palabra_dic)) {
                cout << "La palabra " << palabra_usuario << " no está en el diccionario." << endl;
                continue;
            }

            if (!chequea_posible(palabra_mayus, letras_sacadas)) {
                cout << "La palabra " << palabra_usuario << " no se puede formar con las letras sacadas." << endl;
                continue;
            }

            // Si llega aquí: está en el diccionario y se puede formar
            palabra_usuario = palabra_dic; // la guardamos en minúsculas (coherente con el diccionario)
            break;
        }

        // Calculamos la puntuación de la palabra elegida
        string palabra_mayus = a_mayusculas(palabra_usuario);

        cout << "La puntuación de la palabra " << palabra_usuario << " es: ";
        
        if(modo_juego == 'P')
            cout << puntuacion_palabra(palabra_mayus, letras) << " puntos." << endl;
        else if(modo_juego == 'L')
            cout << palabra_usuario.length() << " letras." << endl;

        // Buscamos las mejores soluciones posibles
        mejores_palabras = SolucionesPosibles(letras_sacadas, dic, modo_juego);

        cout << "Las mejores soluciones posibles son: " << endl;
        for(const string& palabra : mejores_palabras){
            cout << palabra << endl;
        }
        cout << "La puntuacion maxima era de: ";
        if(modo_juego == 'P')
            cout << puntuacion_palabra(a_mayusculas(*mejores_palabras.begin()), letras) << " puntos." << endl;
        else if(modo_juego == 'L')
            cout << (*mejores_palabras.begin()).length() << " letras." << endl;

        cout << "¿Quieres jugar otra partida? (s/n): ";
        char respuesta;
        do{
            cin >> respuesta;
            respuesta = toupper(respuesta);
            if(respuesta != 'S' && respuesta != 'N'){
                cout << "Introduzca una respuesta válida (s/n)." << endl;
            }else if(respuesta == 'N'){
                jugando = false;
            }
        }while(respuesta != 'S' && respuesta != 'N');
    }

    return 0;
}

// Comprueba si palabra_mayus se puede formar con las letras_sacadas
bool chequea_posible(const string& palabra_mayus, const Letras_Set& letras_sacadas) {
    // Contamos letras disponibles en letras_sacadas
    map<char,int> disponibles;
    for (auto it = letras_sacadas.begin(); it != letras_sacadas.end(); ++it) {
        LETRASInfo info = *it;
        disponibles[info.caracter()] += info.repeticiones();
    }

    // Contamos letras necesarias en la palabra
    map<char,int> necesarias;
    for (char c : palabra_mayus) {
        necesarias[c]++;
    }

    // Comprobamos que para cada letra hay suficientes en las disponibles
    for (auto &par : necesarias) {
        char letra = par.first;
        int veces = par.second;
        if (disponibles[letra] < veces)
            return false;
    }

    return true;
}

// Calcula las mejores soluciones posibles según el modo de juego
set<string> SolucionesPosibles(const Letras_Set& letras_sacadas, const Diccionario& dic, char modo_juego) {
    set<string> soluciones;
    int mejor_puntuacion = 0;
    vector<string> palabras_candidatas;

    // Calculamos el máximo número de letras que podemos usar (sumando repeticiones)
    int max_len = 0;
    for (auto it = letras_sacadas.begin(); it != letras_sacadas.end(); ++it) {
        LETRASInfo info = *it;
        max_len += info.repeticiones();
    }

    // Recogemos palabras del diccionario hasta longitud = max_len
    for(int len = 1; len <= max_len; ++len){
        vector<string> v = dic.PalabrasLongitud(len);
        palabras_candidatas.insert(palabras_candidatas.end(), v.begin(), v.end());
    }

    // Evaluamos cada palabra candidata
    for(const string& palabra_dic : palabras_candidatas){
        string palabra_mayus = a_mayusculas(palabra_dic);

        if (!chequea_posible(palabra_mayus, letras_sacadas))
            continue;

        int puntuacion_actual = 0;
        if(modo_juego == 'P'){
            puntuacion_actual = puntuacion_palabra(palabra_mayus, letras_sacadas);
            if(puntuacion_actual > mejor_puntuacion){
                mejor_puntuacion = puntuacion_actual;
                soluciones.clear();
                soluciones.insert(palabra_dic);
            } else if(puntuacion_actual == mejor_puntuacion){
                soluciones.insert(palabra_dic);
            }
        } else if(modo_juego == 'L'){
            if(int(palabra_dic.length()) > mejor_puntuacion){
                mejor_puntuacion = palabra_dic.length();
                soluciones.clear();
                soluciones.insert(palabra_dic);
            } else if(int(palabra_dic.length()) == mejor_puntuacion){
                soluciones.insert(palabra_dic);
            }
        }
    }
    return soluciones;
}

// en el directorio practica-final-cifrasyletras/
// compilar con: g++ -std=c++17 -Wall -Wextra -I include -o letras src/Main_letras.cpp src/diccionario.cpp src/letras.cpp src/letras_set.cpp src/bolsa_letras.cpp


// en el directorio practica-final-cifrasyletras/
// compilar con: g++ -std=c++17 -Wall -Wextra -I include -o letras src/Main_letras.cpp src/diccionario.cpp src/letras.cpp src/letras_set.cpp src/bolsa_letras.cpp