//Un sistema de calificación te pide ingresar una nota (de 0 a 100) y muestra:
//Si la nota es mayor o igual a 90: "Excelente"
//Si la nota es mayor o igual a 70: "Aprobado"
//Si la nota es menor a 70: "Reprobado"
//Si la nota no está entre 0 y 100: "Nota inválida"

#include <iostream>
using namespace std ;
int main(){
    int nota;

    cout << "ingrese una nota del (0 al 100)";
    cin  >>  nota ;

    if(nota >= 90){
    cout << "Excelente" << endl;

    } else if (nota >=70) {
     cout <<"Aprobado" << endl;

    } else if (nota >=0 && nota <70) {
    cout <<"Reprobado" << endl;
               
        
    } else { 
    cout << "nota invalida"<< endl ;

    }

   

return 0;
}


