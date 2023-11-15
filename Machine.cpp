#include <bits/stdc++.h>
#include "Machine.h"
#include "Register.h"
#include "Memory.h"
using namespace std;

Machine :: Machine() {
    counter = -1;
}
void Machine :: open(string file_name) {
    ifstream f(file_name);
    if (!f.is_open()) {
        cout << "Error opening file: " << file_name << endl;
        return;
    }
    string line;
    vector <string> v(3);
    while(getline(f,line)){
        counter++;
        int indx = 0;
        int c = 0;
        for(int i = 0; i < line.length(); i++){
            if(line[i] == ' '){
                v[c] = line.substr(indx,i-indx);
                indx = i+1;
                c++;
            }
            else if(i == line.length()-1){
                v[c] = line.substr(indx,i-indx+1);
            }
        }
        M.lode(counter, v[0]+v[1]);
        counter++;
        M.lode(counter, v[2]);
        op = convert(v[0]);
        r = convert(v[1]);
        m = convert(v[2]);
        operations(op,r, m);
    }
    f.close();

}

long Machine :: convert(string s) {
    return stol(s, nullptr, 16);
}
long Machine:: get_counter(){
    return counter;
}
void Machine :: Load(long address_of_R , long address_of_XY ){
    Register Reg ;
    long val = Reg.Get_Value(address_of_XY) ;
    Reg.Set_Value(address_of_R , val) ;
}
void  Machine :: Move(long address_of_R , long address_of_S){
    Register Reg ;
    long val = Reg.Get_Value(address_of_R) ;
    Reg.Set_Value(address_of_S , val) ;
    Reg.Remove_Register(address_of_R) ;
}
void Machine :: JUMP(long address_of_R , long address_of_XY ) {
    Register Reg;
    Memory Mem;
    long value_Of_R0 = Reg.Get_Value(0);
    long value_of_R = Reg.Get_Value(address_of_R);
    if (value_of_R == value_Of_R0) {
        Mem.Get_Instruction(long address_of_XY);
    }
}
void Machine :: operations(long Instruction , long Register_address , long XY) {
    switch (Instruction) {
        case 1:{
            ::Load(Register_address , XY) ;
        }
        case 2:{
            long converted=convert(y);
            R.load(x,converted);
            break;
        }
        case 3:{
            long l = R.get(x);
            string s = to_string(l);
            M.lode(y,s);
            break;
        }
        case 4 : {
            Machine::Move(Register_address , XY) ;
        }
        case 12:{
            break;
        }
    }
}

