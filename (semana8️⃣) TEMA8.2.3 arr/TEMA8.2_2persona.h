#ifndef PERSONA_H
#define PERSONA_H
#include <cstring>
#include <string>
using namespace std;


//---0
class persona{
    protected:
        string nombre;
        int edad;
    public:
        //a1, a2
        persona(string n, int e);
        ~persona();
        //b1
        void datosPersonales() const;
};


//---1
class estudianteCiencias: public persona{
    private:
        int codigo;
        int semestre;
    public:
        //a1, a2
        estudianteCiencias(string n, int e, int c, int s);
        ~estudianteCiencias();
        //b1
        void perfilEstudiante() const;
};


//
#endif