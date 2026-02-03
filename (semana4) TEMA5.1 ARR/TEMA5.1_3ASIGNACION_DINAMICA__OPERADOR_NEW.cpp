#include <iostream>
using namespace std;



int main(){
    //3.1. Asignacion simple
    int* p= new int;
    *p= 42;                             //i) CLAAAAAAAAAAAAAARO: una vez que ya tengo acceso a ua epsaico en el "heap" (memoria desordenada y flexivble) pues le pongo el valor que deseo

    //error frecuente 1: usar sin inicializar
    int* p= new int;
    cout << *p;         //valor basura

    //Corrección
    int* p= new int(42);                //ii) ESTE ES EL MÁS ADECUADO,, ya que así se incializa defrente con un valor válid0o. EN cambio en el antewriorn, primero se incializa con un valor desconocidio,, QUIZA PEUDA SER INVALIDOP







    //3.2. Asignacion de arreglos
    int n;
    cin >> n;
    int* v= new int[n];

    //Error frecuente 2: asumir que el arreglo se inicializa
    for(int i=0; i<n; i++){
        cout << v[i];       //Valor basura
    }

    //correción
    int* v= new int[n]();   //inicializa en "0" --> Esto solo llena a todos los valores con "0"
    //lo más sencillo e intuitivo es con el for()
    for(int i=0; i<n; i++){
        *(v+i)= i*10;
    }
    //otra versión manual ((solo si es que conozco la cantyidad de elementos))
    int* v= new int[5]{10, 20, 30, 40};

    //YYYYYYYYYYYYY AÚN MÁS IMPORTANTE ((siempre recordar el delete --> cuando termine de usarlo))
    delete[] v; //-->lo borro
    v= nullptr; //-->reinicio mi puntero para que no apunte a un lugar innecesariqamente









    cout << "\n\n-------------\nEND";
    return 0;
}