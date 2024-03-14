#ifndef DIVIDEVENCERAS_H
#define DIVIDEVENCERAS_H

#include <array>
#include <string>
#include "Abecedario.h"

using namespace std;

class DivideVenceras{
public:
    static array<int,2> divideVenceras(string s, int tamanio);
private:
    static bool isProblemaPequenio(string s, int tamanio);
    static array<int,2> solucionarDirectamente(string s, int tamanio);
    static int dividirProblema(string s, int tamanio);
    static array<int,2> combinar(array<int,2> primerProblema, array<int,2> segundoProblema);
    static string calcularMitad(string s);
};

#endif