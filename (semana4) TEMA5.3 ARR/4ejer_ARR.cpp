#include <iostream>
using namespace std;

//1----: Agregar estudiante y duplicar capacidad si es necesario-----
        void agregarEstudiante(int*& codigos, double*& promedios, int& cantidad, int& capacidad, int nuevoCodigo, double nuevoPromedio) {
            if (cantidad == capacidad) {
                capacidad *= 2;
                int* tempCod = new int[capacidad];
                double* tempProm = new double[capacidad];

                //filling with the previous values from the original DinamicArray to the new one that i called "temp." 
                for (int i = 0; i < cantidad; i++) {
                    tempCod[i] = codigos[i];
                    tempProm[i] = promedios[i];
                }

                delete[] codigos;           //and I delete the "original" previous dynamic arrays but not the pointers, the pointers still continues lasting. So what i do is to link the recent "Dynamic arrays" to the original pointer. In this way, we update the array 
                delete[] promedios;         
                codigos = tempCod;
                promedios = tempProm;
            }

            codigos[cantidad] = nuevoCodigo;        //I add the new information
            promedios[cantidad] = nuevoPromedio;
            cantidad++;                             //and i Left ready the "index" for the next update of information
        }



        
//2---: Eliminar desaprobados y redimensionar al tamaño exacto------
                    void eliminarDesaprobados(int*& codigos, double*& promedios, int& cantidad) {
                        int aprobados = 0;
                        //Contamos cuantos pasan
                        for(int i= 0; i<cantidad; i++) {
                            if(promedios[i] >= 10){
                                aprobados++;
                            }
                        }

                        //Nuevo arreglo tamaño exacto
                        int* tempCod = new int[aprobados];
                        double* tempProm = new double[aprobados];
                        

                        int j = 0;
                        for (int i = 0; i < cantidad; i++) {
                            if (promedios[i] >= 10) {                   //I'm just filling with the approved ones
                                tempCod[j] = codigos[i];
                                tempProm[j] = promedios[i];
                                j++;
                            }
                        }

                        delete[] codigos;
                        delete[] promedios;
                        codigos = tempCod;              //I update all my variables
                        promedios = tempProm;
                        cantidad = aprobados;
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
    cin >> capacidad;                   //these variables are gonna keep update whilst the functions are called

    //
    int cantidad = 0;
    
    // Inicializar arreglos dinámicos
    int* codigos = new int[capacidad];
    double* promedios = new double[capacidad];



    //1---
    int newCode;
    int newGrade;
    for(int i=0; i<capacidad; i++){
        cout << "\nPlease, type the new CODE to add:: ";
        cin >> newCode;

        cout << "Type the new GRADE to add:: ";
        cin >> newGrade;
        if(newGrade== -1 || newCode== -1){
            break;
        }

        agregarEstudiante(codigos, promedios, cantidad, capacidad, newCode, newGrade);
        cout << "\n";
    }    

    //2----
    cout << "Estudiantes registrados:" << endl;
    mostrarEstudiantes(codigos, promedios, cantidad);



    //3--
    cout << "\n\nUpdating to just approved students:: \n";
    eliminarDesaprobados(codigos, promedios, cantidad);
    mostrarEstudiantes(codigos, promedios, cantidad);


    //eliminado punteros responsablemente
    delete[] codigos;
    delete[] promedios;


    //
    return 0;
} 