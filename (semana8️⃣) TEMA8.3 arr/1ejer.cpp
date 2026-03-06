#include <iostream>
#include <fstream>
#include <cstring>
#include <string>
using namespace std;


//---1
int** crearMatriz(int n, int m){
    int** gestorFila= new int*[n];
    for(int i=0; i<n; i++){
        gestorFila[i]=  new int[m];
    }
    return gestorFila;
}


//---2
void llenarMatriz(int** M, int n, int m){
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            M[i][j]= (i+1)*(j+1);
        }
    }
}


//---3
int* sumaFilas(int** M, int n, int m){
    int* sumaFila= new int[n];
    //
    for(int i=0; i<n; i++){
        sumaFila[i]= 0;     //inicio con 0
        for(int j=0; j<m; j++){
            sumaFila[i]+= M[i][j]; 
        }
    }
    return sumaFila;
}


//---4delete
void liberarMatriz(int** M, int n){
    for(int i=0; i<n; i++){
        delete[] M[i];
    } 
    delete[] M;
}


//main
//
int main(){
    //---1
    int m;
    cout << "digite el valor de 'm': ";
    cin >> m;
    int n;
    cout << "digite el valor de 'n': ";
    cin >> n;
    int** M= crearMatriz(n, m);
    //---2
    llenarMatriz(M, n, m);
    //---3
    int* sumaFila= sumaFilas(M, n, m);
    for(int i=0; i<n; i++){
        cout << "suma de fila '" << i+1 << "' es: " << sumaFila[i] << "\n";
    }
    //---4
    liberarMatriz(M, n);


    //eliminando el arreglo de sumaFilas
    delete[] sumaFila;


    //
    cout << "\n\n-------------END\n";
    return 0;
}