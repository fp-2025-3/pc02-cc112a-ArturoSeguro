#include <iostream>
using namespace std;


//función2
//
void imprimiendoPICOS(int* PindiceF, int* PindiceC, int cantidadPICOS){
    cout << "Elementos Picos:: \n";
    for(int i=0; i<cantidadPICOS; i++){
        cout << "Pico en (" << *(PindiceF+i) << "," << *(PindiceC+i) << ")";
        cout << "\n";
    }
}


//función3
//
void imprimiendoMATRIZ(int** Pmatriz){
    for(int i=0; i<4; i++){
        for(int j=0; j<5; j++){
            cout << *(*(Pmatriz+i)+j) << " ";
        }
        cout << "\n";
    }
}


//función4
//
int esPICO(int** Pmatriz, int* PindiceF, int* PindiceC){
    int sumadorF=0;
    int sumadorC=0;

    for(int i=0; i<4; i++){
        for(int j=0; j<5; j++){
            //
            int valorActual= *(*(Pmatriz+i)+j);
            bool cumpleMayorIgualTodos= true;
            bool cumpleEstrictoUno= false;

            //verificación de ARRIBA
            if(i-1>=0){
                int vecino= *(*(Pmatriz+i-1)+j);
                if(valorActual< vecino){
                    cumpleMayorIgualTodos = false;      //falla condición 1
                }
                if(valorActual> vecino){
                    cumpleEstrictoUno= true;            //cumple condición 2
                }
            }

            //verificación de ABAJO
            if(i+1<=3){
                int vecino = *(*(Pmatriz+i+1)+j);
                if(valorActual < vecino){
                    cumpleMayorIgualTodos = false;
                }
                if(valorActual > vecino){
                    cumpleEstrictoUno = true;
                }
            }

            //verificación de IZQUIERDA
            if(j-1>=0){         // aca había puesto "j-1<=0" y eso esun error
                int vecino = *(*(Pmatriz+i)+j-1);
                if(valorActual < vecino){
                    cumpleMayorIgualTodos = false;
                }
                if(valorActual > vecino){
                    cumpleEstrictoUno = true;
                }
            }

            //verificación de DERECHA
            if(j+1<=4){
                int vecino = *(*(Pmatriz+i)+j+1);
                if(valorActual < vecino){
                    cumpleMayorIgualTodos = false;
                }
                if(valorActual > vecino){
                    cumpleEstrictoUno = true;
                }
            }

            if(cumpleMayorIgualTodos == true && cumpleEstrictoUno == true){
                *(PindiceF+sumadorF)= i;
                sumadorF++;
                *(PindiceC+sumadorC)= j;
                sumadorC++; 
            }
        }
    }

    return sumadorF;
}


//main
//
int main(){
    const int F=4, C=5;
    int matriz[4][5]= { {3, 3, 3, 3, 3},
                        {3, 4, 4, 2, 3},
                        {3, 4, 5, 4, 3},
                        {3, 3, 3, 3, 3} };

    int* Pmatriz[4];
    for(int i=0; i<4; i++){
        Pmatriz[i]= matriz[i];
    }

    imprimiendoMATRIZ(Pmatriz);

    int indiceF[20]= {0};
    int* PindiceF= indiceF;
    int indiceC[20]= {0};
    int* PindiceC= indiceC;


    int cantidadPICOS= esPICO(Pmatriz, PindiceF, PindiceC);
    cout << "cantidad de PICOS: " << cantidadPICOS;
    cout << "\n\n";

    //imprimiendoPICOS
    imprimiendoPICOS(PindiceF, PindiceC, cantidadPICOS);


    return 0;
}