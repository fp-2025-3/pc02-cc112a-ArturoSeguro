#include <iostream>
using namespace std;


//--1
//
struct producto{
    char* nombre;

    int codigo;
    double precio;
    int stock;
};


//--2
//
producto* crearProducto(){
    producto* actualPRO= new producto;

    //
    char* PUNnombre= new char[20];
    cout << "\n\n\nColoque el nombre:: ";
    cin.getline(PUNnombre, 20);
    (*actualPRO).nombre= PUNnombre;    
    //
    cout << "Coloque el codigo:: ";
    cin >> (*actualPRO).codigo;
    cin.ignore();
    //
    cout << "Coloque el precio:: ";
    cin >> (*actualPRO).precio;
    cin.ignore();
    //
    cout << "Coloque el stock:: ";
    cin >> (*actualPRO).stock;
    cin.ignore();

    return actualPRO;
}


//--3. INVENTARIO
//
void inventario(producto* actualPRO2){
    cout << "Codigo: " << (*actualPRO2).codigo << "\t|| Nombre: " << (*actualPRO2).nombre << 
    "\t|| Precio: " << (*actualPRO2).precio << "\t|| Stock: " << (*actualPRO2).stock << "\n";
}


//--4
//
producto* buscarProducto(producto** PRO, int cantidad, int codigoBuscado){
    for(int i=0; i<cantidad; i++){
        if((*PRO[i]).codigo== codigoBuscado){
            return PRO[i];
        }
    }

    return nullptr;
}


//main
//
int main(){
    int cantidad;
    cout << "\nColoque el numero de productos a registrar: ";
    cin >> cantidad;
    cin.ignore();
    producto** PRO= new producto*[cantidad];


    //--2
    cout << "\n";
    for(int i=0; i<cantidad; i++){
        PRO[i]= crearProducto();
    }


    //--3
    cout << "\n\n\nINVENTARIO----------\n";
    for(int i=0; i<cantidad; i++){
        producto* TEMPpro= PRO[i];
        inventario(TEMPpro);
    }


    //--4
    int codigoBuscado;
    cout << "\n\n\nCOloque el codigo del producto que busca:: ";
    cin >> codigoBuscado;
    cin.ignore();
    //
    producto* productoBuscado= buscarProducto(PRO, cantidad, codigoBuscado);
    cout << "\nBuscando el producto de codigo " << codigoBuscado << "........";
    if(productoBuscado== nullptr){
        cout << "\nProducto no encontrado";
    }else{
        cout << "\nProducto encontrado:: " << (*productoBuscado).nombre << " | " << "Precio: " << (*productoBuscado).precio;
    }
 

    //delete
    for(int i=0; i<cantidad; i++){
        delete[] (*PRO[i]).nombre;  //deleting (char) lo creado en "crearProducto()""
        delete PRO[i];              //deleting (struct) lo creado también en "crearProducto()"
    }
    delete[] PRO;                   //deleting (struct) lo creado en este main (**PRO)
    


    cout << "\n\n-------------END\n";
    return 0;
}