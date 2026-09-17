/*6.El Problema:
Estructura: Define un struct Vuelo con numero_vuelo (int), asientos_disponibles (int) y estado_lleno (bool).
Datos iniciales: En tu main(), crea un arreglo estático de 3 vuelos con datos de prueba. Todos deben iniciar con estado_lleno en false.
Función: Escribe una función bool ReservarAsientos(Vuelo* cartelera, int tamano, int num_vuelo, int asientos_pedidos, int* asientos_restantes).
Lógica de Seguridad: Aplica tu escudo protector para los punteros nulos.
Búsqueda y Alteración: Recorre el arreglo usando aritmética de punteros (cartelera + i). Busca el vuelo solicitado por el usuario.
Reglas de Negocio:
Si el vuelo existe y tiene asientos suficientes, resta los asientos_pedidos de sus asientos disponibles.
Si al restar, los asientos_disponibles llegan exactamente a 0, cambia su estado_lleno a true (usando el operador flecha ->).
Guarda la cantidad final de asientos que sobraron en la dirección de memoria de asientos_restantes (usando el operador de desreferenciación *).
Retorna true si la reserva fue exitosa. Si no hay suficientes asientos o el vuelo no existe, retorna false.
Prueba: En el main(), intenta reservar asientos en un vuelo, atrapa el resultado en el puntero de asientos restantes, e imprime si la operación fue un éxito y el estado actualizado de ese vuelo.*/
#include <iostream>

// Struct en CamelCase
struct Vuelo {
    int numero_vuelo;
    int asientos_disponibles;
    bool estado_lleno;
};

// Prototipo de la función
bool ReservarAsientos(Vuelo* cartelera, int tamano, int num_vuelo, int asientos_pedidos, int* asientos_restantes);

int main() {
    const int kTamano = 3;
    Vuelo cartelera[kTamano] = {
        {101, 5, false},
        {202, 2, false},
        {303, 0, true}
    };

    int num_vuelo = 202; 
    int asientos_pedidos = 1; 
    int asientos_restantes = 0; 

    std::cout << "--- SISTEMA DE RESERVA DE VUELOS ---\n";
    std::cout << "Intentando reservar " << asientos_pedidos << " asientos en el vuelo " << num_vuelo << "...\n\n";

    // Llamada enviando los mapas de memoria
    bool exito = ReservarAsientos(cartelera, kTamano, num_vuelo, asientos_pedidos, &asientos_restantes);

    if (exito) {
        std::cout << "[EXITO] Reserva confirmada. Asientos restantes: " << asientos_restantes << "\n\n";
    } else {
        std::cout << "[ERROR] Reserva fallida. No hay suficientes asientos o el vuelo no existe.\n\n";
    }

    std::cout << "--- ESTADO ACTUALIZADO DE LA CARTELERA ---\n";
    for (int i = 0; i < kTamano; ++i) {
        std::cout << "Vuelo: " << (cartelera + i)->numero_vuelo
                  << " | Asientos Disponibles: " << (cartelera + i)->asientos_disponibles
                  << " | Estado Lleno: " << ((cartelera + i)->estado_lleno ? "SI" : "NO") << "\n";
    }

    return 0;
}

// Implementación de la función
bool ReservarAsientos(Vuelo* cartelera, int tamano, int num_vuelo, int asientos_pedidos, int* asientos_restantes) {
    // Escudo protector explícito con nullptr
    if (cartelera == nullptr || asientos_restantes == nullptr || tamano <= 0) {
        return false;
    }

    // Búsqueda con aritmética de punteros
    for (int i = 0; i < tamano; ++i) {
        if ((cartelera + i)->numero_vuelo == num_vuelo) {
            
            // Verificación de stock
            if ((cartelera + i)->asientos_disponibles >= asientos_pedidos) {
                (cartelera + i)->asientos_disponibles -= asientos_pedidos;
                
                // Actualización de estado
                if ((cartelera + i)->asientos_disponibles == 0) {
                    (cartelera + i)->estado_lleno = true;
                }
                
                // Extracción de datos
                *asientos_restantes = (cartelera + i)->asientos_disponibles;
                
                return true;
            } else {
                return false; // No hay suficientes asientos
            }
        }
    }
    
    return false; // Vuelo no encontrado
}