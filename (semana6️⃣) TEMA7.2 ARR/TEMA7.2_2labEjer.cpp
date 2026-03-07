#include <iostream>
#include <fstream>
#include <cstring>
using namespace std;

//


//main
//
int main(){
    string nombreArchivo= "TEMA7.2_2notas.txt";
    //1er,2do paso
    ifstream leer(nombreArchivo, ios::in);
    //3er paso
    int i=0;
    int notas[100];
    while(leer >> notas[i]){
        i++;        //se queda como la cantidad total de estudiantes
    }
    //4to paso
    leer.close();


    //ultimo indice
    int ULin= i-1;
    //cantidad de estudiantes
    int cantidad= i;
    //promedio
    int promedio=0;
    for(int i=0; i<cantidad; i++){
        promedio= promedio+ notas[i];
    }
    promedio= promedio/cantidad;
    //alto y bajo con bubbleSort
    for(int i=0; i<cantidad-1; i++){
        for(int j=0; j<cantidad-1-i; j++){
            if(notas[j]< notas[j+1]){
                swap(notas[j], notas[j+1]);
            }
        }
    }
    //cantidad aprovados y desaprovados
    int aprobados= 0;
    int desaprobados= 0;
    for(int i=0; i<cantidad; i++){
        if(notas[i]>= 10){
            aprobados++;
        }else{
            desaprobados++;
        }
    }
    //1er, 2do paso
    string nombreArchivo2= "TEMA7.2_2reporte.txt";
    ofstream reporte(nombreArchivo2, ios::out);
    //3er paso
    reporte << "REPORTE GENERAL\n";
    reporte << "--------------------------------\n";
    reporte << "Total estudiantes: " << cantidad << "\n";
    reporte << "Promedio: " << promedio << "\n";
    reporte << "Mayor nota: " << notas[0] << "\n";
    reporte << "Menor nota: " << notas[ULin] << "\n";
    reporte << "Aprobados: " << aprobados << "\n";
    reporte << "Desaprobados: " << desaprobados << "\n";
    //4to paso
    reporte.close();

    
    //
    cout << "\n\n-------------END\n";
    return 0;
}