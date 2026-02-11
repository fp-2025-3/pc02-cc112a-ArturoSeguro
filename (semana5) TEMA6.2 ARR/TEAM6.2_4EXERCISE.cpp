#include <iostream>
using namespace std;


//function1
struct polinomial{
    int degree;
    int coefficient;
    polinomial* next;
};


//filling (function2)
polinomial filling(polinomial* actualP, int degree){
    polinomial* head= nullptr;
    for(int i=degree; i> 0; i--){                                   //((ERROR1)) I THINK IT IS WRONG. I SHOULDN´T USE [i]
        cout << "put the coefficient of 'x^" << i << "':: ";
        cin >> actualP[i].coefficient;

        //
        actualP[i].next= head;
        head= actualP[i].next;      //this is usefull for track my "nested struct" by a for that searchs if(==nulptr)
    }


}


//Showing POlinomials (function3)
void printingPolinomial(polinomial* actualP, int degree){
    polinomial* head2= nullptr;
    for(int i=degree; i> 0; i++){
        if(i== degree){
            //nothing
        }else{
            cout << " + ";
        }
        cout << "x^" << actualP[i].coefficient;



    }
}


//function4


//function5


//function6




//main
//
//
//
int main(){
    polinomial* POINpolinonial= new polinomial[2];

    //(function2)
    for(int i=0; i<2; i++){
        cout << "Provide the degree of the polinomial:: ";
        cin >> POINpolinonial[i].degree;
        *POINpolinonial= filling(POINpolinonial+i, POINpolinonial[i].degree);

        cout << "\n\n";
    }


    //showing polinomials
    for(int i=0; i<2; i++){
        cout << i+1 << " Polinomial:: ";
        printingPolinomial(POINpolinonial+i, POINpolinonial[i].degree);

        cout << "\n";
    }


    //function1


    //function2


    //function3


    //function4


    //function5


    //function6



    //Deleting

    delete[] POINpolinonial;
    


    cout << "\n\n-------------END\n";
    return 0;
}