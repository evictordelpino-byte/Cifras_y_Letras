#include "cifras_set.h"

#include <cstdlib>
#include <ctime>
#include <iostream>

using namespace std;

// Genera todas las operaciones posibles entre dos números
vector<cifras_set::Operacion>
cifras_set::generarOperaciones(int a, int b) const {

    vector<Operacion> ops;
    Operacion op;

    // Suma
    op = {a, b, '+', a + b};
    ops.push_back(op);

    // Producto
    op = {a, b, '*', a * b};
    ops.push_back(op);

    // Resta (solo si es positiva)
    if (a > b) {
        op = {a, b, '-', a - b};
        if (op.resultado > 0) ops.push_back(op);
    } else if (b > a) {
        op = {b, a, '-', b - a};
        if (op.resultado > 0) ops.push_back(op);
    }

    // División exacta
    if (b != 0 && a % b == 0) {
        op = {a, b, '/', a / b};
        if (op.resultado > 0) ops.push_back(op);
    } else if (a != 0 && b % a == 0) {
        op = {b, a, '/', b / a};
        if (op.resultado > 0) ops.push_back(op);
    }

    return ops;
}

// Comprueba si los números actuales mejoran la mejor solución encontrada
void cifras_set::probarMejoria(const vector<int> &numeros,
                               const vector<Operacion> &operaciones_hechas) {

    for (int v : numeros) {
        int diff = abs(v - objetivo_actual);

        if (diff < diferencia) {
            diferencia = diff;
            mejor_encontrado = v;
            mejores_operaciones = operaciones_hechas;
        }
    }
}

// Función recursiva buscar()
void cifras_set::buscar(vector<int> numeros,
                        vector<Operacion> operaciones_hechas) {

    multiset<int> estado(numeros.begin(), numeros.end());

    // Evitar estados repetidos
    if (visitados.count(estado) > 0) return;
    visitados.insert(estado);

    // ¿Mejora la solución?
    probarMejoria(numeros, operaciones_hechas);

    if (diferencia == 0) return;
    if (numeros.size() < 2) return;

    int n = numeros.size();

    for (int i = 0; i < n - 1; i++) {
        for (int j = i + 1; j < n; j++) {

            int a = numeros[i];
            int b = numeros[j];

            vector<Operacion> ops = generarOperaciones(a, b);

            vector<int> resto;
            for (int k = 0; k < n; k++) {
                if (k != i && k != j) resto.push_back(numeros[k]);
            }

            for (size_t t = 0; t < ops.size(); t++) {

                vector<int> nuevos_numeros = resto;
                nuevos_numeros.push_back(ops[t].resultado);

                vector<Operacion> nuevas_operaciones = operaciones_hechas;
                nuevas_operaciones.push_back(ops[t]);

                buscar(nuevos_numeros, nuevas_operaciones);

                if (diferencia == 0) return;
            }
        }
    }
}

// Método principal resolver()
cifras_set::Solucion
cifras_set::resolver(const vector<int> &numeros_iniciales, int objetivo) {

    objetivo_actual = objetivo;
    mejor_encontrado = 0;
    diferencia = abs(objetivo_actual);
    visitados.clear();
    mejores_operaciones.clear();

    vector<Operacion> operaciones_hechas;

    buscar(numeros_iniciales, operaciones_hechas);

    Solucion sol;
    sol.objetivo   = objetivo_actual;
    sol.mejor_valor = mejor_encontrado;
    sol.diferencia = diferencia;
    sol.exacto = (diferencia == 0);
    sol.operaciones = mejores_operaciones;

    return sol;
}


//              MAIN


int main() {

    cout << "Juego de las cifras\n";

    /*
    //En caso de desear introducir los numeros uno mismo
    vector<int> numeros(6);
    cout << "Introduce 6 numeros: ";
    for (int i = 0; i < 6; i++) cin >> numeros[i];

    int objetivo;
    cout << "Introduce el objetivo: ";
    cin >> objetivo;

    */

    srand(time(nullptr));
    vector<int> C = {1,2,3,4,5,6,7,8,9,10,25,50,75,100};
    vector<int> numeros;
    int objetivo = rand()%1000;
    for(int i = 0; i < 6; ++i){
        numeros.push_back(C[rand()%C.size()]);
    }

    cout << "Numeros seleccionados: " << endl;
    for(auto it = numeros.begin(); it != numeros.end(); ++it){
        cout << *it << " ";
    }
    cout << endl;

    cout << "numero objetivo: " << objetivo << endl;

    cifras_set resultado;
    cifras_set::Solucion sol = resultado.resolver(numeros, objetivo);

    cout << "\nObjetivo: " << sol.objetivo << "\n";
    cout << "Mejor valor: " << sol.mejor_valor << "\n";
    cout << "Diferencia: " << sol.diferencia << "\n";

    if (sol.exacto)
        cout << "Solucion exacta encontrada.\n";
    else
        cout << "No hay solucion exacta.\n";

    cout << "\nOperaciones realizadas:\n";

    for (size_t i = 0; i < sol.operaciones.size(); i++) {
        const cifras_set::Operacion &op = sol.operaciones[i];
        cout << op.a << " " << op.op << " " << op.b
             << " = " << op.resultado << "\n";
    }

    return 0;
}
