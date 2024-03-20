/******************************************************************************

 �̹� ������Ʈ�� �ǽ����� 8-5�� 8-6�� �����ϵ� �̵��� ������ ���ο� ���α׷��� �ۼ��ϴ� ���̴�.
 ���ð� ť�� �����ϴ� ����� ũ�� �迭�� �̿��ϴ� ��İ� linked list�� �����ϴ� �ΰ��� ����� �ִ�.
 ���� �ǽ����� 8-5�� 8-6�� BaseArray�� ��ӹ޾� MyQueue�� MyStack�� �����Ͽ���.
 BaseArray�� �������� �迭 �޸𸮸� �Ҵ� ���� �� ������ �迭���ҿ� ���� �ְų� ��� Ŭ������.
 �̹� ���������� �迭�� ������ �̿��ϴ� BaseArray ���
 double linked list�� BaseList Ŭ������ �����ϰ�,
 �� BaseList�� ����Ͽ� MyQueue�� MyStack�� �����ϵ��� �Ѵ�.
 ��, MyQueue�� MyStack�� �迭�� �̿��ϴ� ���� �ƴ϶�
 double linked list�� BaseList�� �̿��Ͽ� ������ ���� ���̴�.

 ���α׷��� ��ü �������� �������� �Ʒ��� ����.

******************************************************************************/
#include <iostream>
using namespace std;
// ������ value�� �����ϰ� �ִ� double linked ����Ʈ ���
class Node {
private:
    // ��� ����� private���� �����Ͽ� �ܺο��� ���� ���ϰ� �ϰ�,
    // BaseList������ Node�� ��� ����� ������ �� �ְ� Ŭ���� ��ü�� friend�� ����
   
    Node* prev;
    Node* next;
    int value;

    Node(int value) { prev = next = nullptr; this->value = value; }
    int getValue() { return value; } 
    void add(Node* n) { next = n; n->prev = this; }     // ���� ��� ������ n ��带 �߰��Ѵ�.
    Node* remove() { Node* n = next; delete this; return n; }  // ���� ��带 �����ϰ� �� ����� next ��带 �����Ѵ�.

    friend class BaseList;
};

 
class BaseList {
private:
    Node* head;    
    Node* tail;    
protected:
    int size;     // ���� ����Ʈ ���� �ִ� ���(������)�� ����

    BaseList() { head = tail = nullptr; size = 0; }  
 
    ~BaseList() { for (Node* n = head; n != nullptr; n = n->remove()); }

    void add_rear(int value);
    int remove_rear();
    int remove_front();
};

