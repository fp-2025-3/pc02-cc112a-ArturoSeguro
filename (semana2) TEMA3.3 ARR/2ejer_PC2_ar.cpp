#include <iostream>
using namespace std;


//función1
//
int* buscar(int* inicio, int* fin, bool (*equivale)(int, int), int clave){
    for(int* p= inicio; p<fin; p++){
        if(equivale(*p, clave)){
            return p;       //retorna dirección d cumple condición
        }
    }

    return nullptr;         //no se encontró nada
}



//función2
//
bool igual(int a, int b){
    return a== b;
}


//función3
//
bool mismaParidad(int a, int b){
    return (a%2)== (b%2);
}



//main
//
int main(){
    int arr[]= {1, 3, 5, 8, 10};
    
    // "inicio" apunto al "1" y "fin" "imediado poesterior al 10" (osea uno más después del 10)
    int* inicio= arr;
    int* fin= arr+ 5;       //seria lo mismo escribir "int* fin= &arr[0]+5"

    //
    int* res1= buscar(inicio, fin, &igual, 8);   //se declara como un puntero porque la funcio "buscar()" esta prototipada para devolver una variable de tipo puntero --> por eso es compatible igualarlo en este declaración
    int* res2= buscar(inicio, fin, &mismaParidad, 3);
    //lo correcto es pasar a las funciones como dirreciones, ya que en los prototipos de función se les declara como punteeros:: "&mismaParidad" y "&igual" ((los punteros y referencias son compatibles:: del mismo tipo))

    //
    if(res1){           //"res1", a pesar de un puntero, decae a "true" si se retorna un valor valido --> decae a "false" si se reforna nullptr
        cout << "Se encontro la igualdad: " << *res1 << "\n";  
        //debería retornar "8"
    }
    if(res2){
        cout << "Se encontro el numero de misma paridad: " << *res2 << "\n";
        //Debería retornar "1" porque 3 es impar
    }

    //
    return 0;
}
