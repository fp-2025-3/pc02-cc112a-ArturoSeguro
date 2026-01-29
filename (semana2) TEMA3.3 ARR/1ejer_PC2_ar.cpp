#include <iostream>
using namespace std;

//función1
//
void derivacion(double* p, int orden, int derivada, int &PrimerIndice){
    int copiaPrimerIndice= PrimerIndice;
    for(int i=0; i<=derivada-1; i++){
        for(int j=0; j<=orden; j++){
            *(p+j)= *(p+j)*(j-i);
        }
        
        copiaPrimerIndice++;
    }

    PrimerIndice= copiaPrimerIndice;
}


//función2
//
void PolinomioImpreso(double* p, int orden, int &PrimerIndice){
    for(int i=orden; i>=PrimerIndice; i--){
        if(i-PrimerIndice== 0){
            cout << *(p+i);
        }else{
            cout << *(p+i) << "x^"<< i-PrimerIndice << " + ";
        }
    }
}


//main
//
int main(){
    int orden;
    cout << "Ingrese el orden de la funcion: \n";
    cin >> orden;
    int derivada= 0;

    //
    double coeficientes[100]= {0};
    for(int i=0; i<=orden; i++){
        cout << "Ingrese el coeficiente de orden" << i << " ::";
        cin >> coeficientes[i];
        cout << "\n";
    }

    //
    double* p= coeficientes;

    int PrimerIndice= 0;
    PolinomioImpreso(p, orden, PrimerIndice);          //comienza de orden 0;

    //
    cout << "\n\nCual es el orden de la derivada:: ";
    cin >> derivada;

    derivacion(p, orden, derivada, PrimerIndice);
    PolinomioImpreso(p, orden, PrimerIndice);            //este orden ya esta modificado (se modifico en "derivacion()")

    return 0;
}
