#include <iostream>
#include <fstream>
#include <cstring>
#include <string>
using namespace std;

//---0
struct empleado{
    int id;         //comenzando en 1
    char nombre[30];
    double salario;
};
//
const char* nombreArchivo= "empleados.dat";


//---1
int buscar(const char* nombreArchivo, int idBuscado){
    //1er, 2do
    ifstream leer(nombreArchivo, ios::in | ios::binary);
    if(!leer){
        cerr << "no se pud abrir el archivo.\n";
        return -1;
    }
    //3er
    empleado e;
    int posicion= 0;
    while((leer.read((char*)(&e), sizeof(empleado)))){
        if(e.id== idBuscado){
            return posicion;
        }
        posicion++;
    }
    //4to
    leer.close();
    return -1;
}

//---2
void mostrar(const char* nombreArchivo, int posicion){
    //1er, 2do
    fstream mostrar(nombreArchivo, ios::out | ios::in | ios::binary);
    if(!mostrar){
        cerr << "no se pud abrir el archivo.\n";
        return;
    }
    //3er
    empleado e;
    mostrar.seekg(posicion*sizeof(empleado), ios::beg);
    mostrar.read((char*)(&e), sizeof(empleado));
    cout << "id:     \t" << e.id << "\n";
    cout << "nombre: \t" << e.nombre << "\n";
    cout << "salario:\t" << e.salario << "\n\n";
    //
    double nuevoSalario;
    cout << "escriba el nuevo salario: ";
    cin >> nuevoSalario;
    e.salario= nuevoSalario;
    //
    mostrar.seekp(posicion*sizeof(empleado), ios::beg);
    mostrar.write((char*)(&e), sizeof(empleado));
    //4to
    mostrar.close();
    return;
}


//main
//
int main(){
    //---1
    int id;
    cout << "Coloque el ID del empleado: ";
    cin >> id;
    int posicion= buscar(nombreArchivo, id);
    //---2
    mostrar(nombreArchivo, posicion);
    

    //
    cout << "\n\n-------------END\n";
    return 0;
}