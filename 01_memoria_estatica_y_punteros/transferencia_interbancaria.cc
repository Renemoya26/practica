/*El Reto:
Estructura: Define un struct Cuenta con id_cuenta (int) y saldo (float).
Configuración Global: Crea una constante const int kTotalCuentas = 3; fuera del main().
Datos Iniciales: En tu main(), inicializa un arreglo estático con tres cuentas (ej. IDs 101, 102, 103 con saldos de 500.0f, 300.0f, 150.0f).
Función: Escribe el prototipo y la implementación de:
bool TransferirFondos(Cuenta* banco, int tamano, int id_origen, int id_destino, float monto)
Lógica de la Función:
Aplica tu escudo de punteros nulos y verifica que el monto a transferir sea mayor a 0.0f.
Usa un ciclo y aritmética de punteros ((banco + i)->) para buscar la cuenta origen y la cuenta destino. Pista: Puedes usar dos punteros temporales (ej. Cuenta* origen = nullptr;) para guardar las direcciones cuando las encuentres.
Si encuentras ambas cuentas y la cuenta origen tiene saldo suficiente (>= monto), resta el monto al origen, súmalo al destino y retorna true. Si falla alguna validación, retorna false.
Prueba: En el main(), simula una transferencia de $100.0f de la cuenta 101 a la 102. Imprime si fue exitosa y muestra el saldo final de todas las cuentas.*/
#include <iostream>
struct Cuenta {
    int id_cuenta;
    float saldo;
};

const int kTotalCuentas = 3;
bool TransferirFondos(Cuenta* banco, int tamano, int id_origen, int id_destino, float monto);

int main() {
    Cuenta banco[kTotalCuentas] = {
        {101, 500.0f},
        {102, 300.0f},
        {103, 150.0f}
    };

    int id_origen = 101;
    int id_destino = 102;
    float monto = 100.0f;

    bool transferencia_exitosa = TransferirFondos(banco, kTotalCuentas, id_origen, id_destino, monto);

    if (transferencia_exitosa) {
        std::cout << "Transferencia exitosa!" << std::endl;
    } else {
        std::cout << "Transferencia fallida!" << std::endl;
    }

    // Mostrar el saldo final de todas las cuentas
    for (int i = 0; i < kTotalCuentas; ++i) {
        std::cout << "Cuenta ID: " << (banco + i)->id_cuenta 
                  << ", Saldo: " << (banco + i)->saldo << std::endl;
    }

    return 0;
}

bool TransferirFondos(Cuenta* banco, int tamano, int id_origen, int id_destino, float monto) {
    if (banco == nullptr || tamano <= 0 || monto <= 0.0f) {
        return false; // Escudo de punteros nulos y validación de monto
    }

    Cuenta* origen = nullptr;
    Cuenta* destino = nullptr;

    for (int i = 0; i < tamano; ++i) {
        if ((banco + i)->id_cuenta == id_origen) {
            origen = banco + i;
        }
        if ((banco + i)->id_cuenta == id_destino) {
            destino = banco + i;
        }
    }

    if (origen != nullptr && destino != nullptr && origen->saldo >= monto) {
        origen->saldo -= monto; // Restar del saldo de la cuenta origen
        destino->saldo += monto; // Sumar al saldo de la cuenta destino
        return true; // Transferencia exitosa
    }

    return false; // Falló alguna validación
}