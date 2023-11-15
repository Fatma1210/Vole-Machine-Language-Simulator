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
        M.write(counter, convert(v[0]+v[1]));
        counter++;
        M.write(counter, convert(v[2]));
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
    long val = R.Get_Value(address_of_XY) ;
    R.Set_Value(address_of_R , val) ;
}
void  Machine :: Move(long address_of_R , long address_of_S){
    long val = R.Get_Value(address_of_R) ;
    R.Set_Value(address_of_S , val) ;
 //   Reg.Remove_Register(address_of_R) ;
}
void Machine :: JUMP(long address_of_R , long address_of_XY ) {
    long value_Of_R0 = R.Get_Value(0);
    long value_of_R = R.Get_Value(address_of_R);
    if (value_of_R == value_Of_R0) {
        M.read( address_of_XY);
    }
}
void Machine :: operations(long Instruction , long Register_address , long XY) {
    switch (Instruction) {
        case 1:{
            Load(Register_address , XY) ;
        }
        case 2:{
            R.Set_Value(Register_address,XY);
            break;
        }
        case 3:{
            long l = R.Get_Value(Register_address);
            M.write(XY,l);
            break;
        }
        case 4 : {
            long s = XY/16;
            long t = XY-(s*16);
            Move(s , t) ;
            break;
        }
        case 11:{
            JUMP(Register_address, XY);
        }
        case 12:{
            break;
        }
    }
}

