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
void Machine :: operations(long n, long x, long y) {
    switch (n) {
        case 1:{
            long l = convert(M.get(y));
            R.load(x,l);
            break;
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
    }
}

