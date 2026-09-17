/*Ejercicio Propuesto 10: "Análisis de Tráfico de Red"
Este ejercicio evaluará tu capacidad para procesar todos los elementos de un arreglo, hacer cálculos anidados, y extraer múltiples resultados globales usando referencias (&) y punteros (*).
El Problema:
Define un struct Servidor que contenga un id_servidor (int), un arreglo estático paquetes_perdidos[5] de tipo int (representando las pérdidas de conexión en 5 días), y una variable estado_alerta (bool).
En tu main(), crea un arreglo estático de 3 servidores con datos de prueba. Todos deben iniciar con estado_alerta en false.
Escribe una función bool AuditarRed. Debe recibir 4 parámetros:
Un puntero al arreglo de servidores.
El tamaño del arreglo.
Una referencia int& servidor_mas_inestable (para guardar el ID del servidor que perdió más paquetes en total).
Un puntero int* total_alertas (para contar cuántos servidores entraron en estado de alerta).
La Lógica de la Función:
Escudo de punteros nulos (Regla de oro).
Inicializa tus receptores (*total_alertas = 0, y una variable temporal para rastrear el máximo de paquetes perdidos).
Recorre todo el arreglo de servidores. Para cada servidor, suma sus 5 días de paquetes_perdidos.
Regla de Negocio 1 (Alerta): Si la suma de paquetes perdidos de ese servidor es mayor a 100, cámbiale su estado_alerta a true (con la flecha ->) y aumenta tu contador total_alertas.
Regla de Negocio 2 (El Peor Servidor): Compara la suma de ese servidor con tu máximo registrado. Si es mayor, actualiza tu máximo y guarda el id_servidor en tu referencia servidor_mas_inestable.
Retorna true al finalizar de recorrer todos los servidores.
En el main(), invoca la función y muestra: el total de servidores en alerta, el ID del servidor más inestable, y el estado de cada servidor.*/
#include <iostream>

// Constantes globales de configuración (Estilo Google)
const int kNumDias = 5;
const int kNumServidores = 3;
const int kLimiteAlerta = 100;

struct Servidor {
    int id_servidor;
    int paquetes_perdidos[kNumDias];
    bool estado_alerta;
};

// Función AuditarRed (Lógica impecable de punteros y referencias)
bool AuditarRed(Servidor* servidores, int tamano, int& servidor_mas_inestable, int* total_alertas) {
    // 1. Escudo de punteros nulos
    if (servidores == nullptr || total_alertas == nullptr || tamano <= 0) {
        return false;
    }

    // 2. Inicialización de receptores y variables de apoyo
    *total_alertas = 0; 
    int max_paquetes_perdidos = -1; 

    // 3. Recorrido de la memoria RAM
    for (int i = 0; i < tamano; ++i) {
        int suma_paquetes_perdidos = 0;

        for (int j = 0; j < kNumDias; ++j) {
            suma_paquetes_perdidos += (servidores + i)->paquetes_perdidos[j];
        }

        // Regla de Negocio 1: Alerta
        if (suma_paquetes_perdidos > kLimiteAlerta) {
            (servidores + i)->estado_alerta = true;
            (*total_alertas)++; // Modificación segura de la dirección
        } else {
            (servidores + i)->estado_alerta = false;
        }

        // Regla de Negocio 2: El Peor Servidor
        if (suma_paquetes_perdidos > max_paquetes_perdidos) {
            max_paquetes_perdidos = suma_paquetes_perdidos;
            servidor_mas_inestable = (servidores + i)->id_servidor; // Modificación vía referencia
        }
    }

    return true; 
}

int main() {
    Servidor servidores[kNumServidores] = {
        {1, {20, 30, 25, 15, 10}, false},
        {2, {50, 60, 55, 45, 40}, false},
        {3, {10, 5, 15, 20, 25}, false}
    };
    
    std::cout << "--- ANALISIS DE TRAFICO DE RED ---\n";
    std::cout << std::boolalpha; 
    
    std::cout << "\nEstado inicial de los servidores:\n";
    for (int i = 0; i < kNumServidores; ++i) {
        std::cout << "Servidor ID: " << servidores[i].id_servidor
                  << " | Estado: " << (servidores[i].estado_alerta ? "ALERTA (ROJO)" : "NORMAL (VERDE)") << "\n";
    }

    int servidor_mas_inestable = 0; 
    int total_alertas = 0;

    // Ejecución de la auditoría enviando el mapa de memoria con &
    if (AuditarRed(servidores, kNumServidores, servidor_mas_inestable, &total_alertas)) {
        
        std::cout << "\n--- REPORTE DE AUDITORIA ---\n";
        std::cout << "Total de servidores en alerta: " << total_alertas << "\n";
        std::cout << "ID del servidor mas inestable: " << servidor_mas_inestable << "\n";
        
        std::cout << "\nEstado final de los servidores:\n";
        for (int i = 0; i < kNumServidores; ++i) {
            std::cout << "Servidor ID: " << servidores[i].id_servidor
                      << " | Estado: " << (servidores[i].estado_alerta ? "ALERTA (ROJO)" : "NORMAL (VERDE)") << "\n";
        }
    } else {
        std::cout << "[ERROR] Fallo crítico al auditar la red.\n";
    }

    return 0;
}