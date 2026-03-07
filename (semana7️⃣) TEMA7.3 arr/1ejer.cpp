#include <iostream>
#include <fstream>
#include <cstring>
#include <string>
using namespace std;

//---0
struct alumno{
    int codigo;
    string nombre;
    float nota1;
    float nota2;
    float nota3;
    float promedio;
    string descripcion;
};
//
const char* nombreArchivo= "notas.txt";
const char* nombreReporte= "reporteAlumnos.txt";


//main
//
int main(){
    //1er, 2do
    ifstream leer(nombreArchivo, ios::in);
    if(!leer){
        cerr << "no se pudo abrir el archivo.\n";
        return -1;
    }
    //3er
    alumno a;
    int totalAlumnos=0;
    while(leer >> a.codigo >> a.nombre >> a.nota1 >> a.nota2 >> a.nota3){
        totalAlumnos++;
    }
    //4to
    leer.close();


    //1er, 2do
    ifstream extraer(nombreArchivo, ios::in);
    if(!extraer){
        cerr << "no se pudo abrir el archivo.\n";
        return -1;
    }
    //3er
    alumno* A= new alumno[totalAlumnos];
    for(int i=0; i<totalAlumnos; i++){
        extraer >> A[i].codigo >> A[i].nombre >> A[i].nota1 >> A[i].nota2 >> A[i].nota3;
    }
    //promedioCadaUNO
    for(int i=0; i<totalAlumnos; i++){
        A[i].promedio= (A[i].nota1+ A[i].nota2+ A[i].nota3)/3.0;
    }
    //condicionCadaUNO
    for(int i=0; i<totalAlumnos; i++){
        if(A[i].nota1<5 || A[i].nota2<5 || A[i].nota3<5){
            A[i].descripcion= "DESAPROBADO POR REGLA ACADEMICA.";
        }else if(A[i].promedio>= 10){
            A[i].descripcion= "APROBADO.";
        }else{
            A[i].descripcion= "DESAPROBADO.";
        }
    }
    //promedio general del curso
    float sumaGeneral=0;
    for(int i=0; i<totalAlumnos; i++){
        sumaGeneral+= A[i].promedio;
    }
    float promedioGeneral= sumaGeneral/totalAlumnos;
    //mayor y menor promedio --> ordenamientoBURBUJA
    for(int i=0; i<totalAlumnos-1; i++){
        for(int j=0; j<totalAlumnos-1-i; j++){
            if(A[j].promedio> A[j+1].promedio){
                alumno temp= A[j];
                A[j]= A[j+1];
                A[j+1]= temp;
            }
        }
    }
    //4to
    extraer.close();


    //1er, 2do
    ofstream escribir(nombreReporte, ios::out);
    if(!escribir){
        cerr << "no se pudo abrir el archivo.\n";
        return -1;
    }
    //3er
    escribir << "===REPORTE===\n";
    escribir << "total de estudiantes: " << totalAlumnos << "\n";
    escribir << "promedio general curso:" << promedioGeneral << "\n";
    escribir << "mayor nota: " << A[totalAlumnos-1].promedio << "\tNombre: " << A[totalAlumnos-1].nombre << "\n";
    escribir << "menor nota: " << A[0].promedio << "\tNombre: " << A[0].nombre << "\n\n";
    escribir << "------------------------------------------------\n";
    escribir << "codigo\tnombre\t\tpromedi\tcondici\n";
    for(int i=0; i<totalAlumnos; i++){
        escribir << A[i].codigo << "\t" << A[i].nombre << "\t\t" << A[i].promedio << "\t" << A[i].descripcion<< "\n";
    }
    //4to
    escribir.close();


    //
    cout << "\n\n-------------END\n";
    delete[] A;                 //liberando memoria
    return 0;
}