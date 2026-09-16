/*5. Comparar estudiantes: Se define un struct Estudiante con nombre y nota;
una función recibe dos estudiantes mediante referencias y retorna una
referencia al estudiante con mayor nota.*/
#include <iostream>
#include <string>

// 1. Struct en CamelCase
struct Estudiante
{
    std::string nombre;
    float nota;
};

// 2. FUNCIÓN CORREGIDA: Ahora devuelve una REFERENCIA CONSTANTE (&)
const Estudiante &CompararEstudiantes(const Estudiante &estudiante_1, const Estudiante &estudiante_2)
{
    // Si el primero es mayor o igual (empate), devolvemos el primero
    if (estudiante_1.nota >= estudiante_2.nota)
    {
        return estudiante_1;
    }
    else
    {
        // En cualquier otro caso, el segundo es mayor
        return estudiante_2;
    }
}

int main()
{
    Estudiante estudiante_1, estudiante_2;

    std::cout << "Ingrese el nombre del primer estudiante: ";
    std::cin >> estudiante_1.nombre;
    std::cout << "Ingrese la nota del primer estudiante: ";
    std::cin >> estudiante_1.nota;

    std::cout << "\nIngrese el nombre del segundo estudiante: ";
    std::cin >> estudiante_2.nombre;
    std::cout << "Ingrese la nota del segundo estudiante: ";
    std::cin >> estudiante_2.nota;

    // 3. RECEPCIÓN POR REFERENCIA: Atrapamos el resultado con un '&' para no hacer copia
    const Estudiante &estudiante_ganador = CompararEstudiantes(estudiante_1, estudiante_2);

    std::cout << "\n--- RESULTADO ---\n";
    std::cout << "El estudiante con mayor nota es: " << estudiante_ganador.nombre
              << " con nota: " << estudiante_ganador.nota << "\n";

    return 0;
}