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
	cout << "그래픽 에디터 입니다." << endl;

	while (true) {
		cout << "삽입:1, 삭제:2, 모두보기:3, 종료:4 >> ";
		cin >> choice;
		cin.ignore(1);

		switch (choice) {
		case 1:
			cout << "선:1, 원:2, 사각형:3 >> ";
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
			cout << "삭제하고자 하는 도형의 인덱스  >> ";
			cin >> choice;
			cin.ignore(1);
			if (choice >= v.size() || choice < 0) {
				cout << "인덱스 범위에 해당하지 않습니다" << endl;
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