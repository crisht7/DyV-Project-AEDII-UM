#ifndef DIVIDEVENCERAS_H
#define DIVIDEVENCERAS_H

#include <array>
#include <string>
#include "Abecedario.h"

using namespace std;

class DivideVenceras{
public:
    static Resultado divideVenceras(string s, int tamanio);
private:
    static bool isProblemaPequenio(string cadena);
    static Resultado solucionarDirectamente();
    static int dividirProblema(string cadena);
    static Resultado combinar(Resultado primerSubProblema, Resultado segundoSubProblema, Resultado tercerSubproblema);
    static Resultado combinar(Resultado primerSubProblema, Resultado segundoSubProblema);
    static Resultado calcularMitad(const string& cadena, int indice, int tamanioBuscado);
    static Resultado encontrarSubcadenaAscendente(string cadena, int tamanioBuscado);
    static string getMitadCadena(const string& cadena, int mitad, bool isDerecha);
};

#endif