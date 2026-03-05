//Archivo INTERFAZ
#ifndef PERSONAJE_H
#define PERSONAJE_H
#include <string>
using namespace std;


//---0
class personaje{
    private:
        string nombre;
        int salud;
        int municion;
    public:
        //a1, a2
        personaje(string n, int s, int m);
        ~personaje();
        //b.1, b2, b3
        void disparar();
        void getHitted(int s);
        void estado() const; 
};


//
#endif