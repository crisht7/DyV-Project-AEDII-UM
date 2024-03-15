#include <iostream>
#include <string>

using namespace std;

struct Dato {
    int inicio;
    int final;
};

char generarLetra(char minimo, char maximo) {
    int rango = maximo - minimo + 1;
    int numeroAleatorio = rand() % rango;
    return minimo + numeroAleatorio;
}

string generadorCasos(int N) {
    string cadena = "";

    for (int i = 0; i < N; i++) {
        char letra = generarLetra('a', 'z');
        cadena += letra; // Agregar la letra al final de la cadena
    }

    return cadena;

}

Dato encontrarSubcadena(int inicio, int final,const string& A, int m) {
    int max_len = 0; // Longitud máxima de la subcadena ascendente
    int indice_inicio = -1; // Índice de inicio de la subcadena ascendente
    int longitud_actual = 1; // Longitud actual de la subcadena ascendente

    for (int i = inicio + 1; i <= final; ++i) {
        if (A[i] >= A[i - 1]) {
            longitud_actual++;
        } else {
            if (longitud_actual >= m && longitud_actual > max_len) {
                max_len = longitud_actual;
                indice_inicio = i - longitud_actual;
            }
            longitud_actual = 1;
        }
    }

    // Verificar si la última subcadena también cumple con la condición
    if (longitud_actual >= m && longitud_actual > max_len) {
        max_len = longitud_actual;
        indice_inicio = final - longitud_actual + 1;
    }

    // Si no se encontró una subcadena de longitud exacta m, buscar la mayor subcadena ascendente < m
    if (max_len < m) {
        max_len = 0;
        longitud_actual = 1;
        for (int i = inicio + 1; i <= final; ++i) {
            if (A[i] >= A[i - 1]) {
                longitud_actual++;
            } else {
                if (longitud_actual > max_len) {
                    max_len = longitud_actual;
                    indice_inicio = i - longitud_actual;
                }
                longitud_actual = 1;
            }
        }
    }

    Dato resultado;
    resultado.inicio = indice_inicio;
    resultado.final = indice_inicio + max_len - 1;
    return resultado;
}

bool Pequeno(int inicio,int final, int m ) {
    return (final - inicio)+1 <= m;
}

Dato extenderDerecha(const string& A , Dato S){
    while(A[S.final]<A[S.final+1]){
        S.final++;
    }
    return S;
}

Dato extenderIzquierda(const string& A , Dato S){
    while(A[S.inicio-1]<A[S.inicio]){
        S.inicio--;
    }
    return S;
}


Dato cadFrontera(const string&A, int m){

    Dato S3 = {m,m+1};
    extenderIzquierda(A,S3);
    extenderDerecha(A,S3);

    return S3;
}

//Método sobrecargado para comparar varios Datos

Dato cadenaMasLarga(Dato S1, Dato S2){
if ((S1.final-S1.inicio)+1 > (S2.final-S2.inicio)+1) {
       return S1;
   } else {
       return S2;
   }
}

Dato cadenaMasLarga(Dato S1, Dato S2, Dato S3) {
    Dato maximo = S1;

    if ((S2.final-S2.inicio)+1 > (maximo.final-maximo.inicio)+1) {
        maximo = S2;
    }

    if ((S3.final-S3.inicio)+1 > (maximo.final-maximo.inicio)+1) {
        maximo = S3;
    }

    return maximo;
}


Dato Combinar(Dato S1,Dato S2,const string& A , int m ){

    //cout << "He entrado al COMBI" << endl;
     if (!(A[m] < A[m + 1])) {    //Si no hay continuidad en la frontera
        // cout << "He entrado a if" << endl;
        return cadenaMasLarga(S1, S2);
    } else if (S1.final == m) {   // Si S1 toca frontera
        if (S2.inicio == m + 1) {  // Si S2 toca frontera
            //Concateno índices          
            Dato nuevo = {S1.inicio, S2.final};
            return nuevo;
        }else{                      // S1 toca frontera pero S2 no
            return extenderDerecha(A,S1);
        }
    } else if (S2.inicio == m + 1) {  // Si S2 toca frontera 
        S2 = extenderIzquierda(A, S2);
        return cadenaMasLarga(S1, S2);
    } else {
        Dato S3 = cadFrontera(A, m);  // Hay continuidad en la frontera
        return cadenaMasLarga(S1, S2, S3);
    }

}


//función para dividir la cadena de caso grande en dos

int Dividir(int inicio, int final) {
   return ((inicio + final) / 2);
}


Dato dyv(int inicio, int final, int m, const string& A) {
    int mitad;
    if(Pequeno(inicio,final,m)){
       // cout << "He hecho el caso directo" << endl;
        return encontrarSubcadena(inicio,final,A,m);
    }else{
       // cout << "He entrado al else" << endl;
        mitad=Dividir(inicio, final);
        return Combinar(dyv(inicio,mitad,m,A),dyv(mitad+1,final,m,A),A,mitad);
    }
    
}



int main() {
   
    int m = 0;

    cout << "Introduzca de que tamaño quiere que sea la subcadena (Si no encuentra una de tamaño exacto devolverá la mayor que encuentre): " << endl;
    cin >> m ;

    srand(time(nullptr));

    int N = rand() % (101 - m) + m;  // Genera un numero entre 100 y m.
    cout << "N: " << N << endl;

    string A = generadorCasos(N);

    cout << "Prueba generada: " << A << endl; 

    Dato resultado =  dyv(0,A.length()-1,m,A); 
    
    //encontrarSubcadena(0,A.length()-1, A, m); 

    cout << "Posición de inicio: " << resultado.inicio+1 << endl;
    cout << "Número de caracteres en la mayor subcadena ascendente: " << (resultado.final - resultado.inicio)+1 << endl;

    return 0;
}

/*
Dada una cadena A de longitud n, y un natural m <= n, hay que encontrar
la subcadena B de m carcateres con mas caracteres consecutivos ordenados ascendentemente(incluyendo caracteres iguales). 
Llamenos C a la subcadena de B formada por dichos caracteres. 
Devolver como solucion el indice p de comienzo de  B y el numero de caracteres en C. En caso de 
empate, será válida cualqiora de las solucione optimas.
.
Ejemplo: n=10, m=5
A= c d d a b c d a c c
Solución: posición de inicio igual a 4, y número de caracteres en la mayor
subcadena ascendente igual a 4 (a b c d)
*/