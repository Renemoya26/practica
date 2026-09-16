#include <iostream>

// 1. Struct en CamelCase
struct Persona {
    int edad;
    float altura;
};

// 2. Función en CamelCase. Recibe por referencia (&) para modificar los originales
void IntercambiarEdades(Persona &p1, Persona &p2) {
    // Si la primera es menor, intercambiamos sus edades
    if (p1.edad < p2.edad) {
        int temp = p1.edad;
        p1.edad = p2.edad;
        p2.edad = temp;
    }
}

int main() {
    // Declaración de variables usando el nombre del struct con mayúscula
    Persona p1, p2;

    std::cout << "Ingrese la edad de la primera persona: ";
    std::cin >> p1.edad;
    std::cout << "Ingrese la altura de la primera persona: ";
    std::cin >> p1.altura;

    std::cout << "Ingrese la edad de la segunda persona: ";
    std::cin >> p2.edad;
    std::cout << "Ingrese la altura de la segunda persona: ";
    std::cin >> p2.altura;

    // Invocamos la función. En C++, al pasar por referencia, solo enviamos los nombres
    IntercambiarEdades(p1, p2);

    std::cout << "\n--- Despues del intercambio ---\n";
    std::cout << "Edad de la primera persona: " << p1.edad << " | Altura: " << p1.altura << "\n";
    std::cout << "Edad de la segunda persona: " << p2.edad << " | Altura: " << p2.altura << "\n";

    return 0;
}