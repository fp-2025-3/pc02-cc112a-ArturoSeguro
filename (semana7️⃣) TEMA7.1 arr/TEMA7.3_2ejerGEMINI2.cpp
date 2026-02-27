#include <iostream>
#include <fstream>
#include <cstring>
using namespace std;


//---0.A
class arcadePlayer{
    private:
    int creditosActuales;
    double puntajeMaximo;
    //0. constructores
    public:
    arcadePlayer(int credito, double puntaje);
    arcadePlayer();
    arcadePlayer(const arcadePlayer& playerReceptor);
    //1. destructores
    ~arcadePlayer();
    //2. métodos
    void insertarMoneda();
    void jugarPartida(double puntajeObtenido);
};


//main
//
int main(){
    //
    arcadePlayer jugador1;
    jugador1.insertarMoneda();
    jugador1.insertarMoneda();
    jugador1.jugarPartida(3000);
    //
    arcadePlayer jugador2(jugador1);
    jugador2.jugarPartida(200);
    jugador2.jugarPartida(1000);
    jugador2.insertarMoneda();
    jugador2.jugarPartida(1000);
    jugador2.jugarPartida(1000);
    jugador2.jugarPartida(1000);
    jugador2.jugarPartida(1000);
    jugador2.jugarPartida(1000);
    jugador2.jugarPartida(1000);

    
    //
    cout << "\n\n-------------END\n";
    return 0;
}


//---0.B
//0. constructores
arcadePlayer:: arcadePlayer(int credito, double puntaje)
: creditosActuales(credito), puntajeMaximo(puntaje){
    cout << "jugardor creado.\n";
}
arcadePlayer:: arcadePlayer()
: creditosActuales(3), puntajeMaximo(0){
    cout << "jugardor creado.\n";
}
arcadePlayer:: arcadePlayer(const arcadePlayer& playerCopy)
: creditosActuales(playerCopy.creditosActuales), puntajeMaximo(playerCopy.puntajeMaximo){
    cout << "jugardor creado.\n";
}
//1. destructores
arcadePlayer:: ~arcadePlayer(){
    cout << "GAME OVER. Jugador retirado del sistema.\n";
}
//2. métodos
void arcadePlayer:: insertarMoneda(){
    creditosActuales++;
}
void arcadePlayer:: jugarPartida(double puntajeObtenido){
    if(creditosActuales>0){
        creditosActuales--;
    }else{
        cout << "[sin creditos] --> Inserte una moneda para seguir jugando.\n";
    }
    //
    if(puntajeMaximo< puntajeObtenido){
        puntajeMaximo= puntajeObtenido;
    }
}

