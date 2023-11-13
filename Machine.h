#ifndef MACHINE_H
#define MACHINE_H
using namespace std;
#include "Register.h"
#include "Memory.h"

class Machine {
private:
    long counter;
    long op;
    long r;
    long m;

public:
    Register R;
    Memory M;
    Machine();
    void open(string);
    long convert(string);
    void operations(long, long, long );
    long get_counter();
};

#endif //MACHINE_H
