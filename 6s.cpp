//Calculadora Basica.
//Operaciones basicas : Suma , Resta , Multiplicacion , Division.
//Pide al usuario Ingresar un numero del (1-4)

#include <iostream>
using namespace std ;
int main(){
    int opcion ;
    float  numero1 , nuemero2 , resultado ;

    cout << "--------------- menu de operaciones basicas --------------------" << endl;
    cout << "1. Suma" << endl;
    cout << "2. Resta" << endl;
    cout << "3. Multiplicacion" << endl;
    cout << "4. Division" << endl;
    cout <<"Ingrese una opcion del (1-4)"
    cin >> opcion;

     cout << "Ingrese su numero 1" << endl;
    cin >> numero1

    cout << "ingrese su numero 2" << endl;
    cin >> nuemro2

    switch (expression) {
   
    case 1 :
    resultado = numero1 + nuemero2
    cout << "El resultado es "<< resultado << endl ;
        break;

        case 2:
    resultado = numero1 - nuemero2
    cout << "El resultado es "<< resultado << endl ;
    break;

    case 3:
    resultado = numero1 * nuemero2
    cout << "El resultado es "<< resultado << endl ;
    break;

    case 4 :
    resultado = numero1 / nuemero2
    cout << "El resultado es "<< resultado << endl ;
    

    
    default:
    cout <<"Operacion invalida"

        break;
    }







return 0;


}
