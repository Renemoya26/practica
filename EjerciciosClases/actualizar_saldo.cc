/*4. Actualizar saldo: Se define un struct Cuenta con saldo; una función recibe
la cuenta mediante referencia y un monto, realizando un retiro únicamente si
existe saldo suficiente. */
#include <iostream>

// 1. Struct en CamelCase
struct Cuenta {
    double saldo;
};

// 2. Función en CamelCase. Recibe por referencia (&)
void ActualizarSaldo(Cuenta &c, double monto) {
    // Validamos fondos suficientes
    if (monto <= c.saldo) {
        c.saldo -= monto; // Restamos directamente de la variable original
        std::cout << "-> Retiro exitoso. Saldo actual: $" << c.saldo << "\n";
    } else {
        std::cout << "-> Error: Saldo insuficiente. Saldo actual: $" << c.saldo << "\n";
    }
}

int main() {
    // Creamos la variable (usamos el nombre del struct en mayúscula)
    Cuenta mi_cuenta;
    
    std::cout << "Ingrese el saldo inicial de la cuenta: $";
    std::cin >> mi_cuenta.saldo;
    
    double monto_retiro;
    std::cout << "Ingrese el monto a retirar: $";
    std::cin >> monto_retiro;
    
    std::cout << "\n--- PROCESANDO TRANSACCION ---\n";
    
    // Al pasar por referencia, solo enviamos el nombre de la variable
    ActualizarSaldo(mi_cuenta, monto_retiro);
    
    return 0;
}                                   