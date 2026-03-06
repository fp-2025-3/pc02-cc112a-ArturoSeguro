#ifndef SENSOR_H
#define SENSOR_H
#include <cstring>
#include <string>
using namespace std;


//---1
class Sensor{
    private:
        string id;
        double* posicion;       //arrelgo dinamico de 2valores --> tengo que crearlo en una funcion y destruirlo en "destructore"
    public:
        //a1, a2, a3, a4
        Sensor(string i, double* p);
        Sensor(const Sensor& s);
        Sensor& operator=(const Sensor& s);
        virtual ~Sensor();
        //b1, b2, b3, b4
        virtual double areaCobertura() const= 0;
        virtual bool detecta(double x, double y) const= 0;
        virtual void imprimir() const= 0;
        double* getterPosicion() const;
};


//---2
class SensorCircular: public Sensor{
    private:
        double radio;
    public:
        //a1, a2
        SensorCircular(string i, double* p, double r);
        ~SensorCircular();
        //b1, b2, b3
        double areaCobertura() const override;
        bool detecta(double x, double y) const override;
        void imprimir() const override;
};


//---3
class SensorRectangular: public Sensor{
    private:
        double ancho;
        double alto;
    public:
        //a1, a2
        SensorRectangular(string i, double* p, double an, double al);
        ~SensorRectangular();
        //b1, b2, b3
        double areaCobertura() const override;
        bool detecta(double x, double y) const override;
        void imprimir() const override;
};


//---4
class SistemaSensores{
    private:

    public:
};



//
#endif
