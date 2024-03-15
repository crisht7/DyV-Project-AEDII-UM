#ifndef DIVIDEVENCERAS_H
#define DIVIDEVENCERAS_H

#include <array>
#include <string>
#include "Abecedario.h"

using namespace std;

struct Resultado {
  int indiceInicio;
  int tamanio;
};

class DivideVenceras{
public:
    static Resultado divideVenceras(string s, int tamanio);
private:
    static bool isProblemaPequenio(string s, int tamanio);
    static Resultado solucionarDirectamente(string s, int tamanio);
    static int dividirProblema(string cadena, int tamanio);
    static Resultado combinar(Resultado primerProblema, Resultado segundoProblema, Resultado tercerSubproblema);
    static string calcularMitad(string s, int indice);
    static Resultado encontrarSubcadenaAscendente(string cadena, int tamanioBuscado);
};

#endif