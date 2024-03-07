#include "Abecedario.h"

#define TAMANIO_ABECEDARIO 26

char abecedario[] = "abcdefghijklmnopqrstuvwxyz";

int Abecedario::getPosicionEnAbecedario(char c){
    for(int i = 0; i<TAMANIO_ABECEDARIO ;i++){
        if(abecedario[i]==c){
            return i;
        }
    }
    return -1;
}

char Abecedario::getSiguienteLetra(char c){
    return abecedario[getPosicionEnAbecedario(c)+1];
}