#ifndef ROBOT_H
#define ROBOT_H
#include <cstring>
#include <string>
using namespace std;


//---0
class robot{
    public:
        //a1, a2
        robot();
        virtual ~robot();
        //b1
        virtual void ejecutarTarea();
};


//---1
class futbolista: public robot{
    public:
        //a1, a2
        futbolista();
        ~futbolista();
        //b1
        void ejecutarTarea() override;
};


//---2
class analista: public robot{
    public:
        //a1, a2
        analista();
        ~analista();
        //b1
        void ejecutarTarea() override;
};


//
#endif 