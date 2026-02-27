#include <iostream>
#include <fstream>
#include <cstring>
using namespace std;


//---A.0
class dronExplorador{
    private:
        int id;
        double bateria;
        double cooX;
        double cooY;
        static int contadorGlobalID;
        static int dronesActivos;
    public:
        //0
        dronExplorador(double x, double y, double b);
        dronExplorador(const dronExplorador& dronCOPIED);
        //1
        void setB(double value);
        void setID();
        void actualizarPosicion(double coordX, double coordY);
        void getter() const;
        static int showGlobalID();
        static int showDronActivo();    //Esto cuenta como getDronesActivos()
        //2
        ~dronExplorador();
};
//
int dronExplorador:: contadorGlobalID= 1000;
int dronExplorador:: dronesActivos= 0;


//main
//
int main(){
    //
    dronExplorador d1(3, 4, 90);
    dronExplorador d2(7, 90, 110);
    dronExplorador d3(1, -1, 10);
    dronExplorador d4(6, -90, -1);
    dronExplorador d5(d1);
    //
    d1.actualizarPosicion(90, 900);
    d3.actualizarPosicion(1, 100);
    //
    d1.getter();
    dronExplorador:: showDronActivo();


    //
    cout << "\n\n-------------END\n";
    return 0;
}


//---B.0
//0
dronExplorador:: dronExplorador(double x, double y, double b)
: cooX(x), cooY(y){
    setB(b);
    setID();
}
dronExplorador:: dronExplorador(const dronExplorador& dronCOPIED)
: bateria(dronCOPIED.bateria), cooX(dronCOPIED.cooX), cooY(dronCOPIED.cooY){
    setID();
}
//1
void dronExplorador:: setB(double value){
    if(value<0 || value>100){
        cout << "\nEl valor de bateria colocado '" << value << "' --> NO ES VALIDO.\n";
        cout << "Se establecera en '50'\n";
        this->bateria= 50;
    }else{
        this->bateria= value;
    }
}
void dronExplorador:: setID(){
    contadorGlobalID++;
    this->id= contadorGlobalID;
    //
    dronesActivos++;
}
void dronExplorador:: getter() const{
    cout << "ID: " << this->id << "\n";
    cout << "Bateria: " << this->bateria << "\n";
    cout << "Posicion: (" << this->cooX << ", " << this->cooY << ")\n";

}
void dronExplorador:: actualizarPosicion(double cooX, double cooY){
    this->cooX= cooX;
    this->cooY= cooY;
}
int dronExplorador:: showGlobalID(){
    return contadorGlobalID;
}
int dronExplorador:: showDronActivo(){
    return dronesActivos;
}
//2
dronExplorador:: ~dronExplorador(){
    cout << "Se desconecto el dron de ID: '" << this->id << "'\n";
    dronesActivos--;
    cout << "-->-->Solo quedan '" << dronExplorador::showDronActivo() << "' activos.\n";
}