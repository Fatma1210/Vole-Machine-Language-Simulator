#ifndef MEMORY_H
#define MEMORY_H
#include<iostream>
#include<vector>
using namespace std;
class Memory{
private:
    vector<long> data;

public:
    Memory: data(256, 0);
    long read(long address);
    void write(long address, long value);
};
#endif
