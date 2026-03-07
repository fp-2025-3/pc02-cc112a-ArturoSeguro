#include <iostream>
#include <cstdlib>
#include <cstring>
using namespace std;

void clasificador(char texto[300], char* palabras[60], char* cortas[60], char* largas[60]){
    //primero los tokenizo (Separa palabras)
    int primeraLETRA= 0;
    int i=0;

    int j=0;    //movedor de lugar de "texto[]"
    int k=0;    //movedor de lugar de "cortas[]"     
    int h=0;    //movedor de lugar de "largas[]" 
    do{
        if(*(texto+i)== 0 || *(texto+i-1)= '\0'){
            (palabras+j)= (texto+i);
            j++;
            if( (i-primeraLETRA+1)<= 3){       //es necesario el "+1" para todos los casos
                (cortas+j)= (texto+i);
                k++;    
            }else{
                (largas+j)= (texto+i);
                k++; 
            }
        }

        i++;
    }while(strlen(texto)+1<= i);            //esto medirá hasta uno maś de todos los elementos de mi array texto[300], el último será '-1' 
}


int main(){
    char texto[300]= {'-1'};            //lo lleno todo de "-1"
    cout << "Ingrese el texto:: \n";
    cin.getline(texto, 300);




    char* palabras[60];
    char* cortas[60];
    char* largas[60];




    return 0;
}



//Ya me perdi por completo
//voy  a uintentarlo por completo usando los prototipos del profe