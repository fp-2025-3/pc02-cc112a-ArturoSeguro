#include <iostream>
#include <fstream>
#include <cstring>
using namespace std;

//---0.A
class myClass{
    private:
        int value;
    public:
        //0.
        myClass(int value);
        //2.
        void printValue();
};


//---main
//
int main(){
    //
    myClass objeto1(50);
    objeto1.printValue();
    

    //
    cout << "\n\n-------------END\n";
    return 0;
}


//---0.B
//0.
myClass:: myClass(int vaIntro){
    this->value= vaIntro;
}
//2.
void myClass:: printValue(){
    cout << "Value: " << this->value << "\n";
}