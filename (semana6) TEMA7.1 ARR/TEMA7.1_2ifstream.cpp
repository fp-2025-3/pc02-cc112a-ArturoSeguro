#include <iostream>
#include <fstream>      //para manipular archivos
using namespace std;

int main(){
    //PASO1: INSTANCIAR::       intanciar un objeto de la clase ofstream
    ifstream archivoLectura;

    //PASO2: CONECTAR::         conectar al archivo txt
    archivoLectura.open("notas.txt");

    //comprobación para ver si el archivo existe
    if(!archivoLectura){
        cerr << "Error porque no se pudo abrir archivo para su LECTURA\n";
        return 1;
    }

    //PASO3: USAR::             leer/escribir archivos (escribiendo en notas.txt)
    string nombre;
    int nota;
    while(archivoLectura >> nombre >> nota){    //estados del stream --> impresos en consola
        cout << nombre << " -- " << nota << "\n";
    }

    //PASO4: DESCONECTAR::      desconectamos el achivo texto 
    archivoLectura.close();




    return 0;
}

//PASO5: DESTRUCCIÓN::          automático al salir del "AMBITO" (ambiente)