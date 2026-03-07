#include <iostream>
#include <fstream>
#include <cstring>
#include <cmath>
using namespace std;

//---0
struct poligono{
    int vertices;
    double* x;
    double* y;
};
//
const char* nombreArchivo1= "TEMA7.4_3poligono1.txt";
const char* nombreArchivo2= "TEMA7.4_3poligono2.txt";


//---1
poligono lectura(const char* nombre){
    //1er, 2do
    ifstream leer(nombre, ios::in);
    if(!leer){
        cerr << "No se pudo abrir el archivo.\n";
        poligono p;
        p.vertices= 0;
        p.x= nullptr;
        p.y= nullptr;
        return p;
    }
    //3er
    poligono p;
    leer >> p.vertices;
    //
    p.x= new double[p.vertices];
    p.y= new double[p.vertices];
    for(int i=0; i<p.vertices; i++){
        leer >> p.x[i] >> p.y[i];
    }
    //4to
    leer.close();
    return p;
}


//---2
void rotacion(poligono& p, double angle){
    for(int i=0; i<p.vertices; i++){
        double x= p.x[i], y= p.y[i];
        p.x[i]= cos(angle)*x- sin(angle)*y;
        p.y[i]= sin(angle)*x+ cos(angle)*y;
    }
    return;
}


//---3
void escritura(const char* nombre, poligono p){
    //1er, 2do
    ofstream escritura(nombre, ios::out);
    if(!escritura){
        cerr << "No se pudo abrir el archivo.\n";
        return;
    }
    //3er
    escritura << p.vertices << "\n";
    for(int i=0; i<p.vertices; i++){
        escritura << p.x[i] << " " << p.y[i] << "\n";
    }
    //4to
    escritura.close();
    return;
}


//main
//
int main(){
    //---1
    poligono p= lectura(nombreArchivo1);
    if(p.vertices== 0){
        return 0;
    }
    //---2
    double a;
    cout << "Dea el angulo 'alpha': ";
    cin >> a;
    rotacion(p, a);
    //---3
    escritura(nombreArchivo2, p);
    //deleting dynamic variables
    delete[] p.x;
    delete[] p.y;

    
    //
    cout << "\n\n-------------END\n";
    return 0;
}