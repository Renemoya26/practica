/*Ejercicio Propuesto 5: "Monitor de Sensores Críticos"
Conceptos a evaluar: Arreglos de structs, recorridos con punteros, alteración de estados lógicos y extracción matemática combinando referencias (&) y punteros (*).

El Problema:
Define un struct Sensor que contenga un id_sensor (int), un arreglo estático lecturas[4] de tipo float (representando 4 mediciones de temperatura), y una variable estado_critico (bool).
En tu main(), crea un arreglo estático de 3 sensores inicializados con datos de prueba. Por defecto, el estado_critico de todos debe ser false.
Escribe una función llamada AnalizarSensor. Esta función debe devolver un bool (para saber si el sensor existe o no) y recibir:
Un puntero al arreglo de sensores.
El tamaño del arreglo.
El id_sensor a buscar (int).
Una referencia float &promedio (Ojo: aquí usaremos referencia en lugar de puntero para extraer el cálculo matemático).
La Lógica de la Función:
Recorre el arreglo buscando el id_sensor mediante aritmética de punteros.
Si lo encuentras, calcula el promedio de sus 4 lecturas internas.
Guarda ese resultado directamente en la variable referenciada promedio.
Regla de negocio: Si el promedio calculado es mayor a 100.0, debes cambiar el estado_critico de ese sensor original a true (usando la flecha ->).
Retorna true (sensor encontrado y procesado). Si el ciclo termina sin encontrarlo, retorna false.
En el main(), prueba la función e imprime si el sensor entró en estado crítico o si se mantuvo estable.*/
#include <iostream>

const int kNumSensores = 3;
const int kNumLecturas = 4;

struct Sensor {
    int id_sensor;
    float lecturas[kNumLecturas]; // Arreglo estático real
    bool estado_critico;
};

// Recibe puntero de entrada (*) y referencia de salida (&)
bool AnalizarSensor(Sensor* sensores, int tamano, int id_sensor, float& promedio) {
    if (sensores == nullptr || tamano <= 0) {
        return false;
    }

    for (int i = 0; i < tamano; ++i) {
        if ((sensores + i)->id_sensor == id_sensor) {
            
            float suma = 0.0f;
            // Recorremos el arreglo interno del sensor actual
            for (int j = 0; j < kNumLecturas; ++j) {
                suma += (sensores + i)->lecturas[j];
            }
            
            promedio = suma / kNumLecturas; // Alteramos el original del main() vía &

            // Modificamos el estado crítico vía puntero ->
            if (promedio > 100.0f) {
                (sensores + i)->estado_critico = true;
            } else {
                (sensores + i)->estado_critico = false;
            }

            return true; 
        }
    }
    return false; 
}

int main() {
    // Inicialización correcta de arreglos anidados
    Sensor sensores[kNumSensores] = {
        {1, {95.0f, 102.0f, 98.0f, 101.0f}, false},
        {2, {85.0f, 90.0f, 88.0f, 92.0f}, false},
        {3, {110.0f, 115.0f, 120.0f, 125.0f}, false}
    };

    float promedio_calculado = 0.0f;
    int id_buscar = 3; 

    std::cout << "Analizando sensor con ID: " << id_buscar << "\n";
    std::cout << "Lecturas: ";
    for (int j = 0; j < kNumLecturas; ++j)
    {
        std::cout << sensores[2].lecturas[j] << " "; // Acceso directo al arreglo interno
    }
    std::cout << "\n";
    std::cout << "Estado critico inicial: " << (sensores[2].estado_critico ? "Si" : "No") << "\n";


    // Pasamos el mapa del arreglo y la variable por referencia directa
    if (AnalizarSensor(sensores, kNumSensores, id_buscar, promedio_calculado)) {
        std::cout << "Sensor ID: " << id_buscar << " encontrado.\n";
        std::cout << "Promedio de lecturas: " << promedio_calculado << "\n";
        std::cout << "Estado critico final: " << (sensores[2].estado_critico ? "Si" : "No") << "\n";
        // El sensor 3 está en el índice 2
        if (sensores[2].estado_critico) {
            std::cout << "Estado critico: Si (PELIGRO)\n";
        } else {
            std::cout << "Estado critico: No (ESTABLE)\n";
        }
    } else {
        std::cout << "Sensor ID: " << id_buscar << " no encontrado.\n";
    }

    return 0;
}







