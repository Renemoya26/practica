/*9.El Problema:
Estructura: Define un struct Vehiculo que contenga: id_vehiculo (int), kilometraje (float), y necesita_mantenimiento (bool).
Datos iniciales: En tu main(), crea una constante para el tamaño y un arreglo estático de 4 vehículos con distintos kilometrajes (ej. 8500.0, 9800.5, 4000.0, 9950.0). Todos inician con necesita_mantenimiento en false.
Función: Escribe una función bool RegistrarRuta(Vehiculo* flota, int tamano, float distancia_ruta, float limite_mantenimiento, int* total_mantenimiento, int& id_mas_usado).
La Lógica de Negocio:
Aplica tu escudo inquebrantable de punteros nulos.
Inicializa tu receptor *total_mantenimiento = 0; y crea una variable temporal para rastrear el kilometraje más alto.
Recorre el arreglo de vehículos usando aritmética de punteros (recuerda nuestro truco limpio: Vehiculo* vehiculo_actual = flota + i;).
Actualización Masiva: A cada vehículo, súmale la distancia_ruta a su kilometraje actual.
Regla 1 (Taller): Si el nuevo kilometraje de ese vehículo supera el limite_mantenimiento (ej. 10000.0), cambia su estado necesita_mantenimiento a true y aumenta tu contador total_mantenimiento.
Regla 2 (El más desgastado): Compara el nuevo kilometraje de este vehículo con el kilometraje máximo que has registrado. Si es mayor, actualiza tu máximo y guarda el id_vehiculo en la referencia id_mas_usado.
Retorna true.
Prueba: En el main(), define una distancia_ruta de 150.0 km y un límite de mantenimiento de 10000.0 km. Invoca la función e imprime cuántos vehículos deben ir al taller, cuál es el ID del vehículo con más kilometraje en total, y el estado final de toda la flota.*/
#include <iostream>
struct Vehiculo {
    int id_vehiculo;
    float kilometraje;
    bool necesita_mantenimiento;
};
bool RegistrarRuta(Vehiculo* flota, int tamano, float distancia_ruta, float limite_mantenimiento, int* total_mantenimiento, int& id_mas_usado);

int main() {
    const int kTamano = 4;
    Vehiculo flota[kTamano] = {
        {1, 8500.0f, false},
        {2, 9800.5f, false},
        {3, 4000.0f, false},
        {4, 9950.0f, false}
    };

    float distancia_ruta = 150.0f;
    float limite_mantenimiento = 10000.0f;
    int total_mantenimiento = 0;
    int id_mas_usado = -1;

    std::cout << "--- SISTEMA DE CONTROL DE VEHICULOS ---\n";
    std::cout << "Registrando ruta de " << distancia_ruta << " km con limite de mantenimiento: " << limite_mantenimiento << "\n\n";

    // Llamada a la función RegistrarRuta
    bool exito = RegistrarRuta(flota, kTamano, distancia_ruta, limite_mantenimiento, &total_mantenimiento, id_mas_usado);

    if (exito) {
        std::cout << "[EXITO] Registro de ruta completado.\n";
        std::cout << "Total de vehículos que necesitan mantenimiento: " << total_mantenimiento << "\n";
        if (id_mas_usado != -1) {
            std::cout << "ID del vehículo con más kilometraje: " << id_mas_usado << "\n";
        } else {
            std::cout << "No hay vehículos que superen el límite de mantenimiento.\n";
        }
    } else {
        std::cerr << "[ERROR] Fallo en el registro de ruta.\n";
    }

    std::cout << "\n--- ESTADO FINAL DE LA FLOTA ---\n";
    for (int i = 0; i < kTamano; ++i) {
        std::cout << "Vehículo ID: " << (flota + i)->id_vehiculo
                  << ", Kilometraje: " << (flota + i)->kilometraje
                  << ", Necesita Mantenimiento: " << ((flota + i)->necesita_mantenimiento ? "SI" : "NO") << "\n";
    }

    return 0;
}

bool RegistrarRuta(Vehiculo* flota, int tamano, float distancia_ruta, float limite_mantenimiento, int* total_mantenimiento, int& id_mas_usado) {
    // Escudo de punteros nulos
    if (flota == nullptr || total_mantenimiento == nullptr) {
        std::cerr << "[Error] Puntero nulo detectado.\n";
        return false;
    }

    *total_mantenimiento = 0;
    float max_kilometraje = -1.0f;

    for (int i = 0; i < tamano; ++i) {
        Vehiculo* vehiculo_actual = flota + i;
        vehiculo_actual->kilometraje += distancia_ruta;

        // Regla 1: Taller
        if (vehiculo_actual->kilometraje > limite_mantenimiento) {
            vehiculo_actual->necesita_mantenimiento = true;
            (*total_mantenimiento)++;
        }

        // Regla 2: El más desgastado
        if (vehiculo_actual->kilometraje > max_kilometraje) {
            max_kilometraje = vehiculo_actual->kilometraje;
            id_mas_usado = vehiculo_actual->id_vehiculo;
        }
    }

    return true;
}