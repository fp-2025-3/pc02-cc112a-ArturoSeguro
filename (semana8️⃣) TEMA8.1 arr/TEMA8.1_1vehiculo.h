//Construyendo clase base (archivo de interfaz)
#ifndef VEHICULO_H
#define VEHICULO_H
#include <string>
using namespace std;


//---0
class vehiculo{
    private:
        string placa;
        string marca;
        int year;
        double precio;
    public:
        //a1 y a2
        vehiculo(string p, string m, int y, double pre);
        virtual ~vehiculo();    //criucial convertir al destructor a VIRTUAL --> para aplicar polimorfismo
        //b                     //aqui aplicaré el polimorfismo
        virtual void mostrarInformacion();
};


//---1
class carro: public vehiculo{
    private:
        int numPuertas;
    public:
        //a.1, a.2
        carro(string p, string m, int y, double pre, int nP);
        ~carro();
        //b         //buena practica --> usando "override"
        void mostrarInformacion() override;
};


//---2
class camion: public vehiculo{
    private:
        double capacidadCarga;
    public:
        //a1, a2
        camion(string p, string m, int y, double pre, double cC);
        ~camion();
        //b         //buena practica --> usando "override"
        void mostrarInformacion() override;
};


//---3
class moto: public vehiculo{
    private:
        double potencia;
    public:
        //a1, a2
        moto(string p, string m, int y, double pre, double po);
        ~moto();
        //b         //buena practica --> usando "override"
        void mostrarInformacion() override;
};


//
#endif