#include <iostream>
#include <fstream>
#include <cstring>
#include <string>
#include <iomanip>  //para arreglar la notacion cientifica
using namespace std;

//---c
struct venta{
    int idVenta;
    int idVendedor;
    int idProducto;
    int cantidad;
    double precioUnitario;
};
//---a
struct vendedor{
    int idVendedor;
    double totalVendido;
};
//---b
struct producto{
    int idProducto;
    int cantidadExacta;
};
//
const char* nombreArchivo= "ventas.dat";
const char* nombreReporte= "reporte_ejer4.txt";


//main
//
int main(){
    //1er, 2do
    ifstream leer(nombreArchivo, ios::in | ios::binary);
    if(!leer){
        cerr << "no se pudo abrir el archivo.\n";
        return -1;
    }
    //3er
    venta v;
    int totalRegistros= 0;
    while(leer.read((char*)(&v), sizeof(venta))){
        totalRegistros++;
    }
    //4to
    leer.close();


    //1er, 2do
    ifstream extraer(nombreArchivo, ios::in | ios::binary);
    if(!extraer){
        cerr << "no se pudo abrir el archivo.\n";
        return -1;
    }
    //3er
    venta v2;
    double montoTotal= 0;
    //-->--> los parentesis son para incializar todo con 0 y arreglar problemas de "valkgrind"
    //-a---
    vendedor* vendedores= new vendedor[totalRegistros]();
    int numVendedores=0;
    //-b---
    producto* productos= new producto[totalRegistros]();
    int numProductos=0;
    //-c---
    venta* sospechosas= new venta[totalRegistros]();
    int numSospechosas=0;
    //
    for(int i=0; i<totalRegistros; i++){
        extraer.read((char*)(&v2), sizeof(venta));
        montoTotal+= v2.cantidad*v2.precioUnitario;
        //-a---
        bool nuevoVendedor= false;
        for(int j=0; j<numVendedores; j++){
            if(vendedores[j].idVendedor== v2.idVendedor){
                vendedores[j].totalVendido+= v2.cantidad*v2.precioUnitario;
                nuevoVendedor= true;
                break;
            }
        }
        if(!nuevoVendedor){
            vendedores[numVendedores].idVendedor= v2.idVendedor;
            vendedores[numVendedores].totalVendido= v2.cantidad*v2.precioUnitario;
            numVendedores++;
        }
        //-b---
        bool nuevoProducto= false;
        for(int j=0; j<numProductos; j++){
            if(productos[j].idProducto== v2.idProducto){
                productos[j].cantidadExacta+= v2.cantidad;
                nuevoProducto= true;
                break;
            }
        }
        if(!nuevoProducto){
            productos[numProductos].idProducto= v2.idProducto;
            productos[numProductos].cantidadExacta= v2.cantidad;
            numProductos++;
        }
        //-c---
        if(v2.cantidad> 100){
            sospechosas[numSospechosas]= v2;
            numSospechosas++;
        }
    }
    //4to
    extraer.close();


    //-a---mejorVendedor
    int idMejorVendedor= -1;
    double mayorVendido= -1;
    for(int i=0; i<numVendedores; i++){
        if(vendedores[i].totalVendido> mayorVendido){
            mayorVendido= vendedores[i].totalVendido;
            idMejorVendedor= vendedores[i].idVendedor;
        }
    }
    //-b---mejorProducto
    int idMejorProducto= -1;
    int mayorCantidad= -1;
    for(int i=0; i<numProductos; i++){
        if(productos[i].cantidadExacta> mayorCantidad){
            mayorCantidad= productos[i].cantidadExacta;
            idMejorProducto= productos[i].idProducto;
        }
    }


    //1er, 2do
    ofstream imprimir(nombreReporte, ios::out);
    if(!imprimir){
        cerr << "no se pudo abrir el archivo.\n";
        delete[] vendedores;
        delete[] productos;
        delete[] sospechosas;
        return -1;
    }
    //3er
    imprimir << "===REPORTE===\n";
    imprimir << "total de registros: " << totalRegistros << "\n\n";
    imprimir << "MONTO TOTAL VENDIDO: S/" << fixed << setprecision(2) << montoTotal << "\n\n";
    imprimir << "--------------------------------------------\n";
    imprimir << "VENDEDOR CON MAYOR RECAUDACIÓN:\n";
    imprimir << "ID vendedor: " << idMejorVendedor << "\n";
    imprimir << "total vendido: S/" << mayorVendido << "\n\n";
    imprimir << "--------------------------------------------\n";
    imprimir << "PRODUCTO MAS VENDIDO:\n";
    imprimir << "ID Producto: " << idMejorProducto << "\n";
    imprimir << "Total de unidades: " << mayorCantidad << "\n\n";
    imprimir << "--------------------------------------------\n";
    imprimir << "VENTAS SOSPECHOSAS (cantidad > 100)\n";
    imprimir << "IDventa\tVendedor\tProducto\tCantidad\n";
    for(int i=0; i<numSospechosas; i++){
        imprimir << sospechosas[i].idVenta << "\t" << sospechosas[i].idVendedor << "\t\t" << sospechosas[i].idProducto << "\t\t" << sospechosas[i].cantidad << "\n";
    }
    //4to
    imprimir.close();


    //
    cout << "Se creo eñ archivo. Reviselo";
    cout << "\n\n-------------END\n";
    delete[] vendedores;
    delete[] productos;
    delete[] sospechosas;
    return 0;
}