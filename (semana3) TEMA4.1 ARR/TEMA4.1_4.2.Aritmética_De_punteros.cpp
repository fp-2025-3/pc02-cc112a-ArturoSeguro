#include <iostream>
using namespace std;

int main(){
    char palabra[]= "PERU";
    char* p= palabra;

    *(p+1);

    //"p" apunta a "P"
    //"p+1" apunta a 'E'
    //Se avanza 1 byte (sizeof(char))
    //
    //SUmar a un puntero es avanzar posiciones, no sumar numeros" --> CONFIRMO


    return 0;
}