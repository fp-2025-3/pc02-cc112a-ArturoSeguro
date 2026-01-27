//ARREGLO DE CADENAS
/*
ES un arreglo cuyos elementos son cadenas, y una cadena es:
un arreglo de char terminado en '\0'

POr tanto, un arreglo de cadenas puede representarse como:
    .un arreglo bidimensional de char, o
    .una rreglo de punteros a char (forma más flexible)
*/


#include <iostream>
using namespace std;

int main(){
    //FORMA1 --- Arreglo bidimensional (forma rígida)
    char paises1[3][10]={ "Peru",
                         "Chile",
                         "Brasil" };
    /*
    . Que hay en memoria? 3filas. cada fila tiene 10 caracteres
    . Todas las cadenas tienen longitud máxima fija
    . Se dereperdicia memoria. NO todas las palabras usan las 10 posiciones
    */




    //FORMA2 --- Arreglo de punteros a char (forma eficiente)
    const char* paises2[3][10]={   "Peru",
                                  "Chile",
                                  "Brasil"  };
    /*
    . Qué es realmente paises? paises es un arreglo de punteros
    . Cada puntero apunta a una cadena literal
    */




    //RECORRER UN ARREGLO DE CADENAS CON PUNTERO
    for(int i=0; i<3; i++){
        const char** p= *(paises2+i);        //con cada "i" se aumenta 10 espacios de memoria para analizar la siguiente fila
        
        
        while(*p != '\0'){
            cout << **p;
            p++;
        }
        cout << "\n";
        //este while es para imprimir la matriz de cadenas con punteros
    }

    /*
    . Un ARREGLO DE CADENAS ES UN ARREGLO de punteros, y cada puntero se recorre
        una cadena normal
    */

    return 0;
}