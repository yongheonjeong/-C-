#include <iostream>
using namespace std;

class Matrix {
	int arr[4] = { 0 };
public:
	Matrix(int a=0, int b=0, int c=0, int d=0) {
		arr[0] = a;
		arr[1] = b;
		arr[2] = c;
		arr[3] = d;
	}

	friend Matrix& operator >> (Matrix& op,int arr[]);
	friend Matrix& operator << (Matrix& op,int arr[]);

	void show();
};



Matrix& operator >> (Matrix& op,int arr[]) {

	for (int i = 0; i < 4; i++) {
		arr[i] = op.arr[i];
	}

	return op;
}

Matrix&  operator << (Matrix& op,int arr[]) {
	for (int i = 0; i < 4; i++) {
		op.arr[i] = arr[i];
	}

	return op;
}

void Matrix::show() {

	cout << "Matrix = { ";
	for (int i = 0; i < 4; i++) {
		cout << arr[i] << ' ';
	}cout << "}";
	cout << endl;
}

int main() {

	Matrix a(4, 3, 2, 1), b;
	int x[4], y[4] = { 1,2,3,4 };
	a >> x;
	b << y;

	for (int i = 0; i < 4; i++) {
		cout << x[i] << ' ';
	}cout << endl;

	b.show();
 

}