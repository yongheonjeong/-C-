#include <iostream>
#include <string>
#include <vector>
#include <fstream>
using namespace std;


int main() {
    vector<string> v;
    string line;
    ifstream fin("c://windows//system.ini");
    int choice = 0;

    while (getline(fin, line)) {
        v.push_back(line);
    }

    cout << "C:\\windows\\system.ini ���� �б� �Ϸ�" << endl;
    cout << "���� ��ȣ�� �Է��ϼ���. 1���� ���� ���� �Է��ϸ� ����" << endl;
    while (true) {
        cout << " : ";
        cin >> choice;
        cin.ignore(1);

        if (choice < 1) {
            break;
        }
        else if (choice > v.size()) {
            continue;
        }

        cout << v[choice - 1] << endl;
    }

    fin.close();
}