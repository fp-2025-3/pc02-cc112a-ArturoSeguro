#include <iostream>
using namespace std;

//function1
struct student{
    string name;
    int grade;
};

//function2
student bestStudent(student* PUNstudents, int N){
    int higher= -1;
    int higherIN=- 1;
    for(int i=0; i<N; i++){
        if(higher< PUNstudents[i].grade){
            higher= PUNstudents[i].grade;
            higherIN= i;
        }
    }

    return PUNstudents[higherIN];
}

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
    cout << "Provide the quantity of students: ";
    cin >> N;
    cin.ignore();
    student* PUNstudents= new student[N];

    //
    for(int i=0; i<N; i++){
        cout << "\n\n";
        cout << i+1 << ". Provide the name:: ";
        getline(cin, PUNstudents[i].name);

        cout << i+1 << ". Provide the grade:: ";
        cin >> PUNstudents[i].grade;
        cin.ignore();
    }


    //
    student best= bestStudent(PUNstudents, N);
    cout << "\n\nThe best student is:: " << best.name;
    cout << "\nName:: " << best.grade;

    //function1


    //function2


    //function3


    //function4


    //function5


    //function6
    

    //Deleting dynamic arrays
    delete[] PUNstudents;


    cout << "\n\n-------------END\n";
    return 0;
}