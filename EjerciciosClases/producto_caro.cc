/*8. Producto más caro: Se define un struct Producto con nombre y precio; una
función recibe un arreglo mediante puntero y determina el producto más caro,
retornando su dirección para que main pueda mostrar sus datos. */
#include <iostream>
#include <string>

// Struct en CamelCase
struct Producto {
    std::string nombre;
    double precio;
};

// RETORNO SIMPLE: Devuelve un puntero (Producto*) en lugar de usar dobles punteros (**)
Producto* BuscarProductoMasCaro(Producto *arr, int size) {
    if (arr == nullptr || size <= 0) {
        return nullptr;
    }

    // Puntero rastreador simple
    Producto *mas_caro = &arr[0];
    
    for (int i = 1; i < size; i++) {
        // Como 'mas_caro' es un puntero simple, usamos la flecha directamente
        if (arr[i].precio > mas_caro->precio) {
            mas_caro = &arr[i]; 
        }
    }
    
    // Retornamos el mapa hacia la caja ganadora
    return mas_caro;
}

int main() {
    int n;
    std::cout << "Ingrese la cantidad de productos (maximo 50): ";
    std::cin >> n;
    
    // ARREGLO ESTÁTICO: Lo que hemos visto hasta ahora, sin usar 'new' ni 'delete'
    const int kMaxProductos = 50;
    Producto productos[kMaxProductos];
    
    // Validación de seguridad para no desbordar el arreglo estático
    if (n > kMaxProductos) {
        n = kMaxProductos;
        std::cout << "[Aviso] Limitado a 50 productos.\n";
    }
    
    for (int i = 0; i < n; i++) {
        std::cout << "Ingrese el nombre del producto " << i + 1 << ": ";
        std::cin >> productos[i].nombre;
        std::cout << "Ingrese el precio del producto " << i + 1 << ": $";
        std::cin >> productos[i].precio;
    }

    // Atrapamos la dirección de memoria devuelta con un puntero simple
    Producto *resultado = BuscarProductoMasCaro(productos, n);

    std::cout << "\n--- RESULTADO ---\n";
    if (resultado != nullptr) {
        std::cout << "El producto mas caro es: " << resultado->nombre 
                  << " con precio: $" << resultado->precio << "\n";
    } else {
        std::cout << "No hay productos disponibles.\n";
    }

    return 0;
}