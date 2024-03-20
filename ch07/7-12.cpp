#include <iostream>
using namespace std;

class SortedArray{
	int size;
	int* p;
	void sort();

public:
	SortedArray();
	SortedArray(SortedArray& src);
	SortedArray(int p[], int size);
	~SortedArray();
	SortedArray operator + (SortedArray& op2);
	SortedArray& operator = (const SortedArray& op2);
	void show();

};
SortedArray::~SortedArray() {
	delete[] p;
}


void SortedArray::sort() {
	int tmp = 0;
	for (int i = 0; i < size; i++) {
		for (int j = i + 1; j < size; j++) {
			if (p[i] > p[j]) {
				tmp = p[i];
				p[i] = p[j];
				p[j] = tmp;
			}
		}
	}
}

SortedArray::SortedArray() {
	p = NULL;
	size = 0;
}

SortedArray::SortedArray(int p[], int size) {
	this->p = new int[size];
	this->size = size;

	for (int i = 0; i < size; i++) {
		this->p[i] = p[i];
	}
	sort();
}


SortedArray SortedArray::operator + (SortedArray& op2) {
	SortedArray tmp;
	SortedArray& obj = *this;

	tmp.size = obj.size + op2.size;
	tmp.p = new int[tmp.size];

	for (int i = 0; i < obj.size; i++) {
		tmp.p[i] = obj.p[i];
	}

	for (int i = 0; i < op2.size; i++) {
		tmp.p[obj.size + i] = op2.p[i];
	}
	tmp.sort();

	return tmp;
}


SortedArray& SortedArray::operator = (const SortedArray& op2) {
	SortedArray& obj = *this;

	obj.size = op2.size;
	obj.p = new int[obj.size];
	for (int i = 0; i < obj.size; i++) {
		obj.p[i] = op2.p[i];
	}

	return obj;
}


SortedArray::SortedArray(SortedArray& src) { 
	size = src.size;
	p = new int[src.size];
	for (int i = 0; i < src.size; i++) {
		p[i] = src.p[i];
	}
}

void SortedArray::show() {
	cout << "배열 출력 : ";
	for (int i = 0; i < size; i++) {
		cout << p[i] << ' ';
	}cout << endl;
}

int main() {

	int n[] = { 2,20,6 };
	int m[] = { 10,7,8,30 };
	SortedArray a(n, 3), b(m, 4), c;

	c = a + b;

	a.show();
	b.show();
	c.show();

}