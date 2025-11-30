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
         * @brief 
         * 
         */
        LETRASInfo();

        /**
         * @brief 
         * 
         */
        LETRASInfo(char c, int r, int p);

        /**
         * @brief 
         * 
         * @return char 
         */
        char caracter() const;

        /**
         * @brief 
         * 
         * @return int 
         */
        int repeticiones() const;

        /**
         * @brief 
         * 
         * @return int 
         */
        int puntuacion() const;

        /**
         * @brief 
         * 
         * @param c 
         */
        void SetRepeticiones(int r);
 };

#endif
