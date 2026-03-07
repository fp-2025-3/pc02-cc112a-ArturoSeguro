//11. strtok --- Separación de cadenas en tokens


#include <iostream>
#include <cstring>
using namespace std;


/*
. Para qué sirve strtok? strtok se usa para dividir una cadena
    en partes (tokens) usando uno o varios delimitadores
*/

//Prototipo de strtok
char* strtok(char* str, const char* delimitadores);

/*
. strtok MODIFICA la cadena original, por ello NO debe usarse con cadenas
    literales, solo con arreglos de char modificables

*/

int main(){
    char texto[]= "JUan,Pedro,Ana";
    char* token= strtok(texto, ",");

    while(token!= nullptr){
        cout << token << "\n";
        token= strtok(nullptr, ",");        //no tiene sentido que analice al puntero "token" y que lo tokenise, se supone que "token" guarda una Dirección de espacio en la memoria
    }

    /*
    . texto es un arreglo de char
    . contiene una cadena modificable
    . contenido inicial en memoria
        "JUan,Pedro,Ana \0"
    . QUé hace strtok?
        Primera llamada: token= strtok(nullptr, ",");
        Busca el primer "," lo reemplaza por '\0'.

    . Devuelve un puntero al inicio del token           //CÓMO????
        Memoria después:
        "JUan \0 Pedro \0 Ana \0"
    ...
    ...
    ...
    */




    //Qué delimitadores se pueden usar?
    strtok(texto, ",; ")    //Separa por coma, punto y coma, espacio










    //ERROR TIPICO 1 -- usar strtok con cadenas literales
    char* p= "A,B,C";
    char* t= strtok(p, ",");        //ERROR (yo aún no veo por qué)

    //comportamiento indefinido porque "A,B,C" es solo lectur
            //qué significa que sea solo lectura???
    

    //solución::::
    char texto[]= "A,B,C";








    //ERROR TIPICO 2 -- perder la cadena original
    /*
    Después de usar strtok, la cadena: "Juan,Pedro,Ana"
    queda convertida en:
    "Juan\0Pedro\0Ana\0"


    Es decir, la cadena original ya no existe

                    //Acaso eso no es lo que se desea??????????????
    */




    //ERROR TIPICO 3 --- Uso simultáneo
    strtok(cadena1, ",");
    strtok(cadena2, ",");       //interfiere
                                //??????????????son cadenas distintas por qué sería in error???






    return 0;
}