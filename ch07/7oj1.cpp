//기존의 MyStack에 푸시(push)용으로 << 연산자를, 팝(pop)을 위해 >> 연산자를, 비어 있는 스택인지 알기 위해 !연산자를 작성하라(멤버 연산자 함수로 구현)
//기존 스택에 다른 스택을 내용을 대입하는 = 연산자를 작성하라. (멤버 연산자 함수로 구현)


//두 스택의 내용을 합쳐 새로운 스택을 만들어 리턴하는 + 연산자 함수를 작성하라.
//  단, 이 연산자 함수를 외부 함수로 구현하고 MyStack 내부에 friend 함수로 선언하라
// 아래 코드와 주석을 이해하고 필요한 내용을 코딩함.



/* 프로그램 전체 구성
헤드 파일 include
class MyIntStack { } 선언
MyIntStack의 각 멤버 함수 구현 코드
외부 + 연산자 함수 구현 코드
main() 함수

/*
/* 결과

Mystack a: pop :50
Mystack b: pop :60
50 10 9 8 7 10
계속하려면 아무 키나 누르십시오 . . .


*/

#include <iostream>
using namespace std;

class MyStack {
	int* p; // 스택 메모리로 사용할 포인터
	int size; // 스택의 최대 크기
	int tos; // 스택의 탑을 가리키는 인덱스
public:
	MyStack();  // 기본생성자 
	MyStack(int size); //매개변수 있는 생성자
	MyStack(const MyStack& src); // 복사 생성자
	~MyStack(); //소멸자
	bool push(int n); // 정수 n을 스택에 푸시한다.
	bool pop(int& n); // 스택의 탑에 있는 값을 n에 팝한다.
	void print();

	// *새로 추가해야 할 연산자 함수
	MyStack& operator << (int n); // << 연산자,push: 객체 자신의 참조자를 리턴
	MyStack& operator >> (int& n); // >> 연산자, pop: 객체 자신의 참조자를 리턴
	bool operator ! (); // !연산자, 스택이 비었으면 true 리턴
	MyStack& operator = (const MyStack& s);// 현재 스택에 s 스택의 내용을 대입

	//외부 + 연산자 함수를 friend로 선언, 현재 배열에 s 배열 추가, 예제 7-12 참고 
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
	//멤버 함수인 push()를 호출하여 n을 스택에 푸시함
	// 스택이 가득 찬 경우 아무 것도 하지 않음; push() 리턴 값도 무시
	// 이 객체의 참조 리턴,예제 7-14 참조
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
	//멤버 함수인 pop()를 호출함(스택에서 팝한 값을 n에 저장)
	// 스택이 빈 경우 아무 것도 하지 않음; pop() 리턴 값도 무시
	//이 객체의 참조 리턴 // 예제 7-14 참조

	if (this->tos == (-1)) {
		exit(1);
	}
	else {
		this->pop(n);
		return *this;
	}
}

bool MyStack::operator ! () {
	//스택이 비어 있으면 true 리턴 // 스택이 빈 상태 체크는 pop() 함수 참조
	//그렇지 않으면 false 리턴

	if (tos == -1) {
		return true;
	}
	else {
		return false;
	}
}

MyStack& MyStack::operator = (const MyStack& s) {
	//포인터 p가 nullptr이 아니면, // ~MyStack() 참조
	// p가 가리키는 메모리 반환
	// 복사 생성자 함수의 내용을 그대로 복사해서 넣을 것
	// 복사 생성자 MyStack(const MyStack& s) 참조
	//이 객체의 참조 리턴 // 예제 7-14 참조

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
	// 외부 + 연산자 함수
	//MyStack 타입의 지역변수 tmp(합친_크기) 선언; // 예제 7-12 참고
	// 이때 합친_크기는 s1 스택 크기와 s2 스택 크기를 합친 크기여야 함
	//s1의 tos와 s2의 tos 멤버를 합친 값을 tmp의 tos 멤버에 저장
	//for문을 이용하여, for문은 예제 4-6 참조
	//s1의 p[i]를 tmp 객체의 p[i]에 저장
	// 이때 모든 원소가 아니라 s1 스택 탑의 개수 만큼만 복사
	//for문을 이용하여 // 모든 원소가 아니라 s2 스택 탑의 개수 만큼만 복사
	//s2 객체의 p[i]를 tmp 객체의 p[i+?]에 저장
	// 이때 s1의 p[i]를 모두 복사하고 난 뒤쪽에,
	// 즉 tmp의 p[i+?]에 s2의 p[i]를 저장해야 함
	//tmp를 리턴함 // 예제 7-12 참고

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

	MyStack b = a; // 복사 생성
	b.push(60);


	int n;
	a.pop(n); // 스택 a 팝
	cout << "Mystack a: pop :" << n << endl;
	b.pop(n); // 스택 b팝
	cout << "Mystack b: pop :" << n << endl;

	a << 7 << 8 << 9; // 7,8,9 을 순서대로 푸시

	a.print();
	b.print();

	MyStack c;
	c = a + b; // a, b 두 스택 스택을 합친 후 결과를 c에 대입
	while (true) {
		if (!c) break; // 스택이 비었으면 빠져 나감
		c >> n;
		cout << n << ' ';
	}
	cout << endl;
}