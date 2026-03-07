#include <iostream>
#include <fstream>
#include <cstring>
using namespace std;

//---000A
class circle{
    //
    private:
    double radius;
    //
    public:
    double getRadius() const;
    double getArea() const;
    double getPerimeter() const;
    void setRadius(double value);
};


//main
//
int main(){
    //
    circle circle1;
    circle1.setRadius (10.0);
    cout << "Radio: " << circle1.getRadius() << "\n";
    cout << "Area: " << circle1.getArea() << "\n";
    cout << "Perimeter: " << circle1.getPerimeter() << "\n";


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