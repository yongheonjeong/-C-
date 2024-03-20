//������ MyStack�� Ǫ��(push)������ << �����ڸ�, ��(pop)�� ���� >> �����ڸ�, ��� �ִ� �������� �˱� ���� !�����ڸ� �ۼ��϶�(��� ������ �Լ��� ����)
//���� ���ÿ� �ٸ� ������ ������ �����ϴ� = �����ڸ� �ۼ��϶�. (��� ������ �Լ��� ����)


//�� ������ ������ ���� ���ο� ������ ����� �����ϴ� + ������ �Լ��� �ۼ��϶�.
//  ��, �� ������ �Լ��� �ܺ� �Լ��� �����ϰ� MyStack ���ο� friend �Լ��� �����϶�
// �Ʒ� �ڵ�� �ּ��� �����ϰ� �ʿ��� ������ �ڵ���.



/* ���α׷� ��ü ����
��� ���� include
class MyIntStack { } ����
MyIntStack�� �� ��� �Լ� ���� �ڵ�
�ܺ� + ������ �Լ� ���� �ڵ�
main() �Լ�

/*
/* ���

Mystack a: pop :50
Mystack b: pop :60
50 10 9 8 7 10
����Ϸ��� �ƹ� Ű�� �����ʽÿ� . . .


*/

#include <iostream>
using namespace std;

class MyStack {
	int* p; // ���� �޸𸮷� ����� ������
	int size; // ������ �ִ� ũ��
	int tos; // ������ ž�� ����Ű�� �ε���
public:
	MyStack();  // �⺻������ 
	MyStack(int size); //�Ű����� �ִ� ������
	MyStack(const MyStack& src); // ���� ������
	~MyStack(); //�Ҹ���
	bool push(int n); // ���� n�� ���ÿ� Ǫ���Ѵ�.
	bool pop(int& n); // ������ ž�� �ִ� ���� n�� ���Ѵ�.
	void print();

	// *���� �߰��ؾ� �� ������ �Լ�
	MyStack& operator << (int n); // << ������,push: ��ü �ڽ��� �����ڸ� ����
	MyStack& operator >> (int& n); // >> ������, pop: ��ü �ڽ��� �����ڸ� ����
	bool operator ! (); // !������, ������ ������� true ����
	MyStack& operator = (const MyStack& s);// ���� ���ÿ� s ������ ������ ����

	//�ܺ� + ������ �Լ��� friend�� ����, ���� �迭�� s �迭 �߰�, ���� 7-12 ���� 
	friend MyStack operator + (const MyStack& s1, const MyStack& s2);
};

MyStack::MyStack() {
	size = 10;
	tos = -1;
	p = new int[size];
}

MyStack::MyStack(int size) {
	this->size = size;
	tos = -1;
	p = new int[size];
}

MyStack::MyStack(const MyStack& src) {
	size = src.size;
	tos = src.tos;
	p = new int[src.size];
	for (int i = 0; i < size; i++)
		this->p[i] = src.p[i];
}

MyStack::~MyStack() {
	if (p)
		delete[] p;
}

bool MyStack::push(int n) {
	if (tos == (size - 1)) {
		return false;
	}
	else {
		++tos;
		p[tos] = n;
		return true;
	}
}

bool MyStack::pop(int& n) {
	if (tos == (-1)) {
		return false;
	}
	else {
		n = p[tos];
		--tos;
		return true;
	}
}

MyStack& MyStack::operator << (int n) {

	// push 
	//��� �Լ��� push()�� ȣ���Ͽ� n�� ���ÿ� Ǫ����
	// ������ ���� �� ��� �ƹ� �͵� ���� ����; push() ���� ���� ����
	// �� ��ü�� ���� ����,���� 7-14 ����
	if (this->tos == (size - 1)) {
		exit(1);
	}
	else {
		this->push(n);

		return *this;
	}
}

