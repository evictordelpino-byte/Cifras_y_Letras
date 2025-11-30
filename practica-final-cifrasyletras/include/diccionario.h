#include <set>
#include <vector>
#include <iostream>
#include <fstream>
#include <string>

using namespace std;

#ifndef __DICCIONARIO_H__
#define __DICCIONARIO_H__


/**
 * @brief TDA DICCIONARIO
 * @details Almacena las palabras de un fichero de texto y permite iterar sobre ellas
 *
 */

class DICCIONARIO {
    private:
        set<string> palabras; /**< Lista que almacena las palabras del diccionario */
    public:
        /**
         * @brief Constructor por defecto de la clase DICCIONARIO
         */
        DICCIONARIO();

        /**
         * @brief Constructor de la clase DICCIONARIO que carga las palabras de un fichero
         * @param nombre_fichero Nombre del fichero de texto que contiene las palabras
         */
        DICCIONARIO(const string& nombre_fichero);

        /**
         * @brief destructor de la clase DICCIONARIO
         * 
         */
        ~DICCIONARIO();

        /**
         * @brief Carga las palabras de un fichero de texto en el diccionario
         * @param nombre_fichero Nombre del fichero de texto que contiene las palabras
         * @return true si se ha cargado correctamente, false en caso contrario
         */
        bool cargar_diccionario(const string &nombre_fichero);

        /**
         * @brief Muestra todas las palabras del diccionario por la salida estándar
         */
        void mostrar_diccionario() const;

        /**
         * @brief Busca una palabra en el diccionario
         * @param palabra Palabra a buscar
         * @return true si la palabra se encuentra en el diccionario, false en caso contrario
         */
        bool Esta(const string& palabra) const;

        /**
         * @brief Muestra todas las palabras del diccionario de una longitud dada
         * 
         * @param longitud Longitud de las palabras a buscar
         * @return vector<string> Vector con las palabras de la longitud dada
         */
        vector<string> PalabrasLongitud(int longitud) const;

        /**
         * @brief Devuelve un iterador al inicio de la lista de palabras
         * @return Iterador al inicio de la lista de palabras
         */
        set<string>::const_iterator cbegin() const;

        /**
         * @brief Devuelve un iterador al final de la lista de palabras
         * @return Iterador al final de la lista de palabras
         */
        set<string>::const_iterator cend() const;

        /**
         * @brief Devuelve un iterador al inicio de la lista de palabras
         * @return Iterador al inicio de la lista de palabras
         */
        set<string>::iterator begin();

        /**
         * @brief Devuelve un iterador al final de la lista de palabras
         * @return Iterador al final de la lista de palabras
         */
        set<string>::iterator end();

        /**
         * @brief Sobrecarga del operador de inserción para escribir el diccionario en un flujo de salida
         * 
         * @param out Flujo de salida
         * @param dic Diccionario a escribir
         * @return fstream& Flujo de salida modificado
         */
        friend ostream& operator<<(ostream& out, const DICCIONARIO& dic);

        /**
         * @brief Sobrecarga del operador de extracción para leer un diccionario desde un flujo de entrada
         * 
         * @param in Flujo de entrada
         * @param dic Diccionario donde se almacenarán las palabras leídas
         * @return fstream& Flujo de entrada modificado
         */
        friend istream& operator>>(istream& in, DICCIONARIO& dic);
};
/*
ostream& operator<<(ostream& out, const DICCIONARIO& dic);
istream& operator>>(istream& in, DICCIONARIO& dic);
*/
#endif
