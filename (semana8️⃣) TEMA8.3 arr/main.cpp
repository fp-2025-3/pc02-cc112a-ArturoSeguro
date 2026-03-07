#include <iostream>
#include "4ejer.h"
#include <cstring>
#include <string>
using namespace std;

 
//main
//
int main(){
    int decision;
    SistemaSensores sistema;
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
                string id; double x, y, r;
                cout << "ID: "; cin >> id;
                cout << "Posicion X: "; cin >> x;
                cout << "Posicion Y: "; cin >> y;
                cout << "Radio: "; cin >> r;
                double p[2] = {x, y};
                sistema.agregarSensor(new SensorCircular(id, p, r));
                cout << "Agregado correctamente.\n";
                break;
            }
            case 2:{
                string id; double x, y, an, al;
                cout << "ID: "; cin >> id;
                cout << "Posicion X: "; cin >> x;
                cout << "Posicion Y: "; cin >> y;
                cout << "Ancho: "; cin >> an;
                cout << "Alto: "; cin >> al;
                double p[2] = {x, y};
                sistema.agregarSensor(new SensorRectangular(id, p, an, al));
                cout << "Agregado correctamente.\n";
                break;
            }
            case 3:{
                cout << "\n=== TODOS LOS SENSORES ===\n";
                sistema.mostrarSensores();
                break;
            }
            case 4:{
                cout << "Area Total: " << sistema.areaTotalCobertura() << "\n";
                break;
            }
            case 5:{
                double x, y;
                cout << "Punto X a evaluar: "; cin >> x;
                cout << "Punto Y a evaluar: "; cin >> y;
                cout << "'" << sistema.sensoresQueDetectan(x, y) << "' sensor(es) detectan el punto.\n";
                break;
            }
            case 6:{
                Sensor* mayor = sistema.sensorMayorCobertura();
                if(mayor){
                    cout << "Sensor con mayor cobertura:\n";
                    mayor->imprimir();
                }
                break;
            }
            case 7:{
                cout << "saliendo...\n";
                break;
            }
            default:{
                cout << "opcion invalida.\n";
                break;
            }
        }
        cout << "\n\n\n";
    }while(decision!= 7);
    

    //
    cout << "\n\n-------------END\n";
    return 0;
}