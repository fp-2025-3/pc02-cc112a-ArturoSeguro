#include <iostream>
#include <fstream>
#include <cstring>
using namespace std;

//---0
struct producto{
    int id;
    char nombre[30];
    double precio;
    int stock;
    bool activo;
};
//
const char* nombreArchivo= "TEMA7.4_1inventario.dat";


//---C
int buscarID(const char* nombreArchivo, int IDbuscado){
    //1er, 2do
    ifstream leer(nombreArchivo, ios::in | ios::binary);
    if(!leer){
        cerr << "No se pudo abrir el archivo.\n";
        return -1;
    }
    //3er
    producto p;
    int i=0;                //posicion
    while(leer.read((char*)(&p), sizeof(producto))){
        if(p.id== IDbuscado){
            leer.close();
            return i;
        }
        i++;
    }
    //4to
    leer.close();
    return -1;
}


//---A
void registrar(const char* nombreArchivo){
    //1er, 2do
    ofstream escribir(nombreArchivo, ios::out | ios:: app | ios::binary);
    if(!escribir){
        cerr << "No se pudo abrir el archivo.\n";
        return;
    }
    //3er
    producto p;
    cout << "Coloque el ID: ";
    cin >> p.id;
    if(buscarID(nombreArchivo, p.id)!=-1){
        cout << "No se puede colocar un ID repetido.\n";
        return;
    }
    //
    cout << "Coloque el nombre: ";
    cin >> p.nombre;
    //
    cout << "Coloque el precio: ";
    cin >> p.precio;
    if(p.precio<= 0){
        cout << "Debe colocar un precio 'mayor' que 0 (>0)\n";
        escribir.close();
        return;
    }
    //
    cout << "Colque el stock: ";
    cin >> p.stock;
    if(p.stock< 0){
        cout << "Debe colocar un precio 'mayor o igual' que 0 (>=0)\n";
        escribir.close();
        return;
    }
    //
    p.activo= true;     //por defecto --> en eliminar() le pondremos FALSE
    //
    escribir.write((char*)(&p), sizeof(producto));
    //4to
    escribir.close();
    return;
}


//---B
void mostrar(const char* nombreArchivo){
    //1er, 2do
    ifstream leer(nombreArchivo, ios::in | ios::binary);
    if(!leer){
        cerr << "No se pudo abrir el archivo.\n";
        return;
    }
    //3er
    producto p;
    int posicionLinea= 0;
    cout << "Posi\tIDpro\tNombr\tPreci\tStock\n";
    while(leer.read((char*)(&p), sizeof(producto))){
        if(p.activo){
            cout << posicionLinea << "\t" << p.id << "\t" << p.nombre << "\t" << p.precio << "\t" << p.stock << "\n";
        }
        posicionLinea++;
    }
    //4to
    leer.close();
    return;
}


//---D
void modificar(const char* nombreArchivo, int id, double nuevoP){
    //
    int posicion= buscarID(nombreArchivo, id);  //para evitar comportamiento inesperados
    //1er, 2do
    fstream modificar(nombreArchivo, ios::in | ios::out | ios::binary);
    if(!modificar){
        cerr << "No se pudo abrir el archivo.\n";
        return;
    }
    //3er
    producto p;
    if(posicion== -1){
        return;
    }
    //
    modificar.seekg(posicion*sizeof(producto), ios::beg);
    modificar.read((char*)(&p), sizeof(producto));
    if(p.activo== false){
        cout << "No se puede modificar a un producto ELIMINADO.\n";
        modificar.close();
        return;
    }
    p.precio= nuevoP;
    //
    modificar.seekp(posicion*sizeof(producto), ios::beg);
    modificar.write((char*)(&p), sizeof(producto));
    //4to
    modificar.close();
    return;
}


//---E
void eliminar(const char* nombreArchivo, int id){
    //
    int posicion= buscarID(nombreArchivo, id);  //para evitar comportamiento inesperados
    //1er, 2do
    fstream modificar(nombreArchivo, ios::in | ios::out | ios::binary);
    if(!modificar){
        cerr << "No se pudo abrir el archivo.\n";
        return;
    }
    //3er
    producto p;
    if(posicion== -1){
        return;
    }
    //
    modificar.seekg(posicion*sizeof(producto), ios::beg);
    modificar.read((char*)(&p), sizeof(producto));
    p.activo= false;
    //
    modificar.seekp(posicion*sizeof(producto), ios::beg);
    modificar.write((char*)(&p), sizeof(producto));
    //4to
    modificar.close();
    return;
}



//---F
double inventario(const char* nombreArchivo){
    //1er, 2do
    ifstream leer(nombreArchivo, ios::in | ios::binary);
    if(!leer){
        cerr << "No se pudo abrir el archivo.\n";
        return -1;
    }
    //3er
    producto p;
    double total= 0;
    while(leer.read((char*)(&p), sizeof(producto))){
        if(p.activo){
            total= total+ (p.stock*p.precio);
        }
    }
    //4to
    leer.close();
    return total;
}


//main
//
int main(){
    int opcion;
    do{
        cout << "\n1. Registrar producto.\n";
        cout << "2. Mostrar producto.\n";
        cout << "3. Buscar producto.\n";
        cout << "4. Modificar producto.\n";
        cout << "5. Eliminar producto.\n";
        cout << "6. Valor de inventario.\n";
        cout << "7. Salir.\n";
        cout << "--> --> Elija su opcion: ";
        cin >> opcion;
        //
        switch(opcion){
            case 1:{
                registrar(nombreArchivo);
                break;
            }
            case 2:{
                mostrar(nombreArchivo);
                break;
            }
            case 3:{    
                int TEMPid;
                cout << "Escriba el ID del producto bucado: ";
                cin >> TEMPid;
                int linea= buscarID(nombreArchivo, TEMPid);
                cout << "El producto esta ubicado en LA LINEA: " << linea;
                break;
            }
            case 4:{
                int TEMPid;
                cout << "Escriba el ID del producto a modificar: ";
                cin >> TEMPid;
                double nuevoP;
                cout << "Escriba el precio a COLOCAR: ";
                cin >> nuevoP;
                modificar(nombreArchivo, TEMPid, nuevoP);
                break;
            }
            case 5:{
                int TEMPid;
                cout << "Escriba el ID del producto a eliminar: ";
                cin >> TEMPid;
                eliminar(nombreArchivo, TEMPid);
                break;
            }
            case 6:{
                double inventarioTotal= inventario(nombreArchivo);
                cout << "El VALOR TOTAL de los productos que se tienen --> es: " << inventarioTotal << "\n";
                break;
            }
            case 7:{
                cout << "Saliendo...\n";
                break;
            }
            default:{
                cout << "Elija una opcion valida.\n";
                break;
            }
        }
    }while(opcion!= 7);


    //
    cout << "\n\n-------------END\n";
    return 0;
}