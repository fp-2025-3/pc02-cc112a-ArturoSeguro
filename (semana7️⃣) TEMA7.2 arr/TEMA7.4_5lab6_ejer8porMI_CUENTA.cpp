#include <iostream>
#include <fstream>
#include <cstring>
#include <string>
using namespace std;

//---0
struct estudiante{
    string apellidos;
    string nombre;
    int nota;
};
//
const char* entrada= "TEMA7.4_4entrada.csv";
const char* salida= "TEMA7.4_5salidaUltima.csv";


//---1
int lectura(const char* nombreArchivo, estudiante e[]){
    //1er, 2do
    ifstream leer(nombreArchivo, ios::in);
    if(!leer){
        cerr << "No se pudo abrir el archivo.\n";
        return -1;
    }
    //3er
    int i=0;
    string TEMPnota;
    while(getline(leer, e[i].apellidos, ',') && getline(leer, e[i].nombre, ',') && getline(leer, TEMPnota)){
        e[i].nota= stoi(TEMPnota);
        i++;
    }
    //4to
    leer.close();
    return i;
}


//---2
void puntos(estudiante e[], int cantidad){
    for(int i=0; i<cantidad; i++){
        e[i].nota= e[i].nota+2;
    }
    return;
}


//---3
void ordenar(estudiante e[], int cantidad){
    for(int i=0; i<cantidad-1; i++){
        for(int j=0; j<cantidad-1-i; j++){
            bool cambiar= false;
            if(e[j].apellidos> e[j+1].apellidos){
                cambiar= true;
            }else if(e[j].apellidos== e[j+1].apellidos){
                if(e[j].nombre> e[j+1].nombre){
                    cambiar= true;
                }else if(e[j].nombre== e[j+1].nombre){
                    if(e[j].nota< e[j+1].nota){
                        cambiar= true;
                    }
                }
            }
            //
            if(cambiar){
                estudiante estuTEMP= e[j];
                e[j]= e[j+1];
                e[j+1]= estuTEMP;
            }
        }
    }
    //
    return;
}


//---4
void escritura(const char* nombreArchivo, estudiante e[], int cantidad){
    //1er, 2do
    ofstream escribir(nombreArchivo, ios::out);
    if(!escribir){
        cerr << "No se pudo abrir el archivo.\n";
        return;
    }
    //3er
    for(int i=0; i<cantidad; i++){
        escribir << e[i].apellidos << "," << e[i].nombre << "," << e[i].nota << "\n";
    }
    //4to
    escribir.close();
    return;
}


//main
//
int main(){
    //---1
    estudiante e[100];
    int cantidad= lectura(entrada, e);
    //---2,3,4
    if(cantidad>0){
        puntos(e, cantidad);
        ordenar(e, cantidad);
        escritura(salida, e, cantidad);
    }


    //
    cout << "\n\n-------------END\n";
    return 0;
}