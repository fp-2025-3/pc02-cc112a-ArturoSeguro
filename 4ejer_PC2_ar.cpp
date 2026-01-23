#include <iostream>
using namespace std;


//función1
//



//función2
//



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
//
void calculoMATRIZ(int** Pmatriz, int &Ax, int &Ay, int &Bx, int &By){
    int OizX, OizY;     //"O" de oficial
    int OdeX, OdeY;

    //coordenadas X correctas de esquinas oficiales
    if(Ax== Bx){
        OizX= Ax;
        OdeX= Ax;
        if(Ay< By){
            OizY= Ay;       //perfecto
            OdeY= By;
        }else{
            OizY= By;       //perfecto
            OdeY= Ay;
        }

    }else if(Ax< Bx){
        OizX= Ax;       //perfecto
        OdeX= Bx;
        if(Ay< By){
            OizY= Ay;       //perfecto
            OdeY= By;
        }else{
            OizY= By;       //perfecto
            OdeY= Ay;
        }

    }else if(Ax> Bx){
        OizX= Bx;       //perfecto
        OdeX= Ax;
        if(Ay< By){
            OizY= Ay;       //perfecto
            OdeY= By;
        }else{
            OizY= By;       //perfecto
            OdeY= Ay;
        }
    }

    //Ahora imprimo resultados
    cout << "Esquina superior izquierda: " << "(" << OizX << "," << OizY << ")";
    cout << "\nEsquina inferior derecha: " << "(" << OdeX << "," << OdeY << ")";
    cout << "\n\n";

    Ax= OizX;
    Ay= OizY;
    Bx= OdeX;
    By= OdeY;
}


//main
//
int main(){
    const int F=4, C=5;
    int matriz[F][C]= { {3, 3, 3, 3, 3},
                        {3, 4, 4, 2, 3},
                        {3, 4, 5, 4, 3},
                        {3, 3, 3, 3, 3} };

    int* Pmatriz[F];
    for(int i=0; i<F; i++){
        Pmatriz[i]= matriz[i];
    }


    int Ax, Ay;
    int Bx, By;

    cout << "COORDENADAindice DE A 'X' :: ";
    cin >> Ax;
    cout << "COORDENADAindice DE A 'Y' :: ";
    cin >> Ay;

    cout << "COORDENADAindice DE B 'X' :: ";
    cin >> Bx;
    cout << "COORDENADAindice DE B 'Y' :: ";
    cin >> By;


    //imprimiendo resultados
    calculoMATRIZ(Pmatriz, Ax, Ay, Bx, By);

    cout << "Suma máxima: " << sumaMAXIMA(Pmatriz, Ax, Ay, Bx, By);

    return 0;
}