#include <iostream>
using namespace std ;
#include "Register.h"
int Register :: counter = 0 ;
Register :: Register() {
    Register_Container[0] = 0 ;
}
Register ::Register(long address, long value) {
    Register_Container[address] = value ;
}
void Register :: Set_Value(long value) {
  Register_Container[counter] = value ;
}
long Register :: Get_Value() {
    return Register_Container[counter] ;
}
