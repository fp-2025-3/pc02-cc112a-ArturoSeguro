#include <iostream>
#include <fstream>
#include <cstring>
#include <string>
using namespace std;


//---c
struct venta {
    int idVenta;        //codigo
    int idVendedor;     //codigo
    int idProducto;     //codigo
    int cantidad;
    double precioUnitario;
};
//---a
struct infoVendedor{
    int idVendedor;
    double totalVendido;
};
//---b
struct infoProducto{
    int idProducto;
    int totalUnidades;
};
//
const char* nombreArchivo= "TEMA7.4_8ventas.dat";
const char* nombreReporte= "TEMA7.4_8reporte.txt";


//no es conveniente usar funciones aqui


//main
//
int main(){
    //---1er, 2do
    ifstream leer(nombreArchivo, ios::in | ios::binary);
    if(!leer){
        cerr << "Error: No se pudo abrir el archivo " << nombreArchivo << "\n";
        return 1;
    }
    //---3er
    int totalRegistros= 0;
    leer.read((char*)(&totalRegistros), sizeof(totalRegistros));
    //
    double montoTotal= 0.0;
    //-a--para el mejor vendedor
    infoVendedor* vendedores= new infoVendedor[totalRegistros];
    int numVendedores= 0;
    //-b--para el mejor producto
    infoProducto* productos= new infoProducto[totalRegistros];
    int numProductos= 0;
    //-c--para ventas sospechosas
    venta* sospechosas= new venta[totalRegistros];
    int numSospechosas= 0;
    //
    venta v;
    for(int i=0; i< totalRegistros; i++){
        leer.read((char*)(&v), sizeof(venta));
        double totalVenta= v.cantidad* v.precioUnitario;
        montoTotal+= totalVenta;
        //-a--
        bool vendedorEncontrado= false;
        for(int j=0; j<numVendedores; j++){
            if(vendedores[j].idVendedor== v.idVendedor){
                vendedores[j].totalVendido+= totalVenta;
                vendedorEncontrado= true;
                break;
            }
        }
        //para vendedor nuevo --> FUNCIONA tanto para el 1er vendedor (numVendedores=0) y cuando se detecta otro idVendedor que no sea de los ya registrados
        if(!vendedorEncontrado){
            vendedores[numVendedores].idVendedor= v.idVendedor;
            vendedores[numVendedores].totalVendido= totalVenta;     //se registra por primera vez
            numVendedores++;
        }
        //-b---
        bool productoEncontrado= false;
        for(int j=0; j<numProductos; j++){
            if(productos[j].idProducto== v.idProducto){
                productos[j].totalUnidades+= v.cantidad;
                productoEncontrado= true;
                break;
            }
        }
        //
        if(!productoEncontrado){
            productos[numProductos].idProducto= v.idProducto;
            productos[numProductos].totalUnidades= v.cantidad;      //registrando por primera vez
            numProductos++;
        }
        //-c---
        if(v.cantidad> 100){
            sospechosas[numSospechosas]= v;
            numSospechosas++;
        }
    }
    //---4to
    leer.close();


    //-a---Buscar vendedor con MAYOR recaudación
    int idMejorVendedor= -1;
    double maxRecaudacion= -1.0;
    for(int i=0; i<numVendedores; i++){
        if(vendedores[i].totalVendido> maxRecaudacion){
            maxRecaudacion= vendedores[i].totalVendido;
            idMejorVendedor= vendedores[i].idVendedor;
        }
    }
    //-b---
    int idMejorProducto= -1;
    int maxCantidad= -1;
    for(int i=0; i<numProductos; i++){
        if(productos[i].totalUnidades> maxCantidad){
            maxCantidad= productos[i].totalUnidades;
            idMejorProducto= productos[i].idProducto;
        }
    }
    

    //1er, 2do
    ofstream escribir(nombreReporte, ios:: out);
    if(!escribir){
        cerr << "Error: No se pudo abrir el archivo " << nombreReporte << "\n";
        delete[] vendedores;
        delete[] productos;
        delete[] sospechosas;
        return 1;
    }
    //3er
    escribir << "==== REPORTE GENERAL DE VENTAS ===\n\n";
    escribir << "total de registros:\t" << totalRegistros << "\n\n";
    //
    escribir << "MONTO TOTTAL VENDIDO:\n";
    escribir << "S/. " << montoTotal << "\n\n";
    escribir << "---------------------------------------------\n";
    //
    escribir << "VENDEDOR CON MAYOR RECAUDACION:\n";
    escribir << "ID Vendedor:\t" << idMejorVendedor << "\n";
    escribir << "Total vendido:\tS/. " << maxRecaudacion << "\n\n";
    escribir << "----------------------------------------------\n";
    //
    escribir << "PRODUCTO MAS VENDIDO:\n";
    escribir << "ID producto:\t" << idMejorProducto << "\n";
    escribir << "Total cantidad:\t" << maxCantidad << "\n\n";
    escribir << "-----------------------------------------------\n";
    //
    escribir << "VENTAS SOSPECHOSAS (cantidad > 100):\n";
    for(int i=0; i<numSospechosas; i++){
        escribir << "ID Venta: " << sospechosas[i].idVenta
        << "\t| Vendedor: " << sospechosas[i].idVendedor
        << "\t| Producto: " << sospechosas[i].idProducto
        << "\t| Cantidad: " << sospechosas[i].cantidad << "\n";
    }
    //4to
    escribir.close();
    delete[] vendedores;
    delete[] productos;
    delete[] sospechosas;
    cout << "El archivo 'reporte.txt' se genero correctamente.\n";
    

    //
    cout << "\n\n-------------END\n";
    return 0;
}