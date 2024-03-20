#include <iostream>
using namespace std;

class BaseArray{
private:
    int capacity;
    int *mem;
protected:
    BaseArray(int capacity=100){
        this->capacity = capacity; 
        mem = new int[capacity];
    }
    ~BaseArray() { delete[] mem; }
    void put(int index, int val) { mem[index] = val; }
    int get(int index) { return mem[index]; }
    int getCapacity() { return capacity; }
};

class MyStack : public BaseArray{
    int tos = -1;
public:
    MyStack(int capacity) : BaseArray(capacity){     
    }
    void push(int val);
    int capacity();
    int length();
    int pop();
};

void MyStack::push(int val){
    if(tos>=getCapacity()){
        cout << "Buffer OverRun";
        exit(1);
    }else{
        put(++tos,val);
    }
}

 int MyStack::capacity(){
    return getCapacity();
 }

int MyStack::length(){
    if(tos<=-1){ 
        return 0;
    }else{
        return tos+1;
    }
}

int MyStack::pop(){
    if(tos<=-1){
        cout << "Access denied";
        exit(1);
    }else{
        int popElement = get(tos--);
        return popElement;
    }
}


int main(){
    MyStack mStack(100);
    int n;
    cout << "스택에 삽입할 5개의 정수를 입력하라 >> ";

    for(int i=0;i<5;i++){
        cin >> n;
        mStack.push(n);
    }

    cout << "스택 용량: " << mStack.capacity() << ", 스택크기:" << mStack.length() << endl;
    cout << "스택의 모든 원소를 팝하여 출력한다 >> ";

    while(mStack.length() != 0){
        cout << mStack.pop() << ' ';
    }

    cout << endl << "스택의 현재 크기 : " << mStack.length() << endl;
 }