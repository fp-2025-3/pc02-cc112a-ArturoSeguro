#include <iostream>
using namespace std;

//1----: Agregar estudiante y duplicar capacidad si es necesario-----
        void agregarEstudiante(int*& codigos, double*& promedios, int& cantidad, int& capacidad, int nuevoCodigo, double nuevoPromedio) {
            if (cantidad == capacidad) {
                capacidad *= 2;
                int* tempCod = new int[capacidad];
                double* tempProm = new double[capacidad];

                for (int i = 0; i < cantidad; i++) {
                    tempCod[i] = codigos[i];
                    tempProm[i] = promedios[i];
                }

                delete[] codigos;
                delete[] promedios;
                codigos = tempCod;
                promedios = tempProm;
            }
            codigos[cantidad] = nuevoCodigo;
            promedios[cantidad] = nuevoPromedio;
            cantidad++;
        }



        
//2---: Eliminar desaprobados y redimensionar al tamaño exacto------
                    void eliminarDesaprobados(int*& codigos, double*& promedios, int& cantidad) {
                        int aprobados= 0;
                        //Contamos cuantos pasan
                        for(int i=0; i<cantidad; i++){
                            if (promedios[i] >= 10){
                                aprobados++;
                            }
                        }



                        //Nuevo arreglo tamaño exacto
                        int* tempCod= new int[aprobados];
                        double* tempProm= new double[aprobados];
                        
                        int j = 0;
                        for(int i=0; i<cantidad; i++) {
                            if(promedios[i]>= 10) {
                                tempCod[j] = codigos[i];
                                tempProm[j] = promedios[i];
                                j++;
                            }
                        }

                        delete[] codigos;
                        delete[] promedios;
                        codigos= tempCod;
                        promedios= tempProm;
                        cantidad= aprobados;
                    }

//function3: Mostrar estudiantes
void mostrarEstudiantes(int* codigos, double* promedios, int cantidad) {
    for (int i = 0; i < cantidad; i++) {
        cout << "Codigo: " << codigos[i] << " Promedio: " << promedios[i] << endl;
    }
}

//function4


//function5


//function6




//main---------------------
//
//
//
int main(){
    //
    int capacidad;
    cout << "cuantos datos de estudiantes desea agregar:: ";
    cin >> capacidad;

    //
    int cantidad = 0;
    
    // Inicializar arreglos dinámicos
    int* codigos = new int[capacidad];
    double* promedios = new double[capacidad];



    //1---
    agregarEstudiante(codigos, promedios, cantidad, capacidad, 101, 14.5);
    agregarEstudiante(codigos, promedios, cantidad, capacidad, 102, 8.0);
    agregarEstudiante(codigos, promedios, cantidad, capacidad, 103, 16.2);
    agregarEstudiante(codigos, promedios, cantidad, capacidad, 104, 9.5);
    agregarEstudiante(codigos, promedios, cantidad, capacidad, 105, 12.3);


    //2----
    cout << "Estudiantes registrados:" << endl;
    mostrarEstudiantes(codigos, promedios, cantidad);

    //eliminado punteros responsablemente
    delete[] codigos;
    delete[] promedios;

    //functi
    return 0;
} 