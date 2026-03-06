#include <iostream>
#include "4ejer.h"
#include <cstring>
#include <string>
using namespace std;


//---1
void agregarCircular(Sensor* s[], int cantidadActual){
    double* posi= new double[2];
    posi[0]= 1.0;
    posi[0]= 2.1;
    SensorCircular sC= SensorCircular("12301", posi, 4.56);
    s[cantidadActual]= new SensorCircular(sC);
    //
    cantidadActual++;
    cout << "se agrego correctamente.\n";
}


//main
//
int main(){
    int decision;
    Sensor* s[50];
    int cantidadActual= 0;
    do{
        cout << "1. agregar SensorCircular.\n";
        cout << "2. agregar SensorRectangular.\n";
        cout << "3. mostrar todos los sensores.\n";
        cout << "4. area total de cobertura.\n";
        cout << "5. cuantos sensores detectan mi punto (x , y).\n";
        cout << "6. sensor con mayor area de cobertura.\n";
        cout << "7. salir.\n";
        cout << "--> --> Elija la opcion: ";
        cin >> decision;
        //
        switch(decision){
            case 1:{
                agregarCircular(s, cantidadActual);
            }
            case 2:{
                break;
            }
            case 3:{
                break;
            }
            case 4:{
                break;
            }
            case 5:{
                break;
            }
            case 6:{
                break;
            }
            case 7:{
                cout << "saliendo...\n";
                break;
            }
            default:{
                break;
            }
        }
        cout << "\n\n\n";
    }while(decision!= 7);



    //
    cout << "\n\n-------------END\n";
    return 0;
}