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
    polinomial* head= nullptr;          //pointer prepared to point a variable of the type y made in the struct
    polinomial* last= nullptr;          //pointer prepared to point a variable of the type y made in the struct  

    for(int i=degree; i>= 0; i--){                  //it is necessary to include the "0" too.             
        polinomial* ActualNode= new polinomial;
        (*ActualNode).next= nullptr;            //the intern pointer of this Actual(new) Structure during this loop will indicate to nothing --> in the next loop it is gonna to pint the struct of that same next loop

        (*ActualNode).degree= i;
        cout << "Input the coefficient of 'x^" << i << "':: ";
        cin >> (*ActualNode).coefficient;
    
        //Inserting in the list
        if(head== nullptr){
            //if list is the first node, it is both head and last
            head= ActualNode;
            last= ActualNode;
        }else{
            //Attach "this actual newNode" to the end of the list (first)
            (*last).next= ActualNode;      //changing pointers of structures (the intern(inside) pointer of the previos structure will point to this new one on this loop)
            last= ActualNode;              //changing pointers of structures (and the pointer outside this system of structures will point always to the actual strcuture  -->--> jus in the previous line "last" was the precious structure, but in this new line, no more)
        }
    }

    return head;        
}


//Showing POlinomials (function3)
void printingPolinomial(polinomial* head){
    polinomial* current1= head;                  //it's better term it as "current" then "actual"

    while(current1!= nullptr){
        cout << (*current1).coefficient << "x^" << (*current1).degree;

        //analyzing whether this pointer structure has a structure pointer pointing to something or "nullptr" or not (if not that means that there is no more --> I'm in the last one, so i don't have to put a "+")
        if( (*current1).next!= nullptr){
            cout << " + ";
        }
        current1= (*current1).next;
    }

    cout << "\n";
    return;
}


//Deleting hype variables
void deleteList(polinomial* head){
    while(head!= nullptr){
        polinomial* current2= head;
        head= (*head).next;             //going in the structure inside the currentSTRUCTURE (of this loop)

        delete current2;
    }

    return;
}

//function5


//function6




//main
//
//
//
int main(){
    int N;
    cout << "Provide the number of polinomials:: ";
    cin >> N;
    //the DOUBLE pointer is pretty necessary to create an array od Structure pointers
    polinomial** POINpolinonial= new polinomial*[N];      //this ARRAYpointer  --> points --> to an array of Actual Structures, not Structures pointers

    cout << "\n";
    //(function2)
    for(int i=0; i<N; i++){
        cout << "\n\n";
        int tempDegree;
        cout << i+1 << "___ Provide the degree of the polinomial:: ";
        cin >> tempDegree;
        POINpolinonial[i]= filling(tempDegree);

        cout << "\n\n";
    }


    //RESULTSSSSSSSSSSSSSS-------------
    //showing polinomials
    for(int i=0; i<N; i++){
        cout << i+1 << "___ Polinomial:: ";
        printingPolinomial(POINpolinonial[i]);
    }


    //showing degress (NOW I CAN with the sintax i was trying before)
    cout << "\n";
    for(int i=0; i<N; i++){
        cout << i+1 << "___ Polinomial degree:: ";
        cout << POINpolinonial[i][0].degree;

        cout << "\n";
    }

    //function1


    //function2


    //function3


    //function4


    //function5


    //function6



    //Deleting
    for(int i=0; i<N; i++){
        deleteList(POINpolinonial[i]);
    }


    delete[] POINpolinonial;
    


    cout << "\n\n-------------END\n";
    return 0;
}