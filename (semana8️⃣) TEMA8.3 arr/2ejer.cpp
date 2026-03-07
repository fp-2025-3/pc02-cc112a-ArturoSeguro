#include <iostream>
#include <fstream>
#include <cstring>
#include <string>
#include <cmath>
using namespace std;


//---0
struct Punto{
    double coox;
    double cooy;
};


//---1
void leerPunto(Punto* p){
    cout << "dea la coordenada x: ";
    cin >> p->coox;
    cout << "dea la coordenada y: ";
    cin >> p->cooy;
};


//---2
double distanciaOrigen(const Punto* p){
    double x= p->coox;
    double y= p->cooy;
    double distancia= sqrt((x*x)+ (y*y));
    return distancia;
}


//---3
Punto* masLejano(Punto* p1, Punto* p2){
    if(distanciaOrigen(p1)> distanciaOrigen(p2)){
        return p1;
    }else{
        return p2;
    }
}


//main
//
int main(){
    Punto p1;
    Punto p2;
    //---1
    cout << "=== coordenada 1.\n";
    leerPunto(&p1);
    cout << "=== coordenada 2.\n";
    leerPunto(&p2);
    //---2
    Punto* p3= masLejano(&p1, &p2);
    cout << "el punto más lejano tiene las siguentes corrdenas.\n";
    cout << "x= " << p3->coox << "\n";
    cout << "y= " << p3->cooy << "\n";


    //
    cout << "\n\n-------------END\n";
    return 0;
}