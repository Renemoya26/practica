/*3.El Problema:
Define un struct Producto que contenga un id_producto (int) y un stock (int).
En tu main(), crea una constante kNumProductos = 3 y un arreglo estático de 3 productos inicializados con datos de prueba (ej. IDs 101, 102, 103 con diferentes cantidades de stock).
Escribe una función llamada VenderProducto. Debe devolver un bool (éxito o fracaso) y recibir 4 parámetros:
Un puntero al inicio del arreglo de productos (Producto* inventario).
El tamaño del arreglo (int tamano).
El ID del producto que el cliente quiere comprar (int id_buscar).
La cantidad que desea comprar (int cantidad_compra).
La Lógica de la Función:
Aplica tu escudo de punteros nulos.
Usa un ciclo for y aritmética de punteros (ej. (inventario + i)->id_producto) para buscar el producto solicitado por todo el arreglo.
Si encuentras el producto, verifica que su stock sea mayor o igual a la cantidad_compra. Si hay suficiente, réstalo del stock original y retorna true. Si no hay suficiente, retorna false.
Si el ciclo termina y no se encontró el producto, retorna false.
En el main(), prueba la función intentando vender un producto y muestra si fue exitoso o no, imprimiendo el stock antes y después.*/
#include <iostream>
struct Producto {
    int id_producto;
    int stock;
};

bool VenderProducto(Producto* inventario, int tamano, int id_buscar, int cantidad_compra);

int main(){
    const int kNumProductos = 3;
    Producto inventario[kNumProductos] = {
        {101, 10},
        {102, 5},
        {103, 20}
    };

    int id_buscar = 102; // ID del producto que el cliente quiere comprar
    int cantidad_compra = 3; // Cantidad que desea comprar

    std::cout << "--- GESTION DE INVENTARIO ---\n";
    std::cout << "Stock inicial del producto con ID " << id_buscar << ": ";
    for (int i = 0; i < kNumProductos; ++i) {
        if ((inventario + i)->id_producto == id_buscar) {
            std::cout << (inventario + i)->stock << "\n";
            break;
        }
    }

    bool exito = VenderProducto(inventario, kNumProductos, id_buscar, cantidad_compra);

    if (exito) {
        std::cout << "[Exito] Venta realizada. Se vendieron " << cantidad_compra << " unidades del producto con ID " << id_buscar << ".\n";
    } else {
        std::cout << "[Error] Venta fallida. Verifique el stock o el ID del producto.\n";
    }

    std::cout << "Stock final del producto con ID " << id_buscar << ": ";
    for (int i = 0; i < kNumProductos; ++i) {
        if ((inventario + i)->id_producto == id_buscar) {
            std::cout << (inventario + i)->stock << "\n";
            break;
        }
    }

    return 0;
}

bool VenderProducto(Producto* inventario, int tamano, int id_buscar, int cantidad_compra) {
    if (inventario == nullptr) {
        std::cerr << "[Error] Puntero nulo detectado.\n";
        return false;
    }

    for (int i = 0; i < tamano; ++i) {
        if ((inventario + i)->id_producto == id_buscar) {
            if ((inventario + i)->stock >= cantidad_compra) {
                (inventario + i)->stock -= cantidad_compra;
                return true;
            } else {
                std::cerr << "[Error] Stock insuficiente para el producto con ID " << id_buscar << ".\n";
                return false;
            }
        }
    }

    std::cerr << "[Error] Producto con ID " << id_buscar << " no encontrado en el inventario.\n";
    return false;
}
