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
        //4. Merge
        void merge(int* notas, int l, int mid, int r, int* codigos, int* inasistencias){
            //tamaño de sub-arreglos
            int tamL= (mid-l)+ 1;       //AA..                 //el "+1" es importante ya que uno de los dos lados es el que se tiene que quedar con uno más cuando la cantidad de elemtos es impar
            int tamR= (r-mid);          //BB..

            //arreglos temporales (heap)
            int *notasL= new int[tamL];     //AA..
            int *notasR= new int[tamR];     //BB..
            //
            int *codigosL= new int[tamL];     //AA..
            int *codigosR= new int[tamR];     //BB..
            //
            int *inasistenciasL= new int[tamL];     //AA..
            int *inasistenciasR= new int[tamR];     //BB..


            //los convierto en lo que quiero (las mitades correspondientes del arreglo notas[] --> que también está en el "heap")
            for(int i=0; i<tamL; i++){
                notasL[i]= notas[l+i];          //AA..
                //
                codigosL[i]= codigos[l+i];
                //
                inasistenciasL[i]= inasistencias[l+i];
            }
            for(int i=0; i<tamR; i++){
                notasR[i]= notas[(mid+1)+i];    //BB..          //este "+1" es distinto al del comienzo,,,, este "+1" dice que se tiene que declarar uno más adelante por que el "A..." era el que tenia más (primer "1") elementos y por ende tú (B..) tienes que irte uno más adelante para recien comenzarte a añadir elementos 
                //
                codigosL[i]= codigos[(mid+1)+i];
                //
                inasistenciasL[i]= inasistencias[(mid+1)+i];
            }


            //ordenamiento
            int inL= 0;
            int inR= 0;
            int inCombinado= l;

            //el menor de las 2 mitades
            while(inL< tamL && inR< tamR){
                if(notasL[inL]< notasR[inR]){
                    if(codigosL[inL]< codigosR[inR]){
                        notas[inCombinado]= notasL[inL];
                        //
                        codigos[inCombinado]= codigosL[inL];
                        //
                        inasistencias[inCombinado]= inasistenciasL[inL];
                        inL++;
                    }else{
                        notas[inCombinado]= notasR[inR];
                        //
                        codigos[inCombinado]= codigosR[inR];
                        //
                        inasistencias[inCombinado]= inasistenciasR[inR];
                        inR++;
                    }
                }else if(notasL[inL]< notasR[inR]){
                    notas[inCombinado]= notasL[inL];
                    //
                    codigos[inCombinado]= codigosL[inL];
                    //
                    inasistencias[inCombinado]= inasistenciasL[inL];
                    inL++;
                }else{
                    notas[inCombinado]= notasR[inR];
                    //
                    codigos[inCombinado]= codigosR[inR];
                    //
                    inasistencias[inCombinado]= inasistenciasR[inR];
                    inR++;
                }

                inCombinado++;
            }

            //el resto de "L" si llegan a sobrar
            while(inL< tamL){
                notas[inCombinado]= notasL[inL];
                //
                codigos[inCombinado]= codigosL[inL];
                //
                inasistencias[inCombinado]= inasistenciasL[inL];

                inL++;
                inCombinado++;
            }

            //el resto de "R" si llegan a sobrar
            while(inL< tamR){
                notas[inCombinado]= notasR[inR];
                //
                codigos[inCombinado]= codigosR[inR];
                //
                inasistencias[inCombinado]= inasistenciasR[inR];

                inR++;
                inCombinado++;
            }

            //liberando memoria (del heap)
            delete[] inasistenciasL;
            delete[] inasistenciasR;
            //
            delete[] codigosL;
            delete[] codigosR;
            //
            delete[] notasL;
            delete[] notasR;
        }

        //5. MergeSort
        void mergeSort(int* notas, int l, int r, int* codigos, int* inasistencias){
            //BASE
            if(l>= r){
                return;
            }

            //punto medio
            int mid= (r+l)/2;

            //recursividad 1era mitadL
            mergeSort(notas, l, mid, codigos, inasistencias);

            //recursividad 2da mitadR
            mergeSort(notas, mid+1, r, codigos, inasistencias);

            //ordeno las 2mitades YA ORDENADAS
            merge(notas, l, mid, r, codigos, inasistencias);            //el primero que se llame aca, será el último en resolverse (En el esquema de recursividad)
        }








