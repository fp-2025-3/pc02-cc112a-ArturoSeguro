//archivo de implementación
#include <iostream>
#include "TEMA8.1_1vehiculo.h"
using namespace std;

//---0
//a.1
vehiculo:: vehiculo(string p, string m, int y, double pre){
    placa= p;
    marca= m;
    year= y;
    precio= pre;
}
//a.2
vehiculo:: ~vehiculo(){
    cout << "Destruyendo 'vehiculo'\n";
}
//b
void vehiculo:: mostrarInformacion(){
    cout << "Marca: " << marca << "\n";
    cout << "Placa: " << placa << "\n";
    cout << "Year: " << year << "\n";
    cout << "Precio: " << precio << "\n";
}


//---1
//a.1
carro:: carro(string p, string m, int y, double pre, int nP)
: vehiculo(p, m, y, pre){
    numPuertas= nP;
}
//a.2
carro:: ~carro(){
    cout << "Destruyendo 'carro'\n";
}
//b
void carro:: mostrarInformacion(){
    cout << "=== Datos de CARRO ===\n";
    vehiculo::mostrarInformacion();
    cout << "numeroPuertas: " << numPuertas << "\n";
}


//---2
//a.1
camion:: camion(string p, string m, int y, double pre, double cC)
: vehiculo(p, m, y, pre){
    capacidadCarga= cC;
}
//a.2
camion:: ~camion(){
    cout << "Destruyendo 'camion'\n";
}
//b
void camion:: mostrarInformacion(){
    cout << "=== Datos de CAMION ===\n";
    vehiculo:: mostrarInformacion();
    cout << "capacidadCarga: " << capacidadCarga << " toneladas\n";
}


//---3
//a.1
moto:: moto(string p, string m, int y, double pre, double po)
: vehiculo(p, m, y, pre){
    potencia= po;
}
//a.2
moto:: ~moto(){
    cout << "Destruyendo 'moto'\n";
}
//b
void moto:: mostrarInformacion(){
    cout << "=== Datos de MOTO ===\n";
    vehiculo:: mostrarInformacion();
    cout << "potencia: " << potencia << " cc\n";
}