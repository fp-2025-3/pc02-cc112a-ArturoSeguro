#include <iostream>
#include "TEMA8.2_1personaje.h"
#include <cstring>
#include <string>
using namespace std;


//main
//
int main(){
    //
    personaje p("ronaldo", 100, 4);
    p.disparar();
    p.getHitted(70);
    p.disparar();
    p.disparar();
    p.disparar();
    p.disparar();
    p.getHitted(50);


    //
    cout << "\n\n-------------END\n";
    return 0;
}