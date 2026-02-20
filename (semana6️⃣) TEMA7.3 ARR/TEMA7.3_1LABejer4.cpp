#include <iostream>
#include <fstream>
#include <cstring>
using namespace std;


//
const char* nombreArchivo= "TEMA7.3_laguna.txt";


//
struct coo{
    float x;
    float y;
};


//
struct laguna{
    int nt;
    int nv;
    //
    coo coordenadasV[3];     
    //apuntará a 3 de los 7 líneas de coorde. de vertices
    int ordenT;       
    //Dependiendo del orden de triangulo que sea: T1, T2, T3.... --> pues se eligirán las coordenadas que le corresponden
    //va apuntar a las últimas "nt" lineas
};


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
    //aca quisiera adelantarme "nv" lineas y de ahí --> tomar como primer valor de "coordenadasV[3]" a la "nv+1" línea --> luego en otro bucle tomaría como valor al "nv+2" línea --> y así hasta alacanzar el valor de "nv+nt" línea
    //solo que no sé cómo hacer eso en formator ".txt" --> en binary estoy muy seguro que solo tendría que usar "leer.seekg([nv-1]+1, ios::beg);" --> luego "leer.read((int*)(&p), sixeof(laguna));" cierto?, pero cómo hago esto en formato "txt."?

    //
    cout << "\n\n-------------END\n";
    return 0;
}