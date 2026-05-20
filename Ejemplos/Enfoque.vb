Algoritmo BusquedaLinealCorta
    Entradas: arreglo[], tamano, objetivo

    Para indice = 0 Hasta tamano - 1 Hacer
        Si arreglo[indice] == objetivo Entonces
            Retornar indice  // Se encuentra el dato y termina el algoritmo inmediatamente
        FinSi
    FinPara

    Retornar -1  // Si el ciclo termina y no salió antes, el dato no existe
FinAlgoritmo
