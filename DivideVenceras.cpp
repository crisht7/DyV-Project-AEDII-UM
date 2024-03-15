#include "DivideVenceras.h"

#define INDICE_TAMANIO_SUBCADENA 1

// No necesitaría tamanio, lo incluyo para igual que diapositivas TODO:no seguro si asi
bool DivideVenceras::isProblemaPequenio(string s, int tamanio){
    return s.length() == 1;
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

    Resultado resultado = {indiceInicio, maxLongitud};
    return resultado;
}


string DivideVenceras::calcularMitad(string s, int indice){
    return "";
}

string DivideVenceras::getMitadCadena(const string& cadena, int indiceMitad, bool isDerecha){
    if(isDerecha){
        return cadena.substr(indiceMitad, cadena.length()-1);
    } else{
        return cadena.substr(0, indiceMitad);
    }
}

Resultado DivideVenceras::divideVenceras(string cadena, int tamanio){
    // De acuerdo con diapositiva 11 de teoría
    if(isProblemaPequenio(cadena,tamanio)){
        return solucionarDirectamente(cadena,tamanio);
    } else{
        int indice = dividirProblema(cadena,tamanio);

        string stringIzquierda = getMitadCadena(cadena, indice, false);
        string stringDerecha = getMitadCadena(cadena, indice, true);



        Resultado solucion = combinar(divideVenceras(stringIzquierda,tamanio), divideVenceras(stringDerecha, tamanio), divideVenceras(calcularMitad(cadena, indice), tamanio));                 // BORRAR: de momento, para que no de error
        return solucion;
    }
}