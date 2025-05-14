#include <iostream>
using namespace std;

int main() {
    int menuGlobal, MenuMañana, MenuTarde, MenuNoche, años;
    float wallet = 100.00, restante;

    cout << "-------------Moya Juice---------------" << "\n";
    cout << "1. Menu de mañana" << "\n";
    cout << "2. Menu de la tarde" << "\n";
    cout << "3. Menu de la noche" << "\n";
    cout << "4. Salir" << "\n";
    cout << "Bienvenido, ¿qué menú quisiera ordenar?: ";
    cin >> menuGlobal;

    switch (menuGlobal) {
        case 1:
            cout << "-------------Menu de mañana - Moya Juice-------------" << "\n";
            cout << "1. Jugo de naranja ($1.00)" << "\n";
            cout << "2. Jugo de piña ($1.50)" << "\n";
            cout << "3. Jugo de fresa ($2.00)" << "\n";
            cout << "4. Jugo de mango ($2.50)" << "\n";
            cout << "5. Jugo para niños ($1.00)" << "\n";
            cout << "Bienvenido, tenga buenos días, ¿qué desea ordenar?: ";
            cin >> MenuMañana;

            switch (MenuMañana) {
                case 1:
                    cout << "Usted ha seleccionado un Jugo de naranja ($1.00)" << "\n";
                    restante = wallet - 1.00;
                    break;
                case 2:
                    cout << "Usted ha seleccionado un Jugo de piña ($1.50)" << "\n";
                    restante = wallet - 1.50;
                    break;
                case 3:
                    cout << "Usted ha seleccionado un Jugo de fresa ($2.00)" << "\n";
                    restante = wallet - 2.00;
                    break;
                case 4:
                    cout << "Usted ha seleccionado un Jugo de mango ($2.50)" << "\n";
                    restante = wallet - 2.50;
                    break;
                case 5:
                    cout << "Usted ha seleccionado un Jugo para niños ($1.00), por favor indique su edad: ";
                    cin >> años;

                    if (años >= 0 && años <= 7) {
                        restante = wallet - 1.00;
                        cout << "Usted tiene " << años << " años. ¡Disfrute su jugo para niños!" << "\n";
                    } else if (años > 7 && años <= 14) {
                        restante = wallet - 2.00;
                        cout << "Usted tiene " << años << " años. ¡Disfrute su jugo para niños!" << "\n";
                    } else if (años >= 15 && años <= 17) {
                        restante = wallet - 3.00;
                        cout << "Usted tiene " << años << " años. ¡Disfrute su jugo para niños!" << "\n";
                    } else if (años >= 18) {
                        restante = wallet;
                        cout << "Lo siento, no puede comprar el jugo para niños." << "\n";
                    } else {
                        cout << "Ha ocurrido un error, pruebe más tarde.\n";
                        restante = wallet;
                    }
                    break;
                default:
                    cout << "Selección inválida.\n";
                    restante = wallet;
            }

            cout << "Su saldo actual es de: $" << restante << "\n";
            break;

        case 2:
            cout << "-------------Menu de la tarde - Moya Juice-------------" << "\n";
            cout << "1. Jugo de naranja ($1.00)" << "\n";
            cout << "2. Jugo de piña ($1.50)" << "\n";
            cout << "3. Jugo de fresa ($2.00)" << "\n";
            cout << "4. Jugo de mango ($2.50)" << "\n";
            cout << "Bienvenido, tenga buenas tardes, ¿qué desea ordenar?: ";
            cin >> MenuTarde;

            switch (MenuTarde) {
                case 1:
                    cout << "Usted ha seleccionado un Jugo de naranja ($1.00)" << "\n";
                    restante = wallet - 1.00;
                    break;
                case 2:
                    cout << "Usted ha seleccionado un Jugo de piña ($1.50)" << "\n";
                    restante = wallet - 1.50;
                    break;
                case 3:
                    cout << "Usted ha seleccionado un Jugo de fresa ($2.00)" << "\n";
                    restante = wallet - 2.00;
                    break;
                case 4:
                    cout << "Usted ha seleccionado un Jugo de mango ($2.50)" << "\n";
                    restante = wallet - 2.50;
                    break;
                default:
                    cout << "Selección inválida.\n";
                    restante = wallet;
            }

            cout << "Su saldo actual es de: $" << restante << "\n";
            break;

        case 3:
            cout << "-------------Menu de la noche - Moya Juice-------------" << "\n";
            cout << "1. Jugo de naranja ($1.00)" << "\n";
            cout << "2. Jugo de piña ($1.50)" << "\n";
            cout << "3. Jugo de fresa ($2.00)" << "\n";
            cout << "4. Jugo de mango ($2.50)" << "\n";
            cout << "Bienvenido, tenga buenas noches, ¿qué desea ordenar?: ";
            cin >> MenuNoche;

            switch (MenuNoche) {
                case 1:
                    cout << "Usted ha seleccionado un Jugo de naranja ($1.00)" << "\n";
                    restante = wallet - 1.00;
                    break;
                case 2:
                    cout << "Usted ha seleccionado un Jugo de piña ($1.50)" << "\n";
                    restante = wallet - 1.50;
                    break;
                case 3:
                    cout << "Usted ha seleccionado un Jugo de fresa ($2.00)" << "\n";
                    restante = wallet - 2.00;
                    break;
                case 4:
                    cout << "Usted ha seleccionado un Jugo de mango ($2.50)" << "\n";
                    restante = wallet - 2.50;
                    break;
                default:
                    cout << "Selección inválida.\n";
                    restante = wallet;
            }

            cout << "Su saldo actual es de: $" << restante << "\n";
            break;

        case 4:
            cout << "Gracias por visitar Moya Juice. ¡Hasta pronto!\n";
            break;

        default:
            cout << "Opción inválida.\n";
            break;
    }

    return 0;
}















