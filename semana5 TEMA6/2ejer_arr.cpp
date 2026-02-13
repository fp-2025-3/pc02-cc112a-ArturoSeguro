#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

//
struct goals{
    int favor=0;
    int contra=0;
};
 
//
struct match{
    float empatado;
    float perdido;
    float ganado;
};

//PRINCIPAL
struct team{
    string nombres;
    float puntos;  

    match partidos;
    goals goles;

    int diferenciaGoles;
    float performance;
};

//function1


//function2


//function3


//function4


//function5


//function6




//main
//
//
//
int main(){

    //
    int cantidad= 5;
    srand(time(0));

    //
    team* PUNpaises= new team[cantidad];

    //PARTIDOOOOOOOOOOOOOOOOS
    for(int i=0; i<cantidad; i++){
        //
        cout << "Dea el nombre del equipo: ";
        getline(cin, PUNpaises[i].nombres);

        //
        PUNpaises[i].partidos.ganado= rand()%101;

        //
        int actualGana= PUNpaises[i].partidos.ganado;
        if(actualGana< 100){
            PUNpaises[i].partidos.empatado= rand()%(101- actualGana);
        }else{
            PUNpaises[i].partidos.empatado= 0;
            PUNpaises[i].partidos.perdido= 0;
        }

        //
        int actualEmpata= PUNpaises[i].partidos.empatado;
        if(actualGana+actualEmpata< 100){
            PUNpaises[i].partidos.perdido= rand()%(101- actualGana-actualEmpata);
        }else{
            PUNpaises[i].partidos.perdido= 0;
        }
    }

    //impresion sin goles
    cout << "PAIS\t\t\t\tGANADO\t\tPERDIDO\t\tEMPATADO\t\tPUNTOS\t\tPERFORMANCE\n";
    for(int i=0; i<cantidad; i++){
        cout << "Pais " << i << "\t\t" << PUNpaises[i].partidos.ganado << "\t\t" 
        << PUNpaises[i].partidos.perdido << "\t\t" << PUNpaises[i].partidos.empatado << "\t\t"
        << PUNpaises[i].puntos << "\t\t" << PUNpaises[i].performance << "\n";
    }

    //GOLEEEEEEEEEEEEEEEES
    //ganados
    for(int i=0; i<5; i++){
        for(int j=0; j<PUNpaises[i].partidos.ganado; j++){
            int TEMPfavor= rand()%6;
            int TEMPcontra= rand()%TEMPfavor;

            PUNpaises[i].goles.favor= PUNpaises[i].goles.favor+ TEMPfavor;
            PUNpaises[i].goles.contra= PUNpaises[i].goles.contra+ TEMPcontra;
        }
    }

    //perdidos
    for(int i=0; i<5; i++){
        for(int j=0; j<PUNpaises[i].partidos.perdido; j++){
            int TEMPcontra= rand()%6;
            int TEMPfavor= rand()%TEMPcontra;

            PUNpaises[i].goles.favor= PUNpaises[i].goles.favor+ TEMPfavor;
            PUNpaises[i].goles.contra= PUNpaises[i].goles.contra+ TEMPcontra;
        }
    }

    //perdidos
    for(int i=0; i<5; i++){
        for(int j=0; j<PUNpaises[i].partidos.empatado; j++){
            int TEMPcontra= rand()%6;
            int TEMPfavor= TEMPcontra;

            PUNpaises[i].goles.favor= PUNpaises[i].goles.favor+ TEMPfavor;
            PUNpaises[i].goles.contra= PUNpaises[i].goles.contra+ TEMPcontra;
        }
    }

    //GOLES DIFERENCIA
    for(int i=0; i<5; i++){
        PUNpaises[i].diferenciaGoles= PUNpaises[i].goles.favor- PUNpaises[i].goles.contra;
    }





    //TABLAAAAAAAAAAAAAAAAAAA
    cout << "PAIS\t\t\tGANADO\t\tPERDIDO\t\tEMPATADO\t\tGOLES.FAVOR\t\tGOLES.CONTRA\t\tGOLES.DIFERENCIA\t\tPUNTOS\t\tPERFORMANCE\n";
    for(int i=0; i<cantidad; i++){
        cout << "Pais " << i << "\t\t" << PUNpaises[i].partidos.ganado << "\t\t" 
        << PUNpaises[i].partidos.perdido << "\t\t" << PUNpaises[i].partidos.empatado << "\t\t" 
        << PUNpaises[i].goles.favor << "\t\t" << PUNpaises[i].goles.contra << "\t\t" << PUNpaises[i].diferenciaGoles << "\t\t"
        << PUNpaises[i].puntos << "\t\t" << PUNpaises[i].performance << "\n";
    }


    //el mayor funciónss
    int performanceMayor= -1;
    int INpais= -1;
    for(int i=0; i<cantidad; i++){
        if(performanceMayor< PUNpaises[i].performance){
            performanceMayor= PUNpaises[i].performance;
            INpais= i;
        }
    }

    cout << "\n\nCAMPEON: Pais_ << " << INpais << " | PUNTOS: " << PUNpaises[INpais].puntos  << " | GOLES.DIFERENCIA: " << PUNpaises[INpais].diferenciaGoles  << " | PERFORMANCE: " << PUNpaises[INpais].performance << "%";





    //function1


    //function2


    //function3


    //function4


    //function5


    //function6
    


    cout << "\n\n-------------END\n";
    return 0;
}