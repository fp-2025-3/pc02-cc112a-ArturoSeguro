#include <iostream>
#include <fstream>
#include <string>
#include <cstring>
using namespace std;

//---0
struct alumno{
    string apellidos[30];
    string nombre[30];
    int nota[30];
};
//
const char* entrada= "TEMA7.4_4entrada.csv";
const char* salida= "TEMA7.4_4salidaOTRO.csv";


//---1
int lectura(const char* nombre, alumno& a){
    //1er, 2do
    ifstream leer(nombre, ios::in);
    if(!leer){
        cerr << "No se pudo abrir el archivo.\n";
        return -1;
    }
    //3er
    int i=0;
    string notaTEMP;
    while(getline(leer, a.apellidos[i], ',') && getline(leer, a.nombre[i], ',') && getline(leer, notaTEMP)){
        a.nota[i]= stoi(notaTEMP);
        i++;
    }
    //4to
    leer.close();
    return i;
}


//---2
void puntos(alumno& a, int cantidad){
    for(int i=0; i<cantidad; i++){
        a.nota[i]= a.nota[i]+2;
    }
    return;
}


//---3
void ordenar(alumno& a, int cantidad){
    for(int i=0; i<cantidad-1; i++){
        for(int j=0; j<cantidad-1-i; j++){
            if(a.apellidos[j]> a.apellidos[j+1]){
                swap(a.apellidos[j], a.apellidos[j+1]);
                swap(a.nombre[j], a.nombre[j+1]);
                swap(a.nota[j], a.nota[j+1]);
            }else if(a.apellidos[j]== a.apellidos[j+1]){
                if(a.nombre[j]> a.nombre[j+1]){
                    swap(a.apellidos[j], a.apellidos[j+1]);
                    swap(a.nombre[j], a.nombre[j+1]);
                    swap(a.nota[j], a.nota[j+1]);
                }else if(a.nombre[j]== a.nombre[j+1]){
                    if(a.nota[j]< a.nota[j+1]){         //Quiero quedarme con la mayor primero
                        swap(a.apellidos[j], a.apellidos[j+1]);
                        swap(a.nombre[j], a.nombre[j+1]);
                        swap(a.nota[j], a.nota[j+1]);
                    }
                }
            }
        }
    }
    //
    return;
}


//---4
void escritura(const char* salida, alumno a, int cantidad){
    //1er, 2do
    ofstream escribir(salida, ios::out);
    if(!escribir){
        cerr << "No se pudo abrir el archivo.\n";
        return;
    }
    //3er
    for(int i=0; i<cantidad; i++){
        escribir << a.apellidos[i] << "," << a.nombre[i] << "," << a.nota[i] << "\n";
    }
    //4to
    escribir.close();
    return;
}


//main
//
int main(){
    alumno a;
    //---1
    int cantidad= lectura(entrada, a);
    if(cantidad== -1){
        return 0;
    }
    //---2
    puntos(a, cantidad);
    //---3
    ordenar(a, cantidad);
    //---4
    escritura(salida, a, cantidad);


    //
    cout << "\n\n-------------END\n";
    return 0;
}