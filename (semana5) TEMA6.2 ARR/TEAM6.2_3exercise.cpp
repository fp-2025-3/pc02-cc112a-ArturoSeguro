#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;


//function0
struct match{
    float TIEDm;
    float LOSTm;
    float WINm;
};

//function1
struct team{
    string name;    //check
    float TOTALp;   
    match encounters;    //check

    float performance;      //check
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
    //100 matchs per team
    srand(time(0));

    int N;
    cout << "Provide the quantity of teams (under 8):: ";
    cin >> N;
    cin.ignore();

    //
    team* POINteams= new team[N];

    //filling matchs of each team --&& asking name at the same time
    for(int i=0; i<N; i++){
        ////
        cout << "Provide the name of the team:: ";
        getline(cin, POINteams[i].name);


        ////
        POINteams[i].encounters.WINm= rand()%101;

        int actualWIN= POINteams[i].encounters.WINm;
        if(actualWIN< 100){
            POINteams[i].encounters.TIEDm= rand()%(101- actualWIN);
        }else{
            POINteams[i].encounters.TIEDm= 0;
            POINteams[i].encounters.LOSTm= 0;
        }

        int actualTIED= POINteams[i].encounters.TIEDm;
        if(actualWIN+actualTIED< 100){
            POINteams[i].encounters.LOSTm= rand()%(101- actualWIN-actualTIED);
        }else{
            POINteams[i].encounters.LOSTm= 0;
        }
    }

    //Calculating "TOTALp" --&& performance
    for(int i=0; i<N; i++){
        POINteams[i].TOTALp= POINteams[i].TOTALp+ (POINteams[i].encounters.WINm*3);
        POINteams[i].TOTALp= POINteams[i].TOTALp+ (POINteams[i].encounters.TIEDm*2);
    
        ////
        POINteams[i].performance= ((POINteams[i].TOTALp)/300)*100;
    }




    //printing
    cout << "TEAM\t\t\tWINm\t\tLOSTm\t\tTIEDm\t\tPOINTS\t\tPERFORMANCE\n";
    for(int i=0; i<N; i++){
        cout << "Country " << i << "\t\t" << POINteams[i].encounters.WINm << "\t\t" << POINteams[i].encounters.LOSTm << "\t\t" << POINteams[i].encounters.TIEDm << "\t\t" << POINteams[i].TOTALp << "\t\t" << POINteams[i].performance << "\n";
    }


    //Team withbest performance
    int bestS=-1;
    int INbestS=-1;
    for(int i=0; i<N; i++){
        if(bestS< POINteams[i].performance){
            bestS= POINteams[i].performance;
            INbestS= i;
        }
    }

    cout << "\nThe team with the best performance is:: Country " <<  INbestS;
    cout << "\nPerformance::  " << bestS;



    //function1


    //function2


    //function3


    //function4


    //function5


    //function6
    


    cout << "\n\n-------------END\n";
    return 0;
}