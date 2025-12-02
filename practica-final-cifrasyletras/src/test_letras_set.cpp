#include "letras_set.h"
#include <iostream>

using namespace std;

int main(int argc, char* argv[]){
    if(argc != 2){
        cout << "Uso: " << argv[0] << " <fichero_letras.txt>" << endl;
        return 1;
    }

    Letras_Set letras(argv[1]);
    cout << "Letras leidas del fichero " << argv[1] << ":" << endl;
    cout << letras;

    return 0;
}

//en el directorio pracitica-final-cifrasyletras
// compilar con: g++ -std=c++17 -Wall -Wextra -I include/ -o test_set_letras src/test_letras_set.cpp src/letras_set.cpp src/letras.cpp