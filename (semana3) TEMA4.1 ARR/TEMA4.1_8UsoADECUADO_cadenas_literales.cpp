//8. USO ADECUADO DE CADENAS LITERALES (const char*)

#include <iostream>
using namespace std;

int main(){
    /*
    . QUé es una cadena literal? "HOla mundo". ES una cadena almacenada
        en memoria de solo lectura
    . EL compilador la crea automáticamente
    . NO debe modificarse


    . Error clásico del estudiante
    */

    char* p= "HOla";
    p[0]= 'h';                 //comportamiento indefinido

    /*
    . Por qué es un error? "Hola" es una cadena literal. Esta en una región no modificable
    . Intentar cambiarla puede:
        -colgar el programa
        -generar error en tiempo de ejecución


    . Forma correcta
    */

    const char* p= "HOla";

    //si una cadena no debe cambiarse, el tipo debe decirlo
    //si se quiere modificar la cadena

    char palabra[]= "Hola";
    palabra[0]= 'h';             //correcto



    return 0;
}