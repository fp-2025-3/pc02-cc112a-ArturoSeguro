#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

//
struct polinomio{
    int grado;
    int coeficiente;
    polinomio* siguiente;
};

//function1
polinomio* filling(int grado){
    polinomio* cabeza= nullptr;
    polinomio* cola= nullptr;

    for(int i=grado; i>= 0; i--){       
        polinomio* actualCoefi= new polinomio;
        (*actualCoefi).siguiente= nullptr;

        //
        (*actualCoefi).grado= i;
        (*actualCoefi).coeficiente= (rand()%30)-5;  //para que puedan haber negativos
   
        //
        if(cabeza== nullptr){
            cabeza= actualCoefi;
            cola= actualCoefi;
        }else{
            (*cola).siguiente= actualCoefi;
            cola= actualCoefi;
        }
    }

    //
    return cabeza;        
}




//
void imprimiendoPolinomio(polinomio* cabeza){
    polinomio* actual1= cabeza;

    while(actual1!= nullptr){
        cout << (*actual1).coeficiente << "x^" << (*actual1).grado;

        //
        if( (*actual1).siguiente!= nullptr){
            cout << " + ";
        }
        actual1= (*actual1).siguiente;
    }

    cout << "\n";
    return;
}

//function3


//function4
void sumar(polinomio* cabeza0, polinomio** todos){          //necesito que el grado mayor gane
    polinomio* actual3= cabeza0;

    polinomio* actual31= &todos[0][0];
    polinomio* actual32= &todos[0][1];
    polinomio* actual33= &todos[0][2];


    int i= (*cabeza0).grado;
    while(actual3!= nullptr){
        (*actual31).coeficiente= (*actual31).coeficiente+ (*actual32).coeficiente+ (*actual33).coeficiente;

        //paso al siguiente
        actual3= (*actual3).siguiente;

        actual31= (*actual31).siguiente;
        actual32= (*actual32).siguiente;
        actual33= (*actual33).siguiente;


        i--;
    }

    cout << "\n";
    return;
}





//function5


//function6
//
void deleteCoeficientes(polinomio* cabeza){
    while(cabeza!= nullptr){
        polinomio* actual2= cabeza;
        cabeza= (*cabeza).siguiente;        

        delete actual2;
    }

    return;
}


 
//main
//
//
//
int main(){
    srand(time(0));

    int cantidad= 3;
    polinomio** PUNpolinomio= new polinomio*[cantidad];

    cout << "\n";
    //
    for(int i=0; i<cantidad; i++){
        cout << "\n\n";
        int gradoTEMP= 4;
        PUNpolinomio[i]= filling(gradoTEMP);

        cout << "\n\n\n";
    }

    //
    for(int i=0; i<cantidad; i++){
        cout << i+1 << "<-- Polinomio: ";
        imprimiendoPolinomio(PUNpolinomio[i]);
    }



    //SUMAR
    int gradoMayor= -1;
    int INpolinomio= -1;
    for(int i=0; i<cantidad; i++){
        if(gradoMayor< (*PUNpolinomio[i]).grado){
            gradoMayor= (*PUNpolinomio[i]).grado;
            INpolinomio= i;
        }
    }

    //falta terminarlo
    polinomio tempCAMBIADO= *PUNpolinomio[INpolinomio];
    sumar(PUNpolinomio[INpolinomio], &PUNpolinomio[0]);
    imprimiendoPolinomio(PUNpolinomio[INpolinomio]);

    *PUNpolinomio[INpolinomio]= tempCAMBIADO;       //lo devulevo (porque e la función lo habia cambiado)







    //delete todo slos coeficientes que creee
    for(int i=0; i<cantidad; i++){
        deleteCoeficientes(PUNpolinomio[i]);
    }



    //function1


    //function2


    //function3


    //function4


    //function5


    //function6
    


    cout << "\n\n-------------END\n";
    return 0;
}