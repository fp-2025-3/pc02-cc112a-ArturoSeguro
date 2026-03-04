#include <iostream>
#include <fstream>
#include <cstring>
#include <string>
#include <cmath>
using namespace std;

//---0
struct punto{
    double cooX;
    int cooY; 
};
//
const char* nombreSalida= "grafico.txt";


//main
//
int main(){
    //coordenadas X y Y
    punto p[80];
    const double pi= 3.1416;
    for(int i=0; i<80; i++){
        //80 puntos espaciados [0, 2pi]. --> el último "i" será i=79;
        p[i].cooX= ((pi*2)/79.0)*(i);
        double valorY= sin(5*p[i].cooX);
        //mapeando en las 21filas [0,20]
        p[i].cooY= round(10- 10*valorY);
    }

    //1er, 2do
    ofstream escribir(nombreSalida, ios::out);
    if(!escribir){
        cerr << "No se pudo abrir.\n";
        return -1;
    }
    //3er
    for(int i=0; i<21; i++){
        if(p[0].cooY== i){
            escribir << "*";
        }else{
            escribir << "|";
        }
        //
        for(int j=1; j<80; j++){
            if(p[j].cooY== i){
                escribir << "*";
            }else if(i== 10){
                escribir << "-";
            }else{
                escribir << " ";
            }
        }
        escribir << "\n";
    }
    //4to
    escribir.close();
    

    //
    cout << "\n\n-------------END\n";
    return 0;
}