#include <iostream>
#include <fstream>
#include <cstring>
#include <string>
using namespace std;


//---0
struct Proyecto{ 
    int id;
    char titulo[40];
    double presupuesto;
    int duracionMeses;
};
//
const char* nombreArchivo= "proyectos.dat";


//---1
void crear(const char* nombreArchivo, int N){
    Proyecto* p= new Proyecto[5*N];    //para tenen espacio de sobra    
    for(int i=0; i<N; i++){
        cout << "-->--> proyecto numero '" << i+1 << "'\n";
        cout << "id: ";
        cin >> p[i].id;
        cout << "titulo: ";
        cin >> p[i].titulo;
        cout << "presupuesto: ";
        cin >> p[i].presupuesto;
        cout << "duracionMeses: ";
        cin >> p[i].duracionMeses;
        cout << "\n";
    }
    //ordenado con bubble
    for(int i=0; i<N-1; i++){
        for(int j=0; j<N-1-i; j++){
            if(p[j].presupuesto< p[j+1].presupuesto){
                swap(p[j], p[j+1]);
            }
        }
    }
    //1er, 2do
    ofstream escribir(nombreArchivo, ios::out | ios::binary);
    if(!escribir){
        cerr << "no se pudo abrir archivo.\n";
        delete[] p;
        return;
    }
    //3er
    for(int i=0; i<N; i++){
        escribir.write((char*)(&p[i]), sizeof(Proyecto));
    }
    //4to
    escribir.close();
    delete[] p;         //la idea es usar el archivo como base de datos --> no usar la RAM (Eso es un poco trampa)
}


//---2
void agregar(const char* nombreArchivo){
    Proyecto nuevo;
    cout << "-->--> proyectoNuevo numero\n";
    cout << "id: ";
    cin >> nuevo.id;
    //1er, 2do
    fstream modificar(nombreArchivo, ios::out | ios::in | ios::binary);
    if(!modificar){
        cerr << "no se pudo abrir archivo para agrupar.\n";
    }
    //3er__verificacion de id repetido correcto
    Proyecto temp;
    while(modificar.read((char*)(&temp), sizeof(Proyecto))){
        if(temp.id== nuevo.id){
            cout << "[error] --> el id no puede ser repetido.\n";
            modificar.close();
            return;
        }
    }
    //
    cout << "titulo: ";
    cin >> nuevo.titulo;
    cout << "presupuesto: ";
    cin >> nuevo.presupuesto;
    cout << "duracionMeses: ";
    cin >> nuevo.duracionMeses;
    //
    modificar.clear();           //necesario para volver a leer desde 0
    //encontrando posicion para insercion
    modificar.seekg(0, ios::beg);
    int pos= 0;
    while(modificar.read((char*)(&temp), sizeof(Proyecto))){
        if(nuevo.presupuesto > temp.presupuesto){
            break;
        }
        pos++;
    }
    //Contando total de registros
    modificar.clear();
    modificar.seekg(0, ios::end);
    long tama= modificar.tellg();
    int totalRegistros= tama/sizeof(Proyecto);
    //acomodando los registros correctamente para la insercion (empezando desde final)
    for(int i= totalRegistros-1; i>= pos; i--){ //movemos todo mas abajo desde el final hasta la linea "pos" -> justo en esea linea metermos el nuevo
        modificar.seekg(i*sizeof(Proyecto), ios::beg);
        modificar.read((char*)(&temp), sizeof(Proyecto));
        //
        modificar.seekp((i+1)*sizeof(Proyecto), ios::beg);
        modificar.write((char*)(&temp), sizeof(Proyecto));
    }
    //insertando
    modificar.seekp(pos*sizeof(Proyecto), ios::beg);
    modificar.write((char*)(&nuevo), sizeof(Proyecto));
    //4to
    modificar.close();
}


//---3
void mostrarTodo(const char* nombreArchivo){
    //1er, 2do
    ifstream leer(nombreArchivo, ios::in | ios::binary);
    if(!leer){
        cerr << "no se pudo abrir archivo.\n";
        return;
    }
    //3er
    Proyecto p;
    int i=0;
    while(leer.read((char*)(&p), sizeof(Proyecto))){
        cout << "-->--> proyecto numero '" << i+1 << "'\n";
        cout << "id: " << p.id << "\n";
        cout << "titulo: " << p.titulo << "\n";
        cout << "presupuesto: " << p.presupuesto << "\n";
        cout << "duracionMeses: " << p.duracionMeses << "\n";
        i++;
    }
    //4to
    leer.close();
}


//main
//
int main(){
    //---1
    int N;
    cout << "cuantos proyectos desea INICIALIZAR: ";
    cin >> N;
    crear(nombreArchivo, N);
    cout << "\n\n\n";
    //---2
    agregar(nombreArchivo);
    cout << "\n\n\n\n";
    //---3
    mostrarTodo(nombreArchivo);
    cout << "\n\n";

    //
    cout << "\n\n-------------END\n";
    return 0;
}