#include <iostream>
#include <ctime>
#include <cstdlib>

//función1
//
void Pburbuja(int* Parr, int tam){
    for(int i=0; i<tam-1; i++){
        for(int j=0; j<tam-1-i; j++){
            int l= *(Parr+j);
            int r= *(Parr+j+1);
            if(l< r){
                *(Parr+j)= r;
                *(Parr+j+1)= l;
            }
        }
    }
}



//main
//
int main(){
    int arr[7]= {7,1,6,2,5,3,4};
    int* Parr= arr;                 // arr= &arr[0]

    


    return 0;
}