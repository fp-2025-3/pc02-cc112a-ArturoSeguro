#include <iostream>
using namespace std;



int main(){
    //4.1 libreación correcta__
    delete p;
    p= nullptr;             //este paso también se hace para variasbles normales

    //4.2 LÑiberación de arreglos__
    delete[] v;
    v= nullptr;

    //4.3 Errores críticos frecuentes
    //error1: olvidar liberar
    int* v= new int[100];           //no delete[]
    //detectable con Valgrind (como si fuerea el asan)


    //error2: usar delete en lugar de delete[]
    int* v= new int[10];
    delete v;       //error             //este error ya lo entendi con el pderoso GEMINI y sus explicaciones de nivel DIOS
    //este error no siempre FALLA, por eso es p'eligroso


    //error3: doble liberación
    int* p= new int;
    delete p;
    delete p;       //ERROR
    //Detectado por ASAN




    cout << "\n\n-------------\nEND";
    return 0;
}