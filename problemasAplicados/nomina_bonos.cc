/*5.El Problema:
Define un struct Empleado que contenga: id_empleado (int), ventas_mensuales (float), salario_base (float), y recibe_bono (bool).
En tu main(), define una constante para el tamaño (3) y crea un arreglo estático de empleados con datos de prueba. Todos inician con recibe_bono en false.
Escribe una función llamada AsignarBonos. Debe ser de tipo void y recibir 4 parámetros:
Un puntero al arreglo de empleados (Empleado* equipo).
El tamaño del arreglo (int tamano).
La meta mínima de ventas para ganar el bono (float meta_ventas).
Una referencia a un contador (int& empleados_premiados) para extraer cuántas personas ganaron el bono.
La Lógica de la Función:
Aplica tu escudo de punteros nulos.
Inicializa tu variable receptora: empleados_premiados = 0;.
Recorre el arreglo usando aritmética de punteros (equipo + i).
Si las ventas_mensuales de ese empleado son mayores o iguales a la meta_ventas:
Cámbiale su estado recibe_bono a true (usando ->).
Auméntale el salario_base en un 10% (multiplícalo por 1.10).
Aumenta en 1 tu contador empleados_premiados.
En el main(), crea una variable para atrapar el contador, invoca la función (pasando la meta de ventas que tú elijas) e imprime el resumen: cuántos ganaron el bono y cómo quedó el salario final de cada empleado*/
#include <iostream>

// Struct en CamelCase y singular
struct Empleado {
    int id_empleado;
    float ventas_mensuales;
    float salario_base;
    bool recibe_bono;
};

// Prototipo con el asterisco pegado al tipo
void AsignarBonos(Empleado* equipo, int tamano, float meta_ventas, int& empleados_premiados);

int main() {
    const int kTamano = 3;
    Empleado equipo[kTamano] = {
        {1, 1200.50f, 3000.00f, false},
        {2, 800.75f, 2800.00f, false},
        {3, 1500.00f, 3200.00f, false}
    };

    float meta_ventas = 1000.00f; 
    int empleados_premiados = 0;  

    std::cout << "--- GESTION DE BONOS ---\n";
    std::cout << "Meta de ventas para ganar el bono: $" << meta_ventas << "\n";

    // Pasamos el arreglo y la variable por referencia (&) implícita en la función
    AsignarBonos(equipo, kTamano, meta_ventas, empleados_premiados);

    std::cout << "\n--- RESUMEN DE BONOS ---\n";
    std::cout << "Cantidad de empleados que ganaron el bono: " << empleados_premiados << "\n";
    for (int i = 0; i < kTamano; ++i) {
        std::cout << "Empleado ID: " << (equipo + i)->id_empleado
                  << " | Salario Final: $" << (equipo + i)->salario_base
                  << " | Recibe Bono: " << ((equipo + i)->recibe_bono ? "Si" : "No") << "\n";
    }

    return 0;
}

// Implementación de la función
void AsignarBonos(Empleado* equipo, int tamano, float meta_ventas, int& empleados_premiados) {
    if (equipo == nullptr || tamano <= 0) {
        std::cerr << "[Error] Puntero nulo o tamano invalido detectado.\n";
        return;
    }

    empleados_premiados = 0; // Inicializamos el contador directo, sin *

    for (int i = 0; i < tamano; ++i) {
        if ((equipo + i)->ventas_mensuales >= meta_ventas) {
            (equipo + i)->recibe_bono = true;    
            (equipo + i)->salario_base *= 1.10f; 
            empleados_premiados++;               // Incremento directo, sin * ni ()
        }
    }
}