/* Ejercicio Propuesto 9: "Sistema de Prioridad de Envíos"
Conceptos a evaluar: Aritmética de punteros avanzada (mirar hacia atrás), intercambio en memoria (swap de structs enteros), protección estricta de límites (Bounds Checking).
El Problema:
Define un struct Paquete que contenga un id_tracking (int), un peso_kg (float), y un es_prioritario (bool).
En tu main(), crea un arreglo estático de 4 paquetes con datos de prueba. Todos inician con es_prioritario en false. Imprime el orden original.
Escribe una función void AdelantarPaquete. Debe recibir:
Un puntero al arreglo de paquetes.
El tamaño del arreglo.
El id_tracking a buscar (int).
Un puntero bool* operacion_exitosa (para avisarle al main si se logró mover el paquete).
La Lógica de la Función:
Escudo de punteros nulos.
Recorre el arreglo buscando el id_tracking.
Regla de Negocio (El Swap): Si lo encuentras, verifica en qué índice está. Si está en el índice 0, no puedes adelantarlo más (ya es el primero); establece *operacion_exitosa = false y termina.
Si está en un índice mayor a 0 (ej. índice i), intercambia el paquete completo de la posición i con el paquete de la posición i - 1. (Pista: crea una variable Paquete temporal para ayudarte a hacer el cambio sin perder datos).
Al paquete que acaba de ser movido a la posición i - 1, cámbiale su estado es_prioritario a true usando la flecha (->).
Establece *operacion_exitosa = true.
En el main(), prueba la función intentando adelantar un paquete de la posición 2, e imprime el arreglo nuevamente para que compruebes con tus propios ojos cómo los datos cambiaron de lugar en la RAM.*/
#include <iostream>

struct Paquete {
    int id_tracking;
    float peso_kg;
    bool es_prioritario;
};

// Prototipo con el estilo Google (asteriscos pegados al tipo)
void AdelantarPaquete(Paquete* paquetes, int tamano, int id_tracking, bool* operacion_exitosa);

int main() {
    const int kNumPaquetes = 4;
    Paquete paquetes[kNumPaquetes] = {
        {101, 2.5f, false},
        {102, 1.0f, false},
        {103, 3.2f, false},
        {104, 0.8f, false}
    };

    std::cout << "--- SISTEMA DE PRIORIDAD DE ENVIOS ---\n";
    std::cout << std::boolalpha; // Permite imprimir true/false en lugar de 1/0
    
    std::cout << "\nOrden original de paquetes:\n";
    for (int i = 0; i < kNumPaquetes; ++i) {
        std::cout << "ID: " << paquetes[i].id_tracking
                  << ", Peso: " << paquetes[i].peso_kg
                  << ", Prioritario: " << paquetes[i].es_prioritario << "\n";
    }

    bool operacion_exitosa = false;
    // Llamada a la función pasando los mapas de memoria
    AdelantarPaquete(paquetes, kNumPaquetes, 103, &operacion_exitosa);

    if (operacion_exitosa) {
        std::cout << "\n[EXITO] El paquete con ID 103 fue adelantado.\n";
    } else {
        std::cout << "\n[ERROR] No se pudo adelantar el paquete con ID 103.\n";
    }

    std::cout << "\nNuevo orden de paquetes:\n";
    for (int i = 0; i < kNumPaquetes; ++i) {
        std::cout << "ID: " << paquetes[i].id_tracking
                  << ", Peso: " << paquetes[i].peso_kg
                  << ", Prioritario: " << paquetes[i].es_prioritario << "\n";
    }

    return 0;
}

// Función implementada con estilo Google
void AdelantarPaquete(Paquete* paquetes, int tamano, int id_tracking, bool* operacion_exitosa) {
    if (paquetes == nullptr || operacion_exitosa == nullptr || tamano <= 0) {
        return;
    }

    for (int i = 0; i < tamano; ++i) {
        if ((paquetes + i)->id_tracking == id_tracking) {
            
            // Validación de límites: No se puede adelantar si ya está en la posición 0
            if (i == 0) {
                *operacion_exitosa = false;
                return;
            }

            // Intercambio completo en RAM usando desreferenciación
            Paquete temp = *(paquetes + i);
            *(paquetes + i) = *(paquetes + i - 1);
            *(paquetes + i - 1) = temp;

            // Actualizamos la prioridad del paquete que ahora está en i - 1
            (paquetes + i - 1)->es_prioritario = true;
            *operacion_exitosa = true;
            return;
        }
    }

    *operacion_exitosa = false;
}