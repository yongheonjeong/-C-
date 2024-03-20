#include <iostream>
#include <vector> 
using namespace std;
 

class Shape {
protected:
	virtual void draw() = 0;
public:
	void paint();
};

void Shape::paint() {
	draw();
}

class Circle : public Shape{
protected:
	virtual void draw() {
		cout << "Circle" << endl;
	}
};


class Rect : public Shape {
protected:
	virtual void draw() {
		cout << "Rect" << endl;
	}
};


class Line : public Shape {
protected:
	virtual void draw() {
		cout << "Line" << endl;
	}
};

int main() { 

	int choice = 0;
	vector<Shape*> v;
	Shape* p;
	cout << "�׷��� ������ �Դϴ�." << endl;

	while (true) {
		cout << "����:1, ����:2, ��κ���:3, ����:4 >> ";
		cin >> choice;
		cin.ignore(1);

		switch (choice) {
		case 1:
			cout << "��:1, ��:2, �簢��:3 >> ";
			cin >> choice;
			cin.ignore(1);

			switch(choice) {
				case 1:
					p = new Line();
					v.push_back(p);
					break;
				case 2:
					p = new Circle();
					v.push_back(p);
					break;
				case 3:
					p = new Rect();
					v.push_back(p);
					break;
			}
			break;

		case 2:
			cout << "�����ϰ��� �ϴ� ������ �ε���  >> ";
			cin >> choice;
			cin.ignore(1);
			if (choice >= v.size() || choice < 0) {
				cout << "�ε��� ������ �ش����� �ʽ��ϴ�" << endl;
				break;
			}
			else {
				v.erase(v.begin() + choice);
			}
			break;

		case 3:
			for (int i = 0; i < v.size(); i++) {
				cout << i << " : ";
				v[i]->paint();
			}
			break;
		case 4:
			return 0;
		}
	}
		 
}