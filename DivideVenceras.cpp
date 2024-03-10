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

// No necesitaría tamanio, lo incluyo para igual que diapositivas
int DivideVenceras::dividirProblema(string s, int tamanio){
    return s.length()/2;           // BORRAR: de momento, así no creo que sea
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

array<int,2> DivideVenceras::divideVenceras(string cadena, int tamanio){
    // De acuerdo con diapositiva 11 de teoría
    // https://aulavirtual.um.es/access/content/group/1900_G_2023_N_N/grupo%202%20-%20Quino/teor%C3%ADa/tema%202%20-%20DyV/tema2.pdf
    if(isProblemaPequenio(cadena,tamanio)){
        return solucionarDirectamente(cadena,tamanio);
    } else{
        int indice = dividirProblema(cadena,tamanio);
        array<int, 2> solucion = combinar(divideVenceras(0,indice), divideVenceras(indice+1, cadena.length()));                 // BORRAR: de momento, para que no de error
        return solucion;
    }
}