#include <iostream>
using namespace std;



int main(){
    //********1.    ARREGLOS ESTÁTICOS .VS.VS. ARREGLOS DINÁMICOS
    //********1.1.  ARREGLOS ESTÁTICOS
    int a[100];
    ////    CARACTERÍSTICAS
    //. Tamaño fijo en tiempo de compilación
    //. Se almacenan en el stack
    //. Se destruyen automáticamente al salir del bloque
    ////    PROBLEMAS REALES
    //. Desperdicio de memoria
    //. Riesgo de stack overflow
    //. No escalables




    //********1.2.  ARREGLOS DINÁMICOS
    int* a= new int[100];
    ////    CARACTERÍSTICAS
    //. Tamaño decidido en tiempo de ejecución
    //. Memoria en el heap
    //. Vida controlada explicitamente por el programador
    //  ((con memoria dinámica, el poder viene con responsabilidad))




    cout << "\n\n-------------\nEND";
    return 0;
}




//make TEMA5.1_1AhoraSíCOMENZAMOS
//./TEMA5.1_1AhoraSíCOMENZAMOS