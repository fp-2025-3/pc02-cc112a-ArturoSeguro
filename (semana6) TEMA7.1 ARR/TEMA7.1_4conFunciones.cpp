#include <iostream>
#include <fstream>      //para manipular archivos
using namespace std;

//--1
void escribirArchivo(string& nombreArchivo, const string& nombre, int nota);
//--2
void leerArchivo(const string& nombreArchivo);


//main
//
int main(){
    string nombreArchivo= "notas.txt";

    //--1 --> ESCRITURA MEDIANTE FUNCIÓN
    escribirArchivo(nombreArchivo, "Juan", 17);
    escribirArchivo(nombreArchivo, "Arturo", 20);
    escribirArchivo(nombreArchivo, "americo", 20);
    escribirArchivo(nombreArchivo, "Jose", 11);

    cout << "---1ERA LECTURA::\n";
    //--2 --> LECTURA ARCHIVO Y MOSTRANDO EN CONSOLA
    leerArchivo(nombreArchivo);

    //--1 
    escribirArchivo(nombreArchivo, "Enrique", 18);
    escribirArchivo(nombreArchivo, "Alexander", 19);

    cout << "---2DA LECTURA::\n";
    //--2 --> LECTURA ARCHIVO Y MOSTRANDO EN CONSOLA
    leerArchivo(nombreArchivo);

    //
    return 0;
}





//--1
//
void escribirArchivo(string& nombreArchivo, const string& nombre, int nota){
    //PASO1: INSTANCIAR::       intanciar un objeto de la clase ofstream
    ofstream archivoEscritura;

    //PASO2: CONECTAR::         conectar al archivo txt
    archivoEscritura.open(nombreArchivo, ios::app);

    //comprobación para ver si el archivo existe
    if(!archivoEscritura){
        cerr << "Error porque no se pudo abrir archivo para su ESCRITURA\n";
        return;
    }

    //PASO3: USAR::             leer/escribir archivos (escribiendo en notas.txt)
    archivoEscritura << nombre << "\t" << nota << "\n";

    //PASO4: DESCONECTAR::      desconectamos el achivo texto 
    archivoEscritura.close();
}


//--2
//
void leerArchivo(const string& nombreArchivo){
    //PASO1: INSTANCIAR::       intanciar un objeto de la clase ofstream
    ifstream archivoLectura;

    //PASO2: CONECTAR::         conectar al archivo txt
    archivoLectura.open(nombreArchivo);

    //comprobación para ver si el archivo existe
    if(!archivoLectura){
        cerr << "Error porque no se pudo abrir archivo para su LECTURA\n";
        return;
    }

    //PASO3: USAR::             leer/escribir archivos (escribiendo en notas.txt)
    string nombre;
    int nota;
    while(archivoLectura >> nombre >> nota){    //estados del stream --> impresos en consola
        cout << nombre << " -- " << nota << "\n";
    }

    //PASO4: DESCONECTAR::      desconectamos el achivo texto 
    archivoLectura.close();
}