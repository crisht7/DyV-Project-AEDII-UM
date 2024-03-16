/*
    Enunciado : https://aulavirtual.um.es/access/content/group/1900_G_2023_N_N/pr%C3%A1cticas/dyv-2024-cadenas.pdf
    Apuntes : https://aulavirtual.um.es/access/content/group/1900_G_2023_N_N/grupo%202%20-%20Quino/teor%C3%ADa/tema%202%20-%20DyV/tema2.pdf
    Problema 3

    Mikael Henrique Krüppel Pinto
    Cristóbal Maya Hortelano
*/
#include "DivideVenceras.h"

using namespace std;

int main(){
    int n, m;
    cout << "n> ";
    cin >> n;
    cout << "m> ";
    cin >> m;
    srand(time(nullptr));

    string casoGenerado = Abecedario::generarCadenaAleatoria(n);
    cout << "caso> " << casoGenerado << endl;

    Resultado resultado = DivideVenceras::divideVenceras(casoGenerado, m);

    cout << endl << "tamanio> " << resultado.tamanio << endl;
    cout << "indiceInicio> " << resultado.indiceInicio << endl;
    return 0;
}