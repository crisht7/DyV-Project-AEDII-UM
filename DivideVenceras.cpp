#include "DivideVenceras.h"

#define INDICE_TAMANIO_SUBCADENA 1

// No necesitaría tamanio, lo incluyo para igual que diapositivas TODO:cambiar
bool DivideVenceras::isProblemaPequenio(string s, int tamanio){
    return s.length() <= tamanio;
}

// No necesitaría parámetros, lo incluyo para igual que diapositivas.
Resultado DivideVenceras::solucionarDirectamente(string s, int tamanio){
    Resultado resultado = {1,1};
    return resultado;
}

// No necesitaría tamanio, lo incluyo para igual que diapositivas
int DivideVenceras::dividirProblema(string cadena, int tamanio){
    return cadena.length() / 2;           // BORRAR: de momento, así no creo que sea
}

/*
    Según diapositivas:
        Método para obtener la solución al problema
        original, a partir de las soluciones de los subproblemas.
*/
Resultado DivideVenceras::combinar(Resultado primerSubproblema, Resultado segundoSubproblema, Resultado tercerSubproblema){
    // TODO: Contemplar el caso de la mitad
    if(primerSubproblema.tamanio>=segundoSubproblema.tamanio){
        return primerSubproblema;
    } else{
        return segundoSubproblema;
    }
}


// -1 en indiceInicio si no encontrado
Resultado DivideVenceras::encontrarSubcadenaAscendente(string cadena, int tamanioBuscado) {
    int maxLongitud = 0;
    int indiceInicio = 0;
    int longitudActual = 1;

    // Recorrer la cadena
    for (int i = 1; i < cadena.length(); i++) {
        // Si el elemento actual es mayor que el anterior, aumentar la longitud actual
        if (Abecedario::isPosteriorAlfabeticamente(cadena[i], cadena[i-1]) && longitudActual < tamanioBuscado) {
            longitudActual++;
        } else {
        // Si no, actualizar la longitud máxima y el índice de inicio si es necesario
            if (longitudActual > maxLongitud) {
                maxLongitud = longitudActual;
                indiceInicio = i - maxLongitud;
            }
            longitudActual = 1;
        }
    }

    // Actualizar la longitud máxima y el índice de inicio si la última secuencia es la más larga
    if (longitudActual > maxLongitud) {
        maxLongitud = longitudActual;
        indiceInicio = cadena.length() - maxLongitud;
    }

    Resultado resultado;
    resultado.tamanio=maxLongitud;
    resultado.indiceInicio=indiceInicio;
    return resultado;
}


string DivideVenceras::calcularMitad(string s, int indice){
    return "";
}

Resultado DivideVenceras::divideVenceras(string cadena, int tamanio){
    // De acuerdo con diapositiva 11 de teoría
    if(isProblemaPequenio(cadena,tamanio)){
        return solucionarDirectamente(cadena,tamanio);
    } else{
        int indice = dividirProblema(cadena,tamanio);

        string stringIzquierda = cadena.substr(0, indice);
        string stringDerecha = cadena.substr(indice, cadena.length()-1);


        Resultado solucion = combinar(divideVenceras(stringIzquierda,tamanio), divideVenceras(stringDerecha, tamanio), divideVenceras(calcularMitad(cadena, indice), tamanio));                 // BORRAR: de momento, para que no de error
        return solucion;
    }
}