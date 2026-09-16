#include <iostream>

struct Numero {
    int valor;
};

// Función en CamelCase, asterisco junto al tipo de retorno
Numero* BuscarMayor(Numero *arr, int size) {
    if (arr == nullptr || size <= 0) {
        return nullptr;
    }

    // El puntero rastreador inicia apuntando a la dirección del primer elemento
    Numero *mayor = &arr[0];
    
    for (int i = 1; i < size; i++) {
        // Usamos la flecha (->) porque 'mayor' es un puntero
        if (arr[i].valor > mayor->valor) {
            // Actualizamos la ruta con la nueva dirección (&)q
            mayor = &arr[i]; 
        }
    }
    return mayor;
}

int main() {
    int n;
    std::cout << "Ingrese la cantidad de numeros: ";
    std::cin >> n;
    
    // Reserva de memoria dinámica en el Heap
    Numero *arr = new Numero[n];
    
    for (int i = 0; i < n; i++) {
        std::cout << "Ingrese el numero " << i + 1 << ": ";
        std::cin >> arr[i].valor;
    }

    Numero *mayor = BuscarMayor(arr, n);
    
    if (mayor != nullptr) {
        std::cout << "El numero mayor es: " << mayor->valor << "\n";
    } else {
        std::cout << "No se encontro un numero mayor.\n";
    }

    return 0;
}