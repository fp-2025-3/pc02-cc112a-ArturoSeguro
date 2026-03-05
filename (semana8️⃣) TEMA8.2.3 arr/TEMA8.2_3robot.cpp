#include <iostream>
#include "TEMA8.2_3robot.h"
#include <cstring>
#include <string>
using namespace std;


//---0
//a1
robot:: robot(){
    cout << "creando robot.\n";
}
//a2
robot:: ~robot(){
    cout << "destruyendo robot.\n";
}
//b
void robot:: ejecutarTarea(){
    cout << "esperando ordenes.\n";
}


//---1
//a1
futbolista:: futbolista(){
    cout << "creando futbolista.\n";
}
//a2
futbolista:: ~futbolista(){
    cout << "destruyendo futbolista.\n";
}
//b
void futbolista:: ejecutarTarea(){
    robot:: ejecutarTarea();
    cout << "pateando al angulo.\n";
}


//---2
//a1
analista:: analista(){
    cout << "creando analista.\n";
}
//a2
analista:: ~analista(){
    cout << "destruyendo analista.\n";
}
//b
void analista:: ejecutarTarea(){
    robot:: ejecutarTarea();
    cout << "analizando datos y organizando archivos.\n";
} 