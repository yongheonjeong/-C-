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

    cout << "C:\\windows\\system.ini 파일 읽기 완료" << endl;
    cout << "라인 번호를 입력하세요. 1보다 작은 값을 입력하면 종료" << endl;
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