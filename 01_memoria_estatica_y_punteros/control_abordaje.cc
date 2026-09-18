/*4.El Reto:
Estructura: Define un struct Pasajero con id_pasajero (int), peso_equipaje (float), y es_vip (bool).
Configuración Global: Crea la constante const int kTotalPasajeros = 5; de forma segura fuera del main().
Datos Iniciales: En tu main(), inicializa un arreglo estático de 5 pasajeros con datos quemados (mezcla algunos VIP y distintos pesos de equipaje, ej. 15.5f, 22.0f, 8.0f).
Función: Escribe el prototipo y la implementación de
bool ProcesarAbordaje(Pasajero* vuelo, int tamano, int& total_vip, int* id_mas_pesado)
Lógica Estricta:
Aplica tu escudo para validar que vuelo e id_mas_pesado no sean nulos, y que el tamaño sea válido.
Inicializa la referencia total_vip en 0 y crea una variable temporal para rastrear el peso máximo.
Recorre el arreglo usando estrictamente aritmética de punteros ((vuelo + i)->).
Si el pasajero es VIP (es_vip == true), incrementa la referencia total_vip.
Si el peso_equipaje del pasajero actual es mayor al peso máximo registrado, actualiza tu máximo y guarda el ID del pasajero en la dirección de memoria apuntada por id_mas_pesado.
Retorna true al terminar con éxito.
Prueba: En el main(), declara tus variables receptoras, llama a la función y muestra en pantalla cuántos pasajeros VIP abordaron y qué ID tiene el pasajero con el equipaje más pesado.*/
#include <iostream>
struct Pasajero {
    int id_pasajero;
    float peso_equipaje;
    bool es_vip;
};

bool ProcesarAbordaje(Pasajero* vuelo, int tamano, int& total_vip, int* id_mas_pesado) {
    // Validación de punteros nulos y tamaño válido
    if (vuelo == nullptr || id_mas_pesado == nullptr || tamano <= 0) {
        return false;
    }

    total_vip = 0; // Inicializa el contador de VIPs
    float peso_maximo = -1.0f; // Variable temporal para rastrear el peso máximo

    for (int i = 0; i < tamano; ++i) {
        Pasajero* pasajero_actual = vuelo + i; // Acceso mediante aritmética de punteros

        // Contar pasajeros VIP
        if (pasajero_actual->es_vip) {
            total_vip++;
        }

        // Verificar si el peso del equipaje es mayor al máximo registrado
        if (pasajero_actual->peso_equipaje > peso_maximo) {
            peso_maximo = pasajero_actual->peso_equipaje;
            *id_mas_pesado = pasajero_actual->id_pasajero; // Guardar ID del pasajero con equipaje más pesado
        }
    }

    return true; // Retorna true al finalizar con éxito
}

int main() {
    const int kTotalPasajeros = 5; // Configuración global segura
    Pasajero vuelo[kTotalPasajeros] = {
        {1, 15.5f, true},
        {2, 22.0f, false},
        {3, 8.0f, true},
        {4, 30.0f, false},
        {5, 12.5f, true}
    };

    int total_vip = 0; // Variable para contar pasajeros VIP
    int id_mas_pesado = -1; // Variable para almacenar el ID del pasajero con equipaje más pesado

    std::cout << "--- PROCESO DE ABORDAJE ---\n";

    // Llamada a la función ProcesarAbordaje
    bool exito = ProcesarAbordaje(vuelo, kTotalPasajeros, total_vip, &id_mas_pesado);

    if (exito) {
        std::cout << "Total de pasajeros VIP abordados: " << total_vip << "\n";
        std::cout << "ID del pasajero con el equipaje más pesado: " << id_mas_pesado << "\n";
    } else {
        std::cout << "[ERROR] Fallo en el procesamiento del abordaje.\n";
    }

    return 0;
} 