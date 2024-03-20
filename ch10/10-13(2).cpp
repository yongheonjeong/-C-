#include <iostream>
#include <string>
#include <map>
using namespace std;

// more safe program

int main() {
	string line = "";
	string name="";
	
	int score = 0;
	int fIndex = 0;
	
	int choice = 0;

	map<string, int> highMap;

	cout << "**** 점수관리 프로그램 HIGH SCORE 을 시작합니다. *****" << endl;
	
	while (true) {
		cout << "입력1, 조회:2, 종료:3 >> ";
		cin >> choice;
		cin.ignore(1);

		switch (choice) {
		case 1:
			cout << "이름과 점수 >>";
			getline(cin, line,'\n');
			fIndex = line.find(" ");
			name = line.substr(0, fIndex);
			score = stoi(line.substr(fIndex));

			highMap.insert(make_pair(name, score));
			break;
		
		case 2:
			cout << "이름>>";
			getline(cin, name);
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