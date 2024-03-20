#include <iostream>
using namespace std;

template<class T>
class array5 {
	T* data;
	int size;
public:
	array5(int size=5) {
		this->size = size;
		data = new T[size];
	}

	~array5() {
		delete data;
	}

	T* getData() { return data; }
	int getSize() { return size; };

	template<class S>
	void add(S& arr2) {
		int addSize = arr2.getSize() + this->size;
		T* copyData = this->data;

		this->data = new T[addSize];

		for (int i = 0; i < size; i++) {
			data[i] = (T)copyData[i];
		}

		for (int i = 0; i < arr2.getSize(); i++) {
			data[i + size] = (T)arr2.getData()[i];
		}
		this->size = addSize;
		delete copyData;

	}

	void print() {
		for (int i = 0; i < size; i++) {
			cout << data[i];
			cout << " ";
		} cout << endl;
	}

	T& operator[](int idx) {
		return data[idx];
	}
	template<class A>
	friend ostream& operator << (ostream& out,  A& a);
};

template<class A>
ostream& operator << (ostream& out, A& a) {
	for (int i = 0; i < a.getSize(); i++) {
		out << a.getData()[i];
		out << ' ';
	}  
	return out;
}

template <class T, class S>
void add(T& arr1, S& arr2) {
	arr1.add(arr2);
}

/*
template <class T, class S>
void add(T& a, S& b) {

}
*/

int main() { 
	array5<float> f5; // f5크기의 배열로 사용 가능한 class 구현
	array5<double> d5;
	for (int i = 0; i < 5; i++) {
		f5[i] = (float)i; // [] 연산자 구현...
		d5[i] = (double)i;
	}

	f5.print();
	d5.print();

	add(f5, d5); // f5에 d5 더함.. 이건 template 함수
	add(d5, f5);

  
 
	f5.print();
	d5.print();
 
 
	cout << f5 << endl; // << 연산자 구현
	 cout << d5 << endl; // << 연산자 구현..
}
