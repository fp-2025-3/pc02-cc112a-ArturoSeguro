#include <iostream>
#include <cctype>
#include <cstring>
#include <cstdlib>
#include <ctime>
using namespace std;

//quiero rellenar cada fila de la matriz con los numeros 1-9
//luego pedir un numero y de esa columna seleccionada poner toda la columna con el valor de ese mismo numero




/*
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
*/
//
//
//-->-->Ya había practicado este ejercicio antes, pero me dí cuenta que los punteros no los usé de manera adecuada, aquí traté de hacer algo nuevo sin mucho exito



//función 0
//
//
void imprimirMatriz(int* PUNmatriz[9]){
    cout << "----------------------------\n";       //para que se vea bonito
    for(int i=0; i<9; i++){
        for(int j=0; j<9; j++){
            cout << *(PUNmatriz[i]+ j) << " ";
        }
        cout << "\n";
    }
    cout << "----------------------------\n";
}



//función 1
//
//
void generarMatriz(int* PUNmatriz[9]){
    // 1. Fila original
    int base[9]= {1, 2, 3, 4, 5, 6, 7, 8, 9};

    // 2. Rellenar l amatriz fila por fila
    for(int i=0; i<9; i++){
        //Desorndedamiento por método ALGORITMO FISHER-YATES SIMPLE (el que usted mencionó profesor)
        for(int i=8; i>0; i--){
            int j= rand()% (i+1);       //"wow" era mucho más simple de lo que me hubiera imaginado
            swap(base[i], base[j]);
        }

        for(int j=0; j<9; j++){
            *(PUNmatriz[i]+j)= base[j];
        }
    }
}



//función 2.5
//
//
int buscarPosicion(int* fila, int valorBusqueda){
    for(int j=0; j<9; j++){
        if(*(fila+ j)== valorBusqueda){
            return j;           //retorna el índice (0-8)
        }
    }

    return -1;      //si es que no encuentra nada (no debería suceder)
}





//función 2
//
//
void desplazarFilas(int* PUNmatriz[9], int valorObjetivo, int colObjetivo){
    int indiceMeta= colObjetivo-1;

    for(int i=0; i<9; i++){
        //i) encontrar donde está el número en esta fila
        int* filaActual= PUNmatriz[i];
        int posActual= buscarPosicion(filaActual, valorObjetivo);

        //ii) Calcular cuánto hay que desplazar 
        //se desea mover lo de "posActual" --> "indiceMeta"  -->--> MOVIENDO TODOS los elementos al mismo tiempo
        int desplazamiento= indiceMeta- posActual;

        //arreglo temporal (si tratara de hacerlo en la misma fila de la matriz crearía muchos problemas)
        int filaTemp[9];

        for(int j=0; j<9; j++){
            //Lógica de rotación circular
            int nuevoLugar= j+ desplazamiento;

            //Ajustar si se sale de los bordes (circular) -->-->--> Esto no me había dado cuenta
            if(nuevoLugar>= 9){
                nuevoLugar= nuevoLugar-9;
            }
            if(nuevoLugar< 0){
                nuevoLugar= nuevoLugar+9;
            }

            filaTemp[nuevoLugar]= *(filaActual+j);  // recordando que "filaActual= PUNmatriz[i]""
        }

        //iii) Ahora sí modificaré a la matriz original
        for(int j=0; j<9; j++){
            *(filaActual+j)= filaTemp[j];
        }

    }
}




int main(){
    /*
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
    */
    srand(time(0));

    //Matriz estática
    int matriz[9][9]= {-1}; //lo lleno de "-1" porsiaca para darme cuenta de errores

    //Arreglo de pnuteros (Doble puntero simulado)
    int* PUNmatriz[9];
    for (int i = 0; i < 9; i++) {
        PUNmatriz[i] = &matriz[i][0]; // Usamos 'i', no '9'
    }

    // 1. Generar
    cout << "Generando matriz inicial...\n";
    generarMatriz(PUNmatriz);
    imprimirMatriz(PUNmatriz);

    // 2. Solicitar datos
    int f, c;
    cout << "Fila inicial (1-9): ";
    cin >> f;
    cout << "Columna inicial (1-9): ";
    cin >> c;

    //valor seleccionado
    int valorSeleccionado= *(PUNmatriz[f-1]+ (c-1));

    cout << "\nValor seleccionado en (" << f << "," << c << ") es:: " << valorSeleccionado << "\n";
    cout << "Reordenando para que toda la columna '" << c << "' tenga el valor::: " << valorSeleccionado << "\n";

    
    // 3. Modificar matriz
    desplazarFilas(PUNmatriz, valorSeleccionado, c);

    // 4. Mostrar resultado
    cout << "\nMatriz Final:\n";
    imprimirMatriz(PUNmatriz);

    return 0;
}