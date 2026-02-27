#include <iostream>
#include <fstream>
#include <cstring>
using namespace std;

//---000A
class circle{
    private:
    double radius;
    //0. funciones miembros
    public:
    double getRadius() const;
    double getArea() const;
    double getPerimeter() const;
    void setRadius(double value);
    //1. constructor
    circle(double radius);      //por parametro
    circle();                   //por predeterminado
    circle(const circle& circleReceptor);   //por copia
    //1. destructor
    ~circle();
};


//main
//
int main(){
    //


    //
    cout << "\n\n-------------END\n";
    return 0;
}


//---000B
double circle:: getRadius() const{
    return radius;
}
double circle:: getArea() const{
    return (3.1416)*(radius*radius);
}
double circle:: getPerimeter() const{
    return (2*3.1416)*(radius);
}
void circle:: setRadius(double value){
    radius= value;
}
//
circle:: circle(double rad)
: radius(rad){
}
circle:: circle()
: radius(1.0){
}
circle:: circle(const circle& cir)
: radius(cir.radius){
}
//
circle:: ~circle(){
}