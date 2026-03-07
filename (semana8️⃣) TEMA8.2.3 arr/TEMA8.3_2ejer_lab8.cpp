#include <iostream>
#include <fstream>
#include <cstring>
#include <string>
using namespace std;


//---a
struct cuentaBancaria{
    int codigo;
    char titular[40];
    double saldo;
    bool activa;
};
//
const char* nombreArchivo= "TEMA8.3_2cuentas.dat";


//---0
bool repetido(cuentaBancaria* cB, int codigoBuscado, int indice){
    for(int i=0; i<indice; i++){
        if(cB[i].codigo== codigoBuscado){
            return true;
        }
    }
    return false;
}


//---1
void crear(const char* nombreArchivo, int N){
    //1er, 2do
    ofstream escribir(nombreArchivo, ios:: out | ios::binary);
    if(!escribir){
        cerr << "No se pudo abrir archivo.\n";
    }
    //3er
    cuentaBancaria* cB= new cuentaBancaria[N];
    for(int i=0; i<N; i++){
        bool repeticion;
        cout << "-->--> Cuenta Numero '" << i+1 << "'\n";
        do{
            cout << "Dea el Codigo de Cuenta: ";
            cin >> cB[i].codigo;
            repeticion= repetido(cB, cB[i].codigo, i);
            if(repeticion== true){
                cout << "[error] --> El codigo no puede ser el mismo.\nColoque otro.\n";
            }
        }while(repeticion== true);
        cout << "Dea el nombre del titular: ";
        cin >> cB[i].titular;
        cout << "Dea el monto del saldo: ";
        cin >> cB[i].saldo;
        cB[i].activa= true;
    }
    //ordenamiento
    for(int i=0; i<N-1; i++){
        for(int j=0; j<N-1-i; j++){
            if(cB[j].codigo> cB[j+1].codigo){
                swap(cB[j], cB[j+1]);
            }
        }
    }
    //
    for(int i=0; i<N; i++){
        escribir.write((char*)(&cB[i]), sizeof(cuentaBancaria));
    }
    //4to
    escribir.close();
    delete[] cB;
}


//---3
void imprimir(cuentaBancaria cB){
    cout << "codigo de cuenta: " << cB.codigo << "\n";
    cout << "nolmbre de titular: " << cB.titular << "\n";
    cout << "saldo de cuenta: " << cB.saldo << "\n";
}


//---2
void buscar(const char* nombreArchivo, int posicion){
    //1er, 2do
    ifstream leer(nombreArchivo, ios:: in | ios::binary);
    if(!leer){
        cerr << "No se pudo abrir archivo.\n";
    }
    //3er
    cuentaBancaria cB;
    leer.seekg(posicion*sizeof(cuentaBancaria), ios::beg);
    leer.read((char*)(&cB), sizeof(cuentaBancaria));
    if(cB.activa){
        cout << "=== CUENTA ENCONTADA ===\n";
        imprimir(cB);
    }
    //4to
    leer.close();
}


//---5
int buscarCodigo(const char* nombreArchivo, int codigoBuscado){
    //1er, 2do
    ifstream leer(nombreArchivo, ios:: in | ios::binary);
    if(!leer){
        cerr << "No se pudo abrir archivo.\n";
    }
    //3er
    cuentaBancaria cB;
    int j=0;
    while(leer.read((char*)(&cB), sizeof(cuentaBancaria))){
        if(cB.codigo== codigoBuscado){
            leer.close();
            return j;        //devuelve linea (posicion)
        }
        j++;
    }
    //4to
    leer.close();
    return -1;               //no lo encontro
}


