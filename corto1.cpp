//Una tienda vende entradas
//Niños(0-12 años):$años
//Adolecentes(18-64 años):$10
//Mayores de 65:$6

#include <iostream>
using namespace std;

int main() {
    int edad;
    float precio, wallet = 20.00, restantes;

    cout << "Bienvenido al cine. Por favor indique su edad: ";
    cin >> edad;

    if (edad >= 0 && edad <= 12) {
        precio = 5;
    } else if (edad >= 13 && edad <= 17) {
        precio = 7;
    } else if (edad >= 18 && edad <= 64) {
        precio = 10;
    } else if (edad >= 65 && edad <= 120) {
        precio = 6;
    } else {
        cout << "Edad no válida. Dígitela nuevamente." << endl;
        return 0;
    }

    if (wallet >= precio) {
        restantes = wallet - precio;
        cout << "Entrada comprada por $" << precio << ". Su saldo restante es: $" << restantes << endl;
    } else {
        cout << "Su saldo es insuficiente para comprar la entrada." << endl;
    }

    return 0;
}