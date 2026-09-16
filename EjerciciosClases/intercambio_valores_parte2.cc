/*1. Intercambio de valores: Se define un struct Persona con edad y altura;
una función recibe dos personas mediante referencias y determina cuál es
mayor, intercambiando sus edades si la primera es menor*/

#include <iostream>
struct persona{
    int edad;
    float altura;
    
};

void intercambiar(persona &p1, persona &p2){
    if(p1.edad < p2.edad){
        int temp = p1.edad;
        p1.edad = p2.edad;
        p2.edad = temp;
    }
}