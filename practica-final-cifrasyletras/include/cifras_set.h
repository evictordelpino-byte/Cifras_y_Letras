#ifndef CIFRAS_SET_H
#define CIFRAS_SET_H

#include <vector>
#include <set>


//#include <multiset>
//>>>>>>> 048ca9c (Mis cambios locales en cifras y letras)

using namespace std;

class cifras_set {
public:
    struct Operacion {
        int a;
        int b;
        char op;
        int resultado;
    };

    struct Solucion {
        bool exacto;
        int objetivo;
        int mejor_valor;
        int diferencia;
        vector<Operacion> operaciones;
    };

    Solucion resolver(const vector<int> &numeros_iniciales, int objetivo);

private:
    int objetivo_actual;
    int mejor_encontrado;
    int diferencia;
    set< multiset<int> > visitados;
    vector<Operacion> mejores_operaciones;

    vector<Operacion> generarOperaciones(int a, int b) const;
    void probarMejoria(const vector<int> &numeros,
                       const vector<Operacion> &operaciones_hechas);
    void buscar(vector<int> numeros,
                vector<Operacion> operaciones_hechas);
};

#endif // CIFRAS_SET_H

