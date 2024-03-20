#include <iostream>
#include <map>
using namespace std;

int main() {
	string name="";
	int score = 0;
	int choice = 0;

	map<string, int> highMap;

	cout << "**** �������� ���α׷� HIGH SCORE �� �����մϴ�. *****" << endl;
	
	while (true) {
		cout << "�Է�1, ��ȸ:2, ����:3 >> ";
		cin >> choice;

		switch (choice) {
		case 1:
			cout << "�̸��� ���� >>";
			cin >> name;
			cin.ignore(1);
			cin >> score;
			cin.ignore(1);
			highMap.insert(make_pair(name, score));
			break;
		
		case 2:
			cout << "�̸�>>";
			cin >> name;
			cin.ignore(1); 
			if (highMap.find(name) == highMap.end()) {
				cout << "����" << endl;
			}
			else {
				cout << name << " �� ������ " << highMap[name] << endl;
			}
			break;

		case 3:
			cout << "���α׷��� �����մϴ�..";
			return 0;
		 
		}

	}
}