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
            int alMENOSuno=0;   //para verificar
            if(i-1>=0){
                if(*(*(Pmatriz+i)+j)>*(*(Pmatriz+i-1)+j)){
                    alMENOSuno++;
                }
                
            }
            if(i+1<=3){
                if(*(*(Pmatriz+i)+j)>*(*(Pmatriz+i+1)+j)){
                    alMENOSuno++;
                }
            }
            //
            if(j-1<=0){
                if(*(*(Pmatriz+i)+j)>*(*(Pmatriz+i)+j-1)){
                    alMENOSuno++;
                }
            }
            if(j+1<=4){
                if(*(*(Pmatriz+i)+j)>*(*(Pmatriz+i)+j+1)){
                    alMENOSuno++;
                }
            }

            if(alMENOSuno != 0){
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