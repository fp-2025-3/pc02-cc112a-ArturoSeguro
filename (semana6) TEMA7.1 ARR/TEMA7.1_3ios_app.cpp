#include <iostream>
#include <fstream>      //para manipular archivos
using namespace std;

int main(){
    //PASO1: INSTANCIAR::       quiero agregar estudiantes
    //PASO2: CONECTAR::         conectar al archivo txt
    ofstream agregando("notas.txt", ios::app | ios::out);

    //comprobación para ver si el archivo existe
    if(!agregando){
        cerr << "Error porque no se pudo abrir archivo para su LECTURA\n";
        return 1;
    }

    //PASO3: USAR::             leer/escribir archivos (escribiendo en notas.txt)
    agregando << "Americo\t 50";

    //PASO4: DESCONECTAR::      desconectamos el achivo texto 
    agregando.close();




    return 0;
}

//PASO5: DESTRUCCIÓN::          automático al salir del "AMBITO" (ambiente)