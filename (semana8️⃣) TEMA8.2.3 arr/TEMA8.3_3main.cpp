#include <iostream>
#include "TEMA8.3_3ejer_lab8.h"
#include <cstring>
#include <string>
#include <ctime>
#include <cstdlib>
using namespace std;


//---0
void RGBalea(double*& cRGB){    //los punteros tambien se deben pasar por referencia
    cRGB= new double[3];
    cRGB[0]= rand()%101;
    cRGB[1]= rand()%101;
    cRGB[2]= rand()%101;
}


//main
//
int main(){ 
    srand(time(0));
    //---0
    double* RGB[3];
    for(int i=0; i<3; i++){
        RGBalea(RGB[i]);
    }
    figura* f[3];
    //---1,2
    f[0]= new circulo("anillo", RGB[0], 7.1);
    f[1]= new rectangulo("terreno", RGB[1], 2.1, 4.5);
    f[2]= new circulo("anillo", RGB[2], 6.9);
    //
    f[0]->imprimir();
    cout << "\n";
    f[1]->imprimir();
    cout << "\n";


    //---3
    gestor g(3);    //correcta inicializacion de gestor
    //
    g.agregarFigura(f[0]);
    g.agregarFigura(f[1]);
    g.agregarFigura(f[2]);
    //
    g.mostrarTodo();
    cout << "\n";
    //
    g.areaTotal();
    cout << "\n";
    //
    g.guardarArchivo("TEMA8.3_3figuras.txt");
    

    //delete
    for(int i=0; i<3; i++){
        delete[] RGB[i];
        delete f[i];
    }


    //
    cout << "\n\n-------------END\n";
    return 0;
}