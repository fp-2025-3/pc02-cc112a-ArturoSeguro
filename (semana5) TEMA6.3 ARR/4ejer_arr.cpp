#include <iostream>
using namespace std;

//--1
//
struct Item {
    char* descripcion;
    int cantidad;
    double precioUnitario;
};

struct Pedido {
    int numeroPedido;
    char* nombreCliente;
    Item* items;
    int cantidadItems;
};


//--2
//
Item crearItem(const char* descripcion, int cantidad, double precio){
    Item TEMPitem;
    
    //calculando longitud manualmente para no usar <cstring>
    int len = 0;
    while(descripcion[len] != '\0'){
        len++;
    }
    
    //reservando memoria dinamica para char*
    TEMPitem.descripcion = new char[len + 1];
    
    //copiando caracter por caracter
    for(int i=0; i<=len; i++){
        TEMPitem.descripcion[i] = descripcion[i];
    }
    
    TEMPitem.cantidad = cantidad;
    TEMPitem.precioUnitario = precio;
    
    return TEMPitem;
}


//--3
//
Pedido* crearPedido(int numero, const char* cliente, int cantidadItems){
    Pedido* PUNpedido = new Pedido;
    (*PUNpedido).numeroPedido = numero;
    
    //Reservar memoria para nombreCliente y copiar manualmente
    int len = 0;
    while(cliente[len] != '\0'){
        len++;
    }
    (*PUNpedido).nombreCliente = new char[len + 1];
    for(int i=0; i<=len; i++){
        (*PUNpedido).nombreCliente[i] = cliente[i];
    }
    
    //Reservar un arreglo dinamico de Item
    (*PUNpedido).cantidadItems = cantidadItems;
    (*PUNpedido).items = new Item[cantidadItems];
    
    //se hara en el main() para poder asignar los valores específicos requeridos.
    
    return PUNpedido;
}


//--4
//
double calcularTotal(const Pedido* p){
    double totalCalculado = 0;
    
    for(int i=0; i<(*p).cantidadItems; i++){
        totalCalculado = totalCalculado + ((*p).items[i].cantidad * (*p).items[i].precioUnitario);
    }
    
    return totalCalculado;
}


//--5
//
Item* itemMasCaro(Pedido* p){
    if((*p).cantidadItems == 0){
        return nullptr;
    }
    
    //asumo que el primero es el mas caro inicialmente
    Item* masCaroTEMP = &(*p).items[0];
    
    for(int i=1; i<(*p).cantidadItems; i++){
        if((*p).items[i].precioUnitario > (*masCaroTEMP).precioUnitario){
            masCaroTEMP = &(*p).items[i];
        }
    }
    
    return masCaroTEMP;
}


//--6
//
void deleting(Pedido* p){
    if(p != nullptr){
        //1. eliminar las descripciones dinámicas de cada Item
        for(int i=0; i<(*p).cantidadItems; i++){
            delete[] (*p).items[i].descripcion;
        }
        
        //2. eliminar el arreglo dinamico principal de items
        delete[] (*p).items;
        
        //3. eliminar el nombre del cliente
        delete[] (*p).nombreCliente;
        
        //4. eliminar el pedido principal (el struct base)
        delete p;
    }
    return;
}


//--7. Funcion extra para imprimir
//
void imprimiendoPedido(Pedido* p){
    cout << "Pedido Nro: " << (*p).numeroPedido << "\n";
    cout << "Cliente: " << (*p).nombreCliente << "\n\n";
    
    cout << "Items:\n";
    for(int i=0; i<(*p).cantidadItems; i++){
        cout << "- " << (*p).items[i].descripcion << " | Cant: " << (*p).items[i].cantidad 
             << " | Precio: " << (*p).items[i].precioUnitario << "\n";
    }
    
    cout << "\nTotal: " << calcularTotal(p) << "\n\n";
    
    Item* caro = itemMasCaro(p);
    if(caro != nullptr){
        cout << "Item mas caro: " << (*caro).descripcion << " | Precio: " << (*caro).precioUnitario << "\n";
    }
    return;
}


//main
//
int main(){
    int cantidadItemsTEMP = 3;
    
    //--3
    Pedido* miPedido = crearPedido(101, "Arturo & Americo", cantidadItemsTEMP);
    
    //--2
    (*miPedido).items[0] = crearItem("Laptop", 1, 100);
    (*miPedido).items[1] = crearItem("miniRefri", 2, 200);
    (*miPedido).items[2] = crearItem("Teclado", 3, 300);
    
    //--7
    cout << "\nEjemplo de ejecucion:\n\n";
    imprimiendoPedido(miPedido);
    
    //--6
    deleting(miPedido);
    
    //
    cout << "\n\n-------------END\n";
    return 0;
}