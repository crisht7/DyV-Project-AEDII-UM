#ifndef ABECEDARIO_H
#define ABECEDARIO_H

#include <iostream>

struct Resultado {
  int indiceInicio;
  int tamanio;
};

using namespace std;

class Abecedario{
public:
    static int getPosicionEnAbecedario(char c);
    static char getSiguienteLetra(char c);
    static char getPrimeraEnAbecedario(char a, char b);
    static char generarLetraAleatoria();
    static string generarCadenaAleatoria(int tamanio);
    static bool isPosteriorAlfabeticamente(char a, char b);
};

#endif