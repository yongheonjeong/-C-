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
		cout << "삽입:1, 삭제:2, 모두보기:3, 종료:4 >> ";
		cin >> choice;
		cin.ignore(1);

		switch (choice) {
		case 1:
			cout << "생성하고자 하는 원의 반지름과 이름은 >> ";
			getline(cin, line);
			fIndex = line.find(" ");
			radius = stoi(line.substr(0, fIndex));
			name = line.substr(fIndex + 1);
			cirv.push_back(Circle(radius, name));
			break;

		case 2:
			cout << "삭제하고자 하는 원의 이름은 >>";
			cin >> line;
			for (i = 0; i < cirv.size(); i++) {
				if (cirv[i].getName() == line) {
					isExist = true;
					cirv.erase(cirv.begin() + i );
				}
			}

			if (!isExist) {
				cout << name << " 원이 존재하지 않습니다." << endl;
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