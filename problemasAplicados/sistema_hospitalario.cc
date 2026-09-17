/*7.El Problema:
Estructura: Define un struct Paciente que contenga id_paciente (int), nivel_oxigeno (double), y requiere_uci (bool).
Datos iniciales: En tu main(), crea una constante para el tamaño y un arreglo estático de 4 pacientes. Todos inician con requiere_uci en false y distintos niveles de oxígeno (ej. 98.5, 88.0, 95.2, 85.1).
Función: Escribe una función bool ProcesarTriage(Paciente* sala_espera, int tamano, double limite_critico, int* total_criticos, int& id_mas_grave).
Lógica de Negocio:
Aplica tu escudo de punteros nulos para sala_espera y total_criticos.
Inicializa tu variable receptora *total_criticos = 0; y crea una variable temporal para rastrear el nivel de oxígeno más bajo.
Recorre el arreglo con aritmética de punteros (sala_espera + i).
Regla 1 (Filtro Crítico): Si el nivel_oxigeno del paciente es menor al limite_critico (ej. 90.0), cambia su requiere_uci a true (usando ->) y aumenta en 1 tu contador total_criticos.
Regla 2 (El más grave): Compara el oxígeno del paciente actual con tu mínimo registrado. Si es menor, actualiza tu mínimo y guarda el id_paciente en tu referencia id_mas_grave.
Retorna true al terminar de procesar.
Prueba: En el main(), invoca la función pasando un límite crítico de 90.0. Imprime cuántos pacientes necesitan UCI, cuál es el ID del paciente más grave, y el estado final de todos los pacientes.*/
#include <iostream>
struct Paciente {
    int id_paciente;
    double nivel_oxigeno;
    bool requiere_uci;
};

bool ProcesarTriage(Paciente* sala_espera, int tamano, double limite_critico, int* total_criticos, int& id_mas_grave);

int main() {
    const int kTamano = 4;
    Paciente sala_espera[kTamano] = {
        {1, 98.5, false},
        {2, 88.0, false},
        {3, 95.2, false},
        {4, 85.1, false}
    };

    double limite_critico = 90.0;
    int total_criticos = 0;
    int id_mas_grave = -1;

    std::cout << "--- SISTEMA DE TRIAGE HOSPITALARIO ---\n";
    std::cout << "Procesando pacientes con limite critico de oxigeno: " << limite_critico << "\n\n";

    // Llamada a la función ProcesarTriage
    bool exito = ProcesarTriage(sala_espera, kTamano, limite_critico, &total_criticos, id_mas_grave);

    if (exito) {
        std::cout << "[EXITO] Procesamiento completado.\n";
        std::cout << "Total de pacientes que requieren UCI: " << total_criticos << "\n";
        if (id_mas_grave != -1) {
            std::cout << "ID del paciente mas grave: " << id_mas_grave << "\n";
        } else {
            std::cout << "No hay pacientes criticos.\n";
        }
    } else {
        std::cerr << "[ERROR] Fallo en el procesamiento de triage.\n";
    }

    std::cout << "\n--- ESTADO FINAL DE LOS PACIENTES ---\n";
    for (int i = 0; i < kTamano; ++i) {
        std::cout << "Paciente ID: " << (sala_espera + i)->id_paciente
                  << ", Nivel de Oxigeno: " << (sala_espera + i)->nivel_oxigeno
                  << ", Requiere UCI: " << ((sala_espera + i)->requiere_uci ? "SI" : "NO") << "\n";
    }

    return 0;
}

bool ProcesarTriage(Paciente* sala_espera, int tamano, double limite_critico, int* total_criticos, int& id_mas_grave) {
    // Escudo de punteros nulos
    if (sala_espera == nullptr || total_criticos == nullptr) {
        std::cerr << "[Error] Puntero nulo detectado.\n";
        return false;
    }

    *total_criticos = 0;
    double nivel_minimo = 100.0; // Inicializamos con un valor alto para encontrar el mínimo

    for (int i = 0; i < tamano; ++i) {
        Paciente* paciente_actual = sala_espera + i;

        // Regla 1: Filtro Crítico
        if (paciente_actual->nivel_oxigeno < limite_critico) {
            paciente_actual->requiere_uci = true;
            (*total_criticos)++;
        }

        // Regla 2: El más grave
        if (paciente_actual->nivel_oxigeno < nivel_minimo) {
            nivel_minimo = paciente_actual->nivel_oxigeno;
            id_mas_grave = paciente_actual->id_paciente;
        }
    }

    return true;
}