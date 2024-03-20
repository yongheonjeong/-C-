#include <iostream>
using namespace std;

class MyStack {
	int data[100];
	int tos;
public:
	MyStack() { tos = -1;  }
	void push(int n) throw(char*);
	int pop() throw(char*);
};

void MyStack::push(int n) throw(const char*){
	if (tos == 99)
		throw "Stack Full";
	tos++;
	data[tos] = n;
}

int MyStack::pop() throw(const char*){
	if (tos == -1)
		throw "Stack Empty";
	int rData = data[tos--];
	return rData;
}

int main() {

	MyStack intStack;
	try {
		intStack.push(100);
		intStack.push(200);
		cout << intStack.pop() << endl;
		cout << intStack.pop() << endl;
		cout << intStack.pop() << endl;

	}
	catch (const char* s) {
		cout << "예외 발생:" << s << endl;
	}
 
}