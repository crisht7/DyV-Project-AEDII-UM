#include "DivideVenceras.h"

bool DivideVenceras::isProblemaPequenio(string cadena){
    return cadena.length() == 1;
}

Resultado DivideVenceras::solucionarDirectamente(){
    Resultado resultado = {1,1};                    // ya que el caso base es el de una cadena de length 1
    return resultado;
}

int DivideVenceras::dividirProblema(string cadena){
    return cadena.length() / 2;
}

/*
    Método para obtener la solución al problema original
    a partir de las soluciones de los subproblemas.
*/
Resultado DivideVenceras::combinar(Resultado primerSubproblema, Resultado segundoSubproblema, Resultado tercerSubproblema){
    Resultado mayor = primerSubproblema;

    if (segundoSubproblema.tamanio > mayor.tamanio) {
        mayor = segundoSubproblema;
    }

    if (tercerSubproblema.tamanio > mayor.tamanio) {
        mayor = tercerSubproblema;
    }

    return mayor;
}

Resultado DivideVenceras::combinar(Resultado primerSubproblema, Resultado segundoSubproblema){
    Resultado mayor = primerSubproblema;

    if (segundoSubproblema.tamanio > mayor.tamanio) {
        mayor = segundoSubproblema;
    }

    return mayor;
}

Resultado DivideVenceras::encontrarSubcadenaAscendente(string cadena, int tamanioBuscado) {
    int maxLongitud = 0;
    int indiceInicio = 0;
    int longitudActual = 1;

    for (int i = 1; i < cadena.length(); i++) {
        
        if (Abecedario::isPosteriorAlfabeticamente(cadena[i], cadena[i-1]) && longitudActual < tamanioBuscado) {
            longitudActual++;
        } else {
            if (longitudActual > maxLongitud) {
                maxLongitud = longitudActual;
                indiceInicio = i - maxLongitud;
            }
            longitudActual = 1;
        }
    }

    if (longitudActual > maxLongitud) {
        maxLongitud = longitudActual;
        indiceInicio = cadena.length() - maxLongitud;
    }

    Resultado resultado = {indiceInicio, maxLongitud};
    return resultado;
}


Resultado DivideVenceras::calcularMitad(const string& cadena, int indice, int tamanioBuscado){
    Resultado izquierda = encontrarSubcadenaAscendente(cadena.substr(indice - 1, cadena.length() - indice - 1),tamanioBuscado);
    Resultado derecha = encontrarSubcadenaAscendente(cadena.substr(indice),tamanioBuscado);

    return combinar(izquierda, derecha);
}

string DivideVenceras::getMitadCadena(const string& cadena, int indiceMitad, bool isDerecha){
    if(isDerecha){
        return cadena.substr(indiceMitad, cadena.length()-1);
    } else{
        return cadena.substr(0, indiceMitad);
    }
}

/*
    Estructura DyV de acuerdo con diapositiva 11 de teoría.
*/
Resultado DivideVenceras::divideVenceras(string cadena, int tamanio){
    if(isProblemaPequenio(cadena)){
        return solucionarDirectamente();
    } else{
        int indice = dividirProblema(cadena);

        string stringIzquierda = getMitadCadena(cadena, indice, false);
        string stringDerecha = getMitadCadena(cadena, indice, true);

        return combinar(divideVenceras(stringIzquierda,tamanio), divideVenceras(stringDerecha, tamanio), calcularMitad(cadena, indice,tamanio));
    }
}