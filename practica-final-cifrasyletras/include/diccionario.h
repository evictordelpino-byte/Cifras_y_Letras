#include <set>
#include <vector>
#include <iostream>
#include <fstream>
#include <string>

using namespace std;

#ifndef __Diccionario_H__
#define __Diccionario_H__


/**
 * @brief TDA Diccionario
 * @details Almacena las palabras de un fichero de texto y permite iterar sobre ellas
 *
 */

class Diccionario {
    private:
        set<string> palabras; /**< Lista que almacena las palabras del diccionario */
    public:
        /**
         * @brief Constructor por defecto de la clase Diccionario
         */
        Diccionario();

        /**
         * @brief Constructor de la clase Diccionario que carga las palabras de un fichero
         * @param nombre_fichero Nombre del fichero de texto que contiene las palabras
         */
        Diccionario(const string& nombre_fichero);

        /**
         * @brief destructor de la clase Diccionario
         * 
         */
        ~Diccionario();

        /**
         * @brief Carga las palabras de un fichero de texto en el diccionario
         * @param nombre_fichero Nombre del fichero de texto que contiene las palabras
         * @return true si se ha cargado correctamente, false en caso contrario
         */
        bool cargar_diccionario(const string &nombre_fichero);

        /**
         * @brief Devuelve el numero de palabras en el diccionario
         **/
        int size() const ;

        /**
         * @brief Muestra todas las palabras del diccionario por la salida estándar
         */
        void mostrar_diccionario() const;

        /**
         * @brief Indica si una palabra está en el diccionario o no
         * @param palabra: la palabra que se quiere buscar
         * @return true si la palabra esta en el diccionario. False en caso contrario
         */
        bool Esta(const string& palabra) const;

        /**
         * @brief Obtiene todas las palabras en el diccionario de un longitud dada
         * @param longitud: la longitud de las palabras de salida
         * @return un vector con las palabras de longitud especifica en el parametro de entrada
         */
        vector<string> PalabrasLongitud(int longitud) const;

        class iterator{
            private:
            set<string>::iterator it;
            public:
            iterator ();
            iterator (set<string>::iterator i);
            string operator *();
            iterator & operator ++();
            bool operator ==(const iterator &i);
            bool operator !=(const iterator &i);
            friend class Diccionario;
        };
        iterator begin();
        iterator end();

        /**
         * @brief Sobrecarga del operador de inserción para escribir el diccionario en un flujo de salida
         * 
         * @param out Flujo de salida
         * @param dic Diccionario a escribir
         * @return fstream& Flujo de salida modificado
         */
        friend ostream& operator<<(ostream& out, const Diccionario& dic);

        /**
         * @brief Sobrecarga del operador de extracción para leer un diccionario desde un flujo de entrada
         * 
         * @param in Flujo de entrada
         * @param dic Diccionario donde se almacenarán las palabras leídas
         * @return fstream& Flujo de entrada modificado
         */
        friend istream& operator>>(istream& in, Diccionario& dic);
};

#endif
