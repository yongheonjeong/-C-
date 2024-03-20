#include <iostream>
using namespace std;

//singleLinkedList
class Node {
public:
	string name = "";
	Node* next;
	Node() {  next = nullptr; }
	Node* getNext() { return next; }
	virtual void show() {}

};

 
class GraphicEditor {
	Node* head, * tail;
	int size;
public:
	GraphicEditor() { head = tail = nullptr; size = 0; }
	~GraphicEditor();
	void add(Node* p);
	void remove(int index);
	bool isEmpty() { return head == nullptr && tail == nullptr;  }
	void print();
};

 
void GraphicEditor::add(Node* p) {
	if (isEmpty()) {
		head = p;
		tail = p;
		p->next = nullptr;
		size++;
	}
	else if (tail != nullptr) {
		tail->next = p;
		tail = tail->next;
		tail->next = nullptr;
		size++;
	}

 
}

 
void GraphicEditor::remove(int index) {
	if (isEmpty()) {
		cout << "err : empty list" << endl;
		return;
	}

	if (index > size - 1) {
		cout << "can't delete" << endl;
		return;
	}

	Node* tmp = head;
	for (int i = 0; i < index && tmp != nullptr; i++) {
		tmp = tmp->getNext();
	}


	if (tmp == head && tmp->getNext() == nullptr) { // empty 
		delete tmp;
		head = tail = nullptr;
		size--;
	}
	else if (tmp == head && tmp->getNext() != nullptr) { // head
		head = tmp->getNext();
		delete tmp;
		size--;
	}
	else {
		Node* prev = head; 
		if (tmp == tail) { //tail
			for (; prev != tmp; prev = prev->getNext());
			delete tail;
			tail = prev;
			tmp = nullptr;
			size--;
		}
		else if(tmp != tail && tmp !=nullptr) //middle
		{ 
			for (; prev != tmp; prev = prev->getNext());
			prev->next = tail->next;
			delete tmp;
			tmp = nullptr;
			size--;
		}
 
	}
	
}
 
void GraphicEditor::print() {
	Node* tmp = head;
	int size = 0;
	for (; tmp != nullptr; tmp = tmp->getNext()) {
		cout << size++ << " : ";
			tmp->show();
	}
}

 
GraphicEditor::~GraphicEditor() {
	Node* tmp = head;
	for (; tmp != nullptr;) {
		Node* target = tmp;
		tmp = tmp->getNext();
		delete target;
		target = nullptr;
	}
}

class Line  : public Node{
public:
	Line() { name = "Line"; }
	virtual void show() override {
		
		cout << name << endl;
	}
};


class Circle : public Node {
public:
	Circle() { name = "Circle"; }
	virtual void show() override{
		cout << name << endl;
	}
};


class Rect : public Node {
public:
	Rect() { name = "Rect"; }
	virtual void show() override{
		cout << name << endl;
	}
};

int main() {
	
	GraphicEditor ged;
	cout << "그래픽 에디터 입니다." << endl;
	int choice;
	
	while (true) {
		cout << "삽입:1 ,삭제:2, 모두보기:3, 종료:4 >>";
		cin >> choice;

		switch (choice) {
		case 1:
			cout << "선:1, 원:2, 사각형:3 >>";
			cin >> choice;
			if (choice == 1) {
				ged.add(new Line());
			}
			else if (choice == 2) {
				ged.add(new Circle());
			}
			else if (choice == 3) {
				ged.add(new Rect());
			}
			else
				continue;
			break;
		case 2:
			cout << "삭제 하고자 하는 도형의 인덱스 >>";
			cin >> choice;
			ged.remove(choice-1);
			break;

		case 3:
			ged.print();
			break;
		}

		if (choice == 4) break;
	}

}