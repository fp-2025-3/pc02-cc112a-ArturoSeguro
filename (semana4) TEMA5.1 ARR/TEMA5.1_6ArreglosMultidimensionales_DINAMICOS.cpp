#include <iostream>
using namespace std;



int main(){
    //6.1 Matriz como puntero a punteros
    int filas= 3, columnas= 4;

    int** M= new int*[filas];
    for(int i=0; i<filas; i++){
        M[i]= new int[columnas];
    }

    //QUé sucedio?
    //i) cree un arreglo de punteros en el heap
    //ii)luego aparte "con ayuda de for()" CREE OTROS 3 arreglos (dinámicos) que se conectan con el arrelgo de punteros del iniciop "i)"

    //6.2 Un paso IMPORTANTÍSIMO es eliminarlos luego de usarlos,, en esrte caso se hace de manera INVERSA --> como si fuera RECURSIVIDAD
    for(int i=0; i<filas; i++){
        delete[] M[i];      //borra cada fila de interos
    }
    delete[] M;



    //error frecuente : liberar solo M
    delete[] M;         //fuga masiva -->-->--> dejo un monton de valores sin eliminar, caumulados en mi mi RAM ((tengo qe ser responsables y eliminarlos))


    //6.3 Error frecuente: indices fuera de rango
    M[3][0]= 10;    //fuga de limites
    //Detectado por Asan

    //Es totalmente correcto llamar a "M[][]", porque es un doble puntero y esa notación es correcta --> al igual que *(*(M+3)+0)

    cout << "\n\n-------------\nEND";
    return 0;
}