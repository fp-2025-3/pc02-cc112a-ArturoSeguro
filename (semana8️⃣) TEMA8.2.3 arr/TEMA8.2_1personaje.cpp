#include <iostream>
#include "TEMA8.2_1personaje.h"
#include <cstring>
#include <string>
using namespace std;


//---0
//a1
personaje:: personaje(string n, int s, int m){
    nombre= n;
    salud= s;
    municion= m;
}
//a2
personaje:: ~personaje(){
    cout << "personaje destruido\n";
}
//b1
void personaje:: disparar(){
    if(municion>0){
        cout << "disparo!!!!\n";
        municion--;
        cout << "queda ahora '" << municion << "' de municion.\n";
    }else{
        cout << "no tienes municion --> Busca balas.\n";
    }
}
//b2
void personaje:: getHitted(int s){
    if(salud-s>0){
        cout << "recibiste '" << s << "' de daño.\n";
        salud -= s;
        cout << "salud actual: " << salud << "\n";
    }else{
        salud= 0;
        cout << "moriste!!!\n";
    }
}
//b3
void personaje:: estado() const{
    cout << "nombre: " << nombre << "\n";
    cout << "municion: " << municion << "\n";
    cout << "salud: " << salud << "\n";
}