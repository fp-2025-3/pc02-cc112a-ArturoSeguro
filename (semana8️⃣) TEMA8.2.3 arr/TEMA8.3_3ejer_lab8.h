#ifndef FIGURA_H
#define FIGURA_H
#include <cstring>
#include <string>
using namespace std;    


//---0 
class figura{
    private:
        string nombre;
        double* colorRGB;       //arreglo dinamico de 3 valores
    public:
        //a1, a2
        figura(string n, double* cRGB);
        virtual ~figura();
        //a3, a4
        figura(const figura& f);    //constructor de copia
        figura& operator=(const figura& f);      //operador de asignacion
        //b1, b2, b3 (no se tienen que declarar --> se quedan como prototipos nada mas)
        virtual double area() const= 0;
        virtual double perimetro() const= 0;
        virtual void imprimir() const= 0;
        //b4, b5 (getters)
        string nombreGetter() const;
        double* RGBgetter() const;
};


//---1
class circulo: public figura{
    private:
        double radio;
    public:
        //a1, a2
        circulo(string n, double* cRGB, double r);
        ~circulo();
        //b1, b2, b3
        double area() const override;
        double perimetro() const override;
        void imprimir() const override;
};


//---2
class rectangulo: public figura{
    private:
        double base;
        double altura;
    public:
        //a1, a2
        rectangulo(string n, double* cRGB, double b, double a);
        ~rectangulo();
        //b1, b2, b3
        double area() const override;
        double perimetro() const override;
        void imprimir() const override;
};


//---3
class gestor{
    private:
        figura** figuras;
        int cantidadActual;
        int capacidad;
    public:
        //a1, a2
        gestor(int capa= 3);                //iniciarar con 3 de predeterminado
        ~gestor();
        //b1, b2, b3, b4
        void agregarFigura(figura *f);
        void mostrarTodo() const;           //Debe ejecutar los imprimir() de cada uno
        double areaTotal() const;
        void guardarArchivo(const char* nombreArchivo) const;
};


//
#endif