/*8.El Problema:
Estructura: Define un struct Sensor que contenga: id_sensor (int), un arreglo estático temperaturas[3] (float) para registrar 3 lecturas en el día, y estado_critico (bool).
Datos iniciales: En tu main(), crea un arreglo estático de 3 sensores con datos de prueba (ej. un sensor con lecturas 30.5, 31.0, 30.0; otro con 38.0, 39.5, 40.0). Todos inician con estado_critico en false.
Función: Escribe una función bool AnalizarSensores(Sensor* red, int tamano, float umbral_alerta, int* total_alertas, int& id_sensor_caliente).
Lógica de Negocio:
Aplica tu escudo inquebrantable de punteros nulos.
Inicializa tu receptor *total_alertas = 0; y crea una variable temporal para rastrear el promedio de temperatura más alto.
Recorre el arreglo de sensores usando aritmética de punteros (puedes usar el truco del Sensor* sensor_actual = red + i; que vimos antes).
Sub-ciclo: Para cada sensor, suma sus 3 temperaturas y calcula su promedio.
Regla 1 (Alerta): Si el promedio de ese sensor es mayor al umbral_alerta (ej. 35.0), cambia su estado_critico a true y aumenta tu total_alertas.
Regla 2 (El más caliente): Compara el promedio de este sensor con el promedio máximo que has registrado. Si es mayor, actualiza tu máximo y guarda el id_sensor en la referencia id_sensor_caliente.
Retorna true.
Prueba: En el main(), define tu umbral en 35.0, invoca la función e imprime cuántos sensores están en estado crítico, cuál es el ID del sensor con el promedio más alto, y el estado final de todos.*/
#include <iostream>
struct Sensor {
    int id_sensor;
    float temperaturas[3];
    bool estado_critico;
};

bool AnalizarSensores(Sensor* red, int tamano, float umbral_alerta, int* total_alertas, int& id_sensor_caliente);

int main(){
    const int kTamano = 3;
    Sensor red[kTamano] = {
        {1, {30.5f, 31.0f, 30.0f}, false},
        {2, {38.0f, 39.5f, 40.0f}, false},
        {3, {34.0f, 35.5f, 36.0f}, false}
    };

    float umbral_alerta = 35.0f;
    int total_alertas = 0;
    int id_sensor_caliente = -1;

    std::cout << "--- SISTEMA DE MONITOREO DE SENSORES ---\n";
    std::cout << "Analizando sensores con umbral de alerta: " << umbral_alerta << "\n\n";

    // Llamada a la función AnalizarSensores
    bool exito = AnalizarSensores(red, kTamano, umbral_alerta, &total_alertas, id_sensor_caliente);

    if (exito) {
        std::cout << "[EXITO] Analisis completado.\n";
        std::cout << "Total de sensores en estado critico: " << total_alertas << "\n";
        if (id_sensor_caliente != -1) {
            std::cout << "ID del sensor con promedio mas alto: " << id_sensor_caliente << "\n";
        } else {
            std::cout << "No hay sensores criticos.\n";
        }
    } else {
        std::cerr << "[ERROR] Fallo en el analisis de sensores.\n";
    }

    std::cout << "\n--- ESTADO FINAL DE LOS SENSORES ---\n";
    for (int i = 0; i < kTamano; ++i) {
        std::cout << "Sensor ID: " << (red + i)->id_sensor
                  << ", Estado Critico: " << ((red + i)->estado_critico ? "SI" : "NO") << "\n";
    }

    return 0;
}

bool AnalizarSensores(Sensor* red, int tamano, float umbral_alerta, int* total_alertas, int& id_sensor_caliente) {
    // Escudo de punteros nulos
    if (red == nullptr || total_alertas == nullptr) {
        std::cerr << "[ERROR] Puntero nulo detectado.\n";
        return false;
    }

    *total_alertas = 0;
    float promedio_maximo = -1.0f;

    for (int i = 0; i < tamano; ++i) {
        Sensor* sensor_actual = red + i;
        float suma_temperaturas = 0.0f;

        // Calcular el promedio de temperaturas
        for (int j = 0; j < 3; ++j) {
            suma_temperaturas += sensor_actual->temperaturas[j];
        }
        float promedio = suma_temperaturas / 3.0f;

        // Regla 1: Alerta
        if (promedio > umbral_alerta) {
            sensor_actual->estado_critico = true;
            (*total_alertas)++;
        }

        // Regla 2: El más caliente
        if (promedio > promedio_maximo) {
            promedio_maximo = promedio;
            id_sensor_caliente = sensor_actual->id_sensor;
        }
    }

    return true;
}