#include <iostream>
#include <fstream>
#include <cstring>
using namespace std;

//---A.0
class robotJoint{
    private:
        double angle;
        double temperature;
        bool isEmergencyHalted;
    public:
        //0
        robotJoint(double a, double t);
        //1
        void setAngle(double a);
        void setTemperature(double t);
};


//main
//
int main(){
    //
    robotJoint r1(55, 80);
    r1.setAngle(90);
    r1.setAngle(181);
    r1.setAngle(10);
    //
    r1.setTemperature(10);
    r1.setTemperature(0);
    r1.setTemperature(-1);
    r1.setTemperature(90);
    //
    r1.setAngle(90);


    //
    cout << "\n\n-------------END\n";
    return 0;
}


//---B.0
//0
robotJoint:: robotJoint(double a, double t){
    this->setAngle(a);
    this->setTemperature(t);
}
//1
void robotJoint:: setAngle(double a){
    if(a<-90 || a>180){
        cout << "El angulo colocado no es valido. Se puso en 0.\n";
        this->angle= 0;
    }else{
        if(isEmergencyHalted){
            cout << "Esta prohibido modificar el angulo mientras la temperatura sea MAYOR A 85.\n";
        }else{
            this->angle= a;
        }
    }
}
void robotJoint:: setTemperature(double t){
    if(t<20){
        cout << "La temperatura colocado no es valido. Se puso en 25.\n";
        this->temperature= 0;
    }else if(t>85){
        this->temperature= t;
        this->isEmergencyHalted= true;
    }else{
        this->temperature= t;
    }
}