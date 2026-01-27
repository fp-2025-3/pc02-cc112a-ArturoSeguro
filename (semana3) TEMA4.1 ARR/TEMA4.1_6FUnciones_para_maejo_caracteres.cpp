//*********6. FUNCIONES PARA EL MANEJO DE CARACTERES
#include <iostream>
#include <cstring>
using namespace std;

int main(){

    //EJERcicio 6.1 --- strlen
    char texto[20]= "Hola";
    cout << strlen(texto) << endl;

    /*
    . CUenta caracteres antes de '\0'. NO incluye el terminador
    . SI no hay'\0' produce comporatamiento indefinido
    . strlen no sabe de tamaños, sollo busca el caracter nulo
    */




    //EJERcicio 6.2 -- strcpy peligroso
    char destino[5];
    char origen[]= "Programación";

    strcpy(destino, origen);

    /*
    . Destino es un arreglo de 5caracteres. Puede almacenar máximo
        4caracteres visibles + '\0'
    . Copia hasta encontrar '\0'. NO VERIFICA TAMAÑO.
        Resultado: desbordamiento de memoria
    */

    //falla porque en programación hay más de "5-1=4" caracteres
    //y el destino soo puede aceptar "4"






    //EJERcicio 6.3 -- comparar cadenas
    char a[]= "Hola";
    char b[]= "Hola";

    if(a== b){  //error tipico
        cout << "Iguales\n";
    }

    /*
    . Forma correcta if(strcmp(a,b)== 0)
    . a== b compara direcciones. "strcmp()" compara contenido
    
    . Compara caracter por caracter. Devuelve:
        0               --> iguales
        <0 (negativo)   --> a<b (segun ASCIIy caracteres)
        >0 (positivo)   --> a>b
    */



    return 0;
}