//Ranking académico---------
                    //6. RankingAcadémico
                    void ranking(int* notas, int* codigos, int N){
                        //top 5
                        cout << "Lista de los 5 mejores:: \n";
                        cout << "CODIGOS        PROMEDIOS       PUESTO\n";
                        for(int i=0; i<5; i++){
                            cout << codigos[i] << "       " << notas[i] << "         " << i+1;
                            cout << "\n";
                        }

                        //promedio del curso
                        int notasTotal=0;
                        for(int i=0; i<N; i++){
                            notasTotal= notasTotal+ notas[i];
                        }
                        cout << "\n\nel promedio del curso es:: " << notasTotal/N;

                        //numero de desaprovados
                        int desaprobados=0;
                        for(int i=0; i<N; i++){
                            if(notas[i]<10){
                                desaprobados++;
                            }
                        }
                        cout << "\nnumero de desaprobados es:: " << desaprobados;
                        cout << "\n";

                        return;
                    }



//Busqueda---------
        //7. BusquedaLineal
        void lineal(int* notas, int* codigos, int* inasistencias, int N, int codigoBuscado){

            int rankingPlace= -1;
            for(int i=0; i<N; i++){
                if(codigos[i]== codigoBuscado){
                    int rankingPlace= i+1;
                    break;
                }
            }

            int j=rankingPlace-1;               //para mantenerlo simple mi codigo
            if(rankingPlace== -1){
                cout << "no existe el codigo introducido.\n";
                return;             
            }else{
                cout << "NOTAS      FALTAS      PUESTO\n";
                cout << notas[j] << "       " << inasistencias[j] << "       " << rankingPlace;
            }

            return;
        }


//2do Ordenamiento---------
                    //8. InsertionSort
                    void insertion(int* codigos, int* notas, int* inasistencias, int N){
                        for(int i=1; i<N; i++){
                            for(int j=i-1; j>=0; j--){      
                                if(codigos[i]< codigos[j]){
                                    swap(codigos[i], codigos[j]);

                                    //paralelamente
                                    swap(notas[i], notas[j]);
                                    swap(inasistencias[i], inasistencias[j]);
                                }
                            }
                        }

                        return;
                    }



//2da Busqueda---------
        //9. busquedaBinaria
        int binaria(int* codigos, int N, int l, int r, int clave){  //retornará el indice en donde está el resultado
            //Base
            if(l>r){
                return -1;      //significa que no encontró lo que se deseaba
            }

            //
            int mitad= (l+r)/2;
            if(mitad== clave){
                return mitad;
            }else if(clave<mitad){
                return binaria(codigos, N, l, mitad-1, clave);
            }else{
                return binaria(codigos, N, mitad+1, r, clave);
            }

            return -2;      //si algo falla me retornará "-2"
        }








//main---------------------------
//
//
//
int main(){
    srand(time(0));

    int N;
    cout << "Ponga el numero de alumnos que hay:: ";
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




    cout << "\n\nODENADO por NOTA------------------------------\n";
    //4y5.Ordenando por notas y manteniendo relación
    mergeSort(notas, 0, N-1, codigos, inasistencias);

    //6.RankingAcademico
    ranking(notas, codigos, N);

    //
    int codigoBuscado;
    cout << "Escriba el codigo que desea buscar:: ";
    cin >> codigoBuscado;
    //7.BusquedaLineal
    lineal(notas, codigos, inasistencias, N, codigoBuscado);




    cout << "\n\nODENADO por CODIGO------------------------------\n";
    //8.SegundoOrdenamiento (Insertion)
    insertion(codigos, notas, inasistencias, N);

    //
    int codigoBuscado2;
    cout << "Escriba el OTRO codigo que quiera buscar:: ";
    cin >> codigoBuscado2;
    //9.BusquedaBinaria
    int inEncontrado= binaria(codigos, N, 0, N-1, codigoBuscado2);
    bool condicion1= (inEncontrado== -1);
    bool condicion2= (inEncontrado== -2);
    if(condicion1){
        cout << "\nNo se encontro el numero (asegurese de que existe)\n";
    }else if(condicion2){
        cout << "Algo fallo en la busqueda\n";
    }else{
        cout << "NOTAS      FALTAS      PUESTO\n";
        cout << notas[inEncontrado] << "       " << inasistencias[inEncontrado] << "        " << inEncontrado+1;
    }


    //eliminando memoria guardada en el heap
    delete[] inasistencias;
    delete[] notas;
    delete[] codigos;

    //
    cout << "\n\n-------------END\n";
    return 0;
}