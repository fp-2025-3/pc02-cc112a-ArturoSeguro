#include <iostream>
#include <fstream>
#include <cstring>
using namespace std;


//---0
struct empleado{
    int id;
    char nombre[30];
    float salario;
};
//
const char* nombreArchivo= "Tema7.4_2empleados.bin";


//---1
void registrar(const char* nombreArchivo, int id, const char* nombre, float salario){
    empleado e;
    e.id= id;
    strcpy(e.nombre, nombre);
    e.salario= salario;
    //1er, 2do
    ofstream escribir(nombreArchivo, ios::out | ios::app | ios:: binary);
    if(!escribir){
        cerr << "No se pudo abrir el archivo.\n";
        return;
    }
    //3er
    escribir.write((char*)(&e), sizeof(empleado));
    //4to
    escribir.close();
    return;
}


//---2
void mostrar(const char* nombreArchivo){
    //1er, 2do
    ifstream leer(nombreArchivo, ios::in | ios::binary);
    if(!leer){
        cerr << "No se pudo abrir el archivo.\n";
        return;
    }
    //3er
    empleado e;
    cout << "iden\tnomb\tsala\n";
    while(leer.read((char*)(&e), sizeof(empleado))){
        cout << e.id << "\t" << e.nombre << "\t" << e.salario << "\n";
    }
    //4to
    leer.close();
    return;
}


//---3
void rango(const char* nombreArchivo){
    float ran1, ran2;
    cout << "Elija rango MENOR: ";
    cin >> ran1;
    cout << "Elija rango MAYOR: ";
    cin >> ran2;
    //1er, 2do
    ifstream leer(nombreArchivo, ios::in | ios::binary);
    if(!leer){
        cerr << "No se pudo abrir el archivo.\n";
        return;
    }
    //3er
    empleado e;
    cout << "iden\tnomb\tsala\n";
    while(leer.read((char*)(&e), sizeof(empleado))){
        if(e.salario>=ran1 && e.salario<=ran2){
            cout << e.id << "\t" << e.nombre << "\t" << e.salario << "\n";
        }
    }
}


//---4
void borrar(const char* nombreArchivo){
    //1er, 2do
    ofstream escribir(nombreArchivo, ios::out | ios:: binary);
    if(!escribir){
        cerr << "No se pudo abrir el archivo.\n";
        return;
    }
    //3er
    //i don't wwant ot do anything --> i just want to erase
    //4to
    escribir.close();
    return;
}



//main
//
int main(){
    //---1
    registrar(nombreArchivo, 12301, "A", 300);
    registrar(nombreArchivo, 12302, "B", 200);
    registrar(nombreArchivo, 12303, "C", 700);
    registrar(nombreArchivo, 12304, "D", 900);
    registrar(nombreArchivo, 12305, "E", 300);
    registrar(nombreArchivo, 12306, "F", 400);
    registrar(nombreArchivo, 12307, "G", 900);
    registrar(nombreArchivo, 12308, "H", 1100);
    //---2
    mostrar(nombreArchivo);
    //---3
    rango(nombreArchivo);
    //---4 (borrar)
    borrar(nombreArchivo);

    //
    cout << "\n\n-------------END\n";
    return 0;
}