#include <iostream>
#include <ctime>
#include <cstdlib>
using namespace std;


// 
void imprimir(int (*M)[5]){
    for(int i=0; i<5; i++){
        for(int j=0; j<5; j++){
            cout << *(M[i]+j) << "\t";
        }
        cout << "\n";
    }
}


//
int esFilaDominanteEstricta(int (*M)[5], int fila){
    int respuesta=1;    //si no se modifica hasta el final pues cumple todo perfecto (100% estricta)


    for(int i=0; i<5; i++){
        for(int j=0; j<5; j++){
            bool condicion2= (*(M[fila]+j)== *(M[i]+j) && fila!= i);    
            //puede ser igual. Entra al if() solo si es mayor estricto
            if(condicion2){
                respuesta= 0;      //(0) queda como no estricta 
            }
        }
    }

    for(int i=0; i<5; i++){
        for(int j=0; j<5; j++){
            bool condicion1= (*(M[fila]+j)< *(M[i]+j) && fila!= i);    
            //puede ser igual. Entra al if() solo si es mayor estricto
            if(condicion1){
                respuesta= -1;      //(-1) queda como que no cumple
            }
        }
    }
    return respuesta;     
}




//function3










//main
//
int main(){
    srand(time(0));

    const int N= 5;
    int M[N][N] = {0};
    for(int i=0; i<5; i++){
        for(int j=0; j<5; j++){
            M[i][j]= (rand()%9)+1;
        }
    }
    //1--Mi MATRIZ
    imprimir(M);

    
    //2--
    int fila;
    cout << "elija el indice de la fila (0-4) que crea que es dominante:: ";
    cin >> fila;
    //
    int respuesta= esFilaDominanteEstricta(M, 3);
    if(respuesta== 1){
        cout << "Correcto, esa SI es una fila EStrictamente dominante.\n";
    }else if(respuesta== 0){
        cout << "Solo es una fila dominante.\n";
    }else if(respuesta== -1){
        cout << "NO es fiña dominante.\n";
    }




    //function1



    //function2

    

    //
    cout << "\n\n-------------END\n";
    return 0;
}