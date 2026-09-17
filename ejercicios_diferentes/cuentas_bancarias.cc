/*Define un struct Cuenta que contenga un numero_cuenta (int), un arreglo estático transacciones[5] de tipo double (representando abonos positivos y retiros negativos), y una variable estado_activa (bool).
En tu main(), crea un arreglo estático de 3 cuentas inicializadas con datos de prueba (recuerda usar la constante para el tamaño). Todas deben empezar con estado_activa en true.
Escribe una función llamada AuditarCuenta. Esta función debe devolver un bool (para saber si la cuenta se encontró) y recibir 6 parámetros:
Un puntero al arreglo de cuentas.
El tamaño del arreglo.
El numero_cuenta a auditar (int).
Una referencia double &saldo_final (para guardar la suma de todas las transacciones).
Un puntero int *retiros_sospechosos (para guardar cuántos retiros fueron mayores a $100.00).
La Lógica de la Función:
Valida los punteros (¡Regla de oro!).
Recorre el arreglo buscando el numero_cuenta.
Si lo encuentras, suma las 5 transacciones y guárdalo en la referencia saldo_final.
Mientras recorres las transacciones, cuenta cuántas son menores a -100.0 (ej. -150.0). Guarda ese conteo en la dirección de memoria del puntero retiros_sospechosos.
Regla de negocio: Si el saldo_final calculado resulta ser menor a 0 (negativo), cambia el estado_activa de esa cuenta original a false (usando la flecha ->).
Retorna true si procesaste la cuenta, o false si nunca la encontraste.
En el main(), prueba la función enviando los mapas de memoria correctos e imprime el saldo, la cantidad de retiros sospechosos, y si la cuenta fue bloqueada o sigue activa.*/
#include <iostream>

// Constantes globales correctas según el tipo de dato
const int kNumCuentas = 3;
const int kNumTransacciones = 5;
const double kLimiteRetiros = -100.0;
const double kLimiteSaldoNegativo = 0.0;

// Struct en CamelCase
struct Cuenta {
    int numero_cuenta;
    double transacciones[kNumTransacciones];
    bool estado_activa;
};

// Función segura combinando referencia (&) y puntero (*)
bool AuditarCuenta(Cuenta* cuentas, int tamano, int numero_cuenta, double& saldo_final, int* retiros_sospechosos) {
    // Escudo protector doble
    if (cuentas == nullptr || retiros_sospechosos == nullptr || tamano <= 0) {
        return false;
    }

    for (int i = 0; i < tamano; ++i) {
        if ((cuentas + i)->numero_cuenta == numero_cuenta) {
            // Inicialización de receptores
            saldo_final = 0.0;        // Sin asterisco (Referencia)
            *retiros_sospechosos = 0; // Con asterisco (Puntero)

            // Procesamiento del arreglo interno
            for (int j = 0; j < kNumTransacciones; ++j) {
                saldo_final += (cuentas + i)->transacciones[j];
                
                if ((cuentas + i)->transacciones[j] < kLimiteRetiros) {
                    (*retiros_sospechosos)++; // Paréntesis obligatorios por precedencia
                }
            }

            // Regla de negocio
            if (saldo_final < kLimiteSaldoNegativo) {
                (cuentas + i)->estado_activa = false;
            } else {
                (cuentas + i)->estado_activa = true;
            }

            return true;
        }
    }
    return false;
}

int main() {
    Cuenta cuentas[kNumCuentas] = {
        {1001, {200.0, -50.0, -150.0, 300.0, -20.0}, true},
        {1002, {500.0, -200.0, -300.0, 400.0, -50.0}, true},
        {1003, {100.0, -10.0, -20.0, 30.0, -5.0}, true}
    };
    
    std::cout << "--- SISTEMA DE AUDITORIA BANCARIA ---\n";

    double saldo_calculado = 0.0;
    int sospechosos_calculados = 0;
    int cuenta_buscar = 1001;

    // Invocamos enviando el mapa de memoria para el puntero (&)
    bool encontrado = AuditarCuenta(cuentas, kNumCuentas, cuenta_buscar, saldo_calculado, &sospechosos_calculados);

    std::cout << "\nResultados para la cuenta: " << cuenta_buscar << "\n";
    if (encontrado) {
        std::cout << "Saldo final: $" << saldo_calculado << "\n";
        std::cout << "Retiros sospechosos detectados: " << sospechosos_calculados << "\n";
        
        // En un caso real buscaríamos el índice, aquí para la demo validamos directo
        std::cout << "Estado actual de la cuenta: " << (cuentas[0].estado_activa ? "Activa" : "Bloqueada") << "\n";
    } else {
        std::cout << "Cuenta no encontrada en el sistema.\n";
    }

    return 0;
}