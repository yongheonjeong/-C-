#include <iostream>
using namespace std;

class BaseMemory{
    char *mem;
protected:
    BaseMemory(int size) { mem = new char[size]; }
    ~BaseMemory();
    void write(int index,char ch);
    char read(int index);
};

char BaseMemory::read(int index){
    return mem[index];
};

void BaseMemory::write(int index,char ch){
    mem[index] = ch;
}

BaseMemory::~BaseMemory(){
    delete[] mem;
}

class ROM : public BaseMemory{
    int ROM_SIZE;
public:
    ROM(int ROM_SIZE,char arr[],int size) : BaseMemory(ROM_SIZE){
        this->ROM_SIZE = ROM_SIZE;
        for(int i=0;i<size;i++){
            write(i,arr[i]);
        }
    }

    void write(int i,char ch);
    char read(int index);
};

void ROM::write(int i,char ch){
    BaseMemory::write(i,ch);
}

char ROM::read(int index){
    return BaseMemory::read(index);
}




class RAM : public BaseMemory{
    int RAM_SIZE;

public:
    RAM(int RAM_SIZE) : BaseMemory(RAM_SIZE){
        this->RAM_SIZE = RAM_SIZE;
    }

    void write(int i,char ch);
    char read(int index);
};


void RAM::write(int i,char ch){
    BaseMemory::write(i,ch);
}


char RAM::read(int index){
    return BaseMemory::read(index);
}



int main(){

char x[5] = {'h','e','l','l','o'};
ROM biosROM(1024*10,x,5);
RAM mainMemory(1024*1024);

for(int i=0; i<5; i++) mainMemory.write(i,biosROM.read(i));
for(int i=0; i<5; i++) cout << mainMemory.read(i);

}