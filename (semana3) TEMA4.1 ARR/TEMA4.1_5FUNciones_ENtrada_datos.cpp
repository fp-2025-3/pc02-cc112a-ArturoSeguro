//5. FUNCIONES DE ENTRADA DE DATOS



#include <iostream>
using namespace std;

int main(){
    //*********EJER5.1 --- cin >> nombre
    char nombre[10];
    cin >> nombre;

    //El codigo puede detener el programa sin avisar

    //
    /*
    Problemas
    -NO controla tamaño
    -PUde sobreescribir memoria
    -Provoca buffer overflow
    */



    //*********EJER5.2 --- cin.getline
    char frase[]= "hey00";
    cin.getline(frase, 50);

    /*
    Lee hasta 49 caracteres
    Agrega '\0'
    Es mas segura
    SI el buffer está sucio, puede leer vacio.
    (use cin.ignore() para limpiar el buffer)
    */

    //Qué será "Buffer"???

    return 0;
}