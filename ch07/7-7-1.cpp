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

	Matrix& operator >> (int arr[]);
	Matrix& operator << (int arr[]);

	void show();
};



Matrix& Matrix::operator >> (int arr[]) {
	Matrix& tmp = *this;
	for (int i = 0; i < 4; i++) {
		arr[i] = tmp.arr[i];
	}

	return tmp;
}

Matrix& Matrix::operator << (int arr[]) {
	Matrix& tmp = *this;
	for (int i = 0; i < 4; i++) {
		tmp.arr[i] = arr[i];
	}

	return tmp;
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