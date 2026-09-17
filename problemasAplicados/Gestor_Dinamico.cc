/*1.problemasAplicados/Gestor_Dinamico.cc
En tu main(), define una constante global kMaxVentas = 50 y crea un arreglo estático float ventas[kMaxVentas];.
Pregúntale al usuario exactamente cuántas ventas desea registrar hoy y guárdalo en un int cantidad_actual. Valida que este número no sea menor a 1 ni mayor a kMaxVentas.
Escribe una función llamada RegistrarVentas. Debe ser de tipo void y recibir:
Un puntero al arreglo de ventas (float* ventas).
La cantidad de ventas a registrar (int cantidad).
La Lógica de Registro: Dentro de la función, usa un ciclo for y aritmética de punteros (ventas + i) para pedirle al usuario que ingrese el monto de cada venta y guardarlo en la memoria original. No olvides tu escudo de punteros nulos.
Escribe una segunda función llamada CalcularTotal. Debe devolver un float y recibir el puntero al arreglo y la cantidad. Usa aritmética de punteros para sumar todas las ventas registradas y devolver el total.
En el main(), llama a ambas funciones e imprime el total recaudado en el día.*/
#include <iostream>

// 1. PROTOTIPOS DE FUNCIONES (Aviso para el compilador)
void RegistrarVentas(float* ventas, int cantidad);
float CalcularTotal(float* ventas, int cantidad);

int main() {
    const int kMaxVentas = 50;
    float ventas[kMaxVentas];
    int cantidad_actual;

    std::cout << "--- GESTOR DE VENTAS ---\n";
    std::cout << "Ingrese la cantidad de ventas a registrar (1-" << kMaxVentas << "): ";
    std::cin >> cantidad_actual;

    // Validación estricta
    while (cantidad_actual < 1 || cantidad_actual > kMaxVentas) {
        std::cout << "[Error] Cantidad invalida. Ingrese un numero entre 1 y " << kMaxVentas << ": ";
        std::cin >> cantidad_actual;
    }

    RegistrarVentas(ventas, cantidad_actual);
    
    float total = CalcularTotal(ventas, cantidad_actual);
    std::cout << "\nTotal recaudado en el dia: $" << total << std::endl;

    return 0;
}

// 2. IMPLEMENTACIÓN DE FUNCIONES
void RegistrarVentas(float* ventas, int cantidad) {
    if (ventas == nullptr) return;

    for (int i = 0; i < cantidad; ++i) {
        std::cout << "Ingrese el monto de la venta #" << (i + 1) << ": $";
        std::cin >> *(ventas + i); // Aritmética de punteros
    }
}

float CalcularTotal(float* ventas, int cantidad) {
    if (ventas == nullptr) return 0.0f;

    float total = 0.0f;
    for (int i = 0; i < cantidad; ++i) {
        total += *(ventas + i); // Aritmética de punteros
    }
    return total;
}