#include <iostream>
using namespace std;

//function1


//function2


//function3


//function4


//function5


//function6
int* getReversedArray(int* input, int size) {
    int reversed[100]; // Assumption: size < 100
    for (int i = 0; i < size; ++i) {
        reversed[i] = input[size - 1 - i];
    }
    return reversed; // <--- PROBLEM HERE
}




int main(){
    int nums[] = {1, 2, 3};
    int* res = getReversedArray(nums, 3);
    cout << res[0] << "\n"; 
    


    cout << "\n\n-------------END\n";
    return 0;
}