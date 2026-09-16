/*9. Validación de datos: Se define un struct Rectangulo con ancho y alto; una
función recibe el rectángulo mediante referencia y corrige cualquier dimensión
negativa asignándole cero, mientras otra función calcula su área. */
#include <iostream>

// Struct en CamelCase
struct Rectangulo {
    double ancho;
    double alto;
};

// 1. Función en CamelCase. Recibe por referencia (&) para modificar el original
void ValidaDimensiones(Rectangulo &r) {
    if (r.ancho < 0) {
        std::cout << "-> Ancho negativo detectado. Corrigiendo a 0.\n";
        r.ancho = 0;
    }
    if (r.alto < 0) {
        std::cout << "-> Alto negativo detectado. Corrigiendo a 0.\n";
        r.alto = 0;
    }
} // ¡Sin punto y coma aquí!

// 2. Función en CamelCase. Usa 'const &' para leer sin hacer copias pesadas y sin riesgo de modificar
double CalcularArea(const Rectangulo &r) {
    // Validación de seguridad
    if (r.ancho < 0 || r.alto < 0) {
        std::cout << "Error: Dimensiones invalidas para calcular el area.\n";
        return 0;
    }
    return r.ancho * r.alto;
}

int main() {
    Rectangulo rect;
    
    std::cout << "Ingrese el ancho del rectangulo: ";
    std::cin >> rect.ancho;
    std::cout << "Ingrese el alto del rectangulo: ";
    std::cin >> rect.alto;
    
    std::cout << "\n--- DATOS INGRESADOS ---\n";
    std::cout << "Ancho = " << rect.ancho << ", Alto = " << rect.alto << "\n";
    std::cout << "Area del rectangulo: " << CalcularArea(rect) << "\n";

    std::cout << "\n--- VALIDANDO DIMENSIONES ---\n";
    // Pasamos el rectángulo por referencia para que sea corregido si es necesario
    ValidaDimensiones(rect);
    
    std::cout << "Dimensiones corregidas: Ancho = " << rect.ancho << ", Alto = " << rect.alto << "\n";
    std::cout << "Area del rectangulo: " << CalcularArea(rect) << "\n";
    
    std::cout << "\n--- FIN DEL PROGRAMA ---\n";

    return 0;
}