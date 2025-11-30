#include "CifrasSolver.h"
#include <cstdlib>  // std::abs

// Genera todas las operaciones posibles entre a y b que cumplan las reglas del juego
std::vector<CifrasSolver::Operacion>
CifrasSolver::generarOperaciones(int a, int b) const {
    std::vector<Operacion> ops;

    // Suma
    {
        Operacion op;
        op.a = a;
        op.b = b;
        op.op = '+';
        op.resultado = a + b;
        ops.push_back(op);
    }

    // Producto
    {
        Operacion op;
        op.a = a;
        op.b = b;
        op.op = '*';
        op.resultado = a * b;
        ops.push_back(op);
    }

    // Resta: solo se admiten resultados positivos
    if (a > b) {
        Operacion op;
        op.a = a;
        op.b = b;
        op.op = '-';
        op.resultado = a - b;
        if (op.resultado > 0) {
            ops.push_back(op);
        }
    } else if (b > a) {
        Operacion op;
        op.a = b;
        op.b = a;
        op.op = '-';
        op.resultado = b - a;
        if (op.resultado > 0) {
            ops.push_back(op);
        }
    }

    // División exacta: solo si es entera y el resultado es positivo
    if (b != 0 && a % b == 0) {
        Operacion op;
        op.a = a;
        op.b = b;
        op.op = '/';
        op.resultado = a / b;
        if (op.resultado > 0) {
            ops.push_back(op);
        }
    } else if (a != 0 && b % a == 0) {
        Operacion op;
        op.a = b;
        op.b = a;
        op.op = '/';
        op.resultado = b / a;
        if (op.resultado > 0) {
            ops.push_back(op);
        }
    }

    return ops;
}

// Comprueba si alguno de los números actuales mejora la mejor solución guardada
void CifrasSolver::probarMejoria(const std::vector<int> &nums) {
    for (int v : nums) {
        int diff = std::abs(v - objetivo_actual);
        if (diff < diferencia) {
            diferencia = diff;
            mejor_encontrado = v;
        }
    }
}

// Función recursiva que explora todas las combinaciones posibles
void CifrasSolver::backtrack(std::vector<int> nums) {
    // Construimos un estado a partir de los números actuales (sin importar el orden)
    std::multiset<int> estado(nums.begin(), nums.end());

    // Si ya habíamos visto este estado, no tiene sentido repetirlo
    if (visitados.count(estado) > 0) {
        return;
    }

    // Marcamos este estado como visitado
    visitados.insert(estado);

    // Comprobamos si con estos números mejoramos la mejor solución
    probarMejoria(nums);

    // Si ya hemos llegado exactamente al objetivo, no seguimos
    if (diferencia == 0) {
        return;
    }

    // Si tenemos menos de dos números, ya no podemos operar más
    if (nums.size() < 2) {
        return;
    }

    int n = static_cast<int>(nums.size());

    // Recorremos todas las parejas de índices (i, j) con i < j
    for (int i = 0; i < n - 1; ++i) {
        for (int j = i + 1; j < n; ++j) {
            int a = nums[i];
            int b = nums[j];

            // Operaciones posibles con a y b
            std::vector<Operacion> ops = generarOperaciones(a, b);

            // Construimos el resto de números (todos menos i y j)
            std::vector<int> resto;
            for (int k = 0; k < n; ++k) {
                if (k != i && k != j) {
                    resto.push_back(nums[k]);
                }
            }

            // Para cada operación, generamos un nuevo estado y seguimos recursivamente
            for (std::size_t t = 0; t < ops.size(); ++t) {
                int resultado = ops[t].resultado;

                std::vector<int> nuevos_nums = resto;
                nuevos_nums.push_back(resultado);

                backtrack(nuevos_nums);

                // Si ya hemos dado con el objetivo exacto, cortamos por aquí
                if (diferencia == 0) {
                    return;
                }
            }
        }
    }
}

// Prepara el estado interno, lanza el backtracking y devuelve el resultado
CifrasSolver::Resultado
CifrasSolver::resolver(const std::vector<int> &numeros, int objetivo) {
    // Inicializamos los datos internos
    objetivo_actual = objetivo;
    mejor_encontrado = 0;
    diferencia = std::abs(objetivo_actual);
    visitados.clear();

    // Llamada inicial al backtracking
    backtrack(numeros);

    // Montamos la estructura de resultado
    Resultado res;
    res.objetivo = objetivo_actual;
    res.mejor_valor = mejor_encontrado;
    res.diferencia = diferencia;
    res.exacto = (diferencia == 0);

    return res;
}

int main() {
    std::cout << "Juego de las cifras (sin mostrar operaciones)\n";

    // Leemos los 6 numeros de la tirada
    std::vector<int> numeros(6);
    std::cout << "Introduce 6 numeros separados por espacio: ";
    for (int i = 0; i < 6; ++i) {
        std::cin >> numeros[i];
    }

    // Leemos el objetivo
    int objetivo;
    std::cout << "Introduce el objetivo (numero de 3 cifras): ";
    std::cin >> objetivo;

    // Creamos el solver y resolvemos
    CifrasSolver solver;
    CifrasSolver::Resultado res = solver.resolver(numeros, objetivo);

    // Mostramos el resultado
    std::cout << "\nObjetivo: " << res.objetivo << "\n";
    std::cout << "Mejor valor encontrado: " << res.mejor_valor << "\n";
    std::cout << "Diferencia: " << res.diferencia << "\n";

    if (res.exacto) {
        std::cout << "Se ha encontrado una solucion EXACTA.\n";
    } else {
        std::cout << "No hay solucion exacta, se muestra la mas cercana.\n";
    }

    return 0;
}