#include <iostream>
#include <string>
using namespace std;

class MyException {
	int lineNo;
	string func, msg;
public:
	MyException(int n, string f, string m) {
		lineNo = n; func = f; msg = m;
	}
	void print() { cout << func << ":" << lineNo << ", " << msg << endl; }
};

class DivideByZeroException : public MyException {
public:
	DivideByZeroException(int lineNo, string func, string msg) : MyException(lineNo, func, msg) {

	}
};

class InvalidInputException : public MyException {
public:
	InvalidInputException(int lineNo, string func, string msg) : MyException(lineNo, func, msg) {

	}
};

 int main() throw(DivideByZeroException&,InvalidInputException&){
	 int x, y;
	 try {
		 cout << "�������� �մϴ�. �� ���� ���� ������ �Է��ϼ��� >> ";
		 cin >> x >> y;

		 if (x < 0 || y < 0)
			 throw InvalidInputException(33, "main()", "���� �Է� ���� �߻�");
		 if (y == 0)
			 throw DivideByZeroException(35, "main()", "0���� ������ ���� �߻�");
		 cout << (double)x / (double)y;
	 }
	 catch (DivideByZeroException& e) {
		 e.print();
	 }
	 catch (InvalidInputException& e) {
		 e.print();
	 }
	 
 
}