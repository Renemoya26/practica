#include <iostream>

// Prototipo con CamelCase
void IntercambiarExtremos(int *arreglo, int tamano);

int main() {
    int numeros[] = {10, 20, 30, 40, 50};
    int tamano_arreglo = sizeof(numeros) / sizeof(numeros[0]);

    std::cout << "--------arreglo original--------\n";
    for (int i = 0; i < tamano_arreglo; i++) {
        std::cout << numeros[i] << " ";
    }
    std::cout << "\n";

    IntercambiarExtremos(numeros, tamano_arreglo);

    std::cout << "--------arreglo modificado--------\n";
    for (int i = 0; i < tamano_arreglo; i++) {
        std::cout << numeros[i] << " ";
    }
    std::cout << "\n";

    return 0;
}

void IntercambiarExtremos(int *arreglo, int tamano) {
    if (arreglo == nullptr) {
        std::cout << "Error: La direccion del arreglo no es valida.\n";
        return;
    }
    
    int *inicio = arreglo; 
    int *fin = arreglo + tamano - 1; 

    while (inicio < fin) {
        int temp = *inicio;
        *inicio = *fin;
        *fin = temp;

        inicio++;
        fin--;
    }
}