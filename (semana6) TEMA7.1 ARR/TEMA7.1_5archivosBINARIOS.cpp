#include <iostream>
#include <fstream>      //para manipular archivos
#include <cstring>
using namespace std;



//-------------------
//Para trabajar con ARCHIVOS.binarios (1, 0) --> hay que usar "char[]"(arreglo de caracteres)
struct estudiante{
    char nombre[50];
    int nota;
};

//--1
void escribirBinario(const string& nombreArchivo, const string& nombre, int nota);
//--2
void leerBinario(const string& nombreArchivo);
//--3
void modificarNotaBinario(const string& nombreArchivo, const string& nombre, int nuevaNota);


//main
//
int main(){
    const string archivoBinario= "notas.dat";

    //--1
    escribirBinario(archivoBinario, "Arturo", 19);
    escribirBinario(archivoBinario, "Heidy", 20);
    escribirBinario(archivoBinario, "Americo", 20);

    cout << "\n1-- mostrando contenido de archivo BINARIO: \n";
    //-2
    leerBinario(archivoBinario);

    //--1
    escribirBinario(archivoBinario, "Adria", 19);
    escribirBinario(archivoBinario, "Boxio", 18);

    cout << "\n2-- mostrando contenido de archivo BINARIO: \n";
    //-2
    leerBinario(archivoBinario);

    //
    return 0;
}


//--1
//
void escribirBinario(const string& nombreArchivo, const string& nombre, int nota){
    //1er y 2do PASO:         -->Instanciar//Conectada
    ofstream archivo(nombreArchivo, ios::binary | ios::app); //activando modo binario

    //verifico
    if(!archivo){
        cerr << "error al abrir el archivo\n";
        return;
    }

    //3er PASO:                 -->Leo/Escribo
    estudiante e;
    e.nota= nota;
    //
    strncpy(e.nombre, nombre.c_str(), sizeof(e.nombre));
    e.nombre[sizeof(e.nombre)-1]= '\0';             //para asegurarse de que tiene su caracter nulo al final

    //Escribriendo en ARCHIVO BINARIO
    archivo.write((char*)&e, sizeof(estudiante));

    //4TO PASO:                 -->Cierro clase
    archivo.close();
}


//--2
//
void leerBinario(const string& nombreArchivo){
    //1CREO Y 2CONECTO (actibo modo binario)
    ifstream archivo(nombreArchivo, ios::binary);

    //comprobando
    if(!archivo){
        cerr << "Error al leer el archivo binario\n";
    }

    //3ER PASO
    estudiante e;
    while(archivo.read((char*)&e, sizeof(estudiante))){    //estados del stream --> impresos en consola
        cout << e.nombre << " -- " << e.nota << "\n";
    }

    //4TO PASO
    archivo.close();
}