#include <iostream>
#include <string>
#include <fstream>
using namespace std;

int main() {
	string file1;
	string file2;
 
	cout << "���� ����1 �� ��θ�� �Բ� ��Ÿ������ >> ";
	getline(cin, file1);
	ifstream fin1(file1);
	if (!fin1) {
		cout << "open fail";
		return 0;
	}
	
	cout << "���� ����2 �� ��θ�� �Բ� ��Ÿ������ >> ";
	getline(cin, file2);
	ifstream fin2(file2);
	if (!fin2) {
		cout << "open fail";
		return 0;
	}

	fin1.seekg(0, ios::end);
	fin2.seekg(0, ios::end);
	if (fin1.tellg() != fin2.tellg()) {
		cout << "�� ������ ���� �ʽ��ϴ�." << endl;
		return 0;
	}
	else {
		fin1.seekg(0, ios::beg);
		fin2.seekg(0, ios::beg);

		while (true) {
			fin1.get();
			fin2.get();
			if (fin1.tellg() != fin2.tellg()) {
				cout << "�� ������ ���� ����" << endl;
				return 0;
			}
            if(fin1.eof()){
                break;
            }
		}
		cout << "�� ������ ���� ���� �Դϴ�." << endl;
	}
    fin1.close();
    fin2.close();
}