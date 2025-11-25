#ifndef __CIFRAS_SET_H__
#define __CIFRAS_SET_H__
#include <set>
#include <vector>
#include <iostream>

using namespace std;

class Cifras{
private:
    multiset<int> cifras;
    int objetivo;
    vector<char> respuesta;
public:
    Cifras(multiset<int> &c, int obj){
        cifras = c;
        objetivo = obj;
    }
    
    vector<char> solucion(){

    }
};



// MAIN PARA EL PROGRAMA DE LAS CIFRAS

#endif
