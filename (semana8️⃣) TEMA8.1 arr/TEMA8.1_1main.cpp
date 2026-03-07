//archivo de aplicación
#include <iostream>
#include "TEMA8.1_1vehiculo.h"
using namespace std;


int main(){
    //se instancia pero con PUNTEROS (así se usa para el polimorfismo)
    vehiculo* flota[3];
    flota[0]= new carro("ABC-123", "Toyota", 2024, 15000.50, 4);
    flota[1]= new camion("XYZ-987", "Volvo", 2022, 85000.00, 15.5);
    flota[2]= new moto("MTO-456", "Honda", 2025, 4500.00, 250);


    //llamando al método del objeto DINAMICAMENTE 
    for(int i=0; i<3; i++){
        //El programa decide en tiempo de ejecucion qué versión de mostrarInformacion() ejecutar
        flota[i]->mostrarInformacion();
        cout << "\n";
    }


    //liberando memoria
    for(int i=0; i<3; i++){
        delete flota[i];
    }


    //
    cout << "\n\n-------------END\n";
    return 0;
}