#ifndef CIFRAS_SET_H
#define CIFRAS_SET_H

#include <vector>
#include <set>


//#include <multiset>


using namespace std;

class cifras_set {
public:
    /**
     * @brief Struct que guarda una operación y su resultado para imprimirlo
     * 
     * @param a,b numeros de la operacion
     * @param op tipo de operacion
     * @param resultado resultado de la operacion
     */
    struct Operacion {
        int a;
        int b;
        char op;
        int resultado;
    };

    /**
     * @brief Struct que guarda el resultado del calculo de operaciones y si es exacto
     * 
     * @param exacto valor que indica si la solución es exacta
     * @param objetivo valor objetivo que habría que alcanzar
     * @param mejor_valor mejor valor alcanzado con las operaciones
     * @param diferencia diferencia entre el objetivo y el mejor valor
     * @param operaciones operaciones realizadas hasta llegar al resultado
     */
    struct Solucion {
        bool exacto;
        int objetivo;
        int mejor_valor;
        int diferencia;
        vector<Operacion> operaciones;
    };

    /**
     * @brief Funcion que resuelve un problema cifras dados unos numeros iniciales y un objetivo
     * 
     * @param numeros_iniciales numeros empleados para alcanzar el objetivo
     * @param objetivo objetivo a alcanzar mediante las operaciones de numeros
     * @return Solucion, solucion al caso dado de cifras
     */
    Solucion resolver(const vector<int> &numeros_iniciales, int objetivo);

private:
    int objetivo_actual;
    int mejor_encontrado;
    int diferencia;
    set< multiset<int> > visitados;
    vector<Operacion> mejores_operaciones;

    /**
     * @brief Genera las operaciones posibles entre a y b
     * 
     * @param a valor a operar
     * @param b valor a operar
     * @return vector<Operacion> operaciones posibles entre a y b
     */
    vector<Operacion> generarOperaciones(int a, int b) const;

    /**
     * @brief Coprueba si el resultado de ciertas operaciones es mejor que el resultado actual
     *      cambiando el valor de diferencia, mejor_actual y mejores operaciones en caso afirmativo
     * 
     * @param numeros numeros actuales
     * @param operaciones_hechas operaciones realizadas hasta el momento
     */
    void probarMejoria(const vector<int> &numeros,
                       const vector<Operacion> &operaciones_hechas);

    /**
    * @brief busca recursivamente la solucion dados unos numeros y unas operaciones
    * 
    * @param numeros numeros introducidos del problema cifras
    * @param operaciones_hechas operaciones hechas hasta el momento
    */
    void buscar(vector<int> numeros,
                vector<Operacion> operaciones_hechas);
};

#endif // CIFRAS_SET_H

