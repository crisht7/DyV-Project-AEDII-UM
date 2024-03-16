#include "DivideVenceras.h"

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

string DivideVenceras::getMitadCadena(const string& cadena, int indiceMitad, bool isDerecha){
    if(isDerecha){
        return cadena.substr(indiceMitad, cadena.length()-1);
    } else{
        return cadena.substr(0, indiceMitad);
    }
}

bool DivideVenceras::isProblemaPequenio(string cadena){
    return cadena.length() == 1;
}

Resultado DivideVenceras::solucionarDirectamente(){
    Resultado resultado = {1,1};                            // ya que el caso base es el de una cadena de length 1
    return resultado;
}

int DivideVenceras::dividirProblema(string cadena){
    return cadena.length() / 2;
}

/*
    Método para obtener la solución al problema original
    a partir de las soluciones de 3 subproblemas.
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

/*
    Método para obtener la solución al problema original
    a partir de las soluciones de 2 subproblemas.
*/
Resultado DivideVenceras::combinar(Resultado primerSubproblema, Resultado segundoSubproblema){
    Resultado mayor = primerSubproblema;

    if (segundoSubproblema.tamanio > mayor.tamanio) {
        mayor = segundoSubproblema;
    }

    return mayor;
}

Resultado DivideVenceras::calcularMitad(const string& cadena, int indice, int tamanioBuscado){
    /*
        Sanitización del offset de la parte izquierda, ya que indice - tamanioBuscado podría ser < 0
    */
    int offsetIzquierda = indice - tamanioBuscado;
    if(indice - tamanioBuscado < 0){
        offsetIzquierda = 0;
    }

    Resultado izquierda = encontrarSubcadenaAscendente(cadena.substr(offsetIzquierda, cadena.length() - 1),tamanioBuscado);
    Resultado derecha = encontrarSubcadenaAscendente(cadena.substr(indice),tamanioBuscado);

    // TODO: Calcular el indiceInicio con respecto a la cadena original y no del subproblema actual

    izquierda.indiceInicio = izquierda.indiceInicio + offsetIzquierda - 1;
    derecha.indiceInicio = derecha.indiceInicio + indice - 1;

    return combinar(izquierda, derecha);
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

    /*
        +1 debido a que en los ejemplos se establece que
        el primer caracter de una cadena empieza en la posición 1,
        en vez de la posición 0
    */
    Resultado resultado = {indiceInicio+1, maxLongitud};
    return resultado;
}