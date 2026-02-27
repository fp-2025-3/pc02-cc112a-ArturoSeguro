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
    for(int i=0; i<80; i++){
        p[i].cooX= (((3.1416)*4)/80)*(i);                            //debo encajarlos en las 80 diviisones de C
        p[i].cooY= 21*sin(p[i].cooX);              //debo encajarlos en las 21 filas Y
    }


    //1er, 2do
    ofstream escribir(nombreSalida, ios::out);
    if(!escribir){
        cerr << "No se pudo abrir.\n";
        return -1;
    }
    //3er
    for(int i=0; i<21; i++){
        escribir << "|";
        for(int j=1; j<80; j++){
            if(i>=0 && i<=10){
                if(p[j].cooY== 21-(i+1) || p[j].cooY== 21-(i) || p[j].cooY== 21-(i-1)){
                    escribir << "*";
                }else{
                    escribir << " ";
                }
            }else if(i== 11){
                escribir << "-";
            }else if(i>11 && i<=21){
                if(p[j].cooY== 21-(i+1) || p[j].cooY== 21-(i) || p[j].cooY== 21-(i-1)){
                    escribir << "*";
                }else{
                    escribir << " ";
                }
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