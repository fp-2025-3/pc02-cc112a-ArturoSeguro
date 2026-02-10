#include <iostream>
using namespace std;

//function1
struct student{
    int code;
    int average;
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
    int N;
    cout << "Give the number N: ";
    cin >> N;

    //dinamic variables
    int *PUNstudent= new student[N];


    //
    for(int i=0; i<N; i++){
        cout << "\n\n";
        cout << i+1 << "-\t Provide the student's code:: ";
        cin >> (*PUNstudent).code[i];

        cout << i+1 << "-\t Provide the student's average:: ";
        cin >> (*PUNstudent).average[i];
    }   



    //just approve students
    cout << "\n\nShowing approved students___\n";
    for(int i=0; i<N; i++){
        if((*PUNstudent).average[i]>= 10){
            cout << (*PUNstudent).average[i];
        }
    }



    //function1


    //function2


    //function3


    //function4


    //function5


    //function6
    delete[] PUNstudent;


    cout << "\n\n-------------END\n";
    return 0;
}