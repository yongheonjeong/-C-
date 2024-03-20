 #include <iostream>
using namespace std;

// el == element

template<class T>
class DLLNode {
public:
	T info;
	DLLNode* next, * prev;
	DLLNode() {
		next = prev = nullptr;
	}

	DLLNode(const T& el, DLLNode* n = nullptr, DLLNode* p = nullptr) {
		info = el;
		next = n;
		prev = p;
	}
 
};

template<class T>
class DoubleLinkedList {
protected:
	DLLNode<T>* head;
	DLLNode<T>* tail;

public:

	DoubleLinkedList() {
		head = tail = nullptr;
	}

	void addToDLLHead(const T& el);
	void addToDLLTail(const T& el);
	T* deleteFromDLLTail();
	T* deleteFromDLLHead();
	void deleteNode(const T& el);
	bool isEmpty() { return head == nullptr;  }
	bool isInList(const T& el);
	void printList();
};

template<class T>
void DoubleLinkedList<T>::addToDLLHead(const T& el) {
	if (head == nullptr) {
		head = new DLLNode<T>(el);
		tail = head;
	}
	else {
		head = new DLLNode<T>(el, head);
		head->next->prev = head;
	}
}

template<class T>
void DoubleLinkedList<T>::addToDLLTail(const T& el) {
	if (tail != nullptr) {
		tail = new DLLNode<T>(el, nullptr, tail);
		tail->prev->next = tail;
	}
	else {
		head = tail = new DLLNode<T>(el);
	}
}

template<class T>
T* DoubleLinkedList<T>::deleteFromDLLHead() {
	if (isEmpty()) {
		return 0;
	}
	
	T* el = new T(head->info);
	
	if (head != nullptr) {

		if (head == tail) {
			delete head;
			head = nullptr;
			tail = nullptr;
		}
		else {
			head = head->next;
			delete head->prev;
			head->prev = nullptr;
		}

	}

	return el;
}

template<class T>
T* DoubleLinkedList<T>::deleteFromDLLTail() {
	T* el = new T(tail->info);
	if (head == tail) {
		delete head;
		head = tail = nullptr;
	}
	else if (tail != nullptr) {

		tail = tail->prev;
		delete tail->next;

		tail->next = nullptr;
	}
	return el;
}

template<class T>
void DoubleLinkedList<T>::deleteNode(const T& el) {
	if (isEmpty())
		return;

	if (head == tail && head->info == el) {
		delete head;
		head = nullptr;
		tail = nullptr;
	}
	else if (head->info == el) {
		deleteFromDLLHead();
	}
	else {
		DLLNode<T>* tmp;
		for (tmp = head; tmp->info != el && tmp->next != nullptr; tmp = tmp->next);

		if (tmp != nullptr && tmp->info == el) {
			if (tmp == tail) deleteFromDLLTail();
			else {
				tmp->prev->next = tmp->next;
				tmp->next->prev = tmp->prev;
				delete tmp;
			}
		}
	}
}

template<class T>
bool DoubleLinkedList<T>::isInList(const T& el){
	DLLNode<T>* tmp = head;
	for (; tmp->info != el && tmp->next != nullptr; tmp = tmp->next);

	return tmp->info == el;
}

template<class T>
void DoubleLinkedList<T>::printList() {
	if (isEmpty()) return;
	
	DLLNode<T>* tmp = head;
	for (; tmp != nullptr; tmp = tmp->next)
		cout << tmp->info << ' ';
	cout << endl;
}

int main()
{
	DoubleLinkedList<int> intdll;
	intdll.addToDLLHead(10);
	intdll.addToDLLTail(20);
	intdll.addToDLLTail(30);
	cout << boolalpha << intdll.isInList(20) << endl;
	cout << boolalpha << intdll.isInList(40) << endl;
	intdll.printList();

	int* p = intdll.deleteFromDLLHead();
	cout << "deleted element " << *p << endl;
	intdll.printList();

	intdll.deleteNode(20);
	intdll.printList();
 
	cout << boolalpha << intdll.isEmpty() << endl;
	intdll.printList();
	
}