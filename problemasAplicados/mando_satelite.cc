/*10.El Problema:
Estructura: Define un struct Satelite que contenga: id_satelite (int), un arreglo coordenadas[2] (float para X e Y), bateria (float de 0.0 a 100.0) y estado_operativo (bool).
Datos iniciales: En tu main(), crea un arreglo estático de 3 satélites. (Ej. uno con 95.5 de batería y true, otro con 12.0 y true, otro con 45.0 y false).
Función: Escribe una función bool OptimizarConstelacion(Satelite* red, int tamano, float limite_bateria, int* satelites_apagados, int& id_mejor_satelite).
La Lógica del Jefe Final:
Doble Escudo Protector: Valida que ninguno de los punteros sea nulo.
Inicializa tu variable receptora de apagados en 0 (puedes usar el truco de *puntero += 1 más adelante) y crea tu temporal para rastrear la batería más alta.
Recorre el arreglo usando estrictamente aritmética de punteros (Satelite* sat_actual = red + i;).
Regla 1 (Apagado de Emergencia): Si la bateria del satélite es menor al limite_bateria (ej. 20.0f) y su estado_operativo está en true, cámbialo a false y suma 1 a tu contador satelites_apagados.
Regla 2 (El Superviviente): Compara la batería de este satélite con tu máximo registrado. Si es mayor, actualiza el máximo y guarda su ID en id_mejor_satelite.
Retorna true al terminar.
Prueba: En el main(), define el límite en 20.0f, invoca la función e imprime cuántos satélites entraron en modo de emergencia, cuál es el ID del mejor satélite, y el estado operativo final de todos.*/
#include <iostream>
struct Satelite {
    int id_satelite;
    float coordenadas[2]; // X e Y
    float bateria; // 0.0 a 100.0
    bool estado_operativo;
};

bool OptimizarConstelacion(Satelite* red, int tamano, float limite_bateria, int* satelites_apagados, int& id_mejor_satelite);

int main(){
    const int kTamano = 3;
    Satelite red[kTamano] = {
        {1, {10.0f, 20.0f}, 95.5f, true},
        {2, {15.0f, 25.0f}, 12.0f, true},
        {3, {20.0f, 30.0f}, 45.0f, false}
    };

    float limite_bateria = 20.0f;
    int satelites_apagados = 0;
    int id_mejor_satelite = -1;

    std::cout << "--- SISTEMA DE OPTIMIZACION DE CONSTELACION ---\n";
    std::cout << "Analizando satelites con limite de bateria: " << limite_bateria << "\n\n";

    // Llamada a la función OptimizarConstelacion
    bool exito = OptimizarConstelacion(red, kTamano, limite_bateria, &satelites_apagados, id_mejor_satelite);

    if (exito) {
        std::cout << "[EXITO] Optimizacion completada.\n";
        std::cout << "Total de satelites apagados: " << satelites_apagados << "\n";
        if (id_mejor_satelite != -1) {
            std::cout << "ID del mejor satelite: " << id_mejor_satelite << "\n";
        } else {
            std::cout << "No hay satelites operativos.\n";
        }
    } else {
        std::cerr << "[ERROR] Fallo en la optimizacion de la constelacion.\n";
    }

    std::cout << "\n--- ESTADO FINAL DE LOS SATELITES ---\n";
    for (int i = 0; i < kTamano; ++i) {
        std::cout << "Satelite ID: " << (red + i)->id_satelite
                  << ", Bateria: " << (red + i)->bateria
                  << ", Estado Operativo: " << ((red + i)->estado_operativo ? "SI" : "NO") << "\n";
    }

    return 0;
}

bool OptimizarConstelacion(Satelite* red, int tamano, float limite_bateria, int* satelites_apagados, int& id_mejor_satelite) {
    // Escudo de punteros nulos
    if (red == nullptr || satelites_apagados == nullptr) {
        std::cerr << "[Error] Puntero nulo detectado.\n";
        return false;
    }

    *satelites_apagados = 0;
    float bateria_maxima = -1.0f; // Inicializamos con un valor menor al mínimo posible

    for (int i = 0; i < tamano; ++i) {
        Satelite* sat_actual = red + i;

        // Regla 1: Apagado de Emergencia
        if (sat_actual->bateria < limite_bateria && sat_actual->estado_operativo) {
            sat_actual->estado_operativo = false;
            (*satelites_apagados)++;
        }

        // Regla 2: El Superviviente
        if (sat_actual->bateria > bateria_maxima) {
            bateria_maxima = sat_actual->bateria;
            id_mejor_satelite = sat_actual->id_satelite;
        }
    }

    return true;
}