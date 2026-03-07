#include <iostream>
using namespace std;

//function1
struct product{
    int price;
    int code;
    
    product* next;
};

//function2


//function3



//function4



//function5



//function6







//main
//
int main(){
    //1. I create a pointer that is prepared to point a variable of the type i created
    product* head= nullptr;

    for(int i=0; i<2; i++){
        //2. creating an other pointer prepared to point my variable that i create
        product* newOne= new product; //->variable in "heap" --> (if i miss the pointer direction i miss the variable)

        //filling newOne
        cout << "Provide code:: ";
        cin >> (*newOne).code;
        cout << "Provide price:: ";
        cin >> (*newOne).price;

        //i filled the last element of newOne with "head= nullptr"
        (*newOne).next= head;   //into this actual "newOne" i'm introducing the "head of the row (better analogy)"

        //we replace what was on "head" (the first time, nothing) with the Actual "newOne"
        head= newOne;   //and as i already saved the direction of "head" i can change it with others --> here i put the "newOne" --> to introduce it in the next loop
    }
    //in each loop i put in "product* next" the previous newOne with its own values




    //3. Showing the products
    product* TEMPhead= head;
    while(TEMPhead!= nullptr){  //i know that the first loop has stored in "(*TEMPhead).next" a nullptr, because of that i know that this will print everything until the first loop [it is supossed that I'm currently at the last one before start in this loop]
        cout << (*TEMPhead).code << "\t" << (*TEMPhead).price;
        TEMPhead= (*TEMPhead).next;
        cout << "\n";
    }





    //4. Deleting variables in HEAP
    while(head!= nullptr){
        product* TEMPhead2= head;
        head= (*TEMPhead2).next;

        delete TEMPhead2;
    }

    //function1



    //function2



    //function3



    //function4



    //function5



    //function6

    

    //
    cout << "\n\n-------------END\n";
    return 0;
}