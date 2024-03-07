#include "DivideVenceras.h"

#define INDICE_TAMANIO_SUBCADENA 1

// No necesitaría s, lo incluyo para igual que diapositivas
bool DivideVenceras::isProblemaPequenio(string s, int tamanio){
    return tamanio == 1;
}

// No necesitaría parámetros, lo incluyo para igual que diapositivas.
array<int,2> DivideVenceras::solucionarDirectamente(string s, int tamanio){
    array<int,2> resultado = {1,1};
    return resultado;
}

// No necesitaría s, lo incluyo para igual que diapositivas
int DivideVenceras::dividirProblema(string s, int tamanio){
    return tamanio/2;           // BORRAR: de momento, así no creo que sea
}

/*
    Según diapositivas:
        Método para obtener la solución al problema
        original, a partir de las soluciones de los subproblemas.
*/
array<int,2> DivideVenceras::combinar(array<int,2> primerSubproblema, array<int,2> segundoSubproblema){
    if(primerSubproblema[INDICE_TAMANIO_SUBCADENA]>=segundoSubproblema[INDICE_TAMANIO_SUBCADENA]){
        return primerSubproblema;
    } else{
        return segundoSubproblema;
    }
}

array<int,2> DivideVenceras::divideVenceras(string s, int tamanio){
    // De acuerdo con diapositiva 11 de teoría
    if(isProblemaPequenio(s,tamanio)){
        array<int,2> solucion = solucionarDirectamente(s,tamanio);
        return solucion;
    } else{
        int indice = dividirProblema(s,tamanio);
        array<int, 2> solucion = ;                 // BORRAR: de momento, para que no de error
        return solucion;
    }
}