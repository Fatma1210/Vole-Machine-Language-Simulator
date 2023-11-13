#include <iostream>
#include "Memory.h"
using namespace std ;

Memory::Memory(int size) : data(size, 0) {}

Memory::int read(int address){
  if (address >= 0 && address < data.size()) {
      return data[address];
  } else {
      cerr << "Memory read error: Invalid address " << address << endl;
      return 0;
  }
}
Memory::void write (int address, int value) {
  if (address >= 0 && address < data.size()) {
      data[address] = value;
  } else {
      cerr << "Memory write error: Invalid address " << address << endl;
  }
}