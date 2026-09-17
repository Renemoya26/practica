/*4.El Problema:
Define un struct Archivo que contenga un id_archivo (int) y un nivel_confidencialidad (int).
En tu main(), crea una constante para el tamaño y un arreglo estático de 4 archivos inicializados con datos de prueba. Imprime el orden inicial.
Escribe una función llamada IntercambiarArchivos. Debe ser de tipo void y recibir 4 parámetros:
Un puntero al arreglo (Archivo* archivos).
El tamaño del arreglo (int tamano).
El índice del primer archivo a mover (int indice_a).
El índice del segundo archivo a mover (int indice_b).
La Lógica de la Función:
Escudo doble: Valida que el puntero no sea nulo Y verifica rigurosamente los límites (Bounds Checking): indice_a e indice_b deben ser mayores o iguales a 0, y estrictamente menores que tamano. Si algo falla, imprime un error y usa return; para abortar.
El Intercambio (Swap): Si los índices son válidos, intercambia el archivo completo de la posición a con el de la posición b usando aritmética de punteros (ej. *(archivos + indice_a)).
Pista: Necesitarás crear una variable temporal (Archivo temp;) para no perder los datos al sobrescribir la memoria.
En el main(), invoca la función para intercambiar los archivos de las posiciones 1 y 2. Imprime el arreglo nuevamente para comprobar que los archivos cambiaron de lugar.*/
#include <iostream>

// Struct en CamelCase
struct Archivo {
    int id_archivo;
    int nivel_confidencialidad;
};

// 1. Prototipo de la función (Asterisco pegado al tipo)
void IntercambiarArchivos(Archivo* archivos, int tamano, int indice_a, int indice_b);

int main() {
    const int kTamano = 4;
    Archivo archivos[kTamano] = {
        {1, 3},
        {2, 5},
        {3, 2},
        {4, 4}
    };

    std::cout << "--- GESTION DE ARCHIVOS ---\n";
    std::cout << "Orden inicial de archivos:\n";
    for (int i = 0; i < kTamano; ++i) {
        std::cout << "Archivo ID: " << (archivos + i)->id_archivo
                  << ", Nivel de Confidencialidad: " << (archivos + i)->nivel_confidencialidad << "\n";
    }

    // Intercambiar archivos en las posiciones 1 y 2
    IntercambiarArchivos(archivos, kTamano, 1, 2);

    std::cout << "\nOrden de archivos despues del intercambio:\n";
    for (int i = 0; i < kTamano; ++i) {
        std::cout << "Archivo ID: " << (archivos + i)->id_archivo
                  << ", Nivel de Confidencialidad: " << (archivos + i)->nivel_confidencialidad << "\n";
    }

    return 0;
}

// 2. Implementación de la función
void IntercambiarArchivos(Archivo* archivos, int tamano, int indice_a, int indice_b) {
    // Escudo de punteros nulos
    if (archivos == nullptr) {
        std::cerr << "[Error] Puntero nulo detectado.\n";
        return;
    }

    // Bounds Checking estricto
    if (indice_a < 0 || indice_a >= tamano || indice_b < 0 || indice_b >= tamano) {
        std::cerr << "[Error] Indices fuera de rango. Deben estar entre 0 y " << (tamano - 1) << ".\n";
        return;
    }

    // Intercambio completo en memoria RAM
    Archivo temp = *(archivos + indice_a);
    *(archivos + indice_a) = *(archivos + indice_b);
    *(archivos + indice_b) = temp;
}