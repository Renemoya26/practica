//Le pida al usuario su edad.
//Calcule el precio de entrada al zoológico según la siguiente tabla:
//Menores de 5 años: Entrada gratis.
//De 5 a 17 años: Entrada $8.
//De 18 a 59 años: Entrada $12.
//60 años o más: Entrada $5.
//Muestre el precio correspondiente.

#include <iostream>
using namespace std;
int main(){
    int precio , edad ;

    cout << "ingrese su  edad" << endl;
    cin >> edad;

    if (edad <= 5 ) {
        precio = 0;

         } else if (edad >= 5 && edad <=17 ) {
            precio = 8;

             } else if (edad >= 18 && edad <= 59) {
                precio = 12;

    
                 } else if (edad >= 60 ) {
                    precio = 5;


                    } else {
        cout << "Edad no válida." << endl;
        return 0;         
    }
    
              
    
    cout << "El precio de su entrada es: $" << precio << endl;

 

return 0;

}


