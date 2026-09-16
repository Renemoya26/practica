/*10.Acertijo de memoria: Se definen tres variables enteras y tres punteros. Una
función recibe los punteros y modifica sus valores de manera que, después de
ejecutarse, el primer número contenga el mayor valor, el segundo el menor y el
tercero la diferencia entre ambos.*/


#include <iostream>
// Función en CamelCase. Recibe 3 punteros.
// El asterisco se pega al tipo de dato según el estilo de Google.
void Acertijo(int* a, int* b, int* c) {
    // Validación de seguridad de oro
    if (a == nullptr || b == nullptr || c == nullptr) {
        std::cout << "Error: Punteros nulos detectados.\n";
        return;
    }

    // 1. Resguardamos los valores iniciales asumiendo que 'a' es ambos
    int mayor = *a;
    int menor = *a;
    
    // 2. Comparamos para encontrar el mayor
    if (*b > mayor) {
        mayor = *b;
    }
    if (*c > mayor) {
        mayor = *c;
    }
    
    // 3. Comparamos para encontrar el menor
    if (*b < menor) {
        menor = *b;
    }
    if (*c < menor) {
        menor = *c;
    }
    
    // 4. Alteramos la memoria original del main() usando los valores resguardados
    *a = mayor;
    *b = menor;
    *c = mayor - menor;
}

// Función auxiliar en CamelCase
void ImprimirValores(int a, int b, int c) {
    std::cout << "Mayor (a): " << a << "\n";
    std::cout << "Menor (b): " << b << "\n";
    std::cout << "Diferencia (c): " << c << "\n";
}

int main() {
    int a, b, c;
    
    std::cout << "Ingrese tres numeros enteros separados por espacio: ";
    std::cin >> a >> b >> c;
    
    std::cout << "\n--- Valores iniciales ---\n";
    std::cout << "a = " << a << " | b = " << b << " | c = " << c << "\n";
    
    // Pasamos las direcciones de memoria
    Acertijo(&a, &b, &c);
    
    std::cout << "\n--- Valores despues del acertijo ---\n";
    ImprimirValores(a, b, c);
    
    return 0;
}