#include <iostream>
#include <vector>

using namespace std;

// Función para encontrar la subcadena ascendente máxima en un rango
pair<int, int> encontrar_subcadena_maxima(const string& A, int inicio, int fin) {
  // Caso base: subcadena de longitud 1
  if (inicio == fin) {
    return {inicio, 1};  ///No pasa de este caso
  }

  // Dividir el problema en dos subproblemas
  int mitad = (inicio + fin) / 2;
  pair<int, int> izquierda = encontrar_subcadena_maxima(A, inicio, mitad);
  pair<int, int> derecha = encontrar_subcadena_maxima(A, mitad + 1, fin);

  // Combinar las soluciones de los subproblemas
  int longitud_maxima = max(izquierda.second, derecha.second);

  // Caso 1: La subcadena máxima se encuentra en la subcadena izquierda
  if (izquierda.second == longitud_maxima) {
    return izquierda;
  }

  // Caso 2: La subcadena máxima se encuentra en la subcadena derecha
  if (derecha.second == longitud_maxima) {
    return derecha;
  }

  // Caso 3: La subcadena máxima se encuentra a caballo entre ambas subcadenas
  int longitud_actual = 1;
  char caracter_actual = A[mitad];
  int inicio_subcadena = mitad;

  // Recorrer la subcadena derecha buscando caracteres consecutivos ascendentes
  for (int i = mitad + 1; i <= fin; i++) {
    if (A[i] >= caracter_actual) {
      longitud_actual++;
      caracter_actual = A[i];
    } else {
      break;
    }
  }

  // Si la longitud actual es mayor que la máxima, actualizar la solución
  if (longitud_actual > longitud_maxima) {
    return {inicio_subcadena, longitud_actual};
  }

  // Devolver la solución con la longitud máxima
  return {derecha.first, derecha.second};
}

int main() {
  string A;//Que detecte automaticamente la longitud de la cadena 
  int n, m;
  n = A.length();
  cout << "Introduce la cadena a buscar: ";
  cin >> A;
  cout << "Escribe la longitud de la secuencia: ";
  cin >> m;
  // Encontrar la subcadena ascendente máxima
  pair<int, int> solucion = encontrar_subcadena_maxima(A, 0, n - 1);

  // Imprimir la solución
  cout << solucion.first << " " << solucion.second << endl;

  return 0;
}
