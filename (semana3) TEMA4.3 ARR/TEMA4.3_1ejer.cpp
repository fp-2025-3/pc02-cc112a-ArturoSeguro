#include <iostream>
#include <cctype>
#include <cstring>
#include <cstdlib>
using namespace std;


//Deseo que el programa detecte si dos numeros me pueden dar el elemento "k"

//function 0
bool esNum(int a){
    if(a== '1' || a== '2' || a== '3' || a== '4' || a== '5' || a== '6' || a== '7' || a== '8' || a== '9' || a== '0'){
        return true;
    }else{
        return false;
    }
}


//function 1
int detectaNumeros(char* cadena, char* numeros[60]){
    int i=0;
    int cantidad=0;
    while( *(cadena+i)!= '\0'){
        int a= *(cadena+i);
        if(esNum(a)){
            numeros[cantidad]= (cadena+i);
            cantidad++;
        }
        i++;
    }

    return cantidad;           //esta es la cantidad de numeros que he guardado en mi arrgelo de punteros
}


//function 2
bool parNumeros(char* numeros[60], int cantidad, int k){
    bool hayOno= false;
    for(int i=0; i<cantidad-1; i++){
        for(int j=i+1; j<cantidad; j++){
            int a= *(numeros[i])- '0';
            int b= *(numeros[j])- '0';
            bool condicion= (a+b == k);
            if(condicion){
                hayOno= true;
            }
        }
    }

    return hayOno;
}


//function 3
void imprimir(bool hayOno, int k){
    if(hayOno){
        cout << "SI existen 2 numeros co suma " << k;
    }else{
        cout << "NO existen 2 numeros co suma " << k;
    }
}


//function 4



//function 5






int main(){
    char cadena[]= "1, 2, 4, 7, 11";
    cout << cadena << "\n";

    int k;
    cout << "Dea el numero 'k':: ";
    cin >> k;

    char* numeros[60];         //"60" por si alguien quiere crear una cadena con más numeros enteros (de una cifra)

    //
    int cantidad= detectaNumeros(&cadena[0], &numeros[0]);

    //
    bool hayOno= parNumeros(&numeros[0], cantidad, k);

    //
    cout << "\n\n";
    imprimir(hayOno, k);
    cout << "\n\n";

    return 0;
}