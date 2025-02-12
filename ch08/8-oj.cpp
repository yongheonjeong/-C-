/******************************************************************************

 이번 프로젝트는 실습문제 8-5와 8-6를 참고하되 이들을 응용한 새로운 프로그램을 작성하는 것이다.
 스택과 큐를 구현하는 방식은 크게 배열을 이용하는 방식과 linked list로 구현하는 두가지 방식이 있다.
 기존 실습문제 8-5와 8-6은 BaseArray를 상속받아 MyQueue와 MyStack을 구현하였다.
 BaseArray는 동적으로 배열 메모리를 할당 받은 후 적절한 배열원소에 값을 넣거나 얻는 클래스다.
 이번 과제에서는 배열의 개념을 이용하는 BaseArray 대신
 double linked list인 BaseList 클래스를 구현하고,
 이 BaseList를 상속하여 MyQueue와 MyStack을 구현하도록 한다.
 즉, MyQueue와 MyStack을 배열을 이용하는 것이 아니라
 double linked list인 BaseList를 이용하여 구현해 보는 것이다.

 프로그램의 전체 구성도와 실행결과는 아래와 같다.

******************************************************************************/
#include <iostream>
using namespace std;
// 정수값 value를 저장하고 있는 double linked 리스트 노드
class Node {
private:
    // 모든 멤버를 private으로 선언하여 외부에서 접근 못하게 하고,
    // BaseList에서만 Node의 모든 멤버에 접근할 수 있게 클래스 전체를 friend로 선언
   
    Node* prev;
    Node* next;
    int value;

    Node(int value) { prev = next = nullptr; this->value = value; }
    int getValue() { return value; } 
    void add(Node* n) { next = n; n->prev = this; }     // 현재 노드 다음에 n 노드를 추가한다.
    Node* remove() { Node* n = next; delete this; return n; }  // 현재 노드를 삭제하고 이 노드의 next 노드를 리턴한다.

    friend class BaseList;
};

 
class BaseList {
private:
    Node* head;    
    Node* tail;    
protected:
    int size;     // 현재 리스트 내에 있는 노드(데이터)의 개수

    BaseList() { head = tail = nullptr; size = 0; }  
 
    ~BaseList() { for (Node* n = head; n != nullptr; n = n->remove()); }

    void add_rear(int value);
    int remove_rear();
    int remove_front();
};

// 새로운 노드(value 값을 저장하고 있음)를 생성한 후 리스트의 맨 마지막에 추가
void BaseList::add_rear(int value) {
    /*
    Node의 포인터 변수 n을 선언하고
        새로운 Node를 동적으로 생성(value 값 전달)하여 n에 저장;
    만약 tail이 nullptr이 아니면 // NULL 대신에 nullptr 사용
        tail의 멤버함수 add(n)호출하여 리스트의 맨 끝에 n을 추가
        리스트 끝에 새로 추가 되었으므로 tail을 n으로 설정
        아닌 경우 // 리스트에 노드가 없을 경우 n이 첫 노드가 됨
        tail과 head 값을 n으로 설정
        BaseList의 데이터 개수를 1 증가
      */
        Node* n = new Node(value);
        if (tail != nullptr) {
            tail->add(n);
            tail = n;
            size++; 
        }
        if (head == tail) {
            head = tail = n;
            size++;  
          }
    
}

// 리스트의 마지막 노드를 제거한 후 그 노드에 저장된 value를 리턴
int BaseList::remove_rear() {
    /*
    리스트의 노드 개수가 0이면 - 1 리턴 // list empty error
        정수형 변수 val을 선언하고,
        tail 노드에 저장된 value 값을 얻어와 val에 저장
        // 삭제할 노드의 앞 노드를 저장할 변수 prev 선언 및 초기화
        Node* 변수 prev를 선언하고 tail의 prev 멤버 값을 변수 prev에 저장
        tail 노드를 메모리에 반납함
        리스트의 노드 개수를 1 감소
        변수 prev가 nullptr이 아니면 // 삭제할 노드의 앞 노드가 존재할 경우
        변수 prev가 포인트하는 노드의 next 멤버를 nullptr로 설정함
        tail에 변수 prev을 설정 // 이제 마지막 노드는 삭제된 노드의 앞 노드가 됨
        아닌경우 즉, 변수 prev가 nullptr이면 // 더 이상 남은 노드가 없는 경우
        tail과 head 값을 nullptr로 설정
        val 값을 리턴
    */
    if (size == 0) {
        cout << "list empty error" << endl;
        return -1;
    }

    int val = tail->getValue();
    Node* prev = tail->prev;
    if (prev != nullptr) {
        prev->next = nullptr;
        delete tail;
        tail = prev;
        size--;
    }
     if(prev == nullptr){
        tail = head = nullptr;
        size--;  // size == 0  -- head, tail == nullprt
      }
 
     return val;
}

