#include <iostream>
//#include <cstring>      //para obtener tamaño de string --> strlen(string)
#include <string>       // es necesario para los string --> ya que cstring no funcionaría en este caso
#include <cctype>       //para convertir a minuscula --> todown(char)
using namespace std;

//function1


//function2


//function3


//function4


//function5


//function6
//*char rellenarArregloDinamico(const string& frase, int tam){   //para ser más eficiente y asegurarme que no se modifique por error
char* rellenarArregloDinamico(const string& frase, int tam){    //el "*" va después del char
    char* PUNfrase1= new char[tam];

    for(int i=0; i<tam+1; i++){             //((ERROR1)) --> lo más recomendable es darle uno más siempre AL FINAL
        if(i== tam){
            PUNfrase1[i]= '\0';
        }else{
            PUNfrase1[i]= frase[i];
        }

    }

    return PUNfrase1;           //Estoy devolviendo un puntero
}



//function7
int eliminarEspacios(char* PUNfrase2, int tam){
    //primero llevo los espacios al final --> con BubbleSORT
    int ultimoIndice=0;
    for(int i=0; i<tam-1; i++){
        for(int j=0; j<tam-1-i; j++){
            if(PUNfrase2[j]== ' '){
                swap(PUNfrase2[j], PUNfrase2[j+1]); //mi ultimo indice en donde se colocó el espacio fue "j+1"
            }
            ultimoIndice= j+1;
        }
    }

    return ultimoIndice+1;  //el tamaño de una cadena/arreglo es el "último indice+1"
}



//function8
void minusculas(char* PUNfrase2, int nuevoTam){
    for(int i=0; i<nuevoTam; i++){
        //todown(PUNfrase2[i]);     --> lowercase are the vowels not capitalized
        //ademas tolowe() no modifica al valor original,,, lo necesario es
        PUNfrase2[i]= tolower(PUNfrase2[i]);
    }

    cout << "\n";
    return;
}


/*
//function9
void imprimir(char* PUNfrase2, int nuevoTam){
    for(int i=0; i<nuevoTam; i++){
        cout << PUNfrase2[i];
    }

    cout << "\n";
    return;
}
*/
//lo repeti sin querer en "function10"


//function10
void imprimir(char* PUNfrase2, int nuevoTam){
    for(int i=0; i<nuevoTam; i++){
        cout << PUNfrase2[i];
    }

    cout << "\n";
    return;
}



//function11
int contarPalabras(char* PUNfrase2, int tam, char* palabras){
    int cantidadPalabras= 0;
    bool adentroPalabra= false;

    for(int i=0; i<tam; i++){
        if(!adentroPalabra){
            palabras[cantidadPalabras]= PUNfrase2[i];
            cantidadPalabras++;
        }else{
            if(PUNfrase2[i-1]== ' ' && PUNfrase2[i]!= ' '){             //si detecta que está en un caracter y el anterior es un espacio, entonces estamos en el inicio de una nueva palabra
                adentroPalabra= true;
            }else{
                adentroPalabra= false;
            }
            if(!adentroPalabra){
                palabras[cantidadPalabras]= PUNfrase2[i];               //ERROR(2) --> tenia que poner "cantidadPalabras" --> no "i"
                cantidadPalabras++;
            }
        }
    }

    return cantidadPalabras;                //devuelvo el numero de palabras que se hallaron y además dejo llenado el arreglo de punteros "palabras"
}
//luego voy a necesitar otra función para que mida las palabras hasta que encuentre el espacio



//function12
void longitudPalabraImprimir(int cantidadPalabras, char** PUNpalabras){
    for(int i=0; i<cantidadPalabras; i++){
        int j=0;
        while(PUNpalabras[i][j]!= ' '){
            j++;
        }

        for(int h=0; h<j; h++){
            cout << PUNpalabras[i][h];
        }

        cout << "\nContiene '" << j << "' letras";
        cout << "\n\n";
    }

    return;
}




//main
//
int main(){
    //pido frase
    string frase;
    cout << "Ingrese su frase:: ";
    getline(cin, frase);


    //memoria dinámica ((llenandola con mi frase))
    //int tam= strlen(frase);         //pido el tamaño del string
    int tam= frase.length();
    char* PUNfrase2= rellenarArregloDinamico(frase, tam);        //ahora mi "PUNfrase2" es el único que tiene la dirección dinámico el "PUNfrase1" ya se borró

    
    //cada elemento de "palabras[]" es un puntero
    char palabras[100][20];       //un arreglo en el que cada fila será una pálabra y cada una tendrá como maximo 20 letras
    char* PUNpalabras[100];                  // un arreglo de punteros
    for(int i=0; i<100; i++){
        PUNpalabras[i]= &palabras[i][0];        //apunto el inicio de cada fila
    }

    //
    int cantidadPalabras= contarPalabras(PUNfrase2, tam, PUNpalabras[0]);     //coloco el inicio del arrelgo de punteros

    //cada inicio de palabra se apunta al arreglo de punteros
    longitudPalabraImprimir(cantidadPalabras, PUNpalabras);



    //
    //
    cout << "\n\n\n\n";
    //borrando espacios
    int nuevoTam= eliminarEspacios(PUNfrase2, tam);


    //convirtiendo todas las letras a minusculas
    minusculas(PUNfrase2, nuevoTam);

    //imprimo mi resultado con 0 espacios
    imprimir(PUNfrase2, tam);

    //delete PUNfrase2;               //ahora sí "sin memory leaks"
    delete[] PUNfrase2;             //era un delte[] porque lo habia declarado al comeinzo como "new char[tam]"

    cout << "\n\n-------------END\n";
    return 0;
}