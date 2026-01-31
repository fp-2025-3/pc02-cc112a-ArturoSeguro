#include <iostream>
#include <cctype>
#include <cstring>
#include <cstdlib>
using namespace std;


//function 1
int palabrasSeparar(char* texto, char* palabras[60], int* PUNindices){
    int i=0;
    int cantidad=0;

    bool entraPalabra= false;
    while( *(texto+i)!= '\0'){

        if(!entraPalabra){
            palabras[cantidad]= (texto+i);
            *(PUNindices+cantidad)= i;          //aca me aseguro de guardar el indice de la primera letra de la palabra
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
void ordenar(char* palabras[60], int cantidad, int* PUNindices){
    for(int i=0; i<cantidad-1; i++){
        for(int j=0; j<cantidad-1-i; j++){      //cometí un horrible error aca --> era "-i" no "-j" --> no me di cuenta
            char a= *palabras[j];
            char b= *palabras[j+1];

            a= toupper(a);
            b= toupper(b);

            if(b< a){
                swap(palabras[j], palabras[j+1]);
                swap( *(PUNindices+j), *(PUNindices+j+1));
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
void imprimirResultado(char* palabras[60], int cantidad, int* PUNindices){
    cout << "Palabras ordenadas:: \n";

    for(int i=0; i<cantidad; i++){
        char* tama= palabras[i];
        int tam= len1(tama);

        for(int j=0; j<tam; j++){
            cout << *(palabras[i]+j);
        }
        cout << "\n--->(orden '" << *(PUNindices+i) << "')";
        cout << "\n\n";
    }
}




int main(){
    char texto[]= "Los punteros no se copian se referencian y se ordenan";
    char* palabras[60];

    //  -->--> No me di cuenta a tiempo de que pedian número de ornde tabién y ya no me quedaba tiempo
    int indices[60];      //estos serán mis indices que me permitiran imprimirlo como en el ejemplo
    int* PUNindices= &indices[0];


    //
    int cantidad= palabrasSeparar(&texto[0], palabras, PUNindices);

    //
    ordenar(palabras, cantidad, PUNindices);

    //
    imprimirResultado(palabras, cantidad, PUNindices);

    return 0;
}