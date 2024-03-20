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

	cout << "**** �������� ���α׷� HIGH SCORE �� �����մϴ�. *****" << endl;
	
	while (true) {
		cout << "�Է�1, ��ȸ:2, ����:3 >> ";
		cin >> choice;
		cin.ignore(1);

		switch (choice) {
		case 1:
			cout << "�̸��� ���� >>";
			getline(cin, line,'\n');
			fIndex = line.find(" ");
			name = line.substr(0, fIndex);
			score = stoi(line.substr(fIndex));

			highMap.insert(make_pair(name, score));
			break;
		
		case 2:
			cout << "�̸�>>";
			getline(cin, name);
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