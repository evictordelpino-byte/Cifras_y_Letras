#include "cifras_set.h"

#include <cstdlib>
#include <ctime>
#include <iostream>

using namespace std;

// Genera todas las operaciones posibles entre dos números
vector<cifras_set::Operacion> cifras_set::generarOperaciones(int a, int b) const {

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
        if (op.resultado > 0) 
        ops.push_back(op);
    } else if (b > a) {
        op = {b, a, '-', b - a};
        if (op.resultado > 0) 
        ops.push_back(op);
    }

    // División exacta
    if (b != 0 && a % b == 0) {
        op = {a, b, '/', a / b};
        if (op.resultado > 0) 
        ops.push_back(op);
    } else if (a != 0 && b % a == 0) {
        op = {b, a, '/', b / a};
        if (op.resultado > 0) 
        ops.push_back(op);
    }

    return ops;
}

// Comprueba si los números actuales mejoran la mejor solución encontrada
void cifras_set::probarMejoria(const vector<int> &numeros,
                               const vector<Operacion> &operaciones_hechas) {

    for (int v : numeros) {
        int diff = abs(v - objetivo_actual); //Para cada numero calcula distancia con el objetivo

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


    //1. Representar estado y evitar repeticiones
    //Se construye multiset con los numeros actuales
    multiset<int> estado(numeros.begin(), numeros.end());

    // Evitar estados repetidos si ya se han realizado esos estados 
    if (visitados.count(estado) > 0) return; //visitados.count devuelve 0 si nunca se ha visto o 1 si si
    visitados.insert(estado); //guarda estados vistos

    //2. Comprobar si mejora la solucion
    probarMejoria(numeros, operaciones_hechas);

    if (diferencia == 0) return;
    //3. Si quedan 1 numero o ninguno no podemos seguir operando
    int n = numeros.size();
    if (n < 2) return;


    //4. Recorrer todas las parejas para generar operaciones
    for (int i = 0; i < n - 1; i++) {
        for (int j = i + 1; j < n; j++) {

            int a = numeros[i];
            int b = numeros[j];

            //5. Genera operaciones
            vector<Operacion> ops = generarOperaciones(a, b);

            //6. Resto de numeros (todos los numeros menos con los que estamos operando)
            vector<int> resto;
            for (int k = 0; k < n; k++) {
                if (k != i && k != j) 
                resto.push_back(numeros[k]);
            }

            //7. Probar cada operacion con esa pareja (a,b)
            for (int l = 0; t < ops.size(); l++) {

                //Creo nuevo conjunto de numeros con los numeros que no se han usado
                vector<int> nuevos_numeros = resto;
                // Añadimos resultado de la operacion con a y b
                nuevos_numeros.push_back(ops[l].resultado);

                // Nuevo historial de operaciones hechas
                vector<Operacion> nuevas_operaciones = operaciones_hechas;
                nuevas_operaciones.push_back(ops[l]);

                buscar(nuevos_numeros, nuevas_operaciones);

                //Si encuentra solucion sale de la funcion
                if (diferencia == 0) return;
            }
        }
    }
}

// Método principal resolver()
cifras_set::Solucion cifras_set::resolver(const vector<int> &numeros_iniciales, int objetivo) {

    objetivo_actual = objetivo; //guarda el objetivo de la partida se usa para distancia
    mejor_encontrado = 0;
    diferencia = abs(objetivo_actual); //la peor diferencia es |0 - objetivo|
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
