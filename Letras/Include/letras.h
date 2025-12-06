#include <iostream>

#ifndef __LETRAS_H__
#define __LETRAS_H__

/**
 * @brief TDA LETRASInfo
 *
 * Contiene información sobre un determinado carácter del juego de las
 * letras. En concreto, almacena información sobre el número de repeticiones de
 * la letra en la partida y de la puntuación que otorga al utilizarse en una
 * palabra
 */

 class LETRASInfo {
    private:
        char c; // caracter
        int r; // repeticiones
        int p; // puntuacion
    public:
        /**
         * @brief Constructor por defecto
         * 
         */
        LETRASInfo();

        /**
         * @brief Constructor con parámetros
         * 
         * @param c caracter
         * @param r repeticiones
         * @param p puntuacion
         */
        LETRASInfo(char c, int r, int p);

        /**
         * @brief Construye una letra a partir de otra
         * 
         * @param otro letra a copiar
         */
        LETRASInfo(const LETRASInfo& otro);


        /**
         * @brief devuelve el caracter de la letra
         * 
         * @return char 
         */
        char caracter() const;

        /**
         * @brief devuelve el número de repeticiones de la letra
         * 
         * @return int 
         */
        int repeticiones() const;

        /**
         * @brief devuelve la puntuación de la letra
         * 
         * @return int 
         */
        int puntuacion() const;

        /**
         * @brief Cambia el número de repeticiones
         * 
         * @param r 
         */
        void SetRepeticiones(int r);

        /**
         * @brief sobrecarga del operador de asignacion
         *      asigna el valor de una letra a otra
         * 
         * @param otro letra que se copia
         * @return LETRASInfo& 
         */
        LETRASInfo& operator=(const LETRASInfo& otro);

        /**
         * @brief Coprueba si una letra es igual a otra
         * 
         * @param otro letra con la que comparar
         * @return true si es igual
         * @return false si no es igual
         */
        bool operator==(const LETRASInfo& otro) const;

        /**
         * @brief Coprueba si una letra es igual a otra
         * 
         * @param otro letra con la que comparar
         * @return true si es igual
         * @return false si no es igual
         */
        bool operator==(char otro) const;

        /**
         * @brief Comprueba si una letra es menor a otra
         * 
         * @param otro letra con la que comparar
         * @return true si es menor
         * @return false si es mayor
         */
        bool operator<(const LETRASInfo& otro) const;

        /**
         * @brief Comprueba si una letra es menor a otra
         * 
         * @param otro letra con la que comparar
         * @return true si es menor
         * @return false si es mayor
         */
        bool operator<(char otro) const;

        //Sobrecarga de operadores
        /**
         * @brief recibe una letra mediante un flujo de entrada
         * 
         * @param is 
         * @param letra 
         * @return std::istream& 
         */
        friend std::istream& operator>>(std::istream& is, LETRASInfo& letra);

        /**
         * @brief Muestra una letra por un flujo de salida
         * 
         * @param os 
         * @param letra 
         * @return std::ostream& 
         */
        friend std::ostream& operator<<(std::ostream& os, const LETRASInfo& letra);
 };

#endif
