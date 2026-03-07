#include <iostream>
using namespace std;


//Function0
struct date{
    int dd;
    int mm;
    int yy;
};



//function1
struct contacts{
    char name[20];
    date birthday;
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
    cin.ignore();

    //dinamic variables
    contacts* PUNcontacts= new contacts[N];


    //
    for(int i=0; i<N; i++){
        cout << "\n\n";
        cout << i+1 << "-\t Provide the student's name:: ";
        cin.getline(PUNcontacts[i].name, 20);

        cout << i+1 << "-\t Provide the student's dd:: ";
        cin >> PUNcontacts[i].birthday.dd;
        cin.ignore();
        cout << i+1 << "-\t Provide the student's mm:: ";
        cin >> PUNcontacts[i].birthday.mm;
        cin.ignore();
        cout << i+1 << "-\t Provide the student's yy:: ";
        cin >> PUNcontacts[i].birthday.yy;
        cin.ignore();
    }   



    //
    int year;
    cout << "\n\nProvide the year of born:: ";
    cin >> year;
    for(int i=0; i<N; i++){
        if(PUNcontacts[i].birthday.yy== year){
            cout << i+1 << "-\t Student's name: " << PUNcontacts[i].name;
            cout << "\n";
        }
    }

    //function1


    //function2


    //function3


    //function4


    //function5


    //function6
    
    //
    delete[] PUNcontacts;

    cout << "\n\n-------------END\n";
    return 0;
}