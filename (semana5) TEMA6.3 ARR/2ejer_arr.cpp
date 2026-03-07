#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

                //--2
                struct goals{
                    int favor=0;
                    int contra=0;
                };
                
                //--1
                struct match{
                    int empatado;
                    int perdido;
                    int ganado;
                };

//--0.PRINCIPAL
struct team{
    string nombres;
    float puntos;  

    match partidos;     //--1
    goals goles;        //--2

    int diferenciaGoles;
    float performance;
};


//main
//
//
//
int main(){
    srand(time(0));
    int cantidad= 5;
    team* PUNpaises= new team[cantidad];


    //i) PARTIDOOOOOOOOOOOOOOOOS--
    for(int i=0; i<cantidad; i++){
        //
        cout << "Dea el nombre del equipo: ";
        getline(cin, PUNpaises[i].nombres);

        //Esta forma de generar aleatoria es mucho más simple
        PUNpaises[i].partidos.ganado= rand()%101;
        PUNpaises[i].partidos.empatado= rand()%(101- PUNpaises[i].partidos.ganado);
        PUNpaises[i].partidos.perdido= 100- PUNpaises[i].partidos.ganado- PUNpaises[i].partidos.empatado;
    }


                    //ii) GOLEEEEEEEEEEEEEEEES--
                    //ganados
                    for(int i=0; i<5; i++){
                        for(int j=0; j<PUNpaises[i].partidos.ganado; j++){
                            int TEMPfavor= (rand()%5)+1;        //entre 1-5 para luego usar correctamente el siguiente rand()
                            int TEMPcontra= rand()%TEMPfavor;   //este rand() daría error si fuer --> rnad()%0 --> ERROR --> ya no sucederá

                            PUNpaises[i].goles.favor= 
                            PUNpaises[i].goles.favor+ TEMPfavor;
                            PUNpaises[i].goles.contra= 
                            PUNpaises[i].goles.contra+ TEMPcontra;
                        }
                    }
                    //perdidos
                    for(int i=0; i<5; i++){
                        for(int j=0; j<PUNpaises[i].partidos.perdido; j++){
                            int TEMPcontra= (rand()%5)+1;
                            int TEMPfavor= rand()%TEMPcontra;

                            PUNpaises[i].goles.favor= 
                            PUNpaises[i].goles.favor+ TEMPfavor;
                            PUNpaises[i].goles.contra= 
                            PUNpaises[i].goles.contra+ TEMPcontra;
                        }
                    }
                    //empatados
                    for(int i=0; i<5; i++){
                        for(int j=0; j<PUNpaises[i].partidos.empatado; j++){
                            int TEMPcontra= (rand()%5)+1;
                            int TEMPfavor= TEMPcontra;

                            PUNpaises[i].goles.favor= 
                            PUNpaises[i].goles.favor+ TEMPfavor;
                            PUNpaises[i].goles.contra= 
                            PUNpaises[i].goles.contra+ TEMPcontra;
                        }
                    }


    //iii) DIFERENCIA GOLES & PUNTOS & PERFORMANCE
    for(int i=0; i<5; i++){
        //DG
        PUNpaises[i].diferenciaGoles=
        PUNpaises[i].goles.favor- PUNpaises[i].goles.contra;

        //Puntos
        PUNpaises[i].puntos=
        (PUNpaises[i].partidos.ganado*3)+ (PUNpaises[i].partidos.empatado*1);
    
        //Rendimiento (performance)
        PUNpaises[i].performance= (float)(PUNpaises[i].puntos/300)*100;  
    }


                    //iv) ORDENANDO SEGÚN PUNTOS MÁS ALTOS
                    for(int i=0; i<cantidad-1; i++){
                        for(int j=0; j<cantidad-1-i; j++){
                            bool intercambiar= false;

                            //mayor puntaje
                            if(PUNpaises[j].puntos< PUNpaises[j+1].puntos){
                                intercambiar= true;
                            }else if(PUNpaises[j].puntos== PUNpaises[j+1].puntos){

                                //por si hay empate --> mayor DG
                                if(PUNpaises[j].diferenciaGoles< PUNpaises[j+1].diferenciaGoles){
                                    intercambiar= true;
                                }else if(PUNpaises[j].diferenciaGoles< PUNpaises[j+1].diferenciaGoles){
                                    
                                    //por si hay empate denuevo --> mayor GOL a favor
                                    if(PUNpaises[j].goles.favor< PUNpaises[j+1].goles.favor){
                                        intercambiar= true;
                                    }
                                }
                            }

                            //si alguno cumple
                            if(intercambiar){
                                team temp= PUNpaises[j];
                                PUNpaises[j]= PUNpaises[j+1];
                                PUNpaises[j+1]= temp;
                            }
                        }
                    }


    //v) TABLAAAAAAAAAAAAAAAAAAA
    cout << "PAIS\t\tGANADO\t\tPERDIDO\t\tEMPATADO\tGOLES.FAVOR\tGOLES.CONTRA\tGOLES.DIFERENCIA\tPUNTOS\tPERFORMANCE\n";
    cout << "--------------------------------------------------------------------------------------------------------------------------------------------------------------";
    for(int i=0; i<cantidad; i++){
        cout << "\n";
        cout << PUNpaises[i].nombres << "\t\t" << PUNpaises[i].partidos.ganado << "\t\t" 
        << PUNpaises[i].partidos.perdido << "\t\t" << PUNpaises[i].partidos.empatado << "\t\t" 
        << PUNpaises[i].goles.favor << "\t\t" << PUNpaises[i].goles.contra << "\t\t" << PUNpaises[i].diferenciaGoles << "\t\t\t"
        << PUNpaises[i].puntos << "\t" << PUNpaises[i].performance;
    }


                    //vi) EL CAMPEON --> como esta ordenado pues es directamente PUNpaises[0]
                    cout << "\n\nCAMPEON: " << "| NOMBRE: " << PUNpaises[0].nombres  << " | PUNTOS: " << PUNpaises[0].puntos  << " | GOLES.DIFERENCIA: " << PUNpaises[0].diferenciaGoles  << " | PERFORMANCE: " << PUNpaises[0].performance << "%";


    //
    cout << "\n\n-------------END\n";
    return 0;
}