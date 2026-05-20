// =====================================================================
//  SISTEMA DE LABORATORIO - NOTAS DEL GRUPO G
//  Parte 5: Integracion del Laboratorio + Casos Especiales
//  Autor : Imanol Miranda  -  Grupo G
//  Curso : Algoritmos y Logica de Programacion (Primer Nivel)
//
//  Une en un solo programa:
//   - Parte 1 (Arreglos)         -> arreglos paralelos nombres[] y notas[]
//   - Parte 2 (Promedio)         -> calcularPromedio() + contarAprobados()
//   - Parte 3 (Teoria busqueda)  -> bandera bool encontrado
//   - Parte 4 (Codigo busqueda)  -> buscarPrimera() con retorno -1
//   - Parte 5 (Casos especiales) -> notas repetidas: 3 variantes
//
//  Restricciones del docente:
//   - SIN variables globales
//   - SIN STL avanzado (sin vector, sin algorithm, sin map)
//   - Solo arreglos crudos, funciones, bucles, condicionales
// =====================================================================

#include <iostream>
#include <iomanip>
#include <string>
using namespace std;

const int MAX = 50;  // capacidad maxima del arreglo

// ---------------------- PROTOTIPOS DE FUNCIONES ----------------------
int  cargarEstudiantes(string nombres[], double notas[]);
void mostrarLista(string nombres[], double notas[], int n);
double calcularPromedio(double notas[], int n);
int  contarAprobados(double notas[], int n);

// Busqueda secuencial - variante basica (primera ocurrencia)
int  buscarPrimera(double notas[], int n, double valor);

// CASOS ESPECIALES - notas repetidas
int  contarRepetidas(double notas[], int n, double valor);
int  buscarTodas(double notas[], int n, double valor, int posiciones[]);

void mostrarMenu();

// =====================================================================
//                              PROGRAMA PRINCIPAL
// =====================================================================
int main() {
    string nombres[MAX];
    double notas[MAX];
    int n = 0;          // cantidad real de estudiantes cargados
    int opcion;

    cout << "=============================================\n";
    cout << "   SISTEMA DE LABORATORIO - NOTAS  GRUPO G   \n";
    cout << "=============================================\n";

    do {
        mostrarMenu();
        while (!(cin >> opcion)) {
            cin.clear();
            cin.ignore(1000, '\n');
            cout << "[!] Ingrese un numero valido: ";
        }

        switch (opcion) {

            case 1:  // CARGAR DATOS
                n = cargarEstudiantes(nombres, notas);
                break;

            case 2:  // MOSTRAR LISTA
                if (n == 0)
                    cout << "\n[!] Primero debe cargar estudiantes (opcion 1).\n";
                else
                    mostrarLista(nombres, notas, n);
                break;

            case 3: { // PROMEDIO + APROBADOS
                if (n == 0) { cout << "\n[!] No hay datos.\n"; break; }
                double prom  = calcularPromedio(notas, n);
                int    aprob = contarAprobados(notas, n);
                cout << "\n--- ESTADISTICAS DEL GRUPO ---\n";
                cout << fixed << setprecision(2);
                cout << "Promedio general : " << prom  << "\n";
                cout << "Aprobados        : " << aprob << " de " << n << "\n";
                break;
            }

            case 4: { // BUSCAR - PRIMERA OCURRENCIA
                if (n == 0) { cout << "\n[!] No hay datos.\n"; break; }
                double valor;
                cout << "\nIngrese la nota a buscar: ";
                cin >> valor;
                int pos = buscarPrimera(notas, n, valor);
                if (pos == -1)
                    cout << "Nota " << valor << " NO encontrada en el grupo.\n";
                else
                    cout << "Nota " << valor << " encontrada en posicion "
                         << pos << " (estudiante: " << nombres[pos] << ")\n";
                break;
            }

            case 5: { // CASO ESPECIAL - CONTAR REPETIDAS
                if (n == 0) { cout << "\n[!] No hay datos.\n"; break; }
                double valor;
                cout << "\nIngrese la nota a contar: ";
                cin >> valor;
                int veces = contarRepetidas(notas, n, valor);
                cout << "La nota " << valor << " aparece "
                     << veces << " vez(es) en el grupo.\n";
                break;
            }

            case 6: { // CASO ESPECIAL - TODAS LAS POSICIONES
                if (n == 0) { cout << "\n[!] No hay datos.\n"; break; }
                double valor;
                int posiciones[MAX];
                cout << "\nIngrese la nota a buscar (todas las ocurrencias): ";
                cin >> valor;
                int cant = buscarTodas(notas, n, valor, posiciones);
                if (cant == 0) {
                    cout << "Nota " << valor << " no encontrada.\n";
                } else {
                    cout << "Nota " << valor << " encontrada en "
                         << cant << " posicion(es):\n";
                    for (int i = 0; i < cant; i++) {
                        cout << "   -> indice " << posiciones[i]
                             << "  : " << nombres[posiciones[i]] << "\n";
                    }
                }
                break;
            }

            case 7:
                cout << "\nFin del sistema. Hasta luego!\n";
                break;

            default:
                cout << "\n[!] Opcion invalida. Intente de nuevo.\n";
        }

    } while (opcion != 7);

    return 0;
}

