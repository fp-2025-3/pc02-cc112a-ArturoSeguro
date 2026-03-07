#include <iostream>
#include "TEMA8.2_2persona.h"
#include <cstring>
#include <string>
using namespace std;


//---0
//a1
persona:: persona(string n, int e){
    nombre= n;
    edad= e;
}
//a2
persona:: ~persona(){
    cout << "destruyendo persona.\n";
}
//b1
void persona:: datosPersonales() const{
    cout << "nombre: " << nombre << "\n";
    cout << "edad: " << edad << "\n";
}


//---1
//a1
estudianteCiencias:: estudianteCiencias(string n, int e, int c, int s)
: persona(n, e){
    codigo= c;
    semestre= s;
}
//a2
estudianteCiencias:: ~estudianteCiencias(){
    cout << "destruyendo estudiante.\n";
}
//b1
void estudianteCiencias:: perfilEstudiante() const{
    cout << "=== Perfil Ciencias ===\n";
    //persona:: datosPersonales();              //esto es si en lugar de "protected" pusiera "private"
    cout << "nombre: " << nombre << "\n";
    cout << "edad: " << edad << "\n";
    cout << "codigo: " << codigo << "\n";
    cout << "semestre: " << semestre << "\n";
}