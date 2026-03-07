#include <iostream>
#include <fstream>
#include <cstring>
using namespace std;


//---A.0
class cuentaBancaria{
    private:
        int numeroCuenta;
        double saldo;
        static int base;
        static double capitalTotal;
    public:
        //0
        cuentaBancaria(double S);
        cuentaBancaria(const cuentaBancaria&)= delete;
        //1
        void generarNC();
        void generarS(double S);
        void imprimriDatos() const;
        static double getCapitalTotal();
        //2
        ~cuentaBancaria();
};


//
int cuentaBancaria::base= 100000;
double cuentaBancaria::capitalTotal= 0;


//main
//
int main(){
    //
    cuentaBancaria c1(-1);
    cuentaBancaria c2(1300);
    cuentaBancaria c3(100);
    cuentaBancaria c4(400);
    cuentaBancaria c5(300);


    //
    cout << "\n\n-------------END\n";
    return 0;
}


//---B.0
//0
cuentaBancaria:: cuentaBancaria(double S){
    this->generarNC();
    this->generarS(S);
}
//1
void cuentaBancaria:: generarNC(){
    base++;
    this->numeroCuenta= base;
}
void cuentaBancaria:: generarS(double S){
    if(S<0){
        cout << "No se puede poner SALDO NEGATIVO. Se iniciará en 0.\n";
        this->saldo= 0;
    }else{
        this->saldo= S;
        cuentaBancaria:: capitalTotal= capitalTotal+ S;
    }
}
void cuentaBancaria:: imprimriDatos() const{
    cout << "Cuenta N: " << this->numeroCuenta << " | Saldo: $" << this->saldo << "\n";
}
double cuentaBancaria:: getCapitalTotal(){
    return capitalTotal;
}
//2
cuentaBancaria:: ~cuentaBancaria(){
    cuentaBancaria:: capitalTotal= capitalTotal- this->saldo;
    cout << "La cuenta" << this->numeroCuenta << "ha sido cerrada y el saldo devuelto es: $" << this->saldo << "\n";
    cout << "capital actual del banco tras cierre: $" << cuentaBancaria:: getCapitalTotal() << "\n";
}