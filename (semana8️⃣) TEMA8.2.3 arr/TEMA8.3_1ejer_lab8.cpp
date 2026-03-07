#include <iostream>
#include <cstring>
#include <string>
#include <cmath>
using namespace std;


//---b
struct termino{
    double coeficiente;
    int exponente;
};
//---a
struct polinomio{
    termino* terminos;
    int cantidad;
};


//---1
void crearPolinomio(polinomio& p, int n){
    p.cantidad= n;
    p.terminos= new termino[n];
}
//---2
void leerPolinomio(polinomio& p){
    for(int i=0; i<p.cantidad; i++){
        cout << "termino '" << i+1 << "' --> digite el coeficiente: ";
        cin >> p.terminos[i].coeficiente;
        //
        cout << "termino '" << i+1 << "' --> digite el exponente: ";
        cin >> p.terminos[i].exponente;
        //
        cout << "\n";
    }
    //
    for(int i=0; i<p.cantidad-1; i++){
        for(int j=0; j<p.cantidad-1-i; j++){
            if(p.terminos[j].exponente< p.terminos[j+1].exponente){
                swap(p.terminos[j], p.terminos[j+1]);
            }
        }
    }
}
//---3
void mostrarPolinomio(const polinomio& p){
    for(int i=0; i<p.cantidad; i++){
        if(p.terminos[i].exponente== 0){
            if(i== p.cantidad-1){
                cout << p.terminos[i].coeficiente;
            }else{
                cout << p.terminos[i].coeficiente << " +";
            }
        }else if(p.terminos[i].exponente<0){
            continue;
        }else{
            if(i== p.cantidad-1){
                cout << p.terminos[i].coeficiente << "x^" << p.terminos[i].exponente;
            }else{
                cout << p.terminos[i].coeficiente << "x^" << p.terminos[i].exponente << " +";
            }
        }
    }
    cout << "\n";
}
//---4
double evaluarPolinomio(const polinomio& p, double x){
    double valorTotal= 0;
    for(int i=0; i<p.cantidad; i++){
        valorTotal+= p.terminos[i].coeficiente*(pow(x, p.terminos[i].exponente));
    }
    //
    return valorTotal;
}
//---5
void derivacion(const polinomio& p, polinomio& der){
    int contador= 0;
    for(int i=0; i<p.cantidad; i++){
        if(p.terminos[i].exponente>0){
            contador++;
        }
    }
    crearPolinomio(der, contador);
    //
    int j=0;
    for(int i=0; i<p.cantidad; i++){
        if(p.terminos[i].exponente>0 && p.terminos[i].coeficiente!= 0){
            der.terminos[j].coeficiente= p.terminos[i].coeficiente*p.terminos[i].exponente;
            der.terminos[j].exponente= p.terminos[i].exponente-1;
            j++;
        }else{
            continue;
        }
    }
}
//---6
void liberando(polinomio &p){
    delete[] p.terminos;
    p.terminos= nullptr;
    p.cantidad= 0;
}


//main
//
int main(){
    polinomio p;
    //
    crearPolinomio(p, 3);
    leerPolinomio(p);
    mostrarPolinomio(p);
    //
    double x;
    cout << "coloque el numero que desea evaluar en el polinomio: ";
    cin >> x;
    double evaluado= evaluarPolinomio(p, x);
    cout << "El valor evaluado es: " << evaluado << "\n";
    //
    polinomio der;
    derivacion(p, der);
    mostrarPolinomio(der);


    //delete
    liberando(der);
    liberando(p);


    //
    cout << "\n\n-------------END\n";
    return 0;
}