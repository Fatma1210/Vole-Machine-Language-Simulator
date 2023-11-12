#include <iostream>
#include <map>
using namespace std ;
#ifndef VOLEMACHINELANGUAGESIMULATOR_REGISTER_H
#define VOLEMACHINELANGUAGESIMULATOR_REGISTER_H
    class Register {
    private:
        static int counter ;
        map < long , long > Register_Container ;
    public:
        Register() ;
        Register(long address , long value) ;
        void Set_Value (long value) ;
        long Get_Value() ;
    };


#endif //VOLEMACHINELANGUAGESIMULATOR_REGISTER_H
