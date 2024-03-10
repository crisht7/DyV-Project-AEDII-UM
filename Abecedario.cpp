#include "Abecedario.h"

#define TAMANIO_ABECEDARIO 26
#define CARACTER_INVALIDO '\n'

char abecedario[] = "abcdefghijklmnopqrstuvwxyz";

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

char Abecedario::getSiguienteLetra(char c){
    if(c=='z'){
        return CARACTER_INVALIDO;
    }
    return abecedario[getPosicionEnAbecedario(c)+1];
}