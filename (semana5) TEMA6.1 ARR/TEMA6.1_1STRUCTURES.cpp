#include <iostream>
using namespace std;

struct student{
    int code;
    int average[2];            //it could be an array one of the "members"
    string gendre;
};     //be carefull

//6. Nested structures (linked structures)
struct date{
    int year;
    int month;
    int day;
};

struct university{
    string name;
    date birthday;
};








//8. Structures as a parameters

void show(student e1){
    cout << e1.code;
}

//giving as a reference (to not copy and be able to modify the value of the structure)
void add(student &e1){
    e1.average[1]++;
}




//
float averageClass(student A[], int tam){
    float total= 0;
    for(int i=0; i<tam; i++){                   //changing grades of structure arrays
        total= total+ A[i].average[1];
    }

    return total/tam;
}









int main(){

    /*

    //2. Declaration
    student e1= {12301, 13, "male"};

    //3, Inicialization
    //3.1 Direct Inicialization
        //--> lo que hice arriba  struct{}


    //3.2 Inicialization Member by member
    student e3;

    e3.code= 12308;       //point operator
    e3.average= 20;
    e3.gendre= "female";



    //----------------------------------------

    //int a1[5]= {0};

    //int a2[5]= {-1};

    //a1= a2;         //this is wrong

    //3.3. structures asignation
    student e4= e3;     //now it is correct


    //4. Lecture amd tipying strucutres
    student e5;
    cout << "\nPut the code of the student:: ";
    cin >> e5.code;
    cout << "\nPut the average of the student:: ";
    cin >> e5.average;
    cout << "\nPut the gendre of the student:: ";
    cin >> e5.gendre;

    //Tipyng
    cout << "\n\nThe code of 5th student is:: " << e5.code;
    cout << "\n\nThe average of 5th student is:: " << e5.average;
    cout << "\n\nThe gendre of 5th student is:: " << e5.gendre;


    //5. Structures Array
    student A[3];           //array of 3(three) structures

    //reading the elemets (structures) of this array A[]
    for(int i=0; i<3; i++){
        cout << "\n\n\nStudent '" << i+1 << "' ::";
        cout << "\nType the Code: ";
        cin >> A[i].code;
        cout << "\nType the Average: ";
        cin >> A[i].average;
        cout << "\nType the Gendre: ";
        cin >> A[i].gendre;
    }




    //6. Nested structures
    university a1;

    //initialization code
    a1.name= "Arturo";
    a1.birthday.year= 2003;
    a1.birthday.month= 4;
    a1.birthday.day= 8;




    */






    //7, structure pointers
    student e6= {1230001230, {21, 2}, "alpha male"};
    student *ptr;

    ptr= &e6;


    //through pointers pointing structures members
    //(i)FIRST WAY ((using arrow operator))
    cout << ptr->code << "\n";
    cout << ptr->average << "\n";
    cout << ptr->gendre << "\n";
    //just useful if "ptr" is a pointer


    //(ii)SECOND WAY
    cout << (*ptr).code << "\n";




    cout << "\n\n-------------END\n";
    return 0;
}