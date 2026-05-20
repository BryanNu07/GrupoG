// =====================================================================
//  BÚSQUEDA SECUENCIAL - PARTE 4

//  CONTENIDO:
//  - Búsqueda secuencial con bandera bool encontrado
//  - Retorna -1 cuando no encuentra el valor
// =====================================================================

#include <iostream>
using namespace std;

// =====================================================================
//  BÚSQUEDA SECUENCIAL CON BANDERA (Parte 4)
// =====================================================================
int buscarPrimera(double notas[], int n, double valor) {
    int  pos        = -1;        // -1 significa "aún no hay índice válido"
    bool encontrado = false;     // BANDERA: cambia a true solo si hallamos la nota
    int  i = 0;                  // índice para recorrer el arreglo

    while (i < n && !encontrado) {
        if (notas[i] == valor) {
            pos        = i;          // guarda la posición exacta
            encontrado = true;       // ¡BANDERA ARRIBA! Sale del while
        }
        i++;
    }
    return pos;
}

// =====================================================================
//  PROGRAMA DE PRUEBA
// =====================================================================
int main() {
    double notas[] = {15.0, 20.0, 18.0, 25.0, 30.0};
    int n = 5;
    double valor;
    int posicion;

    cout << "=== BUSQUEDA SECUENCIAL - PARTE 4 ===\n";
    cout << "Arreglo: 15, 20, 18, 25, 30\n\n";

    // Prueba 1: Valor que SÍ existe
    valor = 20.0;
    posicion = buscarPrimera(notas, n, valor);
    
    if (posicion == -1)
        cout << "Nota " << valor << " NO encontrada.\n";
    else
        cout << "Nota " << valor << " encontrada en posicion: " << posicion << "\n";

    // Prueba 2: Valor que NO existe
    valor = 99.0;
    posicion = buscarPrimera(notas, n, valor);
    
    if (posicion == -1)
        cout << "Nota " << valor << " NO encontrada.\n";
    else
        cout << "Nota " << valor << " encontrada en posicion: " << posicion << "\n";

    return 0;
}
