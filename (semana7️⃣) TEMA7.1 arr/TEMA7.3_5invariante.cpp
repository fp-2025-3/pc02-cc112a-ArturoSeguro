#include <iostream>
#include <fstream>
#include <cstring>
using namespace std;


//---A.0
class time{
    private:
        int hours;
        int minutes;
    public:
        time(int h, int m);
        void setHours(int h);
        void setMinutes(int m);
};


//main
//
int main(){
    //

    

    //
    cout << "\n\n-------------END\n";
    return 0;
}


//---B.0
time:: time(int h, int m){
    setHours(h);
    setMinutes(m);
}
void time:: setHours(int h){
    if(h<0 || h>23){
        this->hours= 0;
        cout << "Hora invalida. Se ha configurado en 0.\n";
    }else{
        this->hours= h;
    }
}
void time:: setMinutes(int m){
    if(m<0 || m>59){
        this->minutes= 0;
        cout << "Minuto invalida. Se ha configurado en 0.\n";
    }else{
        this->minutes= m;
    }
}