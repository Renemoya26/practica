/*El Reto Final:
Estructura: Define un struct Sensor que contenga: id_sensor (int), temperatura (float), y esta_operativo (bool).
Configuración Global: Crea la constante const int kTotalSensores = 4; fuera del main().
Datos Iniciales: En tu main(), crea un arreglo estático de 4 sensores (ej. IDs 1, 2, 3, 4, con temperaturas mixtas como 22.5f, 45.0f, 18.0f, 50.2f, todos en true).
Función: Escribe el prototipo y la implementación de
bool CalibrarRed(Sensor* red, int tamano, float umbral_peligro, int* sensores_desactivados, float& temp_maxima)
La Lógica de Examen:
Aplica tu escudo protector para punteros y tamaño.
Inicializa tu contador de desactivados en 0 (recuerda usar el asterisco correctamente) y la temp_maxima en un valor muy bajo (ej. -999.0f).
Recorre el arreglo usando estrictamente aritmética de punteros ((red + i)->).
Regla 1 (Apagado de seguridad): Si el sensor está operativo Y su temperatura supera el umbral_peligro, cambia su estado a false y suma 1 a tu contador sensores_desactivados.
Regla 2 (El más caliente): Evalúa la temperatura del sensor actual. Si es mayor a temp_maxima, actualiza la referencia directamente.
Retorna true.
Prueba Final: En tu main(), define un umbral de 40.0f. Ejecuta la función e imprime cuántos sensores fueron desactivados por seguridad y cuál fue la temperatura máxima registrada en toda la red.*/
#include <iostream>

// 1. Struct en CamelCase (Google C++ Style Guide)
struct Sensor {
    int id_sensor;
    float temperatura;
    bool esta_operativo;
};

// 2. Constante global única y segura
const int kTotalSensores = 4;

bool CalibrarRed(Sensor* red, int tamano, float umbral_peligro, int* sensores_desactivados, float& temp_maxima);

int main() {
    Sensor red[kTotalSensores] = {
        {1, 22.5f, true},
        {2, 45.0f, true},
        {3, 18.0f, true},
        {4, 50.2f, true},
    };
        // Variables para recibir resultados de la función
    float umbral_peligro = 40.0f;
    int sensores_desactivados = 0;
    float temp_maxima = 0.0f;

    std::cout << "--- CALIBRANDO RED DE SENSORES ---\n";
    if (CalibrarRed(red, kTotalSensores, umbral_peligro, &sensores_desactivados, temp_maxima)) {
        std::cout << "Sensores desactivados por seguridad: " << sensores_desactivados << "\n";
        std::cout << "Temperatura maxima registrada: " << temp_maxima << " C\n\n";
    }

    std::cout << "--- ESTADO FINAL DE LOS SENSORES ---\n";
    for (int i = 0; i < kTotalSensores; ++i) {
        std::cout << "Sensor ID: " << red[i].id_sensor
                  << ", Temperatura: " << red[i].temperatura
                  << " C, Operativo: " << (red[i].esta_operativo ? "SI" : "NO") << "\n";
    }

    return 0;
}

bool CalibrarRed(Sensor* red, int tamano, float umbral_peligro, int* sensores_desactivados, float& temp_maxima) {
    if (red == nullptr || sensores_desactivados == nullptr || tamano <= 0) {
        return false;
    }
    // Inicializamos los valores de salida
    *sensores_desactivados = 0;
    temp_maxima = -999.0f;
    // Recorremos el arreglo de sensores usando aritmética de punteros
    for (int i = 0; i < tamano; ++i) {
        Sensor* sensor_actual = red + i;

        // Regla 1: Apagado de seguridad
        if (sensor_actual->esta_operativo && sensor_actual->temperatura > umbral_peligro) {
            sensor_actual->esta_operativo = false;
            (*sensores_desactivados)++;
        }

        // Regla 2: Evaluar temperatura máxima
        if (sensor_actual->temperatura > temp_maxima) {
            temp_maxima = sensor_actual->temperatura;
        }
    }

    return true;
}