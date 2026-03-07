#include <iostream>
#include <cctype>
#include <cstring>
#include <cstdlib>
using namespace std;


//quiero que me detecte cuantas palabras comienzan con vocal

//function0
bool esVocal(char a){
    if(a== 'a' || a== 'e' || a== 'i' || a== 'o' || a== 'u'
        || a== 'A' || a== 'E' || a== 'I' || a== 'O' || a== 'U'){
        return true;
    }else{
        return false;
    }
}


//function 1
int palabrasSeparar(char* cadena, char* palabras[60]){
    int i=0;
    int cantidad=0;
    bool entraPalabra= false;
    while( *(cadena+i)!= '\0'){
        int a= *(cadena+i);

        if(!entraPalabra){
            if(esVocal(a)){
                palabras[cantidad]= (cadena+i);
                cantidad++;
            }
            entraPalabra= true;         //ya esta en palabra
        }

        if( *(cadena+i)== ' '){
            entraPalabra= false;        //entrará a una palbra en la proxima
        }
        
        i++;
    }

    return cantidad;           //esta es la cantidad de numeros que he guardado en mi arrgelo de punteros
}


//function 2



//function 3



//function 4



//function 5






int main(){
    char cadena[]= "este es un ejemplo en C++ END";
    char* palabras[60];

    cout << cadena << "\n";
    int cantidad= palabrasSeparar(&cadena[0], palabras);

    cout << "Numero de palabras que comienzan conn vocal:: " << cantidad;


    return 0;
}