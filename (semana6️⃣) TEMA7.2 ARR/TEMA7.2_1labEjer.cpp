#include <iostream>
#include <fstream>
#include <cstring>
using namespace std;

//


//main
//
int main(){
    //pidiendo datos
    float ventas[7];
    for(int i=0; i<7; i++){
        cout << "Coloque la venta del DIA-->" << i+1 << "\n";
        cin >> ventas[i];
        cout << "\n";
    }


    //---paso1,2
    string nombreArchivo= "TEMA7.2_1ventas.txt";
    ofstream escribir(nombreArchivo, ios::out);
    if(!escribir){
        cerr << "No se pudo abrir archivo.\n";
        return 1;
    }
    //---Paso3.1
    for(int i=0; i<7; i++){
        escribir << ventas[i] << "\n";
    }
    //---paso4
    escribir.close();


    //sumando
    float sumaTotal=0;
    for(int i=0; i<7; i++){
        sumaTotal= sumaTotal+ ventas[i];
    }
    //promedio
    float promedio= sumaTotal/7;
    //Mayor y Menor con BubbleSort
    for(int i=0; i<7-1; i++){
        for(int j=0; j<7-1-i; j++){
            if(ventas[j]< ventas[j+1]){         //--> el mayor quedara primero (0) y el menor al último (6)
                swap(ventas[j], ventas[j+1]);
            }
        }
    }
    //---paso1,2
    ofstream escribir2(nombreArchivo, ios::out | ios::app);
    //---paso3
    escribir2 << "--------------------" << "\n";
    escribir2 << "RESUMEN\n";
    escribir2 << "Total: " << sumaTotal << "\n";
    escribir2 << "Promedio: " << promedio << "\n";
    escribir2 << "Mayor Venta: " << ventas[0] << "\n";
    escribir2 << "Menor Venta: " << ventas[6] << "\n";
    //---paso4
    escribir2.close();


    //
    cout << "\n\n-------------END\n";
    return 0;
}