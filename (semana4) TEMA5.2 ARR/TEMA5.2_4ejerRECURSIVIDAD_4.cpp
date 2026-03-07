#include <iostream>
#include <ctime>        //time(0)
#include <cstdlib>      //srand()   
using namespace std;

//function1 --> condición(1)
//bool alMenosUno(un puntero al inicio del arrayOriginal, un indice de inicio, un indice de final){  //no es necesario crear un SubArray, como si fuera un MergeSort, puedo moverme por la función original con puros punteros
//
//}
//No es necesario, se configura en el mismo "exploradorDePosibilidades()"




//function2 --> operación(2) --> resultado de cada segmento
long long resultadoSegmento(int* A, int inicio, int fin){ //como lo usaré recursivamente, pues el inicio y final cmabiarán en diversos casos
//                                                                                                       La eficiencia del programa dependerá del tipo de condiciones que le agregue:: el arbol/ramificación producto de la recursividad debe ser lo más eficiente posíble
    long long producto= 1;
    for(int i=inicio; i<=fin; i++){
        producto= producto*A[i];
    }

    return producto;
}





//function3 --> operación(3) --> resultado de costo total (sumando todas los valores de segmento)
//int costoTotal(un array de punteros que contenga todos los inicios de los segmentos creados, un puntero al inicio del array que contenga las longitudes de cada Segmento que forme){
//
//}
//TAMPOCO es necesario, se hace dentro de "exploradorDePosibilidades()"




//function4 --> función recursica(4) --> aplicará de manera adecuada y con condiciones adecuadas las anteriores funciones 
int exploradorDePosibilidades(int* A, int inicio, int n){
    //CASO BASE: pasando el último indice
    if(inicio== n){
        return 0;
    }

    long long minCosto= -1;     //el "-1" significa que aún no calculé el costoMínimo
    bool esElPrimerCalculo= true;


    // Exploramos todos los posibles puntos de corte "i"
    // Desde donde estamos (inicio) hasta el final del arrelgo (n-1)
    for(int i=inicio; i<n; i++){
        //1. Costo del segemento actual (producto)
        long long costoActual= resultadoSegmento(A, inicio, i);

        //2. Costo del resto del arreglo (llamada recursiva)
        long long costoResto= exploradorDePosibilidades(A, i+1, n);

        //3. Costo total de esta combinación
        long long costoTotal= costoActual+ costoResto;

        //4. Lógica para encontrar el Mínimo (manual)
        //Si es la primera vez que calculamos (esElPrimerCalculo) O sí encontramos un costo meno::
        if(esElPrimerCalculo || costoTotal< minCosto){
            minCosto= costoTotal;
            esElPrimerCalculo= false;       //para la primera vez que se pasa por aqui, será por el "true" del comienzo, entonces me aseguraré que todos los siguientes no ses así
        }
    }

    return minCosto;

}









//main---------------------------------------
//
//
//
int main(){
    srand(time(0));

    //1. creando arreglo A
    int A[15];                  //máximo 15
    int tamTotal= 5;            //manualmente --> se podría hacer otro proceso apra pedir los numeros (por ahora no)

    cout << "Arreglo generado:: \n";
    for(int i=0; i<tamTotal; i++){
        A[i]= (rand()%5)+1;   //de (0-20) --> (los negativos lo complican demasiado, pero no es imposible)
        cout << A[i] << " ";
    }
    cout << "\n";


    //2. LLamo a "function4" (el cual llama a las demás convenientemente) y deteermino la solución
    int costoMinimoPosible= exploradorDePosibilidades(&A[0], 0, tamTotal);       //comienzo poniendo al "0"
    cout << "\n\nEl costo minimo posible es:: " << costoMinimoPosible;



    //
    cout << "\n\n-------------END\n";
    return 0;
}
