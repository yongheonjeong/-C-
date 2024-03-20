#include <iostream>
#include <map>
using namespace std;

int main() {
	string name="";
	int score = 0;
	int choice = 0;

	map<string, int> highMap;

	cout << "**** 점수관리 프로그램 HIGH SCORE 을 시작합니다. *****" << endl;
	
	while (true) {
		cout << "입력1, 조회:2, 종료:3 >> ";
		cin >> choice;

		switch (choice) {
		case 1:
			cout << "이름과 점수 >>";
			cin >> name;
			cin.ignore(1);
			cin >> score;
			cin.ignore(1);
			highMap.insert(make_pair(name, score));
			break;
		
		case 2:
			cout << "이름>>";
			cin >> name;
			cin.ignore(1); 
			if (highMap.find(name) == highMap.end()) {
				cout << "없음" << endl;
			}
			else {
				cout << name << " 의 점수는 " << highMap[name] << endl;
			}
			break;

		case 3:
			cout << "프로그램을 종료합니다..";
			return 0;
		 
		}

	}
}