#include <iostream>
#include <ctime>        //time(0)
#include <cstdlib>      //srand()   
using namespace std;

//function1 --> condición(1)
bool alMenosUno(un puntero al inicio del arrayOriginal, un indice de inicio, un indice de final){  //no es necesario crear un SubArray, como si fuera un MergeSort, puedo moverme por la función original con puros punteros

}




//function2 --> operación(2) --> resultado de cada segmento
int resultadoSegmento(un puntero al inicio del arrayOrignial, un indice de inicio, un indice de final){ //como lo usaré recursivamente, pues el inicio y final cmabiarán en diversos casos
//                                                                                                       La eficiencia del programa dependerá del tipo de condiciones que le agregue:: el arbol/ramificación producto de la recursividad debe ser lo más eficiente posíble
}





//function3 --> operación(3) --> resultado de costo total (sumando todas los valores de segmento)
int costoTotal(un array de punteros que contenga todos los inicios de los segmentos creados, un puntero al inicio del array que contenga las longitudes de cada Segmento que forme){

}





//function4 --> función recursica(4) --> aplicará de manera adecuada y con condiciones adecuadas las anteriores funciones 
int exploradorDePosibilidades(un puntero al inicio del arrayOriginal, un indice de inicio, un indice de final){

}









//main---------------------------------------
//
//
//
int main(){
    //1. creando arreglo A
    int A[15];
    srand(time(0));

    for(int i=0; i<15; i++){
        A[i]= (rand()%20)-2;   //de (-2 a 17) --> (los negativos harán el ejercicio más interesante)
    }



    //2. LLamo a "function4" (el cual llama a las demás convenientemente) y deteermino la solución
    int costoMinimoPosible= exploradorDePosibilidades(&A[0], 0, 14);
    cout << "El costo minimo posible es:: " << costoMinimoPosible;



    //
    cout << "\n\n-------------END\n";
    return 0;
}