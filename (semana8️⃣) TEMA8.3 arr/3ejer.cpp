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
Proyecto* crear(const char* nombreArchivo, int N){
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
        return nullptr;
    }
    //3er
    for(int i=0; i<N; i++){
        escribir.write((char*)(&p[i]), sizeof(Proyecto));
    }
    //4to
    escribir.close();
    //
    return p;
}


//---2.1
int repetido(int& N, Proyecto*& p, int idBuscado){
    for(int i=0; i<N; i++){
        if(p[i].id== idBuscado){
            return i;
        }
    }
    return -1;
}


//---2
void agregar(const char* nombreArchivo, int& N, Proyecto*& p){
    //usare p[N]
    cout << "-->--> proyectoNuevo numero '" << N+1 << "'\n";
    cout << "id: ";
    cin >> p[N].id;
    if(repetido(N, p, p[N].id )!= -1){
        cout << "[error] --> el id no puede ser repetido.\n";
        return;
    }
    cout << "titulo: ";
    cin >> p[N].titulo;
    cout << "presupuesto: ";
    cin >> p[N].presupuesto;
    cout << "duracionMeses: ";
    cin >> p[N].duracionMeses;
    N++;
    //ordenado con bubble (con la nueva cantidad 'N' actualizada)
    for(int i=0; i<N-1; i++){
        for(int j=0; j<N-1-i; j++){
            if(p[j].presupuesto< p[j+1].presupuesto){
                swap(p[j], p[j+1]);
            }
        }
    }
    //1er, 2do (como lo quiero ordenado mejor lo sobreescribo todo en vez de usar 'ios::app' seri mas complicado)
    ofstream escribir(nombreArchivo, ios::out | ios::binary);
    if(!escribir){
        cerr << "no se pudo abrir archivo.\n";
        return;
    }
    //3er
    for(int i=0; i<N; i++){
        escribir.write((char*)(&p[i]), sizeof(Proyecto));
    }
    //4to
    escribir.close();
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
    Proyecto* p= crear(nombreArchivo, N);
    cout << "\n\n\n";
    //---2
    agregar(nombreArchivo, N, p);
    cout << "\n\n\n\n";
    //---3
    mostrarTodo(nombreArchivo);
    cout << "\n\n";


    //delete
    delete[] p;

    //
    cout << "\n\n-------------END\n";
    return 0;
}