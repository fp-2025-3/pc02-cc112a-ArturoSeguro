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
    char* PUNfrase1= new char[tam+1];

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














//function11.3 ((solo para contar numero de palabras))
int soloNumeroPalabras(char* PUNfrase2, int tam){
    int cantidadPalabras= 0;  
    
    //
    cantidadPalabras++;         //la primera palabra siempre esta al comienzo

    //
    for(int i=1; i<tam; i++){
        if(PUNfrase2[i-1]== ' ' && PUNfrase2[i]!= ' '){             //si detecta que está en un caracter y el anterior es un espacio, entonces estamos en el inicio de una nueva palabra
            cantidadPalabras++;
        }else{
            //nothing
        }
    }

    //
    return cantidadPalabras;                //devuelvo solamente el numero de palabras
}


//function11.4
void rellenandoPunterosFinales(int indice, char* PUNfrase2, int longitudActual, char* PUNpalabrasActual){
    for(int i=0; i<longitudActual; i++){
        PUNpalabrasActual[i]= PUNfrase2[indice+i];
    }

    PUNpalabrasActual[longitudActual]= '\0';    //fin de arreglo

    //
    return;
}





///function11.2             --> en vex de poner PUNfrase2 ((puedo poner otro que me convenga))
int longitudPalabra(int indice, char* PUNfrase2){          //solo necesito el indice en donde quieren que comience a analizar y la matriz a analizar
    int i=0;
    while(PUNfrase2[indice+i]!= ' ' && PUNfrase2[indice+i]!= '\0'){         // como en otros casos uso "PUNpalabrasActual" entonces necesito '\0'
        i++;                        //era con un "y"= "&&", porque estoy con condiciones "negativas" --> que dan TRUE,,,,, me darán NEGATIVO cuando cualquiera de ellos se vuelva "Positivo"
    }

    //
    return i;
    /*
    return el tamaño de cada palabra añadiendo un "\0" al final porsiaca
            ->-->Esta función será llamada desde function12 donde se necesitará el tamaño en cada palabra para recién ahí asignarlo a "PUNpalabras"
    */
}


//function11                //ACA QUIERO hacer un "new char" para cada palabra
void RellenandoTOTALMENTEpunteros(char* PUNfrase2, int tam, char** &PUNpalabras){
    bool adentroPalabra;     
    
    //
    
    int longitudActual= longitudPalabra(0, PUNfrase2);
    PUNpalabras[0]= new char[longitudActual+1];          //el +1 es para ponerle el "\0" al final
    char* PUNpalabrasActual= PUNpalabras[0];    
    
    //función() para igualar todos los valores de este nuevo puntero
    rellenandoPunterosFinales(0, PUNfrase2, longitudActual, PUNpalabrasActual);
    
    int j=1;            //para ir rellenando correctamente PUNpalabras[]
    //
    for(int i=1; i<tam; i++){
        if(PUNfrase2[i-1]== ' ' && PUNfrase2[i]!= ' '){             //si detecta que está en un caracter y el anterior es un espacio, entonces estamos en el inicio de una nueva palabra
            adentroPalabra= false;              //lo había puesto alrevez --> cuando es "false"--> luego se pondrá "true" con "!" y ahí podré cargar la nueva palabra
        }else{
            adentroPalabra= true;
        }

        if(!adentroPalabra){
            longitudActual= longitudPalabra(i, PUNfrase2);
            PUNpalabras[j]= new char[longitudActual+1];              //el +1 es para ponerle el "\0" al final   
            PUNpalabrasActual= PUNpalabras[j];     

            //función() para igualar todos los valores de este nuevo puntero
            rellenandoPunterosFinales(i, PUNfrase2, longitudActual, PUNpalabrasActual);     //tenía que poner el "i" --> para actualizar el indice adecuado
            j++;        //hay que aumentarlo para la siguiente vez que se vaya a rellenar
        }
    }

    //
    return;           
}






//function12
void ImprimirPalabras(char* PUNfrase2, int numeroPalabras, char** PUNpalabras){
    int longitudActual= longitudPalabra(0, PUNfrase2);
    char* PUNpalabrasActual= PUNpalabras[0];
    for(int j=0; j<longitudActual+1; j++){      //ahora quiero imprimir mis palabras
        cout << PUNpalabrasActual[j];   //listo, ya estoy imprimiendo cada una de mis palabras
    }
    //ahora el numero de letras que tiene cada palabra
    cout << "\n(" << longitudActual << " letras)";
    cout << "\n\n";


    for(int i=1; i<numeroPalabras; i++){
        //
        longitudActual= longitudPalabra(0, PUNpalabras[i]);  
        PUNpalabrasActual= PUNpalabras[i];
        for(int j=0; j<longitudActual+1; j++){      //ahora quiero imprimir mis palabras
            cout << PUNpalabrasActual[j];   //listo ya imprimí mi for()
        }

        //ahora el numero de letras que tiene cada palabra
        cout << "\n(" << longitudActual << " letras)";

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

    




    //-------------------------------------------------((1ER GRAN CAMBIO DE ERRORES))
    //cada elemento de "palabras[]" es un puntero
    /*
    char palabras[100][20];       //un arreglo en el que cada fila será una pálabra y cada una tendrá como maximo 20 letras
    char* PUNpalabras[100];                  // un arreglo de punteros
    for(int i=0; i<100; i++){
        PUNpalabras[i]= &palabras[i][0];        //apunto el inicio de cada fila
    }
    */


    //MI RESULTADO --> PUNpalabras pero hecho dinámicamente (con arreglos anónimos en el "heap")
    int numeroPalabras= soloNumeroPalabras(PUNfrase2, tam);
    char** PUNpalabras= new char*[numeroPalabras];
    //    --> para hacerlo necesito otra función que me entregue el numero de digitos en la palabra
    //    --> función (que lo rellene adecuadamente cada uno)
    RellenandoTOTALMENTEpunteros(PUNfrase2, tam, PUNpalabras);


    ////ESTO LO CAMBIE a rellenandoPUNTEROSfinales()
    //int cantidadPalabras= contarPalabras(PUNfrase2, tam, PUNpalabras[0]);

    //cada inicio de palabra se apunta al arreglo de punteros
    ImprimirPalabras(PUNfrase2, numeroPalabras, PUNpalabras);





    cout << "------------------------------------------------\n";
    cout << "------------------------------------------------\n";
    cout << "------------------------------------------------\n";



    //
    //
    cout << "\n\n\n\n";
    //borrando espacios
    int nuevoTam= eliminarEspacios(PUNfrase2, tam);


    //convirtiendo todas las letras a minusculas
    minusculas(PUNfrase2, nuevoTam);

    //imprimo mi resultado con 0 espacios
    imprimir(PUNfrase2, tam);


    //3)tengo que BORRAR todas las reservas que hice con PUNpunteros[] dentro de rellenandoTOTALMENTE punteros
    for(int i=0; i<numeroPalabras; i++){        //hay una cantidad="numeroPalabras"  --> entonces debo borrar la misma cantidad de variables dinámicas (en el "heep")
        delete[] PUNpalabras[i];              
    }

    //2)tengo que eliminar la otra variable dinámica que había creado
    delete[] PUNpalabras;       //--> aunque sea un arrelgo de punteros, solo se pone delete[]


    //1)delete PUNfrase2;               //ahora sí "sin memory leaks"
    delete[] PUNfrase2;             //era un delte[] porque lo habia declarado al comeinzo como "new char[tam]"

    cout << "\n\n-------------END\n";
    return 0;
}