#include <iostream>
using namespace std;

// 단일 링크 리스트

class Node {	// INT NODE
public:
	int value;
	Node* next; 
	Node(int value, Node* in);
};

Node::Node(int value = 0 , Node* in = nullptr) {
	this->value = value;
	this->next = in;
}

class SingleList {
	Node* head;
	Node* tail;
	// head와 tail은 값을 변수에 저장해서 바로 접근이 가능하지만
	// 그 중간 노드들은 tmp를 이용해 head값을 넣어서 loop문을 통해 접근한다 
public:
	SingleList() {
		head = tail = nullptr;
	}
	~SingleList();
	bool isEmpty() {
		return head == nullptr;
	}
	void addToHead(int);
	void addToTail(int);
	int* deleteFromHead();  
	int deleteFromTail();
	void deleteNode(int);
	bool isInList(int) const;
	void printList();
};

SingleList::~SingleList() {
	for (Node* p; !isEmpty(); ) {
		p = head->next;
		delete head;
		head = p;

		// p는 head->next로 위치시키고 head를 삭제
		// p가 위치하고 있는 곳을 다시 head로 지정 
	}
}

void SingleList::addToHead(int value) {
	head = new Node(value, head);
	if (tail == nullptr)
		tail = head;
}

void SingleList::addToTail(int value) {
	if (tail != nullptr) { // 만약 list가 비어있지 않다면
		tail->next = new Node(value);
		tail = tail->next;  // tail->NewNode   --->    preNode->tail 
	}
	else {
		head = tail = new Node(value);
		// head ->  new Node  <- tail 
	}

}

int* SingleList::deleteFromHead() {

	if(isEmpty()){ // empty list 
		return 0;
	}

	int* value = new int(head->value);
	Node* tmp = head; // delete tmp

	if (head == tail) { // if only one Node in the list
		head = tail = nullptr;
	}
	else {
		head = head->next;
	}

	delete tmp; 
	return value;
}

int SingleList::deleteFromTail() {
	int value = tail->value;
 
	if (head == tail) {
		delete tail;
		tail = head = nullptr;
	}
	else {
		Node* tmp;
		for (tmp = head; tmp->next != tail; tmp = tmp->next); // head,tail은 SingleList Class 
		delete tail;								//로 직접적인 접근이 가능하지만 그 중간 노드들은
		tail = tmp;									//head를 시작으로 하는 tmp로 loop문을 통해 접근한다
		tail->next = nullptr;
	}

	return value;
}

void SingleList::deleteNode(int value) {
	// 3가지 케이스 
	// 리스트에 노드가 하나있는 경우(target) // if only one Node in the list
	// 1) head  2) tail  3) middle 

	if (head != nullptr) {		// if not empty list 
		if (head == tail && head->value == value) { // if only one Node in the list
			delete head;
			head = tail = nullptr;
		}

		else if (value == head->value) { // head value == value, head != tail (more than one list) 
			Node* tmp = head;			 // 1) case 
			head = head->next;
			delete tmp;
		}
		else { 
			Node* prev, *tmp;  
			for (prev = head, tmp = head->next; // tmp는 value에 해당하는 node에 가고 prev는 tmp노드의 이전 노드에 위치, prev->tmp
				tmp != nullptr && tmp->value != value;
				prev = prev->next, tmp = tmp->next);

			if (tmp != nullptr && tmp->value == value) { 
				if (tmp == tail) // 2) case
					tail = prev;
				else // 3) case 
					prev->next = tmp->next;

				delete tmp;
			 }
		}
	}
}

bool SingleList::isInList(int value) const {
	Node* tmp;
	for (tmp = head; tmp != nullptr && tmp->value != value; tmp = tmp->next); // 없다면? tmp = nullptr
	return tmp != nullptr;
}

void SingleList::printList() {
	Node* tmp;
	for (tmp = head; tmp != nullptr; tmp = tmp->next) {
		cout << tmp->value << ' ';
	}cout << endl;
}

int main() {
	
	SingleList intsll;
 
	intsll.addToHead(10);
	intsll.addToTail(20);
	intsll.addToTail(30);
	cout <<boolalpha<< intsll.isInList(20) << endl;
	cout << boolalpha << intsll.isInList(40) << endl;
	intsll.printList();

	int* p = intsll.deleteFromHead();
	cout << "deleted element " << *p << endl; 
	intsll.printList();

}