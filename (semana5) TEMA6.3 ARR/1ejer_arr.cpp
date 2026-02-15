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


//--5
polinomio* multiplicar(polinomio** todos, int cantidad){
    if(cantidad== 0){
        return nullptr;
    }

    //creo una copia del 1er polinomio --> para comenzar a sumarle todas las operaciones uno por uno
    polinomio* resultadoAcumulado= new polinomio;
    (*resultadoAcumulado).grado= (*todos[0]).grado;
    (*resultadoAcumulado).coeficientes= new int [(*resultadoAcumulado).grado+ 1];

    //copiando todos los coeficientes del 1er polinomio a este nuevo
    for(int i=0; i<= (*resultadoAcumulado).grado; i++){
        (*resultadoAcumulado).coeficientes[i]= (*todos[0]).coeficientes[i];
    }

    //multiplicaciones UNO POR UNO --> por el 2do polino (k=1) --> luego por el 3er polino (k=2)
    for(int k=1; k<cantidad; k++){
        int gradoActual= (*resultadoAcumulado).grado;
        int gradoSiguiente= (*todos[k]).grado;
        int nuevoGrado= gradoActual+ gradoSiguiente;        //matemática algebraíca básica ((pero en el examen estas tan estresado que te olvidas))

        //polinomio temporal para guardar el producto de esta bucleActual (iteración)
        polinomio* temp= new polinomio;
        (*temp).grado= nuevoGrado;
        (*temp).coeficientes= new int[nuevoGrado+1];

        //denuevo la tecnica de llenarlo de "0" antes de hacerle cualquier cosa
        for(int i=0; i<=nuevoGrado; i++){
            (*temp).coeficientes[i]= 0;
        }

        //ahora sí la multiplicación entre los 2 polinomios que estan en este bucleActual (iteración)
        for(int i=0; i<= gradoActual; i++){
            for(int j=0; j<= gradoSiguiente; j++){
                //los indices i, j encajan perfecto --> aqui esta arreglado para que esos indices sean los "GRADOS" y justo en las multiplicaiones los grados se suman --> PERFECTO PARA BUCLES como estos
                (*temp).coeficientes[i+j]= (*temp).coeficientes[i+j]+
                (*resultadoAcumulado).coeficientes[i]* 
                (*todos[k]).coeficientes[j];
            }
        }

        //
        deleteCoeficientes(resultadoAcumulado);     //elimino la memoria dinámica de "resultadoAcumulado" que al principio era solo LO MISMO QUE EL 1ER POLINOMIO
        resultadoAcumulado= temp;                   //y le agrego la otra que se quedó con todo lo multiplicado
    }
    
    
    //
    return resultadoAcumulado;      //no es necesario DELETE memoria dinámica de "temp" porque la última vez que se pasa por el for se pasa su dirección hacia el "resultadoAcumulado"
    //en el main() --> "resultadoAcumulado" se pasa a "productoTotal" --> y el productoTotal sí lo tengo que eliminar(delte) DENTRO DEL MAIN
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


    //-5
    polinomio* productoTotal= multiplicar(PUNpolinomio, cantidad);
    cout << "\nProducto <-- Polinomio: ";
    imprimiendoPolinomio(productoTotal);


    //--4
    for(int i=0; i<cantidad; i++){  //de cada polinomio llenado en filling() --> eliminando su grado (new int) y sus coeficientes (new int[])
        deleteCoeficientes(PUNpolinomio[i]);
    }
    deleteCoeficientes(sumaTotal);  //de la función sumar() --3
    deleteCoeficientes(productoTotal); //de funcion multiplixar() --5
    delete[] PUNpolinomio;


    //
    cout << "\n\n-------------END\n";
    return 0;
}