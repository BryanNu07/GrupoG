#include <iostream>
using namespace std;

int busquedaSecuencial(double notas[], int n, double valor) {
    for (int i = 0; i < n; i++) {
        if (notas[i] == valor) {
            return i; // retorna índice encontrado
        }
    }
    return -1; // no encontrado
}

int main() {
    double notas[] = {5.0, 12.5, 20.0, 33.0};
    int n = 4;
    double valor = 20.0;

    int pos = busquedaSecuencial(notas, n, valor);

    if (pos == -1)
        cout << "Nota " << valor << " NO encontrada.\n";
    else
        cout << "Nota " << valor << " encontrada en posición " << pos << ".\n";

    return 0;
}
