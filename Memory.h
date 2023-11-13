#ifndef MEMORY_H
#define MEMORY_H
#include<iostream>
#include<vector>
using namespace std;
class Memory{
private:
    vector<long> data;

public:
    Memory(int size) : data(size, 0);
    int read(long address);
    void write(long address, long value);
};
#endif
