#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

//struct
//
struct polinomio{
    int grado;
    int* coeficientes;           //el problema pedia que los coeficientes esten en un arreglo dinámico
};


                //--1
                //
                polinomio* filling(int grado){
                    //solo es un polinomio --> no una serie de "structs" por cada coeficiente
                    polinomio* p= new polinomio;
                    (*p).grado= grado;

                    //ahora el arreglo de todos los oceficientes (variable dinámica)
                    (*p).coeficientes= new int[grado+1];

                    //lo lleno como lo había hecho en el exam
                    for(int i=0; i<= grado; i++){
                        (*p).coeficientes[i]= (rand()%30)-5;
                    }

                    //
                    return p;        
                }


//--2
//
void imprimiendoPolinomio(polinomio* p){
    if(p== nullptr){
        return;
    }

    int grado_actual= (*p).grado;

    for(int i=0; i<=(*p).grado; i++){
        cout << (*p).coeficientes[i] << "x^" << grado_actual;

        //cuando sean iguales --> significa que será el último (x^0) --> Osea ya no necesito otro " + "
        if(i<(*p).grado){
            cout << " + ";
        }

        grado_actual--;
    }

    cout << "\n";
    return;
}


                //--3
                //
                polinomio* sumar(polinomio** todos, int cantidad){  //cantidad= 3 (en le main)
                    //encuentor el mayor grado de mis 3 polinomios
                    int gradoMayor= -1;
                    for(int i=0; i<cantidad; i++){
                        if(gradoMayor< (*todos[i]).grado){
                            gradoMayor= (*todos[i]).grado;
                        }
                    }

                    //Creando el polinomio, resultado de la suma de los 3
                    polinomio* resultado= new polinomio;
                    (*resultado).grado= gradoMayor;
                    (*resultado).coeficientes= new int[gradoMayor+1];

                    //PRIMERO, lo lleno todo de 0
                    for(int i=0; i<= gradoMayor; i++){
                        (*resultado).coeficientes[i]= 0;
                    }

                    //
                    for(int i=0; i<cantidad; i++){
                        //calculo el "alcance" para llenar el arreglo "resultado" correctamente dependiendo del grado de cada polinomio
                        int alcance =gradoMayor- (*todos[i]).grado;

                        //
                        for(int j=0; j<= (*todos[i]).grado; j++){
                            (*resultado).coeficientes[alcance+j]= 
                            (*resultado).coeficientes[alcance+j]+ (*todos[i]).coeficientes[j];
                        }
                    }


                    //
                    cout << "\n";
                    return resultado;
                }


//--4
//
void deleteCoeficientes(polinomio* p){
    if(p!= nullptr){
        delete[] (*p).coeficientes;
        delete p;       
    }

    return;
}


 




//--main--------------------------
//
//
//
int main(){
    srand(time(0));
    int cantidad= 3;
    polinomio** PUNpolinomio= new polinomio*[cantidad];


    //--1
    for(int i=0; i<cantidad; i++){
        cout << "\n\n";
        int gradoTEMP= rand()%4;
        PUNpolinomio[i]= filling(gradoTEMP);

        cout << "\n";
    }


    //--2
    for(int i=0; i<cantidad; i++){
        cout << i+1 << "<-- Polinomio: ";
        imprimiendoPolinomio(PUNpolinomio[i]);
    }


    //--3
    polinomio* sumaTotal= sumar(PUNpolinomio, cantidad);
    cout << "Suma <-- Polinomio: ";
    imprimiendoPolinomio(sumaTotal);


    //--4
    for(int i=0; i<cantidad; i++){  //de cada polinomio llenado en filling() --> eliminando su grado (new int) y sus coeficientes (new int[])
        deleteCoeficientes(PUNpolinomio[i]);
    }
    deleteCoeficientes(sumaTotal);  //de la función sumar() --3
    delete[] PUNpolinomio;


    //
    cout << "\n\n-------------END\n";
    return 0;
}