/*Una tienda necesita aumentar todos sus precios un 10%.
100, 250, 75, 500, 120 -> 110, 275, 82.5, 550, 132*/
#include <iostream>

void ajustar_precio(float *precio, int tamano);

int main()
{

    float precios[] = {100, 250, 75, 500, 120};
    int tamano = sizeof(precios) / sizeof(precios[0]);

    std::cout << "Precios antes del ajuste: ";
    for (int i = 0; i < tamano; i++)
    {
        std::cout << precios[i] << " ";
    }
    std::cout << std::endl;

    ajustar_precio(precios, tamano);

    std::cout << "Precios despues del ajuste: ";
    for (int i = 0; i < tamano; i++)
    {
        std::cout << precios[i] << " ";
    }
    std::cout << std::endl;

    return 0;
}

void ajustar_precio(float *precio, int tamano)
{
    if (precio == nullptr)
    {
        std::cout << "Error: La direccion de los precios no es valida.\n";
        return;
    }
    for (int i = 0; i < tamano; i++)
    {
        *(precio + i) = *(precio + i) * 1.10f; // Aumenta el precio en un 10%
    }
}
