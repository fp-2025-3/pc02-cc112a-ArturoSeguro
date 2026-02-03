
#include <iostream>
using namespace std;



int main(){
    //********2.1. STACK .VS.VS. HEAP
    /*
    STACK               HEAP
    automático          Manual
    Rápido              Más flexible
    Tamaño limitado     Gran capacidad          //?????? pero cómo lo uso, enseñame porfaaaaaa?
    */

    void f(){
        int x= 10;              // stack
        int* y= new int;        // heap
    }
    ////    ERROR FRECUENTE__ olvidar que "y" no se libera automáticamente


    cout << "\n\n-------------\nEND";
    return 0;
}