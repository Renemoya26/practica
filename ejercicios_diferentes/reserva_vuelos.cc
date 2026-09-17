/*Ejercicio Propuesto 4: "Reserva de Vuelos"
Este ejercicio va a poner a prueba tu capacidad para modificar datos originales a través de punteros, hacer cálculos matemáticos seguros y usar retornos de estado al mismo tiempo.
Conceptos a evaluar: Arreglos de structs, validación lógica múltiple, y extracción de cálculos financieros mediante punteros.
El Problema:

Define un struct Vuelo que contenga un numero_vuelo (int), asientos_disponibles (int) y precio_boleto (double).
En tu main(), crea un arreglo estático de 3 vuelos inicializados con datos de prueba (recuerda usar la constante para el tamaño).
Escribe una función llamada ProcesarReserva. Esta función debe devolver un bool y recibir los siguientes 5 parámetros:
Un puntero al arreglo de vuelos.
El tamaño del arreglo.
El número de vuelo que el cliente quiere buscar (int).
La cantidad de asientos que quiere comprar (int).
Un puntero double* total_a_pagar.
La Lógica de la Función:
Recorre el arreglo buscando el vuelo.
Si lo encuentras, verifica que los asientos_disponibles sean mayores o iguales a los solicitados.
Si hay espacio, resta los asientos comprados del inventario original, calcula el total de la venta (precio_boleto * cantidad), guarda ese dinero en el mapa del puntero total_a_pagar, y retorna true.
Si el vuelo no existe o no hay suficientes asientos, retorna false.
En el main(), invoca la función pasando las direcciones correctas (&) y muestra un mensaje con el total a pagar si fue exitoso, o un mensaje de error si falló.*/
#include <iostream>

// Struct en CamelCase
struct Vuelo
{
    int numero_vuelo;
    int asientos_disponibles;
    double precio_boleto;
};

// Función en CamelCase, asteriscos pegados al tipo de dato
bool ProcesarReserva(Vuelo *vuelos, int tamano, int numero_vuelo, int cantidad_asientos, double *total_a_pagar)
{
    // Escudo de seguridad total
    if (vuelos == nullptr || tamano <= 0 || total_a_pagar == nullptr)
    {
        return false;
    }

    // Recorrido de la memoria usando aritmética de punteros
    for (int i = 0; i < tamano; ++i)
    {
        if ((vuelos + i)->numero_vuelo == numero_vuelo)
        {

            // Validación lógica de negocio (asientos suficientes)
            if ((vuelos + i)->asientos_disponibles >= cantidad_asientos)
            {

                // 1. Restamos del inventario original
                (vuelos + i)->asientos_disponibles -= cantidad_asientos;

                // 2. Guardamos el total en la dirección de memoria del main()
                *total_a_pagar = (vuelos + i)->precio_boleto * cantidad_asientos;

                return true;
            }
            else
            {
                return false; // Vuelo encontrado, pero sin asientos
            }
        }
    }

    return false; // Vuelo no encontrado
}

int main()
{
    // Uso correcto de constante para evitar "números mágicos"
    const int kNumVuelos = 3;
    Vuelo vuelos[kNumVuelos] = {
        {101, 50, 150.0},
        {202, 30, 200.0},
        {303, 20, 250.0}};

    std::cout << "Bienvenido al sistema de reservas de vuelos.\n";
    std::cout << "Vuelos disponibles:\n";
    for (int i = 0; i < kNumVuelos; ++i)
    {
        std::cout << "Vuelo " << vuelos[i].numero_vuelo
                  << ": Asientos disponibles: " << vuelos[i].asientos_disponibles
                  << ", Precio por boleto: $" << vuelos[i].precio_boleto << "\n";
    }

    int numero_vuelo;
    int cantidad_asientos;

    // Esta variable servirá como caja receptora
    double total_a_pagar = 0.0;

    std::cout << "--- SISTEMA DE RESERVAS ---\n";
    std::cout << "Ingrese el numero de vuelo: ";
    std::cin >> numero_vuelo;
    std::cout << "Ingrese la cantidad de asientos a reservar: ";
    std::cin >> cantidad_asientos;

    // Pasamos el arreglo y la dirección de memoria (&) de la caja receptora
    if (ProcesarReserva(vuelos, kNumVuelos, numero_vuelo, cantidad_asientos, &total_a_pagar))
    {
        std::cout << "\n[Exito] Reserva completada! Total a pagar: $" << total_a_pagar << "\n";
    }
    else
    {
        std::cout << "\n[Error] Falla en la reserva. Verifique el numero de vuelo o la disponibilidad.\n";
    }

    return 0;
}