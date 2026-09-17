/*Ejercicio Propuesto 3: "Corrección de Calificaciones"
Conceptos a evaluar: Structs con arreglos internos, aritmética de punteros, validación de límites (bounds checking) y retornos booleanos.

El Problema:
Define un struct Estudiante que contenga un carnet (int) y un arreglo estático notas[3] de tipo float (representando las notas de 3 laboratorios).
En tu main(), crea un arreglo estático de 3 estudiantes inicializados con datos de prueba.
Escribe una función llamada ActualizarNota. Esta función debe devolver un bool y recibir:
Un puntero al inicio del arreglo de estudiantes.
El tamaño del arreglo.
El carnet del estudiante a buscar (int).
El número de la evaluación a corregir (int índice, que debe ser 0, 1 o 2).
La nueva nota a asignar (float).
La Lógica: La función debe recorrer el arreglo usando el puntero. Si encuentra el carnet, debe validar que el índice de la evaluación sea correcto (0 al 2) y que la nueva nota sea válida (0.0 a 10.0). Si todo es correcto, actualiza la nota usando la flecha (->) y retorna true. Si el estudiante no existe o los datos son inválidos, retorna false.
En el main(), prueba la función intentando actualizar una nota y muestra un mensaje de éxito o error dependiendo del retorno.*/
#include <iostream>

// Constantes globales de configuración (Estilo Google)
const int kNumNotas = 3;
const int kNumEstudiantes = 3;

// Struct en CamelCase
struct Estudiante {
    int carnet;
    float notas[kNumNotas];
};

// Función segura y con retornos booleanos
bool ActualizarNota(Estudiante *estudiantes, int tamano, int carnet, int indice, float nueva_nota) {
    // 1. Validación de puntero nulo y tamaño
    if (estudiantes == nullptr || tamano <= 0) {
        return false; 
    }
    
    // 2. Validación estricta de límites (Bounds checking)
    if (indice < 0 || indice >= kNumNotas || nueva_nota < 0.0f || nueva_nota > 10.0f) {
        return false; 
    }

    // 3. Búsqueda y actualización en memoria original
    for (int i = 0; i < tamano; ++i) {
        if ((estudiantes + i)->carnet == carnet) {
            (estudiantes + i)->notas[indice] = nueva_nota; 
            return true;                                   
        }
    }

    return false; // No se encontró el carnet
}

int main() {
    // Inicialización del arreglo estático usando la constante
    Estudiante estudiantes[kNumEstudiantes] = {
        {1, {8.5f, 9.0f, 7.5f}},
        {2, {6.0f, 7.0f, 8.0f}},
        {3, {9.0f, 8.5f, 9.5f}}
    };

    std::cout << "--- SISTEMA DE CALIFICACIONES ---\n";
    
    int carnet;
    std::cout << "Ingrese el carnet del estudiante a actualizar: ";
    std::cin >> carnet;

    int indice;
    std::cout << "Ingrese el indice de la evaluacion a corregir (0 al " << (kNumNotas - 1) << "): ";
    std::cin >> indice;

    float nueva_nota;
    std::cout << "Ingrese la nueva nota (0.0 a 10.0): ";
    std::cin >> nueva_nota;

    // Llamada a la función pasando el mapa de memoria
    bool resultado = ActualizarNota(estudiantes, kNumEstudiantes, carnet, indice, nueva_nota);
    
    std::cout << "\n--- RESULTADO ---\n";
    if (resultado) {
        std::cout << "[Exito] Nota actualizada exitosamente.\n";
    } else {
        std::cout << "[Error] No se pudo actualizar la nota. Verifique el carnet o los limites.\n";
    }

    return 0;
}