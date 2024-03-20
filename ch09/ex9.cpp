#include <iostream>
using namespace std;

class Shape {
	Shape* next;
protected:
	virtual void draw() = 0;
public:
	Shape() { next = NULL; }
	virtual ~Shape() {}
	void paint();
	Shape* add(Shape* p);
	Shape* getNext() { return next; }
};

void Shape::paint() {
	draw();
}

 
Shape* Shape::add(Shape* p) {
	this->next = p;
	return p;
}


class Circle : public Shape {
protected:
	virtual void draw();
};

void Circle::draw() {
	cout << "Circle" << endl;
}


class Rect : public Shape {
protected:
	virtual void draw();
};

void Rect::draw() {
	cout << "Rectangle" << endl;
}


class Line : public Shape {
protected:
	virtual void draw();
};

void Line::draw() {
	cout << "Line" << endl;
}


int main() {
	Shape* tmp;
	Shape* head = NULL;
	Shape* tail;

	head = new Circle();
	tail = head;

	tail = tail->add(new Rect());
	tail = tail->add(new Circle());
	tail = tail->add(new Line());
	tail = tail->add(new Rect());

	tmp = head;
	while (tmp != NULL) {
		tmp->paint();
		tmp = tmp->getNext();
	}

	tmp = head;
	while (tmp != NULL) {
		Shape* next = tmp->getNext();
		delete tmp;
		tmp = next;
	}

}