#include <iostream>
#include <fstream>
#include <cstring>
using namespace std;


//---0
const char* nombreArchivo= "TEMA7.3_2fibonacci.bin";


//--->2
int fibonacci(int valorAnterior1, int valorAnterior2){
    if(valorAnterior1== 0){
        return 0;
    }
    //
    return valorAnterior1+ valorAnterior2;
}


//--->1
void escribirF(const char* nombreArchivo){
    cout << "\nFuncion escribir FIBONACCI:: \n";
    //1er, 2do
    ofstream escribir(nombreArchivo, ios::out | ios::binary);
    if(!escribir){
        cerr << "El archivo no se pudo abrir.\n";
        return;
    }
    //3er
    int valorAnterior1=1;
    int valorAnterior2=1;
    int introducido;
    //
    introducido= fibonacci(0, 0);
    escribir.write((char*)(&introducido), sizeof(introducido));        //son 20 bucles y estas 3 lineas cuentan como si fueran 3 bucles completados
    //
    introducido= fibonacci(1, 0);
    escribir.write((char*)(&introducido), sizeof(introducido));
    //
    introducido= fibonacci(1, 0);
    escribir.write((char*)(&introducido), sizeof(introducido));
    //
    for(int i=0; i<20-3; i++){
        introducido= fibonacci(valorAnterior1, valorAnterior2);
        escribir.write((char*)(&introducido), sizeof(introducido));
        //
        valorAnterior2= valorAnterior1;
        valorAnterior1= introducido;
    }
    //4to
    escribir.close();
    cout << "Terminos de la serie fibonacci escritos correctamente.\n";
    return;
}


//--->3
void leerF(const char* nombreArchivo){
    cout << "\nFuncion leer FIBONACCI:: \n";
    //1er, 2do
    ifstream leer(nombreArchivo, ios::in | ios::binary);
    if(!leer){
        cerr << "El archivo no se pudo abrir.\n";
        return;
    }
    //3er
    int valorF;
    int indice=1;
    while(leer.read((char*)(&valorF), sizeof(valorF))){
        cout << "Termino '" << indice << "' --> " << valorF << "\n";
        indice++;
    }
    //4to
    leer.close();
}


//main
//
int main(){
    //--->1
    escribirF(nombreArchivo);
    cout << "\n";
    //--->3
    leerF(nombreArchivo);


    //
    cout << "\n\n-------------END\n";
    return 0;
}