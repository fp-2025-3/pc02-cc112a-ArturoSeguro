#include <iostream>
#include <ctime>    
#include <cstdlib>
#include <string>               //Necesario para la identación visual
using namespace std;

//func3
double resultadoSegmento(int* B, int inicio, int fin){
//                                                                                                     
    double producto= 1;
    for(int i=inicio; i<=fin; i++){
        producto= producto*B[i];
    }

    return producto;
}



//function4
int maximoCostoB(int* B, int inicio, int n){
    //BASE
    if(inicio== n){
        return 0;
    }

    //
    //debo hacer que halle el máximo
    double maxCosto= -1;
    bool calculoPrime= true;


    for(int i=inicio; i<n; i++){
        double costoActual= resultadoSegmento(B, inicio, i);
        double costoResto= maximoCostoB(B, i+1, n);

        double costoTotal= costoActual+ costoResto;
        
        if(calculoPrime || costoTotal> maxCosto){
            maxCosto= costoTotal;
            calculoPrime= false;      
        }
    }

    return (int)maxCosto;               //quieor retornar un entero "(int)porsiaca"

}


//function4 --->--> para A[3]
int maximoCostoA(int* A, int inicio, int n, int nivel){


    //Visualización GEOMÉTRICA de las llamadas RECURSIVAS
    string indenta= "";
    for(int h=0; h<nivel; h++){
        indenta= indenta+ "\t|";    //aprovechando suma de strings
    }
    cout << indenta << "--> Entrando a funcion (posicion actual:  " << inicio << ")\n";


    //BASE
    if(inicio== n){
        cout << indenta << "<-- CASO BASE alcanzado. Retorna '0'\n";
        return 0;
    }


    //
    //debo hacer que halle el máximo
    double maxCosto= -1;
    bool calculoPrime= true;


    for(int i=inicio; i<n; i++){
        double costoActual= resultadoSegmento(A, inicio, i);
        double costoResto= maximoCostoA(A, i+1, n, nivel+1);

        double costoTotal= costoActual+ costoResto;
        
        if(calculoPrime || costoTotal> maxCosto){
            maxCosto= costoTotal;
            calculoPrime= false;      
        }
    }

    //
    cout << indenta << "<-- Saliendo de (posicion:  " << inicio << ") || Retorna maximo local:  " << maxCosto << "\n";
    return (int)maxCosto;

}







//main-------
//
//
//
int main(){

    //1--------------
    int B[15];                      //arreglo unidimensional de N numeros enteros posiitvos           
    int tamTotal= 5;      

    //
    srand(time(0));

    //
    cout << "Arreglo generado:: \n";
    for(int i=0; i<tamTotal; i++){
        B[i]= (rand()%15)+1;   //de (1-15)
        cout << B[i] << " ";
    }
    cout << "\n";
    //2----------------
    int costoMax= maximoCostoB(&B[0], 0, tamTotal);   
    cout << "\nEl costo maximo es:: " << costoMax;




    //para el Arreglo del problema  
    cout << "\n\n\n";
    cout << "para el problema de b):: \n";
    int A[3]={2, 1, 3};
    costoMax= maximoCostoA(&A[0], 0, 3, 0);         //Decidi empezar desde el nivel 0
    cout << "\nEl costo maximo es:: " << costoMax;


    //
    cout << "\n\n-------------END\n";
    return 0;
}
