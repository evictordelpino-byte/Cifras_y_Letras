#ifndef __DICCIONARIO_H__
#define __DICCIONARIO_H__

#include <set>
#include <iostream>
#include <iofstream>
#include <string>

using namespace std;

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
        bool buscar(const string& palabra) const;

        /**
         * @brief Devuelve un iterador al inicio de la lista de palabras
         * @return Iterador al inicio de la lista de palabras
         */
        set<string>::const_iterator begin() const;

        /**
         * @brief Devuelve un iterador al final de la lista de palabras
         * @return Iterador al final de la lista de palabras
         */
        set<string>::const_iterator end() const;

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
};

#endif
