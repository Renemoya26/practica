//Un programa que reciba una temperatura en grados Celsius y muestre:
//Si la temperatura es menor a 0: "Hace mucho frío"
//Si la temperatura está entre 0 y 18: "Clima fresco"
//Si está entre 19 y 30: "Clima agradable"
//Si es mayor a 30: "Hace calor"
//Y si la temperatura es menor que -50 o mayor que 60: "Temperatura inválida"

#include <iostream>
using namespace std;
int main(){
    int temperatura;
    cout << "Ingrese la temperatura" << endl;
    cin >> temperatura;

    if (temperatura < -50 || temperatura >60 ){
        cout << " temperatura invalida " << endl;

          } else if (temperatura <0 ){
        cout << " Hace mucho frio " << endl;

        } else if (temperatura >=0 && temperatura <=18){
        cout << "Clima fresco" << endl;

         } else if (temperatura >=19 && temperatura <=30){
        cout << "Clima Agradable" << endl;

         } else if (temperatura > 30){
        cout << "Hace calor" << endl;

       
    }
    
        
    
    

return 0;
}