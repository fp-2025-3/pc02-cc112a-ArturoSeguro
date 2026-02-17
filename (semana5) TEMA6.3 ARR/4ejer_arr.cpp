#include <iostream>
using namespace std;


//function1
struct item{
    char* descripcion;
    int cantidad;
    double precioUnitario;
};

//function2
struct pedido{
    int numeroPedido;
    string nombreCliente;
    item* items;            //Arreglo dinamico
    int cantidadItems;
};
 

//function3


//function4


//function5


//function6




//main
//
//
//
int main(){
    //function1
    pedido p1= {2, "arturo"};
    p1.cantidadItems= 9;

    pedido p2= {3, "americo"};
    p1.cantidadItems= 43;


    int total=0;
    for(int i=0; i<2; i++){
        total= p1.cantidadItems+ p2.cantidadItems;
    }

    cout << "TOtal de ITEMS:: " << total;
    //function2


    //function3


    //function4


    //function5


    //function6
    


    cout << "\n\n-------------END\n";
    return 0;
}