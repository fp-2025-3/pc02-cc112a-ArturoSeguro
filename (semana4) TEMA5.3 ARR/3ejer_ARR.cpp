#include <iostream>
#include <ctime>
#include <cstdlib>
using namespace std;



// 
void imprimir(int (*M)[5]){
    cout << "Generated Matrix:: \n";
    for(int i=0; i<5; i++){
        for(int j=0; j<5; j++){
            cout << *(M[i]+j) << "\t";
        }
        cout << "\n";
    }

    cout << "\n";   //making space for next lines
    return;
}




//
int esFilaDominanteEstricta(int (*M)[5], int fila){
    bool foundStrictColumn= false;

    for(int j=0; j<5; j++){
        int myActualValue= *(M[fila]+j);        //this is what i did need --> not "*(M[fila]+j)"
        bool isStrictMax= true;                 //being strictly higher then other in the same column


        for(int i=0; i<5; i++){  
            if(i== fila){
                continue;       //if we are in the same "row" that we want to compare with, then we skip it
            }

            int otherValues= *(M[i]+j);

            if(myActualValue< otherValues){     //my value can´t be lower than other --> if it is I return "false"
                return false;
            }

            if(myActualValue== otherValues){    //this is an extra condition, but it still counts as a "true" return
                isStrictMax= false;
            }
        }

        if(isStrictMax){                //if we found at least one Value of my "fila(row)" stictly higher than others
            foundStrictColumn= true;
        }
    }

    return  foundStrictColumn;
}




//func3
bool esFilaFuertementeDominante(int (*M)[5], int fila){
    if(!esFilaDominanteEstricta(M, fila)){          //if this first functions isn't true, so this other one isn't too;  
        return false;                   
    }

    //we first calculate the sum of currect row "fila"
    int sumaFila= 0;
    for(int j=0; j<5; j++){
        sumaFila= sumaFila+ *(M[fila]+ j);
    }

    //comparing with sums of all othe rows
    for(int i=0; i<5; i++){
        if(i== fila){       //again, we don't need to compare the "fila" with itself, it would cause problems(errors)
            continue;
        }

        int sumOther= 0;
        for(int j=0; j<5; j++){
            sumOther= sumOther+ *(M[i]+ j);
        }

        //if or sum "fila" isn't strictly greater than any of the others, automaticly we return false
        if(sumaFila<= sumOther){
            return false;
        }
    }

    return true;
}







//main
//
//
//
int main(){
    srand(time(0));

    const int N= 5;
    int M[N][N];
    for(int i=0; i<5; i++){
        for(int j=0; j<5; j++){
            M[i][j]= (rand()%2)+1;
        }
    }
    //1--Mi MATRIZ
    imprimir(M);



    cout << "------------------------------------------------------------------\n";
    cout << "Fila\tDominante Estricta\tFuertemente Dominante\n";
    cout << "------------------------------------------------------------------\n";

    
    for(int i=0; i<N; i++){
        bool strict= esFilaDominanteEstricta(M, i);
        bool strong=  esFilaFuertementeDominante(M, i);
        

        cout << i << "\t";

        if(strict){
            cout << "YES";
        }else{
            cout << "NO";
        }


        cout << "\t\t\t";

        if(strong){
            cout << "YES";
        }else{
            cout << "NO";
        }

        cout << "\n";
    }

    //
    cout << "\n\n-------------END\n";
    return 0;
}