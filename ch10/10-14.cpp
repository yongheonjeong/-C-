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
	
	cout << "**** ��ȣ���� ���α׷� WHO�� �����մϴ� *****" << endl;
	while (true) {
		cout << "����:1, �˻�:2, ����:3 >> ";
		cin >> choice;
		cin.ignore(1);

		switch (choice) {
		case 1:
			cout << "�̸� ��ȣ>>";
			getline(cin, line);
			fIndex = line.find(" ");
			name = line.substr(0, fIndex);	// name password, fIndex = 5
			password = line.substr(fIndex+1);  //    --> 6~ 

			WHOmap.insert(make_pair(name, password));
			break;

		case 2:
			cout << "�̸�? ";
			getline(cin, name);
			if (WHOmap.find(name) == WHOmap.end()) {
				cout << "����" << endl;
				continue;
			}
			else {
				while (true) {
					cout << "��ȣ? ";
					getline(cin, password);
					if (WHOmap[name] == password) {
						cout << "���!" << endl;
						break;
					}
					else {
						cout << "����~~" << endl;
					}
				}
			}
			break;

		case 3:
			cout << "���α׷��� �����մϴ�.." << endl;
			return 0;

		}
	}
}