#include <iostream>
#include "TEMA8.2_3robot.h"
#include <cstring>
#include <string>
using namespace std;


//main
//
int main(){
    robot* r[2];
    //
    r[0]= new futbolista();
    r[1]= new analista();
    //
    for(int i=0; i<2; i++){
        r[i]->ejecutarTarea();
    }


    //delete
    for(int i=0; i<2; i++){
        delete r[i];
    }


    //
    cout << "\n\n-------------END\n";
    return 0;
} 