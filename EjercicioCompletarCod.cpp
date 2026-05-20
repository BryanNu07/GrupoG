//Integrantes: Loor Jhon, Cajiao Paulo, Rocha Carolina, Balarezo Diego 
include <iostream> 

using namespace std; 
int main() { 

    // Arreglo con las ventas de la semana 

    int ventas[] = {120, 150, 90, 200, 175, 80, 160}; 

    int total = 0; 

    int mayor150 = 0; 

    int ventaMax = ventas[0]; 

    int tamanio = 7; 

    // Recorrer el arreglo 

    for (int i = 0; i < tamanio; i++) { 

        total += ventas[i]; 

  

        // Contar ventas mayores a 150 

        if (ventas[i] > 150) { 

            mayor150++; 

        } 

  

        // Buscar la venta más alta 

        if (ventas[i] > ventaMax) { 

            ventaMax = ventas[i]; 

        } 

    } 

    // Calcular promedio 

    float promedio = (float)total / tamanio; 

    // Mostrar resultados 

    cout << "Venta total semanal: " << total << endl; 

    cout << "Promedio de ventas: " << promedio << endl; 

    cout << "Dias con ventas mayores a 150: " << mayor150 << endl; 

    cout << "Venta mas alta: " << ventaMax << endl; 

  

    return 0; 

}
