/*Misión 2: "El Cajero Automático"
Estructura: Define un struct Cuenta con id_cuenta (int) y saldo_disponible (double).
Función: Escribe bool ProcesarRetiro(Cuenta* cuenta_usuario, double monto, double* saldo_cajero).
Lógica interna:
Aplica el escudo protector de punteros nulos.
Verifica que haya fondos suficientes en la cuenta. Si no, retorna false.
Si hay fondos, resta el monto al saldo de la cuenta (usando ->).
Resta también el monto al saldo físico del cajero (usando *).
Retorna true.
Prueba en main(): Crea una cuenta con $500.00, inicializa el saldo del cajero en $10,000.00 e intenta retirar $150.00. Imprime los resultados.*/
#include <iostream>

// Struct en CamelCase
struct Cuenta {
    int id_cuenta;
    double saldo_disponible;
};

// Prototipo de la función
bool ProcesarRetiro(Cuenta* cuenta_usuario, double monto, double* saldo_cajero);

int main () {
    Cuenta usuario = {1, 500.00}; 
    double saldo_cajero = 10000.00; 
    double monto_retiro = 150.00; 

    std::cout << "--- CAJERO AUTOMATICO ---\n";
    std::cout << "Saldo inicial de la cuenta: $" << usuario.saldo_disponible << "\n";
    std::cout << "Saldo inicial del cajero: $" << saldo_cajero << "\n\n";

    // Pasamos las direcciones de memoria
    if (ProcesarRetiro(&usuario, monto_retiro, &saldo_cajero)) {
        std::cout << "[Exito] Retiro exitoso de $" << monto_retiro << ".\n\n";
    } else {
        std::cout << "[Error] Retiro fallido. Verifique los fondos.\n\n";
    }

    std::cout << "Saldo final de la cuenta: $" << usuario.saldo_disponible << "\n";
    std::cout << "Saldo final del cajero: $" << saldo_cajero << "\n";

    return 0;
}

// Implementación de la función
bool ProcesarRetiro(Cuenta* cuenta_usuario, double monto, double* saldo_cajero) {
    if (cuenta_usuario == nullptr || saldo_cajero == nullptr) {
        std::cerr << "[Error] Puntero nulo detectado.\n";
        return false;
    }

    if (cuenta_usuario->saldo_disponible < monto) {
        std::cerr << "[Error] Fondos insuficientes en la cuenta.\n";
        return false;
    }

    if (*saldo_cajero < monto) {
        std::cerr << "[Error] Fondos insuficientes en el cajero.\n";
        return false;
    }

    // Procesamiento seguro en memoria
    cuenta_usuario->saldo_disponible -= monto; 
    *saldo_cajero -= monto;                    

    return true;
}