// ���ο� ���(value ���� �����ϰ� ����)�� ������ �� ����Ʈ�� �� �������� �߰�
void BaseList::add_rear(int value) {
    /*
    Node�� ������ ���� n�� �����ϰ�
        ���ο� Node�� �������� ����(value �� ����)�Ͽ� n�� ����;
    ���� tail�� nullptr�� �ƴϸ� // NULL ��ſ� nullptr ���
        tail�� ����Լ� add(n)ȣ���Ͽ� ����Ʈ�� �� ���� n�� �߰�
        ����Ʈ ���� ���� �߰� �Ǿ����Ƿ� tail�� n���� ����
        �ƴ� ��� // ����Ʈ�� ��尡 ���� ��� n�� ù ��尡 ��
        tail�� head ���� n���� ����
        BaseList�� ������ ������ 1 ����
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

// ����Ʈ�� ������ ��带 ������ �� �� ��忡 ����� value�� ����
int BaseList::remove_rear() {
    /*
    ����Ʈ�� ��� ������ 0�̸� - 1 ���� // list empty error
        ������ ���� val�� �����ϰ�,
        tail ��忡 ����� value ���� ���� val�� ����
        // ������ ����� �� ��带 ������ ���� prev ���� �� �ʱ�ȭ
        Node* ���� prev�� �����ϰ� tail�� prev ��� ���� ���� prev�� ����
        tail ��带 �޸𸮿� �ݳ���
        ����Ʈ�� ��� ������ 1 ����
        ���� prev�� nullptr�� �ƴϸ� // ������ ����� �� ��尡 ������ ���
        ���� prev�� ����Ʈ�ϴ� ����� next ����� nullptr�� ������
        tail�� ���� prev�� ���� // ���� ������ ���� ������ ����� �� ��尡 ��
        �ƴѰ�� ��, ���� prev�� nullptr�̸� // �� �̻� ���� ��尡 ���� ���
        tail�� head ���� nullptr�� ����
        val ���� ����
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

// ����Ʈ�� �� ó�� ��带 ������ �� �� ��忡 ����� value�� ����
int BaseList::remove_front() {

    /*
    ����Ʈ�� ��� ������ 0�̸� - 1 ���� // list empty error
        ������ ���� val�� �����ϰ�,
        head ��忡 ����� value ���� ���� val�� ����
        // ������ ����� �� ��带 ������ ���� next ���� �� �ʱ�ȭ
        Node* ���� next�� �����ϰ� head�� next ��� ���� ���� next�� ����
        head ��带 �޸𸮿� �ݳ���
        ����Ʈ�� ��� ������ 1 ����
        ���� next�� nullptr�� �ƴϸ� // ������ ����� �� ��尡 ������ ���
        ���� next�� ����Ʈ�ϴ� ����� prev ����� nullptr�� ������
        head�� ���� next�� ���� // ���� �� ù ���� ������ ����� �� ��尡 ��
        �ƴѰ�� ��, ���� next�� nullptr�̸� // �� �̻� ���� ��尡 ���� ���
        tail�� head ���� nullptr�� ����
        val ���� ����
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

class MyQueue : public BaseList {  	// BaseList�� ��ӹް� �����ؾ� ��
public:
    void enqueue(int value) {  // ť�� �� ���� ��� �߰� �� value ����
        add_rear(value);
    }
    int dequeue() { // ť�� �� ���� ��� �����ϰ� ����� value �� ����
        return remove_front();
    }
    int length() { return size; }
    static void test(); // static �Լ���
};

void MyQueue::test() {
    MyQueue mQ;
    int size;
    cout << "ť�� ������ ������ ����? ";
    cin >> size;
    cout << "ť�� enqueue()�� ���ҵ� : ";
    for (int i = 0; i < size; i++) {
        mQ.enqueue(i * 100); // ť�� ����
        cout << i * 100 << ' ';
    }
    cout << endl << "ť�� ũ��: " << mQ.length() << endl;
    cout << "ť���� dequeue()�� ��� ���ҵ� : ";
    while (mQ.length() != 0)
        cout << mQ.dequeue() << ' '; // ť���� �����Ͽ� ���
    cout << endl << "ť�� ���� ũ�� : " << mQ.length() << endl;
}

class MyStack : public BaseList {
public:
    void push(int value) { // ������ �� ���� ��� �߰� �� value ����
        add_rear(value);
    }
    int pop() { // ������ �� ���� ��� �����ϰ� ����� value �� ����
        return remove_rear();
    }
    int length() { return size; }
    static void test(); // static �Լ���
};

void MyStack::test() {
    MyStack mStack;
    int size;
    cout << "���ÿ� ������ ������ ����? ";
    cin >> size;
    cout << "���ÿ� push()�� ���ҵ� : ";
    for (int i = 0; i < size; i++) {
        mStack.push(i); // ���ÿ� Ǫ��
        cout << i << ' ';
    }
    cout << endl << "���� ũ��: " << mStack.length() << endl;
    cout << "���ÿ��� pop()�� ��� ���ҵ� : ";
    while (mStack.length() != 0)
        cout << mStack.pop() << ' '; // ���ÿ��� ��
    cout << endl << "������ ���� ũ�� : " << mStack.length() << endl;
}

int main()
{
    MyQueue::test();
    MyStack::test();
    return 0;
}

/******************************************************************************
  ���α׷� ���� ���
 ******************************************************************************
ť�� ������ ������ ����? 10
ť�� enqueue()�� ���ҵ� : 0 100 200 300 400 500 600 700 800 900
ť�� ũ��: 10
ť���� dequeue()�� ��� ���ҵ� : 0 100 200 300 400 500 600 700 800 900
ť�� ���� ũ�� : 0
���ÿ� ������ ������ ����? 10
���ÿ� push()�� ���ҵ� : 0 1 2 3 4 5 6 7 8 9
���� ũ��: 10
���ÿ��� pop()�� ��� ���ҵ� : 9 8 7 6 5 4 3 2 1 0
������ ���� ũ�� : 0
******************************************************************************/