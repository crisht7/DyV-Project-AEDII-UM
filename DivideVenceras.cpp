#include "DivideVenceras.h"

#define INDICE_TAMANIO_SUBCADENA 1

// No necesitaría tamanio, lo incluyo para igual que diapositivas
bool DivideVenceras::isProblemaPequenio(string s, int tamanio){
    return s.length() == 1;
}

// No necesitaría parámetros, lo incluyo para igual que diapositivas.
array<int,2> DivideVenceras::solucionarDirectamente(string s, int tamanio){
    array<int,2> resultado = {1,1};
    return resultado;
}

// No necesitaría tamanio, lo incluyo para igual que diapositivas
int DivideVenceras::dividirProblema(string s, int tamanio){
    return s.length() / 2;           // BORRAR: de momento, así no creo que sea
}

/*
    Según diapositivas:
        Método para obtener la solución al problema
        original, a partir de las soluciones de los subproblemas.
*/
array<int,2> DivideVenceras::combinar(array<int,2> primerSubproblema, array<int,2> segundoSubproblema, array<int,2> tercerSubproblema){
    // TODO: Contemplar el caso de la mitad
    if(primerSubproblema[INDICE_TAMANIO_SUBCADENA]>=segundoSubproblema[INDICE_TAMANIO_SUBCADENA]){
        return primerSubproblema;
    } else{
        return segundoSubproblema;
    }
}

string DivideVenceras::calcularMitad(string s){
    
}

array<int,2> DivideVenceras::divideVenceras(string cadena, int tamanio){
    // De acuerdo con diapositiva 11 de teoría
    if(isProblemaPequenio(cadena,tamanio)){
        return solucionarDirectamente(cadena,tamanio);
    } else{
        int indice = dividirProblema(cadena,tamanio);

        string stringIzquierda = cadena.substr(0, indice);
        string stringDerecha = cadena.substr(indice, cadena.length()-1)



        array<int, 2> solucion = combinar(divideVenceras(stringIzquierda,tamanio), divideVenceras(stringDerecha, tamanio), divideVenceras(calcularMitad(cadena, indice), tamanio));                 // BORRAR: de momento, para que no de error
        return solucion;
    }
}