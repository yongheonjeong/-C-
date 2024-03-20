#include <iostream>
using namespace std;

class Stack {
    int stkArr[10];
    int top = -1;
public:
    Stack& operator<<(int op);
    bool operator!();
    int operator>>(int& x);
};


int Stack::operator>>(int& x) {
    if (top <= -1) {
        cout << "Underflow" << endl;
        exit(1);
    }
    else {
        x = stkArr[top--];
    }

    return x;
}


Stack& Stack::operator<<(int op) {
    Stack& tmp = *this;
    top++;
    if (top >= 10) {
        cout << "Overflow" << endl;
        exit(1);
    }
    else {
        tmp.stkArr[top] = op;
        return tmp;
    }
}

bool Stack::operator!() {
    if (top == -1)
        return true;
    else
        return false;
}


int main() {
    Stack stack;
    stack << 3 << 5 << 10;

    while (true) {
        if (!stack) break;
        int x;
        stack >> x;
        cout << x << ' ';
    }
    cout << endl;
}