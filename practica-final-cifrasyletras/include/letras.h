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
         */
        LETRASInfo(char c, int r, int p);

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

        LETRASInfo& operator=(const LETRASInfo& other);

        friend istream& operator>>(istream& is, LETRASInfo& letra);
        friend ostream& operator<<(ostream& os, const LETRASInfo& letra);
 };

#endif
