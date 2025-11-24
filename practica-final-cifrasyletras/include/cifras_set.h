#ifndef __CIFRAS_SET_H__
#define __CIFRAS_SET_H__
#include <set>
#include <iostream>

using namespace std;

class Cifras{
private:
    multiset cifras;
    int objetivo;
    multiset respuesta;
public:
    Cifras(multiset &c, int obj){
        cifras = c;
        objetivo = obj;
    }
    
    multiset solucion(){
        
    }
};



// MAIN PARA EL PROGRAMA DE LAS CIFRAS

#endif
