/*2.El Reto:
Estructura: Define un struct Producto con id_producto (int), precio (float), y stock (int).
Configuración global: Fuera del main(), crea una constante const int kTotalProductos = 4;
Datos Iniciales: En tu main(), crea un arreglo estático de 4 productos con datos quemados (ej. IDs 10, 20, 30, 40 con distintos niveles de stock).
Función: Escribe una función modular: bool ProcesarVenta(Producto* inventario, int tamano, int id_buscar, int cantidad_comprada).
Lógica Estricta:
Aplica tu escudo de punteros nulos.
Recorre el arreglo usando estrictamente aritmética de punteros y el operador flecha: (inventario + i)->.
Si encuentras el id_buscar, verifica si el stock es mayor o igual a la cantidad_comprada.
Si es válido, resta la cantidad del stock original y retorna true. Si no hay stock suficiente o el producto no existe, retorna false.
Prueba: En el main(), simula la compra de un producto, imprime si la venta fue exitosa o fallida, y muestra el stock final de todo el arreglo para comprobar la alteración en memoria.*/
#include <iostream>
struct Producto {
    int id_producto;
    float precio;
    int stock;
};
const int kTotalProductos = 4;
bool ProcesarVenta(Producto* inventario, int tamano, int id_buscar, int cantidad_comprada);

int main() {
    Producto inventario[kTotalProductos] = {
        {10, 15.99f, 20},
        {20, 9.99f, 50},
        {30, 5.49f, 30},
        {40, 12.75f, 10}
    };

    int id_buscar = 20;
    int cantidad_comprada = 5;

    bool venta_exitosa = ProcesarVenta(inventario, kTotalProductos, id_buscar, cantidad_comprada);

    if (venta_exitosa) {
        std::cout << "Venta exitosa!" << std::endl;
    } else {
        std::cout << "Venta fallida!" << std::endl;
    }

    // Mostrar el stock final de todo el arreglo
    for (int i = 0; i < kTotalProductos; ++i) {
        std::cout << "Producto ID: " << (inventario + i)->id_producto 
                  << ", Stock: " << (inventario + i)->stock << std::endl;
    }

    return 0;
}

bool ProcesarVenta(Producto* inventario, int tamano, int id_buscar, int cantidad_comprada) {
    if (inventario == nullptr || tamano <= 0) {
        return false; // Escudo de punteros nulos
    }

    for (int i = 0; i < tamano; ++i) {
        if ((inventario + i)->id_producto == id_buscar) {
            if ((inventario + i)->stock >= cantidad_comprada) {
                (inventario + i)->stock -= cantidad_comprada; // Restar la cantidad del stock
                return true; // Venta exitosa
            } else {
                return false; // No hay stock suficiente
            }
        }
    }
    return false; // Producto no encontrado
}

