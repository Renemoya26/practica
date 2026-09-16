#include <iostream>

struct Producto {
    double precio;
    int cantidad;
};

// 1. Nombre en CamelCase
void CalcularPrecioTotal(Producto *p) {
    // 2. Validación de seguridad crítica
    if (p == nullptr) {
        std::cout << "Error: Puntero nulo detectado.\n";
        return; 
    }

    // 3. Aplicamos la regla de negocio (10% de descuento si hay más de 10)
    if (p->cantidad > 10) {
        p->precio *= 0.9; 
    }
}

int main() {
    // Inicialización limpia de la variable (corregimos el typo 'pord' a 'prod')
    Producto prod = {0.0, 0}; 

    std::cout << "Ingrese el precio del producto: $";
    std::cin >> prod.precio;
    
    std::cout << "Ingrese la cantidad del producto: ";
    std::cin >> prod.cantidad;
    
    // Invocamos la función pasando la dirección de memoria
    CalcularPrecioTotal(&prod);
    
    std::cout << "\n--- FACTURA ---\n";
    std::cout << "Cantidad: " << prod.cantidad << "\n";
    std::cout << "Precio unitario (con descuento aplicado si aplica): $" << prod.precio << "\n";
    
    // Calculamos el total una sola vez aquí en el main con el precio ya actualizado
    std::cout << "Precio total a pagar: $" << prod.precio * prod.cantidad << "\n";

    return 0;
}