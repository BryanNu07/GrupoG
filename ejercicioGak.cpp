#include <iostream>
#include <string>

using namespace std;

int main() {
    // 1. Arreglo con los productos actualmente disponibles
    string inventario[4] = {"leche", "pan", "huevos", "café"};

    string producto_buscado;
    bool encontrado = false;

    // 2. Solicitar el producto al usuario
    cout << "Digite el producto que busca: ";
    cin >> producto_buscado;

    // 3. Búsqueda lineal en el inventario
    for (int i = 0; i < 4; i++) {
        if (inventario[i] == producto_buscado) {
            encontrado = true;
            break; // Salimos del ciclo de inmediato al encontrarlo
        }
    }

    // 4. Mostrar diagnóstico de stock
    cout << "\n[Resultado de Inventario]: " << endl;
    if (encontrado) {
        cout << "-> El producto '" << producto_buscado << "' está en stock." << endl;
    } else {
        cout << "-> El producto '" << producto_buscado << "' no está disponible.an ¡Hay que reabastecer!" << endl;
    }

    return 0;
}
