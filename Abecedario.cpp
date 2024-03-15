#include "Abecedario.h"

#define TAMANIO_ABECEDARIO 26
#define CARACTER_INVALIDO '\n'

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

char Abecedario::getSiguienteLetra(char c){
    if(c=='z'){
        return CARACTER_INVALIDO;
    }
    return abecedario[getPosicionEnAbecedario(c)+1];
}

int Abecedario::getPosicionEnAbecedario(char c){
    for(int i = 0; i<TAMANIO_ABECEDARIO; i++){
        if(abecedario[i]==c){
            return i;
        }
    }
    return -1;
}

char Abecedario::getPrimeraEnAbecedario(char a, char b){
    for(int i = 0; i<TAMANIO_ABECEDARIO; i++){
        if(abecedario[i]== a || abecedario[i] == b){
            return abecedario[i];
        }
    }
    return CARACTER_INVALIDO;
}