// =====================================================================
//                            FUNCIONES
// =====================================================================

void mostrarMenu() {
    cout << "\n----------- MENU -----------\n";
    cout << "1. Cargar estudiantes\n";
    cout << "2. Mostrar lista\n";
    cout << "3. Promedio general y aprobados\n";
    cout << "4. Buscar nota (primera ocurrencia)\n";
    cout << "5. Contar cuantas veces se repite una nota\n";
    cout << "6. Mostrar TODAS las posiciones de una nota\n";
    cout << "7. Salir\n";
    cout << "Opcion: ";
}

int cargarEstudiantes(string nombres[], double notas[]) {
    int cant;
    cout << "\nCuantos estudiantes desea ingresar? ";
    while (!(cin >> cant)) {
        cin.clear();
        cin.ignore(1000, '\n');
        cout << "[!] Ingrese un numero valido: ";
    }

    if (cant <= 0 || cant > MAX) {
        cout << "[!] Cantidad invalida (1 - " << MAX << ").\n";
        return 0;
    }
    cin.ignore();

    for (int i = 0; i < cant; i++) {
        cout << "Estudiante " << (i + 1) << " - Nombre: ";
        getline(cin, nombres[i]);
        cout << "Estudiante " << (i + 1) << " - Nota  : ";
        while (!(cin >> notas[i])) {
            cin.clear();
            cin.ignore(1000, '\n');
            cout << "   [!] Nota invalida. Ingrese un numero: ";
        }
        cin.ignore();
    }
    return cant;
}

void mostrarLista(string nombres[], double notas[], int n) {
    cout << "\n--- LISTA DE ESTUDIANTES (" << n << ") ---\n";
    cout << fixed << setprecision(2);
    for (int i = 0; i < n; i++) {
        cout << "[" << i << "] " << nombres[i]
             << "  ->  " << notas[i] << "\n";
    }
}

// ------- PARTE 2  -------
double calcularPromedio(double notas[], int n) {
    if (n == 0) return 0.0;         // proteccion contra division para cero
    double suma = 0.0;              // acumulador SIEMPRE inicializado en 0
    for (int i = 0; i < n; i++) {
        suma += notas[i];
    }
    return suma / n;
}

int contarAprobados(double notas[], int n) {
    int cont = 0;                   // contador inicializado en 0
    for (int i = 0; i < n; i++) {
        if (notas[i] >= 7.0) cont++;
    }
    return cont;
}

// =====================================================================
//          BUSQUEDA SECUENCIAL - VARIANTE BASICA (Parte 4)
//   Devuelve el indice de la PRIMERA ocurrencia.
//   Si no encuentra el valor, devuelve -1.
//   Usa la bandera 'encontrado' para detener el ciclo apenas halla
//   la primera coincidencia (eficiencia).
// =====================================================================
int buscarPrimera(double notas[], int n, double valor) {
    int  pos        = -1;
    bool encontrado = false;
    int  i = 0;

    while (i < n && !encontrado) {
        if (notas[i] == valor) {
            pos        = i;
            encontrado = true;      // se levanta la bandera -> sale del while
        }
        i++;
    }
    return pos;
}

// =====================================================================
//          CASO ESPECIAL 1 - CONTAR cuantas veces aparece la nota
//   El ciclo NO se detiene al encontrar la primera coincidencia,
//   recorre todo el arreglo y va sumando un contador.
// =====================================================================
int contarRepetidas(double notas[], int n, double valor) {
    int contador = 0;
    for (int i = 0; i < n; i++) {
        if (notas[i] == valor) {
            contador++;             // sigue revisando, no se rompe el ciclo
        }
    }
    return contador;
}

// =====================================================================
//          CASO ESPECIAL 2 - DEVOLVER TODAS las posiciones
//   Guarda en el arreglo 'posiciones[]' cada indice donde se halla
//   el valor. Retorna cuantas posiciones guardo.
// =====================================================================
int buscarTodas(double notas[], int n, double valor, int posiciones[]) {
    int cant = 0;
    for (int i = 0; i < n; i++) {
        if (notas[i] == valor) {
            posiciones[cant] = i;   // guardo el indice
            cant++;                 // muevo el "cursor" del resultado
        }
    }
    return cant;
}
