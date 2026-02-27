#include <iostream>
#include <fstream>
#include <string>
#include <cstring>
using namespace std;

//---0
struct alumno{
    string apellidos;
    string nombre;
    int nota;
};
//
const char* entrada= "TEMA7.4_4entrada.csv";
const char* salida= "TEMA7.4_4salida.csv";


//---1
int lectura(const char* nombreArchivo, alumno a[]){
    //1er, 2do
    ifstream leer(nombreArchivo, ios::in);
    if(!leer){
        cerr << "No se pudo abrir el archivo de entrada.\n";
        return -1;
    }
    //3er
    int i=0;
    string notaTEMP;
    while(getline(leer, a[i].apellidos, ',') && getline(leer, a[i].nombre, ',') && getline(leer, notaTEMP)){
        a[i].nota= stoi(notaTEMP);
        i++;
    }
    //4to
    leer.close();
    return i;
}


//---2
void puntos(alumno a[], int cantidad){
    for(int i=0; i<cantidad; i++){
        a[i].nota= a[i].nota+2;
    }
    //
    return;
}


//---3
void ordenar(alumno a[], int cantidad){
    for(int i=0; i<cantidad-1; i++){
        for(int j=0; j<cantidad-1-i; j++){
            bool intercambiar= false;
            if(a[j].apellidos> a[j+1].apellidos){
                intercambiar= true;
            }else if(a[j].apellidos== a[j+1].apellidos){
                if(a[j].nombre> a[j+1].nombre){
                    intercambiar= true;
                }else if(a[j].nombre== a[j+1].nombre){
                    if(a[j].nota< a[j+1].nota){
                        intercambiar= true;
                    }
                }
            }
            //
            if(intercambiar){
                alumno TEMP= a[j];
                a[j]= a[j+1];
                a[j+1]= TEMP;
            }
        }
    }
    //
    return;
}


//---4
void escritura(const char* salida, alumno a[], int cantidad){
    //1er, 2do
    ofstream escribir(salida, ios::out);
    if(!escribir){
        cerr << "No se pudo abrir el archivo de salida.\n";
        return;
    }
    //3er
    for(int i=0; i<cantidad; i++){
        escribir << a[i].apellidos << "," << a[i].nombre << "," << a[i].nota << "\n";
    }
    //4to
    escribir.close();
    return;
}


//main
//
int main(){
    //---1
    alumno lista[100];
    int cantidad= lectura(entrada, lista);
    //---2,3,4
    if(cantidad>0){
        puntos(lista, cantidad);
        ordenar(lista, cantidad);
        escritura(salida, lista, cantidad);
        //
        cout << "Proceso terminado con exito. Revisa el archivo '" << salida << "'\n";
    }
    

    //
    cout << "\n\n-------------END\n";
    return 0;
}