MyStack& MyStack::operator >> (int& n) {
	// pop
	//��� �Լ��� pop()�� ȣ����(���ÿ��� ���� ���� n�� ����)
	// ������ �� ��� �ƹ� �͵� ���� ����; pop() ���� ���� ����
	//�� ��ü�� ���� ���� // ���� 7-14 ����

	if (this->tos == (-1)) {
		exit(1);
	}
	else {
		this->pop(n);
		return *this;
	}
}

bool MyStack::operator ! () {
	//������ ��� ������ true ���� // ������ �� ���� üũ�� pop() �Լ� ����
	//�׷��� ������ false ����

	if (tos == -1) {
		return true;
	}
	else {
		return false;
	}
}

MyStack& MyStack::operator = (const MyStack& s) {
	//������ p�� nullptr�� �ƴϸ�, // ~MyStack() ����
	// p�� ����Ű�� �޸� ��ȯ
	// ���� ������ �Լ��� ������ �״�� �����ؼ� ���� ��
	// ���� ������ MyStack(const MyStack& s) ����
	//�� ��ü�� ���� ���� // ���� 7-14 ����

	if(s.p){
		size = s.size;
		tos = s.tos;
		p = new int[s.size];
		for (int i = 0; i < size; i++)
			this->p[i] = s.p[i];
		return *this;
	}

}

MyStack operator + (const MyStack& s1, const MyStack& s2) {
	// �ܺ� + ������ �Լ�
	//MyStack Ÿ���� �������� tmp(��ģ_ũ��) ����; // ���� 7-12 ����
	// �̶� ��ģ_ũ��� s1 ���� ũ��� s2 ���� ũ�⸦ ��ģ ũ�⿩�� ��
	//s1�� tos�� s2�� tos ����� ��ģ ���� tmp�� tos ����� ����
	//for���� �̿��Ͽ�, for���� ���� 4-6 ����
	//s1�� p[i]�� tmp ��ü�� p[i]�� ����
	// �̶� ��� ���Ұ� �ƴ϶� s1 ���� ž�� ���� ��ŭ�� ����
	//for���� �̿��Ͽ� // ��� ���Ұ� �ƴ϶� s2 ���� ž�� ���� ��ŭ�� ����
	//s2 ��ü�� p[i]�� tmp ��ü�� p[i+?]�� ����
	// �̶� s1�� p[i]�� ��� �����ϰ� �� ���ʿ�,
	// �� tmp�� p[i+?]�� s2�� p[i]�� �����ؾ� ��
	//tmp�� ������ // ���� 7-12 ����

	MyStack tmp;
	tmp.size = s1.size + s2.size;
	tmp.tos = s1.tos + s2.tos+1;

	for (int i = 0; i < s1.tos+1; i++) {
		tmp.p[i] = s1.p[i];
	}

	for (int i = 0; i < s2.tos+1; i++) {
		tmp.p[i + s1.tos+1] = s2.p[i];
	}

	return tmp;

}

void MyStack::print() {
	for (int i = 0; i < tos+1; i++) {
		cout << p[i] << ' ';
	}cout << endl;
}

int main() {
	MyStack a(10);

	cout << "Enter number1: Mystack push :";
	int k;
	cin >> k; //a.push(10)
	cout << "Mystack a: push 10:" << a.push(k) << endl;

	cout << "Enter number2: Mystack push :";
	cin >> k; //a.push(50)
	cout << "Mystack a: push 50:" << a.push(k) << endl;

	MyStack b = a; // ���� ����
	b.push(60);


	int n;
	a.pop(n); // ���� a ��
	cout << "Mystack a: pop :" << n << endl;
	b.pop(n); // ���� b��
	cout << "Mystack b: pop :" << n << endl;

	a << 7 << 8 << 9; // 7,8,9 �� ������� Ǫ��

	a.print();
	b.print();

	MyStack c;
	c = a + b; // a, b �� ���� ������ ��ģ �� ����� c�� ����
	while (true) {
		if (!c) break; // ������ ������� ���� ����
		c >> n;
		cout << n << ' ';
	}
	cout << endl;
}