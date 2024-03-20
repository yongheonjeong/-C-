#include <iostream>
#include <string>
#include <map>
using namespace std;

int main() {
	map<string, string> WHOmap;

	string name="", password="";
	string line="";

	int fIndex = 0;
	int choice = 0;
	
	cout << "**** 암호관리 프로그램 WHO를 시작합니다 *****" << endl;
	while (true) {
		cout << "삽입:1, 검사:2, 종료:3 >> ";
		cin >> choice;
		cin.ignore(1);

		switch (choice) {
		case 1:
			cout << "이름 암호>>";
			getline(cin, line);
			fIndex = line.find(" ");
			name = line.substr(0, fIndex);	// name password, fIndex = 5
			password = line.substr(fIndex+1);  //    --> 6~ 

			WHOmap.insert(make_pair(name, password));
			break;

		case 2:
			cout << "이름? ";
			getline(cin, name);
			if (WHOmap.find(name) == WHOmap.end()) {
				cout << "없슴" << endl;
				continue;
			}
			else {
				while (true) {
					cout << "암호? ";
					getline(cin, password);
					if (WHOmap[name] == password) {
						cout << "통과!" << endl;
						break;
					}
					else {
						cout << "실패~~" << endl;
					}
				}
			}
			break;

		case 3:
			cout << "프로그램을 종료합니다.." << endl;
			return 0;

		}
	}
}