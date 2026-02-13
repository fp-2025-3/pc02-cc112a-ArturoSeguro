#include <iostream>
using namespace std;


//function1
struct polinomial{
    int degree;
    int coefficient;
    polinomial* next;
};


//filling (function2)
polinomial* filling(int degree){
    polinomial* head= nullptr;
    polinomial* last= nullptr;

    for(int i=degree; i> 0; i--){                                   //((ERROR1)) I THINK IT IS WRONG. I SHOULDN´T USE [i]
        polinomial* newNode= new polinomial;

        cout << "put the coefficient of 'x^" << i << "':: ";
        cin >> (*newNode).degree;


        (*newNode).next= nullptr;

        //logic
        if(head== nullptr){
            //if it is the first node, it is both
            head= newNode;
            last= newNode;
        }else{
            (*last).next= newNode;
        }
        

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