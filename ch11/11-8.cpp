#include <iostream>
#include <string>
using namespace std;
 
class Circle {
	string name;
	int radius;
public:
	Circle(int radius = 1, string name = "") {
		this->radius = radius;
		this->name = name;
	}
	friend istream& operator>>(istream& cin, Circle& c);
	friend ostream& operator<<(ostream& cout, Circle c);
	
};

istream& operator>>(istream& cin, Circle& c) {
	cout << "반지름 >> ";
	cin >> c.radius;
	cin.ignore(1);
	cout << "이름 >> ";
	getline(cin, c.name);
	return cin;
}

ostream& operator<<(ostream& cout, Circle c) {
	cout << "(반지름" << c.radius << "인 " << c.name << ")";
	return cout;
}

int main() {
	 
	Circle d, w;
	cin >> d >> w;
	cout << d << w << endl;
}
