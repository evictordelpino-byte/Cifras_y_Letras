#ifndef CIFRAS_SOLVER_H
#define CIFRAS_SOLVER_H

#include <vector>
#include <set>
// #include <multiset> // según el compilador puede bastar con <set>, pero lo dejo explícito

class CifrasSolver {
public:
    // Estructura para devolver el resultado al usuario
    struct Resultado {
        bool exacto;        // true si se ha llegado exactamente al objetivo
        int objetivo;       // objetivo que se quería alcanzar
        int mejor_valor;    // mejor número obtenido
        int diferencia;     // distancia entre mejor_valor y objetivo
    };

    // Método principal que resuelve una tirada
    Resultado resolver(const std::vector<int> &numeros, int objetivo);

private:
    // Estructura interna para manejar operaciones entre dos números
    struct Operacion {
        int a;
        int b;
        char op;       // '+', '-', '*', '/'
        int resultado;
    };

    // Estado interno del algoritmo de búsqueda
    int objetivo_actual;                      // objetivo con el que estamos trabajando
    int mejor_encontrado;                    // mejor valor encontrado hasta el momento
    int diferencia;                          // |mejor_encontrado - objetivo_actual|
    std::set< std::multiset<int> > visitados; // estados de números ya explorados

    // Funciones auxiliares
    std::vector<Operacion> generarOperaciones(int a, int b) const;
    void probarMejoria(const std::vector<int> &nums);
    void backtrack(std::vector<int> nums);
};

#endif // CIFRAS_SOLVER_H
