/*Intercambio mediante punteros: Se define una función que recibe dos
punteros a enteros y debe intercambiar sus valores sin utilizar una tercera
variable global. */
#include <iostream>
void Intercambiar(int *a, int *b) {
    // Validación de seguridad crítica
    if (a == nullptr || b == nullptr) {
        std::cout << "Error: Puntero nulo detectado.\n";
        return; 
    }

    // Intercambio de valores usando aritmética de punteros
    *a = *a + *b; // Paso 1: a = a + b
    *b = *a - *b; // Paso 2: b = (a + b) - b => b = a
    *a = *a - *b; // Paso 3: a = (a + b) - a => a = b
}


int main(){
    int x = 5;
    int y = 10;
    Intercambiar(&x, &y);
    std::cout << "x = " << x << ", y = " << y << "\n";
    std::cout << "Ingrese el primer numero: ";
    std::cin >> x;
    std::cout << "Ingrese el segundo numero: ";
    std::cin >> y;
    Intercambiar(&x, &y);
    std::cout << "x = " << x << ", y = " << y << "\n";
    
    return 0;
}