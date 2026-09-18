/*En tu main(), crea una constante kMaxLecturas con valor de 15 y un arreglo estático: float temperaturas[kMaxLecturas];.
Pregúntale al usuario exactamente cuántas lecturas de temperatura desea registrar hoy (guárdalo en una variable cantidad_lecturas y confía en que ingresará un número entre 1 y 15).
Asigna el inicio del arreglo a un puntero: float* ptr_temperaturas = temperaturas;.
Usa un ciclo for y estrictamente aritmética de punteros con el operador de desreferenciación (*(ptr_temperaturas + i)) junto con std::cin para pedirle al usuario que ingrese cada lectura.
En otro ciclo (o en el mismo, si lo prefieres), usa el puntero para sumar las lecturas, calcula el promedio y muéstralo en pantalla.*/
#include <iostream>

// Constantes globales de configuración (Google C++ Style Guide)
const int kMaxLecturas = 15;

// Prototipos de funciones modulares
void IngresarTemperaturas(float* temperaturas, int cantidad);
float CalcularPromedio(float* temperaturas, int cantidad);

int main() {
    // 1. Declaración limpia (Stack)
    float temperaturas[kMaxLecturas];
    int cantidad_lecturas = 0;

    std::cout << "--- SISTEMA METEOROLOGICO ---\n";
    std::cout << "Ingrese la cantidad de lecturas (1-" << kMaxLecturas << "): ";
    std::cin >> cantidad_lecturas;

    // 2. Validación de seguridad estricta
    if (cantidad_lecturas <= 0 || cantidad_lecturas > kMaxLecturas) {
        std::cerr << "[ERROR] Cantidad fuera de rango.\n";
        return 1; // Salida con código de error
    }

    // 3. Delegación de tareas a las funciones (pasando el mapa de memoria)
    IngresarTemperaturas(temperaturas, cantidad_lecturas);
    
    float promedio = CalcularPromedio(temperaturas, cantidad_lecturas);
    
    std::cout << "\n[RESULTADO] El promedio de las lecturas es: " << promedio << " grados.\n";

    return 0; // Salida exitosa
}

// -------------------------------------------------------------------------
// FUNCIONES DE NEGOCIO
// -------------------------------------------------------------------------

void IngresarTemperaturas(float* temperaturas, int cantidad) {
    // Escudo de punteros nulos
    if (temperaturas == nullptr || cantidad <= 0) {
        return; 
    }

    std::cout << "\n";
    // Recorrido y escritura directa en memoria usando aritmética de punteros
    for (int i = 0; i < cantidad; ++i) {
        std::cout << "Ingrese la lectura #" << (i + 1) << ": ";
        std::cin >> *(temperaturas + i); 
    }
}

float CalcularPromedio(float* temperaturas, int cantidad) {
    // Escudo de punteros nulos
    if (temperaturas == nullptr || cantidad <= 0) {
        return 0.0f; 
    }

    float sumatoria = 0.0f;
    
    // Recorrido y lectura de memoria usando aritmética de punteros
    for (int i = 0; i < cantidad; ++i) {
        sumatoria += *(temperaturas + i);
    }

    return sumatoria / cantidad;
}