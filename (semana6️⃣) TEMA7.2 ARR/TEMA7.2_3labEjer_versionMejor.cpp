#include <iostream>
#include <fstream>
#include <cstring>
using namespace std;


//
const char* nombreArchivo= "TEMA7.2_3inventario.dat";


//
struct producto {
    int id;                  // Identificador único
    char nombre[30];         // Nombre del producto
    double precio;           // Precio unitario
    int stock;               // Cantidad disponible
    bool activo;             // true = activo, false = eliminado lógicamente
};


//---3 (muy util para reutilizar dentro de otras funciones)
int buscarID(const char* nombreArchivo, int idBuscado){
    //1er, 2do
    ifstream leer(nombreArchivo, ios::in | ios::binary);
    if(!leer){          //--> verificador
        cerr << "el archivo no se pudo abrir.\n";
        return -1;
    }
    //3er
    producto p;
    int pos= 0;
    while(leer.read((char*)(&p), sizeof(producto))){
        if(p.id== idBuscado){
            leer.close();   //4to
            return pos;     //retorno posición física (0,1,2,3...)
        }
        //
        pos++;
    }
    //4to (por si no se encuentra)
    leer.close();
    return -1;
}


//---1
void registrarProducto(const char* nombreArchivo){
    producto p;
    cout << "\n--- NUEVO PRODUCTO ---\n";
    //-ID
    cout << "ID: ";
    cin >> p.id;
    //validando si el ID esta repetido
    if(buscarID(nombreArchivo, p.id)!= -1){         //--> buscará todos los existentes para ver si ya existe --> si es que estoy registrando por primera vez, la función "buscarID()" me devolverá "-1" --> y todo bien
        cout << "[ERROR]--> el ID ya existe. No se permiten IDs repetidos.\n";
        return;
    }
    //-nombre
    cout << "Nombre: ";
    cin >> p.nombre;
    //-validación de Precio
    do{
        cout << "Precio: ";
        cin >> p.precio;
        if(p.precio<= 0){
            cout << "[ERROR]--> El preico debe ser 'menor a 0' (>0).\n";
        }
    }while(p.precio<= 0);
    //-validación de stock
    do{
        cout << "Stock: ";
        cin >> p.stock;
        if(p.stock< 0){
            cout << "[ERROR]--> El stock debe ser 'mayor igual a 0' (>=0).\n";
        }
    }while(p.stock< 0);
    //-estado de activo
    p.activo= true;     //por defecto comieza activo


    //1er, 2do
    ofstream escribir(nombreArchivo, ios::out | ios::binary | ios::app);
    //3er
    escribir.write((char*)(&p), sizeof(producto));
    //4to
    escribir.close();
    cout << "\nProducto registrado exitosamente.\n";
}


//---2
void mostrarProductos(const char* nombreArchivo){
    //1er, 2do
    ifstream leer(nombreArchivo, ios::in | ios:: binary);
    if(!leer){
        cerr << "\nNo hay un inventario registrado aun.\n";
        return;
    }
    //3er
    producto p;
    int pos= 0;
    cout << "\nPOSi\tIDcod\tNOMb\t\tPREc\tSTOc\n";
    cout << "-----------------------------------------------------------\n";
    //
    while(leer.read((char*)(&p), sizeof(producto))){
        if(p.activo){
            cout << pos << "\t" << p.id << "\t" << p.nombre << "\t\t" << p.precio << "\t" << p.stock << "\n";
        }
        pos++;
    }
    //4to
    leer.close();
}


//---4
void modificarPrecio(const char* nombreArchivo, int id, double nuevoPrecio){
    int pos= buscarID(nombreArchivo, id);
    if(pos== -1){
        cout << "\nProducto no encontrado.\n";
        return;
    }
    //1er, 2do
    fstream modificar(nombreArchivo, ios::in | ios::out | ios::binary);
    if(!modificar){
        cerr << "\nError al abrir el archivo.\n";
        return;
    }
    //3er
    producto p;
    //apuntar, leer, modificar
    modificar.seekg(pos*sizeof(producto), ios::beg);
    modificar.read((char*)(&p), sizeof(producto));
    p.precio= nuevoPrecio;
    //reposicionar el cursor(puntero) para escribir por encima correctamente
    modificar.seekp(pos*(sizeof(producto)), ios::beg);
    modificar.write((char*)(&p), sizeof(producto));
    //4to
    modificar.close();
    cout << "\nPrecio modificado correctamente.\n";
}


//---5
void eliminarProducto(const char* nombreArchivo, int id){
    int pos= buscarID(nombreArchivo, id);
    if(pos== -1){
        cerr << "\nProducto no encontrado.\n";
        return;
    }
    //1er,2do
    fstream eliminar(nombreArchivo, ios::in | ios::out | ios::binary);
    //3er
    producto p;
    eliminar.seekg(pos*sizeof(producto), ios::beg);
    eliminar.read((char*)(&p), sizeof(producto));
    p.activo= false;
    //
    eliminar.seekp(pos*sizeof(producto), ios::beg);
    eliminar.write((char*)(&p), sizeof(producto));
    //4to paso
    eliminar.close();
    cout << "producto eliminado (logicamente) correctamente.\n";
}


//---6
double calcularValorInventario(const char* nombreArchivo){
    //1er, 2do
    ifstream leer(nombreArchivo, ios::in | ios::binary);
    if(!leer){
        cerr << "archivo no se pudo abrir.\n";
        return -1;
    }
    //3er paso
    producto p;
    double sumaTotal= 0.0;
    while(leer.read((char*)(&p), sizeof(producto))){
        if(p.activo){
            sumaTotal= sumaTotal+ (p.stock*p.precio);
        }
    }
    //4to
    leer.close();
    return sumaTotal;
}


//main
//
int main(){
    int opcion;

    //
    do{
        cout << "\n=== MENU INVENTARIO ===\n";
        cout << "1. Registrar producto\n";
        cout << "2. Mostrar productos\n";
        cout << "3. Buscar producto\n";
        cout << "4. Modificar precio\n";
        cout << "5. Eliminar producto\n";
        cout << "6. Calcular valor total\n";
        cout << "7. Salir\n";
        cout << "--> Elija la opcion que desee: ";
        cin >> opcion;

        //
        switch(opcion){
            case 1:{
                registrarProducto(nombreArchivo);
                break;
            }
            case 2:{
                mostrarProductos(nombreArchivo);
                break;
            }
            case 3:{
                int id;
                cout << "\nID a buscar: ";
                cin >> id;
                //
                int pos= buscarID(nombreArchivo, id);
                if(pos!= -1){
                    cout << "El producto existe en la posicion fisica (registro): " << pos << "\n";
                }else{
                    cout << "Producto no encontrado.\n";
                }
                break;
            }
            case 4:{
                int id;
                cout << "\nID del producto a modificar: ";
                cin >> id;
                double nuevoPrecio;
                cout << "Nuevo precio: ";
                cin >> nuevoPrecio;
                //
                modificarPrecio(nombreArchivo, id, nuevoPrecio);
                break;
            }
            case 5:{
                int id;
                cout << "\nID del producto a eliminar: ";
                cin >> id;
                eliminarProducto(nombreArchivo, id);
                break;
            }
            case 6:{
                double total= calcularValorInventario(nombreArchivo);
                cout << "\nValor total del inventario activo: $" << total << "\n";
                break;
            }
            case 7:{
                cout << "Saliendo del programa...\n";
                break;
            }
            default:{
                cout << "Opcion no valida.\n";
            }
        }
    }while(opcion!= 7);

    //
    cout << "\n\n-------------END\n";
    return 0;
}