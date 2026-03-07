#include <iostream>
#include <fstream>
#include <cstring>
#include <cmath>    //for abs() integers
#include <cstdlib>  //for fabs() floating point
using namespace std;


//---0
const char* nombreArchivo= "TEMA7.3_laguna.txt";


//---C
struct orden{
    double v[3];
};


//---B
struct coo{
    double x;
    double y;
};


//---A
struct laguna{
    int nt;
    int nv;
    //
    coo* coordenadasV;     
    //apuntará a --> las 7 líneas de coorde. de vertices
    orden* ordenT;       
    //apuntará a todas las líneas restantes "nt" --> lineas son
};

//--->1
double area(laguna l){
    double A=0;
    for(int i=0; i<l.nt; i++){
        double x[3], y[3];
        for(int j=0; j<3; j++){     //para cada vertice
            int indice= l.ordenT[i].v[j]-1;
            x[j]= l.coordenadasV[indice].x;
            y[j]= l.coordenadasV[indice].y;
        }
        //
        A= A+ ( fabs( (x[0]*(y[2]-y[1]))+ (x[1]*(y[0]-y[2]))+ (x[2]*(y[1]-y[0]))) )/2.0;
    }

    return A;
}


//main
//
int main(){
    //1er, 2do
    ifstream leer(nombreArchivo, ios:: in);
    if(!leer){
        cerr << "\n[ERROR]--> no se pudo abrir el archivo.\n";
        return -1;
    }
    //3er
    laguna l;
    leer >> l.nt;
    leer >> l.nv;
    //
    l.coordenadasV= new coo[l.nv];
    for(int i=0; i<l.nv; i++){
        leer >> l.coordenadasV[i].x;
        leer >> l.coordenadasV[i].y;
    }
    //
    l.ordenT= new orden[l.nt];
    for(int i=0; i<l.nt; i++){
        for(int j=0; j<3; j++){
            leer >> l.ordenT[i].v[j];           //esta es una forma para poder trabajar con menos lineas
        }
    }
    //4to
    leer.close();
    double areaTotal= area(l);


    //1er, 2do
    ofstream escribir("TEMA7.3_area.txt", ios::out);
    if(!escribir){
        cerr << "\n[ERROR]--> no se pudo abrir el archivo.\n";
        return -1;
    }
    //3er
    escribir << "El area total de las zonas trianguladas es: '" << areaTotal << "' m^2.\n";
    //4to
    escribir.close();


    //deleting
    delete[] l.ordenT;
    delete[] l.coordenadasV;


    //
    cout << "\n\n-------------END\n";
    return 0;
}