#include <iostream>
using namespace std;

class AbstractStack {

public:
    virtual bool push(int n) = 0;
    virtual bool pop(int& n) = 0;
    virtual int size() = 0;

};

class IntStack : public AbstractStack {
private:
    int tos = -1;
    int* p;
    int size_arr;
public:

    IntStack(int size) {
        this->size_arr = size;
        p = new int[size];
    }

    virtual bool push(int n) {
        if (tos >= size_arr) {
            cout << "Buffer OverRun";
            return false;
        }
        else {
            p[++tos] = n;
            return true;
        }
    }

    virtual bool pop(int& n) {
        if (tos <= -1) {
            return false;
        }
        else {
            n = p[tos--];
            return true;
        }
    }

    virtual int size() {
        return size_arr;
    }

    ~IntStack() {
        delete[] p;
    }

};

int main() {
    IntStack isk(5);
    int popE = 0;

    for (int i = 0; i < isk.size(); i++) {
        int num;
        cout << "push " << i+1 << " : ";
        cin >> num;
        if (isk.push(num)) {
            cout << num << "을 push 했습니다." << endl;
        }
        else {
            cout << "버퍼 오런이 발생해 push에 실패했습니다." << endl;
        }
    }
    cout << "Inserted elements : ";
    while (isk.pop(popE)) {
        cout << popE << " ";
    } cout << endl;

}