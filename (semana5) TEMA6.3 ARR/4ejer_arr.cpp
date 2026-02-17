#include <iostream>
#include <cstring>
using namespace std;


//--1
struct item{
    char* descripcion;
    int cantidad;
    double precio;
};


//--2
struct pedido{
    int numeroPedido;
    char* nombreCliente;
    item* items;
    int cantidadItems;  //neceario para SumaTOTAL
};


//--3
item crearItem(const char* descripcion, int cantidad, double precio){
    //item* TEMPi= new item;    --> el ejercicicio no me pide crear memoria dinámica para CADA ITEM, solo para el conjunto de items (el array de items --> eso ya lo hice en "crearProducto()")
    item TEMPi;

    //(*TEMPi).descripcion= &descripcion[0];
    int tamDes= strlen(descripcion);
    TEMPi.descripcion= new char[tamDes+1];    //+1 para poner el "\0" al final también
    strcpy(TEMPi.descripcion, descripcion);
    //
    TEMPi.cantidad= cantidad;
    TEMPi.precio= precio;
    cout << "\n- " << TEMPi.descripcion << " | " << "Cant: " << TEMPi.cantidad << " | " << "Precio: " << TEMPi.precio;

    return TEMPi;
}


//--4
pedido* crearPedido(int numero, const char* cliente, int cantidadItems){
    pedido* TEMPp= new pedido;

    (*TEMPp).numeroPedido= numero;
    cout << "Pedido N°: " << (*TEMPp).numeroPedido;
    //(*TEMPp).nombreCliente= &cliente[0];
    //cout << "\nCliente: " << (*TEMPp).nombreCliente;
    int tamCli= strlen(cliente);
    (*TEMPp).nombreCliente= new char[tamCli+1];
    strcpy((*TEMPp).nombreCliente, cliente);


    //es necesario reservar memoria dinámica para items
    (*TEMPp).items= new item[cantidadItems];
    cout << "\nItems: ";
    if(cantidadItems== 3){
        (*TEMPp).items[0]= crearItem("Laptop\0", 3, 3200);
        (*TEMPp).items[1]= crearItem("Camara\0", 1, 1500);
        (*TEMPp).items[2]= crearItem("Tikcet\0", 2, 200);
    }else if(cantidadItems== 2){
        (*TEMPp).items[0]= crearItem("Lavadora\0", 1, 3300);
        (*TEMPp).items[1]= crearItem("Canasta\0", 1, 900);
    }

    //
    (*TEMPp).cantidadItems= cantidadItems; 

    //separación
    cout << "\n----------------------------------";
    return TEMPp;
}


//--5
void liberarPedido(pedido* p){
    delete[] (*p).nombreCliente;    //habi hecho un --arreglo dinamico de char para NOMBRE

    //
    for(int i=0; i< (*p).cantidadItems; i++){
        delete[] (*p).items[i].descripcion;      //a cada item le cree un --ARREGLO dinamico de char para DESCRIPCION
    }

    //ahora sí recién el array de items
    delete[] (*p).items;

    //
    delete p;   //aqui estoy deleteando --cada puntero de struct que esta en mi arreglo de punteros a STRUCT --> es decir p[0] y p[1] ....
}


//--6
//void liberarItem(item* i){
//    delete[] i;
//}
//          ->-->--> debería estar dentro del liberarPedido()


//--7
double calcularTotal(const pedido* p){
    double sumaTotal= 0; 
    for(int i=0; i<(*p).cantidadItems; i++){
        sumaTotal= sumaTotal+ (*p).items[i].precio*(*p).items[i].cantidad;
    }

    return sumaTotal;
}


//--8
item* itemMasCaro(pedido* p){
    item* masCaro= (*p).items+0;
    for(int i=1; i<(*p).cantidadItems; i++){
        if(masCaro->precio < (*p).items[i].precio){
            masCaro= (*p).items+i;
        }
    }

    return masCaro;
}


//main
//
//
int main(){
    cout << "\n_____\n";  //para separar de advertencias de asan
    int N=2;
    pedido** p= new pedido*[N];


    //
    p[0]= crearPedido(101, "Arturo\0", 3);
    double Total1= calcularTotal(p[0]);
    cout << "\nTotal: " << Total1;
    //
    item* i1= itemMasCaro(p[0]);
    cout << "\nItem mas caro: " << (*i1).descripcion << " | Precio: " << (*i1).precio;


    //
    cout << "\n\n\n";
    p[1]= crearPedido(102, "Americo\0", 2);
    double Total2= calcularTotal(p[1]);
    cout << "\nTotal: " << Total2;
    //
    item* i2= itemMasCaro(p[1]);
    cout << "\nItem mas caro: " << (*i2).descripcion << " | Precio: " << (*i2).precio;


    //--5
    liberarPedido(p[0]);
    liberarPedido(p[1]);
    delete[] p;     //ahora sí aca estoy borrando(delete) que cree en el main


    //
    cout << "\n\n-------------END\n";
    return 0;
}