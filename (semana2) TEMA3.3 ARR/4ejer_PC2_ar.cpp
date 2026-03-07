#include <iostream>
using namespace std;


//función3
//
int sumaMAXIMA(int** Pmatriz, int &Ax, int &Ay, int &Bx, int &By){
    int acumuladorSUMA=0;
    for(int i=Ay; i<=By; i++){
        for(int j=Ax; j<=Bx; j++){
            acumuladorSUMA= acumuladorSUMA+ *(*(Pmatriz+i)+j);
        }
    }

    return acumuladorSUMA;
}

//función4
void imprimiendoMATRIZ(int** Pmatriz){
    for(int i=0; i<4; i++){
        for(int j=0; j<5; j++){
            cout << *(*(Pmatriz+i)+j) << " ";
        }
        cout << "\n";
    }
}



//main
//
int main(){
    //
    const int F=4, C=5;
    int matriz[F][C]= { {3, 3, -3, 3, 3},
                        {3, -4, 4, 2, 3},
                        {3, -4, 5, 4, 3},
                        {3, 3, -3, -3, -3} };

    int* Pmatriz[F];
    for(int i=0; i<F; i++){
        Pmatriz[i]= matriz[i];
    }



    //
    int maxSuma= -999;                  //este será mi valor inicial de "submatriz de suma máxima"
    int mejorAx= 0, mejorAy= 0;
    int mejorBx= 0, mejorBy= 0;

    for(int y1 = 0; y1 < F; y1++){          //Mis coordenadas "y" estan relacionados con la FILA
        for(int x1 = 0; x1 < C; x1++){      //Mis coordenadas "X" estan relacionados con la COLUMNA --> esos "2" serán importantes para imprimir coordenadas de forma correcta

            for(int y2 = y1; y2 < F; y2++){       
                for(int x2 = x1; x2 < C; x2++){
                    //
                    int sumaActual= sumaMAXIMA(Pmatriz, x1, y1, x2, y2);

                    //
                    if(sumaActual > maxSuma){
                        maxSuma= sumaActual;

                        mejorAx =x1; mejorAy= y1;
                        mejorBx= x2; mejorBy= y2;
                    }
                }
            }
        }
    }


    //Imprimiendo resultados
    imprimiendoMATRIZ(Pmatriz);

    cout << "SubMatriz de una maxima: " << endl;
    cout << "Esquina superiorIZQUIERDA: (" << mejorAy << "," << mejorAx << ")" << endl;
    cout << "Esquina inferiorDERECHA: (" << mejorBy << "," << mejorBx << ")" << endl;
    cout << "Suma maxima: " << maxSuma << endl;

    //
    return 0;
}
