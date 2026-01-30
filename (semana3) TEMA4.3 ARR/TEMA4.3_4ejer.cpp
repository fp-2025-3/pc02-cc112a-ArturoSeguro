#include <iostream>
#include <cctype>
#include <cstring>
#include <cstdlib>
using namespace std;


//function 1
int palabrasSeparar(char* texto, char* palabras[60]){
    int i=0;
    int cantidad=0;

    bool entraPalabra= false;
    while( *(texto+i)!= '\0'){

        if(!entraPalabra){
            palabras[cantidad]= (texto+i);
            cantidad++;

            entraPalabra= true;         //ya esta en palabra
        }

        if( *(texto+i)== ' '){
            entraPalabra= false;        //entrará a una palbra en la proxima
        }
        
        i++;
    }

    //cout << cantidad;
    return cantidad;           //esta es la cantidad de numeros que he guardado en mi arrgelo de punteros
}




//function 2                        -->BubbleSOrt alfabetico
void ordenar(char* palabras[60], int cantidad){
    for(int i=0; i<cantidad-1; i++){
        for(int j=0; j<cantidad-1-j; j++){
            char a= *palabras[j];
            char b= *palabras[j+1];

            a= toupper(a);
            b= toupper(b);

            if(b< a){
                swap(palabras[j], palabras[j+1]);
            }
            
        }
    }
}





//function 4
int len1(char* tama){       //ya no se que nombre ponerle 
    int i=0;

    while(*(tama+i)!= ' ' && *(tama+i)!= '\0'){
        i++;
    }

    return i;
}




//function 3
void imprimirResultado(char* palabras[60], int cantidad){
    cout << "Palabras ordenadas:: \n";

    for(int i=0; i<cantidad; i++){
        char* tama= palabras[i];
        int tam= len1(tama);

        for(int j=0; j<tam; j++){
            cout << *(palabras[i]+j);
        }
        cout << "\n";
    }
}




int main(){
    char texto[]= "Los punteros no se copian se referencian y se ordenan";
    char* palabras[60];

    //
    int cantidad= palabrasSeparar(&texto[0], palabras);

    //
    ordenar(palabras, cantidad);

    //
    imprimirResultado(palabras, cantidad);

    return 0;
}