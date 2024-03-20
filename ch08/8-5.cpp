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

class MyQueue : public BaseArray{
    int index=0;
public:
    MyQueue(int capacity) : BaseArray(capacity){}
    void enqueue(int val);
    int dequeue();

    int capacity();
    int length();

};

void MyQueue::enqueue(int val){
    put(this->index++,val);
}

int MyQueue::dequeue(){
    int dequeue = get(0);

    for(int i=1;i<index;i++){
        put(i-1,get(i));
    }
    this->index--;
    
    return dequeue;
}

int MyQueue::capacity(){
    return getCapacity();
}

int MyQueue::length(){
    return index;
}

int main(){

    MyQueue mQ(100);
    int n;
    cout << "ť�� ������ 5���� ������ �Է��϶� >> ";
    for(int i=0;i<5;i++){
        cin >> n;
        mQ.enqueue(n);
    }
    cout << "ť�� �뷮: " << mQ.capacity() << ", ť�� ũ��:" << mQ.length() << endl;
    cout << "ť�� ���Ҹ� ������� �����Ͽ� ����Ѵ� >> ";

    while(mQ.length() != 0){
        cout << mQ.dequeue() << ' ';
    }

    cout << endl << "ť�� ���� ũ�� : " << mQ.length() << endl;
}

