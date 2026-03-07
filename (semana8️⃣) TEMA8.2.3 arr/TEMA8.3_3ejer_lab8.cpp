#include <iostream>
#include "TEMA8.3_3ejer_lab8.h"
#include <fstream>
#include <cstring>
#include <string>
using namespace std;


//---0 
//a1
figura:: figura(string n, double* cRGB){
    nombre= n;
    //aqui se puede crear el arreglo dinamico
    colorRGB= new double[3];
    colorRGB[0]= cRGB[0];
    colorRGB[1]= cRGB[1];
    colorRGB[2]= cRGB[2];
}
//a2
figura:: ~figura(){
    delete[] colorRGB;      //la mejor practica para evitar memory leaks
    cout << "destruyendo figura.\n";
}
//a3
figura:: figura(const figura& f){
    nombre= f.nombre;
    colorRGB= new double[3];
    colorRGB[0]= f.colorRGB[0];
    colorRGB[1]= f.colorRGB[1];
    colorRGB[2]= f.colorRGB[2];
}
//a4
figura& figura:: operator=(const figura& f){
    if(this!= &f){
        nombre= f.nombre;
        delete[] colorRGB;  //como ya es uno esxistente debo borrar lo que ya estaba creado
        //
        colorRGB= new double[3];
        colorRGB[0]= f.colorRGB[0];
        colorRGB[1]= f.colorRGB[1];
        colorRGB[2]= f.colorRGB[2];
    }
    return *this;
}
//b1, b2, b3 (son virtuales así que no se declaran) (= 0)
//b4
string figura::nombreGetter() const{
    return nombre;
}
//b5
double* figura::RGBgetter() const{
    return colorRGB;
}


//---1
//a1
circulo:: circulo(string n, double* cRGB, double r)
:figura(n, cRGB){
    radio= r;
}
//a2
circulo:: ~circulo(){
    cout << "destruyendo circulo.\n";
}
//b1
double circulo:: area() const{
    return (3.1416)*(radio)*(radio);
}
//b2
double circulo:: perimetro() const{
    return 2*(3.1416)*(radio);
}
//b3
void circulo:: imprimir() const{
    cout << "=== CIRCULO ===\n";
    cout << "nombre: " << figura::nombreGetter() << "\n";
    double* temp= figura::RGBgetter();
    cout << "RED: " << temp[0] << " | GREEN: " << temp[1] << " | BLUE: " << temp[2] << "\n";
    cout << "area: " << area() << "\n";
    cout << "perimetro: " << perimetro() << "\n";
}   


//---2
//a1
rectangulo:: rectangulo(string n, double* cRGB, double b, double a)
:figura(n, cRGB){
    base= b;
    altura= a;
}
//a2
rectangulo:: ~rectangulo(){
    cout << "destruyendo rectangulo.\n";
}
//b1
double rectangulo:: area() const{
    return base*altura;
}
//b2
double rectangulo:: perimetro() const{
    return 2*(base+altura);
}
//b3
void rectangulo:: imprimir() const{
    cout << "=== RECTANGULO ===\n";
    cout << "nombre: " << figura::nombreGetter() << "\n";
    double* temp= figura::RGBgetter();
    cout << "RED: " << temp[0] << " | GREEN: " << temp[1] << " | BLUE: " << temp[2] << "\n";
    cout << "area: " << area() << "\n";
    cout << "perimetro: " << perimetro() << "\n";
}


//---3
//a1
gestor:: gestor(int capa){
    capacidad= capa;
    cantidadActual= 0;
    figuras= new figura*[capacidad];
}
//a2
gestor:: ~gestor(){
    delete[] figuras;           //si lo cree en el "constructor" lo destruyo en el "detructor"
    cout << "destruyendo gestor de figuras.\n";
}
//b1
void gestor:: agregarFigura(figura* f){
    if(cantidadActual== capacidad){  //REDIMENSIONAMIENTO DINAMICO
        capacidad*= 2;
        figura** temporal= new figura*[capacidad];
        for(int i=0; i<cantidadActual; i++){
            temporal[i]= figuras[i];    //leno lo que ya habia en el nuevo arreglo dinamico con más capacidad
        }
        delete[] figuras;   //borro el anterior con poca capacidad
        figuras= temporal;  //lo ponco el de mayor capacidad como oficial
    }
    //
    figuras[cantidadActual]= f;
    cantidadActual++;
}
//b2
void gestor:: mostrarTodo() const{
    cout << "===> ===> LO RECOLECTADO DESDE EL GESTOR\n";
    for(int i=0; i<cantidadActual; i++){
        figuras[i]->imprimir();
    }
}
//b3
double gestor:: areaTotal() const{
    double total= 0;
    for(int i=0; i<cantidadActual; i++){
        total+= figuras[i]->area();
    }
    cout << "el areaTotal es: " << total << "\n";
    return total;
}
//b4
void gestor:: guardarArchivo(const char* nombreArchivo) const{
    //1er, 2do
    ofstream escribir(nombreArchivo, ios::out);
    if(!escribir){
        cerr << "no se pudo abrir.\n";
    }
    //3er
    for(int i=0; i<cantidadActual; i++){
        escribir << "nombre: " << figuras[i]->nombreGetter() << "\n";
        double* temp= figuras[i]->RGBgetter();
        escribir << "RED: " << temp[0] << " | GREEN: " << temp[1] << " | BLUE: " << temp[2] << "\n";
        escribir << "area: " << figuras[i]->area() << "\n";
        escribir << "perimetro: " << figuras[i]->perimetro() << "\n";
        escribir << "---------------------------\n";
    }
    //4to
    escribir.close();
}