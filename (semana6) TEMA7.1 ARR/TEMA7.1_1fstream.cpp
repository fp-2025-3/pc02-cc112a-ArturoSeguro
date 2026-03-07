#include <iostream>
#include <fstream>      //para manipular archivos
using namespace std;

int main(){
    //PASO1: INSTANCIAR::       intanciar un objeto de la clase ofstream
    ofstream archivoEscritura;

    //PASO2: CONECTAR::         conectar al archivo txt
    archivoEscritura.open("notas.txt");

    //comprobación para ver si el archivo existe
    if(!archivoEscritura){
        cerr << "Error porque no se pudo abrir archivo para su ESCRITURA\n";
        return 1;
    }

    //PASO3: USAR::             leer/escribir archivos (escribiendo en notas.txt)
    archivoEscritura << "Juan\t 15\n";
    archivoEscritura << "Pedro\t 11\n";
    archivoEscritura << "Arturo\t 22\n";

    //PASO4: DESCONECTAR::      desconectamos el achivo texto 
    archivoEscritura.close();




    return 0;
}

//PASO5: DESTRUCCIÓN::      al terminar el programa automaticamente se destruye (destructores)
//                          --> Ocurre cuando un objeto sale de su "AMBITO"
//                          --> En ese caso "archivoEstructura" solo tenia un alcance en el main()