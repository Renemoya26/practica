/*Definición:
Problema:
Un sistema bancario almacena el saldo de una cuenta. Crea una función depositar()
que reciba mediante un puntero el saldo y una cantidad a depositar.
La función debe modificar directamente el saldo original.*/
#include <iostream>

// Prototipo de la función usando puntero
void Depositar(float *saldo, float cantidad);

int main()
{
    // 1. Variable original en la memoria
    float saldo_cuenta = 1500.0f;

    std::cout << "Saldo inicial: $" << saldo_cuenta << "\n";

    // 2. Llamada a la función
    // Usamos el operador '&' para enviar la DIRECCIÓN de memoria del saldo
    Depositar(&saldo_cuenta, 350.50f);

    std::cout << "Saldo despues del deposito: $" << saldo_cuenta << "\n";

    return 0;
}

// -------------------------------------------------------------------------
// PASO POR PUNTERO (*): Modifica el valor original desde la dirección
// -------------------------------------------------------------------------
void Depositar(float *saldo, float cantidad)
{
    // Validación de seguridad: evitar punteros nulos
    if (saldo == nullptr)
    {
        std::cout << "Error: La direccion de la cuenta no es valida.\n";
        return;
    }

    if (cantidad <= 0.0f)
    {
        std::cout << "Error: La cantidad a depositar debe ser mayor a 0.\n";
        return;
    }

    // 3. Desreferenciación: usamos '*' para ir al casillero y sumar el dinero
    *saldo += cantidad;

    std::cout << "Deposito de $" << cantidad << " procesado correctamente.\n";
}
