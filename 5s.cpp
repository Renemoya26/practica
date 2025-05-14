//Un programa que recibe una calificación del 1 al 5 y muestra:
//1: "Muy deficiente"
//2: "Insuficiente"
//3: "Suficiente"
//4: "Notable"
//5: "Excelente"
//Cualquier otro número: "Nota no válida"

#include <iostream>
using namespace std ;
int main(){
    int calificacion;
    cout << "Escriba una calificacion del 1 al 5" << endl;
    cin >> calificacion;

    switch (calificacion){    
    case 1:
    cout << "Muy deficiente" << endl;
        break;

         case 2:
    cout << "Insuficiente" << endl;
        break;

        
        case 3:
    cout << "suficiente" << endl;
        break;


         case 4:
    cout << "Notable" << endl;
        break;
        

           case 5:
    cout << "Excelente" << endl;
        break;


        
    
    default:
    cout << "nota ivalida"<< endl ;
        break;
    }






return 0;


}