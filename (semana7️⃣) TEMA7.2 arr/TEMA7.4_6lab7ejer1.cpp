#include <iostream>
#include <fstream>
#include <cstring>
#include <string>
using namespace std;


//---0
struct estudiante{
    string nombre;
};
//
const char* texto1= "TEMA7.4_6archivo1.txt";
const char* texto2= "TEMA7.4_6archivo2.txt";
const char* salida= "TEMA7.4_6nombreM";


//---1
int lectura(const char* nombreArchivo, estudiante e[], int indice){
    //1er, 2do
    ifstream leer(nombreArchivo, ios::in);
    if(!leer){
        cerr << "No se pudo abrir.\n";
        return -1;
    }
    //3er
    while(leer >> e[indice].nombre){
        indice++;
    }
    //4to
    leer.close();
    return indice;
}


//---2
void ordenar(estudiante e[], int cantidad){
    for(int i=0; i<cantidad-1; i++){
        for(int j=0; j<cantidad-1-i; j++){
            if(e[j].nombre> e[j+1].nombre){
                estudiante TEMP= e[j];
                e[j]= e[j+1];
                e[j+1]= TEMP;
            }
        }
    }
    //
    return;
}


//---3
void escritura(const char* nombreArchivo, estudiante e[], int cantidad){
    //1er, 2do
    ofstream escribir(nombreArchivo, ios::out);
    if(!escribir){
        cerr << "No se pudo abrir.\n";
        return;
    }
    //3er
    for(int i=0; i<cantidad; i++){
        cout << e[i].nombre << "\n";
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
    int ultimoIn1= lectura(texto1, e, 0);
    int cantidad= lectura(texto2, e, ultimoIn1);
    //---2,3
    if(cantidad>0){
        ordenar(e, cantidad);
        escritura(salida, e, cantidad);
    }


    //
    cout << "\n\n-------------END\n";
    return 0;
}