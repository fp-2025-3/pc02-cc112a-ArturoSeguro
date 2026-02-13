#include <iostream>
using namespace std;


//
struct producto{
    char* nombre;               //cadea dinamica

    int codigo;
    double precio;
    int stock;
};


//
//1
producto crearProducto(){
    //STRUCT QUE SE DEVOLVERÁ
    producto actualPRO;


    //
    char* PUNnombre= new char[20];
    cout << "\n\n\nColoque el nombre:: ";
    cin.getline(PUNnombre, 20);
    actualPRO.nombre= PUNnombre;    

    //
    cout << "\nColoque el codigo:: ";
    cin >> actualPRO.codigo;
    cin.ignore();

    //
    cout << "\nColoque el precio:: ";
    cin >> actualPRO.precio;
    cin.ignore();

    //
    cout << "\nColoque el stock:: ";
    cin >> actualPRO.stock;
    cin.ignore();

    return actualPRO;
}


//3. INVENTARIO
void inventario(producto* actualPRO2){
    cout << "COdigo: " << (*actualPRO2).codigo << "\t|| NOmbre: " << (*actualPRO2).nombre << 
    "\t|| Precio: " << (*actualPRO2).precio << "\t|| Stock: " << (*actualPRO2).stock << "\n";
}








//2
producto* buscarProducto(producto* PRO, int cantidad, int codigoBuscado){
    for(int i=0; i<cantidad; i++){
        if(PRO[i].codigo== codigoBuscado){
            return PRO+i;
        }
    }

    return nullptr;     //no existe producto
}


//function4


//function5


//function6




//main
//
//
//
int main(){
    int cantidad;
    cout << "\nColoque el numero de productos a registrar: ";
    cin >> cantidad;
    cin.ignore();

    //
    producto PRO[cantidad];

    //1
    cout << "\n";
    for(int i=0; i<cantidad; i++){
        PRO[i]= crearProducto();
    }




    //3. Inventario
    for(int i=0; i<cantidad; i++){
        producto* TEMPpro= &PRO[i];
        inventario(TEMPpro);
    }









    //2 ((pidiendo producto))
    int codigoBuscado;
    cout << "\n\n\nCOloque el codigo del producto que busca:: ";
    cin >> codigoBuscado;
    cin.ignore();

    producto* productoBuscado= buscarProducto(PRO, cantidad, codigoBuscado);
    cout << "\nBuscando el producto de codigo " << codigoBuscado;
    if(productoBuscado== nullptr){
        cout << "\nProducto no encontrado";
    }else{
        cout << "\nProducto encontrado:: " << (*productoBuscado).nombre << " | " << "Precio: " << (*productoBuscado).precio;
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