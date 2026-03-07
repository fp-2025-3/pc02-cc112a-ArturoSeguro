#include <iostream>
#include <cctype>
#include <cstring>
#include <cstdlib>
using namespace std;

/*
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
        cout << "SI existen 2 numeros con suma " << k;
    }else{
        cout << "NO existen 2 numeros con suma " << k;
    }
}

//function 4
//function 5
*/










//
//
//
//--> no respete la condición de eficiencia O(n)
//--> tampoco programe bien para detectar el numero "11" --> en mi codigo se detectaban "1" y "1" --> por eso no funcionaba al pediar k=15



//función1:::
//
//Función para extraer los números reales (incluyendo los de múltiples cifras)
//Retorna la cantidad de números encontrados
int procesarCadena(char* cadena, int* numeros){
    int cantidad= 0;
    int i= 0;

    while( *(cadena+i)!= '\0'){
        // Si encontramos un dígito, empezamos a construir el numero completo (si es que tiene más de una cifra)
        if( isdigit( *(cadena+i)) ){
            int numeroActual= 0;
            //Mientras siga habiendo dígitos (ej: el '1' y el luego '1' para al final '11' )
            while( isdigit( *(cadena+i)) ){
                numeroActual= (numeroActual*10)+ ( *(cadena+i)-'0' );
                i++;    //esto funciona perfecto para un numero de un monotnazo de cifras
            }
            //guardamos el entero completo en el arreglo
            *(numeros+ cantidad)= numeroActual;
            cantidad++;
        }else{
            i++;       //si no es un digito, pues no tengo que hacer nada, solo sigo moviendome por la cadena hasta encontrar el numero que deseo
        }
    }

    return cantidad;
}



//función2:::
//
//Algoritmo O(n) usando "Dos Punteros"
bool encontrarSuma(int* numeros, int cantidad, int k){
    //aqui ya estan todos los numeros colocados en mi cadena de punteros números[]
    int izquierda= 0;           //Puntero al inicio (número más chico)
    int derecha= cantidad-1;    //Puntero al final (número más grande)

    while(izquierda< derecha){
        int sumaActual= *(numeros+ izquierda)+ *(numeros+ derecha);
        
        if(sumaActual== k){
            //Se encontró --> Aquí llegaría si alguien pone "k=15"
            return true;
        }else if(sumaActual< k){
            //Si la suma es muy chica, necesitan números más grandes.
            //Movemos el puntero izquiero a la derecha.
            izquierda++;
        }else{
            //Si al suma es muy grande, necesitamos números más chicos
            //Movemos el puntero derecho a la izquierda
            derecha--;
        }
    }

    return false;
}





int main(){
    char cadena[]= "1, 2, 4, 7, 11";
    cout << cadena << "\n";                 //imprimo la cadena

    int k;
    cout << "Dea el numero 'k':: ";
    cin >> k;


    //NO CONVENIA USAR "char* numeros[60]" --> era mejor "int* numeros[60]"
    //
    //
    /*
    char* numeros[60];         //"60" por si alguien quiere crear una cadena con más numeros enteros (de una cifra)

    //
    int cantidad= detectaNumeros(&cadena[0], &numeros[0]);

    //
    bool hayOno= parNumeros(&numeros[0], cantidad, k);

    //
    cout << "\n\n";
    imprimir(hayOno, k);
    cout << "\n\n";
    */

    int numeros[60];

    // 1. Convertir la cadena de texto a un arreglo de enteros
    int cantidad= procesarCadena(cadena, &numeros[0]);

    // 2. Buscar la suma con eficiencia O(n)
    bool encontrado= encontrarSuma(&numeros[0], cantidad, k);

    if(encontrado){
        cout << "SI existen 2 numeros con suma: " << k << "\n";
    }else{
        cout << "NO existen 2 numeros con suma: " << k << "\n";
    }


    return 0;
}