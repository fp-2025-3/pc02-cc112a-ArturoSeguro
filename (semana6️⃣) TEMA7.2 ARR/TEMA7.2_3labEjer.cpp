#include <iostream>
#include <fstream>
#include <cstring>
using namespace std;

//
struct producto {
    int id;                  // Identificador único
    char nombre[30];         // Nombre del producto
    double precio;           // Precio unitario
    int stock;               // Cantidad disponible
    bool activo;             // true = activo, false = eliminado lógicamente
};


//---1
void registrarProducto(producto p[], int i){
    //id
    int TEMPid;
    int j;
    do{
        cout << "ID: ";
        cin >> TEMPid;
        for(j=0; j<i; j++){
            if(TEMPid== p[j].id){
                cout << "[ERROR]--> no repitas el ID de otro producto.\n";
                continue;
            }
        }break;
    }while(TEMPid== p[j].id);
    p[i].id= TEMPid;
    //nombre
    cout << "Nombre: ";
    cin >> p[i].nombre;
    //precio
    do{
        cout << "Precio: ";
        cin >> p[i].precio;
        if(p[i].precio<=0){
            cout << "[ERROR]--> coloca un precio mayor a 0 (>0).\n";
        }
    }while(p[i].precio<=0);
    //stock
    do{
        cout << "Cantidad de stock: ";
        cin >> p[i].stock;
        if(p[i].stock<0){
            cout << "[ERROR]--> coloca un numero de stock mayor= a 0 (>=0).\n";
        }
    }while(p[i].stock<=0);
    //valor de activo
    cout << "Esta activo? (true/false): ";
    cin >> p[i].activo;

    //
    return;
}


//---2
void mostrarProductos(const char* nombreArchivo){
    //1er,2do paso
    ifstream leer(nombreArchivo, ios::in);
    //3er paso
    producto TEMPp;
    int indice=0;
    while(leer >> TEMPp.id >> TEMPp.nombre >> TEMPp.precio >> TEMPp.stock >> TEMPp.activo){
        if(TEMPp.activo){
            cout << "Producto de la linea-->--> '" << indice+1 << "'\n";
            cout << "id: " << TEMPp.id << "\n";
            cout << "nombre: " << TEMPp.nombre << "\n";
            cout << "precio: " << TEMPp.precio << "\n";
            cout << "stock: " << TEMPp.stock << "\n";
        }
        indice++;
    }
    //4to paso
    leer.close();

    //
    return;
}


//---3
int buscarProducto(const char* nombreArchivo, int idBuscado){
    //1er,2do paso
    ifstream leer(nombreArchivo, ios::in);
    //3er paso
    producto TEMPp;
    int indice=0;
    while(leer >> TEMPp.id >> TEMPp.nombre >> TEMPp.precio >> TEMPp.stock >> TEMPp.activo){
        if(TEMPp.id== idBuscado){
            return indice+1;    //--> este es el número de linea
        }
        indice++;
    }
    //4to paso
    leer.close();

    //
    return -1;          //--> no se encontró
}


//---4
void modificarPrecio(const char* nombreArchivo, int id, double nuevoPrecio){
    //1er,2do paso
    ifstream leer(nombreArchivo, ios::in);
    //3er paso
    producto TEMPp;
    int indice=0;
    while(leer >> TEMPp.id >> TEMPp.nombre >> TEMPp.precio >> TEMPp.stock >> TEMPp.activo){
        if(TEMPp.id== id){
            TEMPp.precio= nuevoPrecio;
        }
        indice++;
    }
    //4to paso
    leer.close();
    //cómo modifico mi archivo binario???
}


//main
//
int main(){
    producto p[100];
    //---1
    int N;
    cout << "Coloque la cantidad de productos que desea crear: ";
    cin >> N;
    for(int i=0; i<N; i++){
        cout << "\n\nPRODUCTO--->---> " << i+1 << "\n";
        registrarProducto(p, i);
    }
    //1er,2do paso
    ofstream escribir("TEMA7.2_3inventario.dat", ios::out | ios::binary | ios::app);
    //3er paso
    for(int i=0; i<N; i++){
        escribir << p[i].id << " " << p[i].nombre << " " << p[i].precio << " " 
        << p[i].stock << " " << p[i].activo << "\n";
    }
    //4to paso
    escribir.close();


    //---2
    mostrarProductos("TEMA7.2_3inventario.dat");


    //---3
    int idBuscado;
    cout << "\nColoque el ID que desea buscar: ";
    cin >> idBuscado;
    int linea= buscarProducto("TEMA7.2_3inventario.dat", idBuscado);
    //
    if(linea== -1){
        cout << "no se encontró el id que colocaste.\n";
    }else{
        cout << "el id que buscas esta en -->--> linea '" << linea << "'\n";
    }


    //---4
    int id;
    cout << "\nColoque el ID que desea MODIFICAR: ";
    cin >> id;
    //
    int nuevoPrecio;
    cout << "\nColoque el PRECIO a colocar: ";
    cin >> nuevoPrecio;
    //
    modificarPrecio("TEMA7.2_3inventario.dat", id, nuevoPrecio);


    

    //
    cout << "\n\n-------------END\n";
    return 0;
}