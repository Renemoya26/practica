/*Ejercicio Propuesto 8: "Gestión de Biblioteca Universitaria"
Conceptos a evaluar: Recorridos múltiples con punteros, validación de estados lógicos anidados, extracción de cálculos con referencias (&) y conteos globales con punteros (*).
El Problema:
Define un struct Libro que contenga un id_libro (int), un arreglo estático calificaciones[4] de tipo float (representando 4 reseñas de estudiantes), y una variable estado_prestado (bool).
En tu main(), crea un arreglo estático de 3 libros inicializados con datos de prueba. Todos deben empezar con estado_prestado en false (disponibles).
Escribe una función llamada ProcesarPrestamo. Debe devolver un bool (para saber si el préstamo fue exitoso) y recibir 5 parámetros:
Un puntero al arreglo de libros.
El tamaño del arreglo.
El id_libro que el estudiante quiere pedir (int).
Una referencia float &calificacion_promedio (para extraer la calificación promedio del libro solicitado).
Un puntero int *libros_disponibles_restantes (para guardar cuántos libros quedan disponibles en total en la biblioteca).
La Lógica de la Función:
Escudo protector de punteros (Regla de oro).
Recorre el arreglo buscando el id_libro.
Regla de negocio 1 (Disponibilidad): Si encuentras el libro, verifica que estado_prestado sea false. Si ya es true (ya está prestado), debes retornar false inmediatamente.
Regla de negocio 2 (Cálculo y Actualización): Si está disponible, calcula el promedio de sus 4 calificaciones y guárdalo en la referencia. Luego, cambia el estado_prestado de ese libro a true (usando la flecha ->).
Regla de negocio 3 (El Conteo Global): Después de prestar el libro, debes hacer otro pequeño recorrido (o usar una variable de apoyo) para contar cuántos libros en todo el arreglo siguen teniendo estado_prestado == false. Guarda ese número en el mapa del puntero libros_disponibles_restantes.
Retorna true (préstamo exitoso).
En el main(), intenta pedir un libro e imprime: si fue exitoso, su calificación promedio, y cuántos libros quedan en la biblioteca.*/
#include <iostream>

// Constantes globales para evitar "números mágicos"
const int kNumLibros = 3;
const int kNumCalificaciones = 4;

// Struct en CamelCase
struct Libro {
    int id_libro;
    float calificaciones[kNumCalificaciones];
    bool estado_prestado;
};  

// Función que procesa el préstamo, combinando punteros y referencias
bool ProcesarPrestamo(Libro* biblioteca, int tamano, int id_libro, float& calificacion_promedio, int* libros_disponibles_restantes) {
    // 1. Escudo protector de punteros
    if (biblioteca == nullptr || libros_disponibles_restantes == nullptr || tamano <= 0) {
        return false;
    }

    for (int i = 0; i < tamano; ++i) {
        if ((biblioteca + i)->id_libro == id_libro) {
            
            // Regla de negocio 1: Disponibilidad
            if ((biblioteca + i)->estado_prestado) {
                return false; // Libro ya prestado
            }

            // Regla de negocio 2: Cálculo y Actualización original
            calificacion_promedio = 0.0f;
            for (int j = 0; j < kNumCalificaciones; ++j) {
                calificacion_promedio += (biblioteca + i)->calificaciones[j];
            }
            calificacion_promedio /= kNumCalificaciones; // Alteración directa vía &
            
            // Cambiamos el estado en la memoria original
            (biblioteca + i)->estado_prestado = true;

            // Regla de negocio 3: Conteo Global de disponibles
            *libros_disponibles_restantes = 0;
            for (int k = 0; k < tamano; ++k) {
                if (!(biblioteca + k)->estado_prestado) {
                    (*libros_disponibles_restantes)++; // Paréntesis de seguridad
                }
            }

            return true; // Préstamo exitoso
        }
    }

    return false; // Libro no encontrado
}

int main() {
    Libro biblioteca[kNumLibros] = {
        {101, {4.5f, 4.0f, 5.0f, 4.8f}, false},
        {102, {3.5f, 3.8f, 4.0f, 3.9f}, false},
        {103, {5.0f, 4.9f, 5.0f, 5.0f}, false}
    };
    
    std::cout << "--- SISTEMA DE BIBLIOTECA UNIVERSITARIA ---\n";

    int id_libro_a_prestar = 102;
    float calificacion_promedio = 0.0f;
    int libros_disponibles = 0;

    // Primer intento (Debería ser exitoso)
    std::cout << "\nIntentando prestar el libro ID: " << id_libro_a_prestar << "...\n";
    if (ProcesarPrestamo(biblioteca, kNumLibros, id_libro_a_prestar, calificacion_promedio, &libros_disponibles)) {
        std::cout << "[EXITO] Libro prestado correctamente.\n";
        std::cout << "Calificacion promedio del libro: " << calificacion_promedio << " estrellas.\n";
        std::cout << "Libros que siguen disponibles en la biblioteca: " << libros_disponibles << "\n";
    } else {
        std::cout << "[ERROR] El libro no existe o ya esta prestado.\n";
    }

    // Segundo intento (Debería fallar porque ya se prestó)
    std::cout << "\nIntentando prestar el MISMO libro nuevamente...\n";
    if (ProcesarPrestamo(biblioteca, kNumLibros, id_libro_a_prestar, calificacion_promedio, &libros_disponibles)) {
        std::cout << "[EXITO] Libro prestado correctamente.\n";
    } else {
        std::cout << "[ERROR] Transaccion rechazada. El libro ya se encuentra prestado.\n";
    }

    return 0;
}