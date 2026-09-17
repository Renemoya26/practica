/*El Problema:
Define un struct Paciente que contenga un numero_expediente (int), un arreglo estático signos_vitales[3] de tipo float (Índice 0: Temperatura, Índice 1: Ritmo Cardíaco, Índice 2: Nivel de Oxígeno), y una variable requiere_uci (bool).
En tu main(), crea un arreglo estático de 3 pacientes inicializados con datos de prueba (recuerda las constantes). Todos inician con requiere_uci en false.
Escribe una función llamada EvaluarTriaje. Debe devolver un bool (si logró procesar el arreglo) y recibir 5 parámetros:
Un puntero al arreglo de pacientes.
El tamaño del arreglo.
Un puntero int* total_uci (para contar cuántos pacientes están críticos).
Una referencia int& expediente_mas_grave (para guardar el expediente del paciente con el peor nivel de oxígeno).
Un puntero float* oxigeno_promedio (para guardar el promedio de oxígeno de todos los pacientes del arreglo).
La Lógica de la Función:
Escudo protector de punteros (Regla de oro).
Recorre el arreglo con aritmética de punteros. Ve sumando el nivel de oxígeno de cada paciente para calcular el promedio al final.
Regla de negocio 1 (Estado Crítico): Si un paciente tiene el oxígeno (índice 2) menor a 90.0f O la temperatura (índice 0) mayor a 39.0f, cambia su requiere_uci a true y aumenta el contador de total_uci.
Regla de negocio 2 (El más grave): Debes rastrear cuál paciente tiene el nivel de oxígeno más bajo de todo el arreglo y guardar su numero_expediente en la referencia expediente_mas_grave.
Calcula el promedio de oxígeno y guárdalo en su puntero. Retorna true.
En el main(), prueba la función e imprime el total de pacientes en UCI, el expediente del más grave, y el promedio general de oxígeno.*/
#include <iostream>

// Constantes para los arreglos
const int kNumSignos = 3;
const int kNumPacientes = 3;

// Struct en CamelCase[cite: 5]
struct Paciente {
    int numero_expediente;
    float signos_vitales[kNumSignos]; // 0: Temp, 1: Ritmo, 2: Oxigeno
    bool requiere_uci;
};

// Función corregida a tipo 'bool'
bool EvaluarTriaje(Paciente* pacientes, int tamano, int* total_uci, int& expediente_mas_grave, float* oxigeno_promedio) {
    // Escudo protector de punteros (Nivel 5/6)
    if (pacientes == nullptr || total_uci == nullptr || oxigeno_promedio == nullptr || tamano <= 0) {
        return false;
    }

    // Inicialización de las "cajas receptoras"
    *total_uci = 0;
    float suma_oxigeno = 0.0f;
    float oxigeno_minimo = 100.0f; 
    expediente_mas_grave = -1;     

    for (int i = 0; i < tamano; ++i) {
        suma_oxigeno += (pacientes + i)->signos_vitales[2];

        // Regla 1: Estado Crítico
        if ((pacientes + i)->signos_vitales[2] < 90.0f || (pacientes + i)->signos_vitales[0] > 39.0f) {
            (pacientes + i)->requiere_uci = true;
            (*total_uci)++; // Paréntesis correctos para proteger la dirección
        }

        // Regla 2: El más grave
        if ((pacientes + i)->signos_vitales[2] < oxigeno_minimo) {
            oxigeno_minimo = (pacientes + i)->signos_vitales[2];
            expediente_mas_grave = (pacientes + i)->numero_expediente;
        }
    }

    *oxigeno_promedio = suma_oxigeno / tamano;
    return true;
}

int main() {
    Paciente pacientes[kNumPacientes] = {
        {1001, {38.5f, 80.0f, 95.0f}, false},
        {1002, {39.5f, 90.0f, 85.0f}, false},
        {1003, {37.0f, 70.0f, 92.0f}, false}
    };

    std::cout << "--- SISTEMA DE TRIAJE HOSPITALARIO ---\n";
    std::cout << "Evaluando a " << kNumPacientes << " pacientes...\n";

    int total_uci = 0;
    int expediente_mas_grave = -1;
    float oxigeno_promedio = 0.0f;
    
    // Llamada directa, enviando los mapas de memoria con &
    if (EvaluarTriaje(pacientes, kNumPacientes, &total_uci, expediente_mas_grave, &oxigeno_promedio)) {
        std::cout << "\n--- REPORTE FINAL ---\n";
        std::cout << "Total de pacientes en UCI: " << total_uci << "\n";
        std::cout << "Expediente del paciente mas grave (Menor Oxigeno): " << expediente_mas_grave << "\n";
        std::cout << "Promedio general de oxigeno: " << oxigeno_promedio << "%\n";
    } else {
        std::cout << "Error critico al evaluar el triaje.\n";
    }

    std::cout << "\n--- ESTADO ACTUALIZADO DE PACIENTES ---\n";
    for (int i = 0; i < kNumPacientes; ++i) {
        std::cout << "Paciente " << pacientes[i].numero_expediente 
                  << " -> Requiere UCI: " << (pacientes[i].requiere_uci ? "SI (TRASLADAR)" : "NO (ESTABLE)") << "\n";
    }

    return 0;
}