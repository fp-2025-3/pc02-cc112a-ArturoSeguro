#include <iostream>
#include "4ejer.h"
#include <cstring>
#include <string>
using namespace std;

//---1 
//a1
Sensor:: Sensor(string i, double* p){   //Esto 'p' se elimina en main()
    id= i;
    posicion= new double[2];    //esto se elimina en destructor
    posicion[0]=p[0];
    posicion[1]=p[1];  
}
//a2
Sensor:: Sensor(const Sensor& s){
    id= s.id;
    posicion= new double[2];
    posicion[0]=s.posicion[0];
    posicion[1]=s.posicion[1];
}
//a3
Sensor& Sensor:: operator=(const Sensor& s){
    if(this!= &s){
        id= s.id;
        delete[] posicion;
        posicion= new double[2];
        posicion[0]=s.posicion[0];
        posicion[1]=s.posicion[1];
    }
    id= s.id;
    return *this;
}
//a4
Sensor:: ~Sensor(){
    delete[] posicion;
    cout << "Destruyendo sensor.\n";
}
//b1, b2, b3 --> son virtuales no se declaran
//b4
double* Sensor:: getterPosicion() const{
    return posicion;
}


//---2
//a1
SensorCircular:: SensorCircular(string i, double* p, double r)
: Sensor(i, p){
    radio= r;
}
//a2
SensorCircular:: ~SensorCircular(){
    cout << "destruyendo sensorCircular.\n";
}
//b1
double SensorCircular:: areaCobertura() const{
    return (3.1416)*(radio)*(radio);
}
//b2
bool SensorCircular:: detecta(double x, double y) const{
    double* centro= Sensor::getterPosicion();
    double X= centro[0];
    double Y= centro[1];
    bool condicion= ( (x-(X))*(x-(X))+ (y-(Y))*(y-(Y)) <= radio*radio );
    if(condicion){
        return true;
    }else{
        return false;
    }
}
//b3
void SensorCircular:: imprimir() const{
    cout << "=== SensorCircular ===\n";
    cout << "radio: " << radio;
    cout << "area cubierta: " << areaCobertura();
    cout << "punto de prueba (3, 4): ";
    if(detecta(3, 4)){
        cout << "se detecto en el area.\n";
    }else{
        cout << "no esta dentro del area.\n";
    }
}


//---3
//a1
SensorRectangular:: SensorRectangular(string i, double* p, double an, double al)
: Sensor(i, p){
    ancho= an;
    alto= al;
}
//a2
SensorRectangular:: ~SensorRectangular(){
    cout << "destruyendo sensorRectangular.\n";
}
//b1
double SensorRectangular:: areaCobertura() const{
    return (ancho)*(alto);
}
//b2
bool SensorRectangular:: detecta(double x, double y) const{
    double* centro= Sensor::getterPosicion();
    double X= centro[0];
    double Y= centro[1];
    bool condicion1= (x> X-ancho/2 && x< X+ancho/2);
    bool condicion2= (y> Y-alto/2 && y< Y+alto/2);
    if(condicion1 && condicion2){
        return true;
    }else{
        return false;
    }
}
//b3
void SensorRectangular:: imprimir() const{
    cout << "=== SensorRectangular ===\n";
    cout << "ancho: " << ancho;
    cout << "alto: " << alto;
    cout << "area cubierta: " << areaCobertura();
    cout << "punto de prueba (3, 4): ";
    if(detecta(3, 4)){
        cout << "se detecto en el area.\n";
    }else{
        cout << "no esta dentro del area.\n";
    }
}