//---4
void modificar(const char* nombreArchivo){
    //1er, 2do
    fstream modificacion(nombreArchivo, ios::in | ios::out | ios::binary);
    if(!modificacion){
        cerr << "No se pudo abrir archivo.\n";
    }
    //3er
    cuentaBancaria cB;
    int codigoBuscar;
    cout << "digite el codigo de a cuenta a modificar: ";
    cin >> codigoBuscar;
    int posicion= buscarCodigo(nombreArchivo, codigoBuscar);
    if(posicion!= -1){
        modificacion.seekg(posicion*sizeof(cuentaBancaria), ios::beg);
        modificacion.read((char*)(&cB), sizeof(cuentaBancaria));
    }else{
        cout << "[error] --> no se ecnontro el ID colocado.\n";
        return;
    }
    if(cB.activa== false){
        cout << "[error] --> la cuenta esta desactivada.\n";
        return;
    }
    //
    char decision;
    cout << "Seleccione si dese retirar o depositar (r/d): ";
    cin >> decision;
    double retiro;
    double deposito;
    if(decision== 'r'){
        do{
            cout << "ingrese el monto a retirar: ";
            cin >> retiro;
            if(cB.saldo-retiro< 0){
                cout << "[error] --> el slado actual de la cuenta es '" << cB.saldo << "'\n";
                cout << "elija un retiro de monto menor al saldo porfavor.\n";
            }
        }while(cB.saldo-retiro< 0);
    }else if(decision== 'd'){
        cout << "ingrese el monto a depositar: ";
        cin >> deposito;
    }
    //
    if(decision== 'r'){
        cB.saldo-= retiro;
    }else if(decision== 'd'){
        cB.saldo+= deposito;
    }
    //
    modificacion.seekp(posicion*sizeof(cuentaBancaria), ios::beg);
    modificacion.write((char*)(&cB), sizeof(cuentaBancaria));
    //4to
    modificacion.close();
}


//---6
void desactivar(const char* nombreArchivo, int codigoBuscado){
    //1er, 2do
    fstream modificacion(nombreArchivo, ios::in | ios::out | ios::binary);
    if(!modificacion){
        cerr << "No se pudo abrir archivo.\n";
    }
    //3er
    cuentaBancaria cB;
    int posicion= buscarCodigo(nombreArchivo, codigoBuscado);
    modificacion.seekg(posicion*sizeof(cuentaBancaria), ios::beg);
    modificacion.read((char*)(&cB), sizeof(cuentaBancaria));
    cB.activa= false;
    //
    modificacion.seekp(posicion*sizeof(cuentaBancaria), ios::beg);
    modificacion.write((char*)(&cB), sizeof(cuentaBancaria));
    //4to
    modificacion.close();
}
//---7
void mostrarTodo(const char* nombreArchivo){
    //1er, 2do
    ifstream leer(nombreArchivo, ios:: in | ios::binary);
    if(!leer){
        cerr << "No se pudo abrir archivo.\n";
    }
    //3er
    cuentaBancaria cB;
    int i=0;
    while(leer.read((char*)(&cB), sizeof(cuentaBancaria))){
        if(cB.activa){
            cout << "-->--> Cuenta Numero '" << i+1 << "'\n";
            imprimir(cB);
        }
        i++;
    }
    //4to
    leer.close();
}


//main
//
int main(){
    //---1
    int N;
    cout << "ingrese el numero de cuentasBancarias con las que iniciar: ";
    cin >> N;
    crear(nombreArchivo, N);
    cout << "\n\n";
    //---2
    int posicion;
    do{
        cout << "coloqiue la linea (posicion) de la cuenta que busca (de '0' hasta '" << N-1 << "'): ";
        cin >> posicion;
        if(posicion<0 && posicion>=N){
            cout << "[error] --> solo estan permitido los valores en parentesis.\nDea valores correctos porfavor.\n";
        }
    }while(posicion<0 && posicion>=N);
    buscar(nombreArchivo, posicion);
    cout << "\n\n";
    //---4
    modificar(nombreArchivo);
    cout << "\n\n";
    //---6
    int codigoBuscar;
    cout << "digite el codigo de la cuenta a eliminar: ";
    cin >> codigoBuscar;
    desactivar(nombreArchivo, codigoBuscar);
    cout << "\n\n";
    //---7
    mostrarTodo(nombreArchivo);


    //
    cout << "\n\n-------------END\n";
    return 0;
}