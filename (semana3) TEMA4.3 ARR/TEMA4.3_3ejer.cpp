#include <iostream>
#include <cctype>
#include <cstring>
#include <cstdlib>
#include <ctime>
using namespace std;

//quiero rellenar cada fila de la matriz con los numeros 1-9
//luego pedir un numero y de esa columna seleccionada poner toda la columna con el valor de ese mismo numero

//function 2
void desordenador(int* PUNindices){
    int medio=9/2;

    for(int i=0; i<9; i++){
        if(rand()%2== 0){
            swap( *(PUNindices+i), *(PUNindices+8-i));
        }else{
            if( *(PUNindices+medio)>= 5){
                swap( *(PUNindices+medio), *(PUNindices+8-i));
            }else{
                swap( *(PUNindices+medio), *(PUNindices+8+i));
            }
        }
    }
}



//function 1
void rellenadorFilas(int* PUNmatriz[9]){
    int numeros[]= {1, 2, 3, 4, 5, 6, 7, 8, 9};

    int indices[9]= {0, 1, 2, 3, 4, 5, 6, 7, 8};
    int* PUNindices= &indices[0];

    desordenador(PUNindices);
    for(int i=0; i<9; i++){
        int indiceActual= *(PUNindices+i);       //estos indices vienen de indices[9]
        swap( numeros[i], numeros[indiceActual]);       //Solo cambio de orden

        //ahora lo relleno desordenado
        for(int j=0; j<9; j++){
            *(PUNmatriz[i]+j)= numeros[j];
        }
    }


}


//function 3
void imprimirMatriz(int* PUNmatriz[9]){
    for(int i=0; i<9; i++){
        for(int j=0; j<9; j++){
            cout << *(PUNmatriz[i]+j) << " ";
        }

        cout << "\n";
    }
}




//function 4



//function 5






int main(){
    srand(time(0));

    //pongo los elelmetnos del arreglo d puinteros en cada inicio de fila de matriz
    int matriz[9][9]= {-1};
    int* PUNmatriz[9];
    for(int i=0; i<9; i++){
        PUNmatriz[9]= &matriz[i][0];
    }

    //
    rellenadorFilas(PUNmatriz);

    //
    imprimirMatriz(PUNmatriz);

    //
    cout << "\n";
    int f;
    cout << "Fila inicial:: ";
    cin >> f;

    cout << "\n";
    int c;
    cout << "Columna inicial:: ";
    cin >> c;

    //
    cout << "valor seleccionado:: " << *(PUNmatriz[f-1]+c-1);



    return 0;
}