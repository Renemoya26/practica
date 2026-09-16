/*7. Modificar elementos de un arreglo: Se define una función que recibe un
puntero al primer elemento de un arreglo de enteros y su tamaño; la función
recorre los elementos y reemplaza los valores negativos por cero. */
#include <iostream>

// Función en CamelCase, sin punto y coma al finalizar la llave principal
void ModificarArreglo(int *arr, int size) {
    // Validación crítica contra punteros nulos
    if (arr == nullptr || size <= 0) {
        std::cout << "Error: Puntero nulo o tamano invalido.\n";
        return;
    }

    // Recorrido y modificación en la memoria original
    for (int i = 0; i < size; i++) {
        if (arr[i] < 0) {
            arr[i] = 0; 
        }
    }
} // Nota: No lleva punto y coma aquí

int main() {
    int n;
    std::cout << "Ingrese la cantidad de elementos del arreglo: ";
    std::cin >> n;
    
    // Reserva de memoria dinámica (Heap)
    int *arr = new int[n];
    
    for (int i = 0; i < n; i++) {
        std::cout << "Ingrese el elemento " << i + 1 << ": ";
        std::cin >> arr[i];
    }
    
    // Pasamos el puntero a la función
    ModificarArreglo(arr, n);
    
    std::cout << "\n--- Arreglo Modificado ---\n";
    for (int i = 0; i < n; i++) {
        std::cout << arr[i] << " ";
    }
    std::cout << "\n";
    
    
    return 0;
}