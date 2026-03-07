#include <iostream>
#include <string>
#include <cstring>
using namespace std;

//2. Ordenando tiempos con INSERTIONsort------------------
void insertion(int* tiempos, char (*nombres)[20], int N){
    for(int i=1; i<N; i++){
        int TempTiempo= tiempos[i];                 //estos son importantísimos para mantenerlo guardado cuando lo quiero volver a "pegar"
        char TempNombre[20];
        strcpy(TempNombre, nombres[i]);

        int j= i-1;
        while(j>= 0 && tiempos[j]> TempTiempo){
            tiempos[j+1]= tiempos[j];
            
            //Paralelamente con los elementos de nombre tambien
            strcpy( nombres[j+1], nombres[j]);              //--> me habia olvidado el nombre de esta funcion (por eso no la usé)
            j--; 
        }

        tiempos[j+1]= TempTiempo; 
        strcpy( nombres[j+1], TempNombre);
    }

    return;
}


//3. Ranking--------------
void imprimirRanking(int* tiempos, char (*nombres)[20], int N){
    cout << "RANKING FINAL\n";
    for(int i=0; i<N; i++){
        cout << i+1 << ".\t" << nombres[i] << "-\t" << tiempos[i] << " segundos";
        cout << "\n";
    }

    return;
}



//4. BusquedaLineal------------
int lineal(char (*nombres)[20], int N, string nombreBuscar){      //va a retornar el indice del corredor
    for(int i=0; i<N; i++){
        if( strcmp(nombres[i], nombreBuscar.c_str())== 0){       //strcmp() y nombre.c_str() --> eran justo lo que necesitaba y no me acordaba de ellos
            return i;
        }
    }

    return -1;          //si es que no lo encuentra
}



//5. Rango de tiempo
void rangoTiempo(int* tiempos, char (*nombres)[20], int N, int rango1, int rango2){
    cout << "\nCorredores en el rango [" << rango1 << ", " << rango2 << "]:\n";
    bool encontrado= false;

    for(int i=0; i<N; i++){
        if(tiempos[i] >= rango1 && tiempos[i] <= rango2){
            cout << nombres[i] << "\t---\t" << " segundos\n";
            encontrado= true;
        }
    }

    if(!encontrado){
        cout << "No hay corredores en ese rango.\n";
    }
}





//main---------------------
//
//
//
int main(){
    //
    char nombres[30][20]= {'Z'};
    int tiempos[30]= {-1};       //si esta con "-1" o "Z" significa que no se llenó

    //1.Pidiendo datos-----
    int N;
    cout << "Ingrese el numero de corredores:: ";
    cin >> N;
    cin.ignore();               //importante. O sino no funciona getline()

    for(int i=0; i<N; i++){
        //i) Primero el nombre
        string temp;
        cout << "Nombre del corredor '" << i+1 << "' es:: ";
        getline(cin, temp);

        //ahora lo pongo en mi arreglo de punteros
        int tamPalabra= temp.length();
        for(int j=0; j<tamPalabra+1; j++){
            *(nombres[i]+j)= temp[j];
            *(nombres[i]+tamPalabra)= '\0';         //para que funcione con funciones de cstring
        }

        //ii) Luego el tiempo
        cout << "Tiempo (En segundos):: ";
        cin >> tiempos[i];
        cin.ignore();


        cout << "\n";     //Dejo espacio para el siguiente nomnreYtiempo
    }

    //2.Ordenando con respecto a tiempo----
    insertion(tiempos, nombres, N);


    //3. Imprimir Ranking
    imprimirRanking(tiempos, nombres, N);


    //4. Datos a buscar (lineal)
    string nombreBuscar;
    cout << "\n\nIngrese nombre a buscar:: ";
    cin >> nombreBuscar;
    int indiceEncontrado= lineal(nombres, N, nombreBuscar);

    if(indiceEncontrado== -1){
        cout << "\nno se encontro el nombre del corredor\n";
    }else{
        cout << "\nCORREDOR ENCONTRADO";
        cout << "\nPosicion:: " << indiceEncontrado+1;
        cout << "\nTiempo:: " << tiempos[indiceEncontrado];
    }



    //5. JUgadores en un rango de tiempo
    int rango1;
    cout << "\n\n\nIngrese el rangoIZQUIERDO de tiempo:: ";
    cin >> rango1;

    int rango2;
    cout << "Ingrese el rangoDERECHO de tiempo:: ";
    cin >> rango2;

    rangoTiempo(tiempos, nombres, N, rango1, rango2);


    //
    cout << "\n\n-------------END\n";
    return 0;
}
