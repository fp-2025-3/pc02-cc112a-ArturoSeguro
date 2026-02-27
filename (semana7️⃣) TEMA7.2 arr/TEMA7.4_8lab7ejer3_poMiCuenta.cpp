#include <iostream>
#include <fstream>
#include <cstring>
#include <string>
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
    double cantidadVendido;
};
//---b
struct producto{
    int idProducto;
    int unidadesVendidas;
};
//
const char* nombreArchivo= "TEMA7.4_8ventas.dat";
const char* nombreReporte= "TEMA7.4_8reporte_myOWN.txt";


//main
//
int main(){
    //1er, 2do
    ifstream leer(nombreArchivo, ios::in | ios::binary);
    if(!leer){
        cerr << "No se pudo abrir.\n";
        return -1;
    }
    //3er
    int totalRegistros;
    leer.read((char*)(&totalRegistros), sizeof(totalRegistros));
    //-a--
    vendedor* vendedores= new vendedor[totalRegistros];
    int numVendedores= 0;
    //-b--
    producto* productos= new producto[totalRegistros];
    int numProductos= 0;
    //-c--
    venta* sospechosas= new venta[totalRegistros];
    int numSospechosas= 0;
    //
    venta v;
    double monto=0;
    for(int i=0; i<totalRegistros; i++){
        leer.read((char*)(&v), sizeof(v));
        monto+= v.cantidad*v.precioUnitario;
        //-a--
        bool vendedorExistente= false;
        for(int j=0; j<numVendedores; j++){
            if(vendedores[j].idVendedor== v.idVendedor){
                vendedores[j].cantidadVendido+= v.cantidad*v.precioUnitario;
                vendedorExistente= true;
            }
        }
        if(!vendedorExistente){
            vendedores[numVendedores].idVendedor= v.idVendedor;
            vendedores[numVendedores].cantidadVendido= v.cantidad*v.precioUnitario;
            numVendedores++;
        }
        //-b--
        bool productoExistente= false;
        for(int j=0; j<numProductos; j++){
            if(productos[j].idProducto== v.idProducto){
                productos[j].unidadesVendidas+= v.cantidad;
                productoExistente= true;
            }
        }
        if(!productoExistente){
            productos[numProductos].idProducto= v.idProducto;
            productos[numProductos].unidadesVendidas= v.cantidad;
            numProductos++;
        }
        //-c--
        if(v.cantidad> 100){
            sospechosas[numSospechosas]= v;
            numSospechosas++;
        }
    }
    //4to
    leer.close();


    //-a--MejorVendedor
    int idMejorVendedor= -1;
    double cantidadVendida= -1.0;
    for(int i=0; i<numVendedores; i++){
        if(vendedores[i].cantidadVendido> cantidadVendida){
            cantidadVendida= vendedores[i].cantidadVendido;
            idMejorVendedor= vendedores[i].idVendedor;
        }
    }
    //-b--MejorProducto
    int idMejorProducto= -1;
    int unidadesProducto= -1;
    for(int i=0; i<numProductos; i++){
        if(productos[i].unidadesVendidas> unidadesProducto){
            unidadesProducto= productos[i].unidadesVendidas;
            idMejorProducto= productos[i].idProducto;
        }
    }


    //1er, 2do
    ofstream escribir(nombreReporte, ios::out);
    if(!escribir){
        cerr << "No se pudo abrir.\n";
        delete[] vendedores;
        delete[] productos;
        delete[] sospechosas;
        return -1;
    }
    //3er
    escribir << "===REPORTE GENERAL DE VENTAS===\n";
    escribir << "Total de registros: " << totalRegistros << "\n\n";
    escribir << "---------------------------------------------\n";
    escribir << "MONTO TOTAL VENDIDO:\n";
    escribir << "s/ " << monto << "\n\n";
    escribir << "---------------------------------------------\n";
    escribir << "VENDEDOR CON MAYOR RECAUDACION:\n";
    escribir << "ID vendedor: " << idMejorVendedor << "\n";
    escribir << "Monto vendido: " << cantidadVendida << "\n\n";
    escribir << "---------------------------------------------\n";
    escribir << "PRODUCTO MAS VENDIDO:\n";
    escribir << "ID producto: " << idMejorProducto << "\n";
    escribir << "Unidades vendidas: " << unidadesProducto << "\n\n";
    escribir << "---------------------------------------------\n";
    escribir << "UNIDADES SOSPECHOSAS (cantidad > 100):\n";
    for(int i=0; i<numSospechosas; i++){
        escribir << "idVenta: " << sospechosas[i].idVenta << "\t| idVendedor: " << sospechosas[i].idVendedor << "  \t| idProducto: " << sospechosas[i].idProducto << "   \t| cantidad: " << sospechosas[i].cantidad << "\n";
    }
    //4to
    escribir.close();
    delete[] vendedores;
    delete[] productos;
    delete[] sospechosas;
    cout << "Se genero el reporte correctamente.";

    //
    cout << "\n\n-------------END\n";
    return 0;
}