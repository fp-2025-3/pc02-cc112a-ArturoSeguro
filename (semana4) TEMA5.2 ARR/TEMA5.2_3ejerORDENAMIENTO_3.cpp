#include <iostream>
#include <ctime>
#include <cstdlib>
using namespace std;

//Generadores----------------
            //1. Codigos
            void generadorCodigos(int* codigos, int N){
                for(int i=0; i<N; i++){
                    //
                    codigos[i]= (2025*1000)+ (rand()%1000);

                    //
                    int j=0;
                    while(j<i){
                        bool condicion= codigos[i]!= codigos[j];
                        if(condicion){
                            i--;    //hará que se vuelva a generar un numALEA por si se repitio
                            break;
                        }
                        j++;
                    }
                }

                //
                return;
            }

            //2. Notas
            void generadorNotas(int* notas, int N){
                for(int i=0; i<N; i++){
                    //
                    notas[i]= (rand()%21)+1;
                }

                //
                return;
            }

            //3. Inasistencias
            void generadorInasistencias(int* inasistencias, int N){
                for(int i=0; i<N; i++){
                    //
                    inasistencias[i]= (rand()%11);
                }

                //
                return;
            }



//Ordenando por notas ((usaré mergeSort para practicar bien bien))---------
//4. PartitionSort
int partitionSort(int l, int d){     //-->Devolvia el indice si no me equivoco

}


//5. ordena los Partition
void mergeSort(int* notas, int N, int l, int d){           
    //Caso BASE, cuando llega a arreglo de un elemento
    if(l>=d){
        return;
    }

    if(l<d){
        int medio= (d+l)/2;
        
        partitionSort(l, medio);
        partitionSort(medio+1, d);
        
        return;
    }

    return;
}






//function3



//function4



//function5



//function6







//main
//
int main(){
    srand(time(0));

    int N;
    cout << "Ponga el numero de alumno que hay:: ";
    cin >> N;


    //1.GeneroCódigos
    int* codigos= new int[N];
    generadorCodigos(codigos, N);

    //2.GeneroNotas
    int* notas= new int[N];
    generadorNotas(notas, N);

    //3.GeneroInasistencias
    int* inasistencias= new int[N];
    generadorInasistencias(inasistencias, N);




    //4.Ordenando por notas y manteniendo relación




    //function2



    //function3



    //function4



    //function5



    //function6

    delete[] inasistencias;
    delete[] notas;
    delete[] codigos;

    //
    cout << "\n\n-------------END\n";
    return 0;
}