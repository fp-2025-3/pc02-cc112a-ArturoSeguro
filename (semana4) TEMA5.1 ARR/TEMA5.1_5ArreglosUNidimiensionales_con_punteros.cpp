#include <iostream>
using namespace std;


//5.1 Paso de arreglos dinámicos a funciones
void llenar(int*& v, int n){
    for(int i=0; i<n; i++){
        *(v+i)= i*i;
    }
} 
//el arreglo no se copia, se pasa la dirección


int main(){ 

    //5.2 Error frecuente : perder la referencia
    int* v= new int[10];
    v= new int[20] //fuga de memoria -->--> // (Aqui le estoy metiendo)otro arreglo dinamico sin borrar el anterior, si lo ejo así comeinzo a acumular la RAM con velores que ya no usaré

    //correción
    delete[] v;
    v= new int[20];

    




    cout << "\n\n-------------\nEND";
    return 0;
}