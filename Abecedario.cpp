#include "Abecedario.h"

#define TAMANIO_ABECEDARIO 26

char abecedario[] = "abcdefghijklmnopqrstuvwxyz";

bool Abecedario::isPosteriorAlfabeticamente(char a, char b){
    return a >= b;
}

string Abecedario::generarCadenaAleatoria(int tamanio){
    string cadena = "";
    for(int i = 0; i<tamanio; i++){
        cadena += generarLetraAleatoria();
    }
    return cadena;
}

// Requiere iniciar el srand
char Abecedario::generarLetraAleatoria(){
    int numeroAleatorio = rand();
    numeroAleatorio = numeroAleatorio % TAMANIO_ABECEDARIO; 
    return abecedario[numeroAleatorio];
}