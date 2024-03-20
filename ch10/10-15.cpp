#include <iostream>
#include <vector> 
#include <string>
using namespace std;

class Circle {
	string name;
	int radius;
public:
	Circle(int radius, string name) {
		this->radius = radius;
		this->name = name;
	}
	double getArea() { return 3.14 * radius * radius; }
	string getName() { return name;  }
};

int main() {
	string line = "";
	string name="";
	int radius=0;
	int choice = 0;
	int fIndex = 0;
	int i = 0;

	bool isExist = false;
	vector<Circle> cirv; 

	while (true) {
		isExist = false;
		cout << "����:1, ����:2, ��κ���:3, ����:4 >> ";
		cin >> choice;
		cin.ignore(1);

		switch (choice) {
		case 1:
			cout << "�����ϰ��� �ϴ� ���� �������� �̸��� >> ";
			getline(cin, line);
			fIndex = line.find(" ");
			radius = stoi(line.substr(0, fIndex));
			name = line.substr(fIndex + 1);
			cirv.push_back(Circle(radius, name));
			break;

		case 2:
			cout << "�����ϰ��� �ϴ� ���� �̸��� >>";
			cin >> line;
			for (i = 0; i < cirv.size(); i++) {
				if (cirv[i].getName() == line) {
					isExist = true;
					cirv.erase(cirv.begin() + i );
				}
			}

			if (!isExist) {
				cout << name << " ���� �������� �ʽ��ϴ�." << endl;
			}
			break;

		case 3:
			for (i = 0; i < cirv.size();i++) {
				cout << cirv[i].getName() << endl;
			}
			break;

		case 4:
			return 0;
		}
	}
		 
}