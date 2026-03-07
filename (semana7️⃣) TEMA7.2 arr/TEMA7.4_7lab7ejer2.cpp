#include <iostream>
#include <fstream>
#include <cstring>
#include <string>
using namespace std;

//---0
struct estudiante{
    string apellido;
    string nombre;
    float nota1;
    float nota2;
    float promedio;
};
//
const char* nombreArchivo= "TEMA7.4_7baseUNI.txt";


//---1
int imprimir(const char* nombreArchivo, estudiante e[]){
    //1er, 2do
    ifstream leer(nombreArchivo, ios::in);
    if(!leer){
        cerr << "no se pudo abrir.\n";
        return -1;
    }
    //3er
    int i=0;
    cout << "orden\tapellidos\tnombre\tnota1\tnota2\tpromedio\n";
    while(getline(leer >> ws, e[i].apellido, ',') && leer >> e[i].nombre >> e[i].nota1 >> e[i].nota2 >> e[i].promedio){
        cout << i+1 << "\t" << e[i].apellido << "\t" << e[i].nombre << "\t" << e[i].nota1 << "\t" << e[i].nota2 << "\t" << e[i].promedio << "\n";
        i++;
    }
    //4to
    leer.close();
    return i;
}


//---2
void ordenar(estudiante e[], int cantidad){
    for(int i=0; i<cantidad-1; i++){
        for(int j=0; j<cantidad-1-i; j++){
            if(e[j].promedio< e[j+1].promedio){
                estudiante TEMP= e[j];
                e[j]= e[j+1];
                e[j+1]= TEMP;
            }
        }
    }
    //
    return;
}


//main
//
int main(){
    //---1
    estudiante e[100];
    int cantidad= imprimir(nombreArchivo, e);
    //---2
    if(cantidad> 0){
        cout << "\n";
        ordenar(e, cantidad);
        cout << "EL promedio maximo: " << e[0].promedio << "\n";
        cout << "Alumno: " << e[0].nombre << " " << e[0].apellido << "\n";
    }
    

    //
    cout << "\n\n-------------END\n";
    return 0;
}