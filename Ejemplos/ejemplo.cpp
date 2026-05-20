#include <iostream>

// Recibe: el arreglo, su tamaño y el valor que queremos encontrar
int busquedaLineal(const int arreglo[], int tamano, int objetivo) {
    
    // Recorremos el arreglo elemento por elemento
    for (int indice = 0; indice < tamano; indice++) {
        
        // Si encontramos el objetivo, retornamos su índice de inmediato
        if (arreglo[indice] == objetivo) {
            return indice; 
        }
    }
    
    // Si el ciclo termina y no se encontró el valor, retornamos -1
    return -1;
}

int main() {
    // Definimos un arreglo desordenado de prueba
    int misNumeros[] = {14, 25, 8, 99, 4, 32, 50};
    
    // Calculamos el tamaño dinámicamente dividiendo el peso total de la memoria
    // entre el peso de un solo elemento. En este caso: 28 bytes / 4 bytes = 7 elementos.
    int tamano = sizeof(misNumeros) / sizeof(misNumeros[0]);
    
    // --- CASO 1: Buscar un elemento que SÍ existe ---
    int buscarExito = 4;
    int resultado1 = busquedaLineal(misNumeros, tamano, buscarExito);
    
    std::cout << "--- Busqueda 1 ---" << std::endl;
    if (resultado1 != -1) {
        std::cout << "El numero " << buscarExito << " se encontro en la posicion: " << resultado1 << std::endl;
    } else {
        std::cout << "El numero " << buscarExito << " no existe en el arreglo." << std::endl;
    }
    
    std::cout << std::endl; // Salto de línea para separar

    // --- CASO 2: Buscar un elemento que NO existe ---
    int buscarFallo = 100;
    int resultado2 = busquedaLineal(misNumeros, tamano, buscarFallo);
    
    std::cout << "--- Busqueda 2 ---" << std::endl;
    if (resultado2 != -1) {
        std::cout << "El numero " << buscarFallo << " se encontro en la posicion: " << resultado2 << std::endl;
    } else {
        std::cout << "El numero " << buscarFallo << " no existe en el arreglo." << std::endl;
    }

    return 0;
}