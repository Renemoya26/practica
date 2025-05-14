// El usuario debe ingresar su edad.
// Si es menor de 10 años, no puede usar la calculadora.
// Si tiene 10 años o más, accede a un menú de operaciones matemáticas (suma, resta, multiplicación, división), usando switch.
// Luego debe ingresar dos números y se le mostrará el resultado.

#include <iostream>
using namespace std;

int main() {
    int edad, opcion;
    float numero1, numero2, resultado;

    cout << "Ingrese su edad:" << endl;
    cin >> edad;

    if (edad < 0) {
        cout << "Edad inválida" << endl;
    } else if (edad < 10) {
        cout << "Lo siento, debes tener por lo menos 10 años para usar la calculadora" << endl;
    } else {
        cout << "Bienvenido a la calculadora" << endl;

        cout << "---- Calculadora Básica ------" << endl;
        cout << "1. Suma" << endl;
        cout << "2. Resta" << endl;
        cout << "3. Multiplicación" << endl;
        cout << "4. División" << endl;
        cout << "Ingrese una opción del 1 al 4:" << endl;
        cin >> opcion;

        cout << "Ingrese el número 1:" << endl;
        cin >> numero1;
        cout << "Ingrese el número 2:" << endl;
        cin >> numero2;

        switch (opcion) {
            case 1:
                resultado = numero1 + numero2;
                cout << "El resultado es: " << resultado << endl;
                break;
            case 2:
                resultado = numero1 - numero2;
                cout << "El resultado es: " << resultado << endl;
                break;
            case 3:
                resultado = numero1 * numero2;
                cout << "El resultado es: " << resultado << endl;
                break;
            case 4:
                if (numero2 == 0) {
                    cout << "No se puede dividir entre cero." << endl;
                } else {
                    resultado = numero1 / numero2;
                    cout << "El resultado es: " << resultado << endl;
                }
                break;
            default:
                cout << "Operación inválida" << endl;
                break;
        }
    }

    return 0;
}
