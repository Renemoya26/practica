/*Ejercicio Propuesto 2: "Estación Climática"
Conceptos a evaluar: Estructuras con arreglos internos, paso por referencia constante (const &), y múltiples resultados vía punteros.

El Problema:
Define un struct Estacion que contenga un nombre_ciudad (string) y un arreglo estático temperaturas[7] de tipo double (representando los 7 días de la semana).
En el main(), declara e inicializa una estación con datos ingresados por el usuario o predefinidos.
Crea una función llamada AnalizarClima. Esta función no va a retornar ningún valor (void), pero debe entregar dos resultados simultáneos al main().
Los parámetros: La función debe recibir la estación por referencia constante (para protegerla de modificaciones accidentales y no hacer copias pesadas), un puntero double* maxima, y un puntero double* minima.
La Lógica: La función debe recorrer el arreglo interno de la estación y descubrir cuál fue la temperatura más alta y cuál la más baja, guardando esos resultados directamente en las direcciones de memoria que pasaste por los punteros.*/
#include <iostream>
#include <string>

// Declaramos la constante para evitar el "número mágico" 7
const int kDiasSemana = 7;

// Struct en CamelCase
struct Estacion
{
    std::string nombre_ciudad;
    double temperaturas[kDiasSemana];
};

// Función segura: Recibe 1 referencia constante y 2 punteros
void AnalizarClima(const Estacion &estacion, double *maxima, double *minima)
{
    // 1. Validación de seguridad crítica contra punteros nulos
    if (maxima == nullptr || minima == nullptr)
    {
        std::cout << "Error: Punteros nulos detectados.\n";
        return;
    }

    // 2. Inicializamos asumiendo que el primer día es el mayor y el menor
    *maxima = estacion.temperaturas[0];
    *minima = estacion.temperaturas[0];

    // 3. Recorremos el resto de los días
    for (int i = 1; i < kDiasSemana; ++i)
    {
        if (estacion.temperaturas[i] > *maxima)
        {
            *maxima = estacion.temperaturas[i]; // Alteramos variable del main()
        }
        if (estacion.temperaturas[i] < *minima)
        {
            *minima = estacion.temperaturas[i]; // Alteramos variable del main()
        }
    }
}

int main()
{
    Estacion estacion;

    std::cout << "Ingrese el nombre de la ciudad: ";
    // Excelente uso de getline para nombres con espacios
    std::getline(std::cin, estacion.nombre_ciudad);

    std::cout << "Ingrese las temperaturas de los " << kDiasSemana << " dias de la semana:\n";
    for (int i = 0; i < kDiasSemana; ++i)
    {
        std::cout << "Dia " << (i + 1) << ": ";
        std::cin >> estacion.temperaturas[i];
    }

    // Declaramos las variables receptoras
    double maxima = 0.0;
    double minima = 0.0;

    // Invocamos pasando los mapas de memoria (&)
    AnalizarClima(estacion, &maxima, &minima);

    std::cout << "\n--- REPORTE CLIMATICO ---\n";
    std::cout << "La temperatura maxima en " << estacion.nombre_ciudad << " es: " << maxima << "\n";
    std::cout << "La temperatura minima en " << estacion.nombre_ciudad << " es: " << minima << "\n";

    return 0;
}