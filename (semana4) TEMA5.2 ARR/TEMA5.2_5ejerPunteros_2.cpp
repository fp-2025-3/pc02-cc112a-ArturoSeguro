#include <iostream>
using namespace std;




//1. ImprimirMatriz
void imprimir(int (*M)[5]){
    for(int i=0; i<5; i++){
        for(int j=0; j<5; j++){
            cout << *(M[i]+j) << "\t";
        }
        cout << "\n";
    }
}


//2. Dominante
bool esFilaDominante(int (*M)[5], int fila){
    for(int i=0; i<5; i++){
        for(int j=0; j<5; j++){
            bool condicion= (*(M[fila]+j)<= *(M[i]+j) && fila!= i);     //si detecta que el supuesto dominante no lo es, entra al if() y retorna "flase"
            if(condicion){
                return false;
            }
        }
    }

    return true;        //si llego hasta aca, es porque cumplio todas las condiciones
}




//function3



//function4



//function5



//function6







//main
//
int main(){
    const int N= 5;
    int M[N][N] = {
        {1, 2, 3, 4, 5},
        {10, 20, 30, 40, 50},
        {1, 1, 1, 1, 1},
        {5, 5, 5, 5, 5},
        {0, 0, 0, 0, 0}
    };
    //1.Matriz (1era impresion)
    imprimir(M);

    
    //2.Dominante
    int fila;
    cout << "elija el indice de la fila (0-4) que crea que es dominante:: ";
    cin >> fila;
    //
    bool respuesta= esFilaDominante(M, 3);  //(ERROR1) --> con esa notación de la función, puedo pasar directamente la matriz bidimensional y en la función trabajar con aritmética de punteros
    if(respuesta){
        cout << "Correcto, esa SI es una fila dominante.\n";
    }else{
        cout << "NOOO es una fila dominante.\n";
    }




    //function1



    //function2



    //function3



    //function4



    //function5



    //function6

    

    //
    cout << "\n\n-------------END\n";
    return 0;
}