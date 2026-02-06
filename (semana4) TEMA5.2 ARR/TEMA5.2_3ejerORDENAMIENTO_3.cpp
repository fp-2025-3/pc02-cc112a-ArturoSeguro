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
                                bool condicion= codigos[i]== codigos[j];    //(error3) quiero analizar si son iguales y ahí recién hacer el cambio;
                                if(condicion){
                                    i--;    
                                    break;
                                }
                                j++;
                            }
                        }

                        //
                        return;
                    }

                    //2. Notas
                    void generadorNotas(float* notas, int N){
                        for(int i=0; i<N; i++){
                            //
                            notas[i]= (rand()%21);  //(error4) el "+1" no es lo que quiero --> con eso podría obtener "21" de nota
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
        void merge(float* notas, int l, int mid, int r, int* codigos, int* inasistencias){
            //tamaño de sub-arreglos
            int tamL= (mid-l)+ 1;      
            int tamR= (r-mid);          

            //arreglos temporales (heap)
            float *notasL= new float[tamL];    
            float *notasR= new float[tamR];  
            //
            int *codigosL= new int[tamL];   
            int *codigosR= new int[tamR];  
            //
            int *inasistenciasL= new int[tamL];   
            int *inasistenciasR= new int[tamR];    


            //los convierto en lo que quiero (las mitades correspondientes del arreglo notas[] --> que también está en el "heap")
            for(int i=0; i<tamL; i++){
                notasL[i]= notas[l+i];        
                //
                codigosL[i]= codigos[l+i];
                //
                inasistenciasL[i]= inasistencias[l+i];
            }
            for(int i=0; i<tamR; i++){
                notasR[i]= notas[(mid+1)+i];    
                //
                codigosR[i]= codigos[(mid+1)+i];
                //
                inasistenciasR[i]= inasistencias[(mid+1)+i];
            }


            //ordenamiento
            int inL= 0;
            int inR= 0;
            int inCombinado= l;

            //el menor de las 2 mitades
            while(inL< tamL && inR< tamR){                              //(ERROR1) lo había hecho de menor -> mayor ((Se pedi ade mayor -> menor))
                if(notasL[inL]== notasR[inR]){
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
                }else if(notasL[inL]> notasR[inR]){
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
            while(inR< tamR){                                   //(error5) pequeños errores que me cuestan muy caro luego
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
        void mergeSort(float* notas, int l, int r, int* codigos, int* inasistencias){
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
            merge(notas, l, mid, r, codigos, inasistencias); 
        }








//Ranking académico---------
                    //6. RankingAcadémico
                    void ranking(float* notas, int* codigos, int N){
                        //top 5
                        cout << "Lista de los 5 mejores:: \n";
                        cout << "CODIGOS\t\tPROMEDIOS\tPUESTO\n";           //los "\t" me ofrecen más orden
                        for(int i=0; i<5; i++){
                            cout << codigos[i] << "\t\t" << notas[i] << "\t\t" << i+1;
                            cout << "\n";
                        }

                        //promedio del curso
                        float notasTotal=0;
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
        void lineal(float* notas, int* codigos, int* inasistencias, int N, int codigoBuscado){

            int rankingPlace= -1;
            for(int i=0; i<N; i++){
                if(codigos[i]== codigoBuscado){
                    rankingPlace= i+1;              //(ERROR2) el "int" de adentro malograba todo
                    break;
                }
            }

            int j=rankingPlace-1;
            if(rankingPlace== -1){
                cout << "no existe el codigo introducido.\n";
                return;             
            }else{
                cout << "NOTAS\tFALTAS\tPUESTO\n";
                cout << notas[j] << "\t" << inasistencias[j] << "\t" << rankingPlace;
            }

            return;
        }


//2do Ordenamiento---------
                    //8. InsertionSort
                    void insertion(int* codigos, float* notas, int* inasistencias, int N){      //(ERROR6) no lo programe adecuadamente
                        for(int i=1; i<N; i++){
                            int j= i-1;
                            while(j>= 0 && codigos[j]> codigos[i]){
                                codigos[j+1]= codigos[j];
                                //paralelamente
                                notas[j+1]= notas[j];
                                inasistencias[j+1]= inasistencias[j];

                                j--;    
                            }

                            codigos[j+1]= codigos[i];
                            //paralelo
                            notas[j+1]= notas[i];
                            inasistencias[j+1]= inasistencias[i];

                        }

                        return;
                    }



//2da Busqueda---------
        //9. busquedaBinaria
        int binaria(int* codigos, int N, int l, int r, int clave){
            //Base
            if(l>r){
                return -1;
            }

            //
            int mitad= (l+r)/2;
            if(codigos[mitad]== clave){      //(error7) no puedo comparar un indice con un elemento del array
                return mitad;
            }else if(clave< codigos[mitad]){
                return binaria(codigos, N, l, mitad-1, clave);
            }else{
                return binaria(codigos, N, mitad+1, r, clave);
            }

            //no es necesario otro "return" (tiene que caer en una de mis opciones ya programadas)
        }








//main---------------------------
//
//
//
int main(){
    srand(time(0));

    int N;
    cout << "Ponga el numero de alumnos que hay (mayor a 5):: "; //(error9) es necesario ">5"para no tener errores de overflow en la función "ranking()""
    cin >> N;

    //1.GeneroCódigos
    int* codigos= new int[N];
    generadorCodigos(codigos, N);

    //2.GeneroNotas
    float* notas= new float[N];             //(error8) los cambie todas las notas[] a float porque así me darán decimales correcta en "el promedio del curso"
    generadorNotas(notas, N);

    //3.GeneroInasistencias
    int* inasistencias= new int[N];
    generadorInasistencias(inasistencias, N);




    cout << "\n\nODENADO por NOTA (descendente)------------------------------\n";
    //4y5.Ordenando por notas y manteniendo relación
    mergeSort(notas, 0, N-1, codigos, inasistencias);

    //6.RankingAcademico
    ranking(notas, codigos, N);

    //
    int codigoBuscado;
    cout << "\nEscriba el codigo que desea buscar:: ";
    cin >> codigoBuscado;
    //7.BusquedaLineal
    lineal(notas, codigos, inasistencias, N, codigoBuscado);




    cout << "\n\nODENADO por CODIGO (ascendente)------------------------------\n";
    //8.SegundoOrdenamiento (Insertion)
    insertion(codigos, notas, inasistencias, N);

    //
    int codigoBuscado2;
    cout << "Escriba el OTRO codigo que quiera buscar:: ";
    cin >> codigoBuscado2;
    //9.BusquedaBinaria
    int inEncontrado= binaria(codigos, N, 0, N-1, codigoBuscado2);
    if(inEncontrado== -1){
        cout << "\nNo se encontro el numero (asegurese de que existe)\n";
    }else{
        cout << "NOTAS\tFALTAS\tPUESTO\n";
        cout << notas[inEncontrado] << "\t" << inasistencias[inEncontrado] << "\t" << inEncontrado+1;
        cout << "\n";
    }


    //eliminando memoria guardada en el heap
    delete[] inasistencias;
    delete[] notas;
    delete[] codigos;

    //
    cout << "\n\n-------------END\n";
    return 0;
}