// 리스트의 맨 처음 노드를 제거한 후 그 노드에 저장된 value를 리턴
int BaseList::remove_front() {

    /*
    리스트의 노드 개수가 0이면 - 1 리턴 // list empty error
        정수형 변수 val을 선언하고,
        head 노드에 저장된 value 값을 얻어와 val에 저장
        // 삭제할 노드의 뒤 노드를 저장할 변수 next 선언 및 초기화
        Node* 변수 next를 선언하고 head의 next 멤버 값을 변수 next에 저장
        head 노드를 메모리에 반납함
        리스트의 노드 개수를 1 감소
        변수 next가 nullptr이 아니면 // 삭제할 노드의 뒤 노드가 존재할 경우
        변수 next가 포인트하는 노드의 prev 멤버를 nullptr로 설정함
        head에 변수 next를 설정 // 이제 맨 첫 노드는 삭제된 노드의 뒤 노드가 됨
        아닌경우 즉, 변수 next가 nullptr이면 // 더 이상 남은 노드가 없는 경우
        tail과 head 값을 nullptr로 설정
        val 값을 리턴
    */
    if (size == 0) {
        return -1;
    }

    int val = head->getValue();
    Node* next = head->next;
    if (next != nullptr) {
        next->prev = nullptr;
        delete head;
        head = next;
        size--;
   
    }

    else if(next == nullptr){
        tail = head = nullptr;
        size--;
  
    }

    return val;
}

class MyQueue : public BaseList {  	// BaseList를 상속받게 선언해야 함
public:
    void enqueue(int value) {  // 큐의 맨 끝에 노드 추가 후 value 저장
        add_rear(value);
    }
    int dequeue() { // 큐의 맨 앞의 노드 삭제하고 노드의 value 값 리턴
        return remove_front();
    }
    int length() { return size; }
    static void test(); // static 함수임
};

void MyQueue::test() {
    MyQueue mQ;
    int size;
    cout << "큐에 삽입할 정수의 개수? ";
    cin >> size;
    cout << "큐에 enqueue()된 원소들 : ";
    for (int i = 0; i < size; i++) {
        mQ.enqueue(i * 100); // 큐에 삽입
        cout << i * 100 << ' ';
    }
    cout << endl << "큐의 크기: " << mQ.length() << endl;
    cout << "큐에서 dequeue()된 모든 원소들 : ";
    while (mQ.length() != 0)
        cout << mQ.dequeue() << ' '; // 큐에서 제거하여 출력
    cout << endl << "큐의 현재 크기 : " << mQ.length() << endl;
}

class MyStack : public BaseList {
public:
    void push(int value) { // 스택의 맨 끝에 노드 추가 후 value 저장
        add_rear(value);
    }
    int pop() { // 스택의 맨 끝의 노드 삭제하고 노드의 value 값 리턴
        return remove_rear();
    }
    int length() { return size; }
    static void test(); // static 함수임
};

void MyStack::test() {
    MyStack mStack;
    int size;
    cout << "스택에 삽입할 정수의 개수? ";
    cin >> size;
    cout << "스택에 push()된 원소들 : ";
    for (int i = 0; i < size; i++) {
        mStack.push(i); // 스택에 푸시
        cout << i << ' ';
    }
    cout << endl << "스택 크기: " << mStack.length() << endl;
    cout << "스택에서 pop()된 모든 원소들 : ";
    while (mStack.length() != 0)
        cout << mStack.pop() << ' '; // 스택에서 팝
    cout << endl << "스택의 현재 크기 : " << mStack.length() << endl;
}

int main()
{
    MyQueue::test();
    MyStack::test();
    return 0;
}

/******************************************************************************
  프로그램 실행 결과
 ******************************************************************************
큐에 삽입할 정수의 개수? 10
큐에 enqueue()된 원소들 : 0 100 200 300 400 500 600 700 800 900
큐의 크기: 10
큐에서 dequeue()된 모든 원소들 : 0 100 200 300 400 500 600 700 800 900
큐의 현재 크기 : 0
스택에 삽입할 정수의 개수? 10
스택에 push()된 원소들 : 0 1 2 3 4 5 6 7 8 9
스택 크기: 10
스택에서 pop()된 모든 원소들 : 9 8 7 6 5 4 3 2 1 0
스택의 현재 크기 : 0
******************************************************************************/