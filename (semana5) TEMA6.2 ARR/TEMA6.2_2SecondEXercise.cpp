#include <iostream>
#include <cmath>
using namespace std;

//function1
struct punto{
    float x;
    float y;
    float z;
};


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
    //Create two "instancias" --> Create 2 "variables of the struct" that i already made
    punto A[2];

    //
    for(int i=0; i<2; i++){
        cout << "\n\n";
        cout << i+1 << ". Provide the axe 'x':: ";
        cin >> A[i].x;
        cout << i+1 << ". Provide the axe 'y':: ";
        cin >> A[i].y;
        cout << i+1 << ". Provide the axe 'z':: ";
        cin >> A[i].z;
    }

    //
    float xx= A[0].x- A[1].x;
    float yy= A[0].y- A[1].y;
    float zz= A[0].z- A[1].z;
    float distance= sqrt((xx*xx) + (yy*yy) + (zz*zz));
    cout << "\n\nTHe euclidian distnace between them is:: " << distance;



    //function1


    //function2


    //function3


    //function4


    //function5


    //function6
    


    cout << "\n\n-------------END\n";
    return 0;
}