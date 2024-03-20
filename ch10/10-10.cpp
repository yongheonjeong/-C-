#include <iostream>
#include <cstdlib>
#include <ctime>
#include <vector>
using namespace std;

class Nation {
    string nation, capital;
public:
    Nation(string nation, string capital);
    string getNation();
    string getCapital();
 
};

Nation::Nation(string nation = "", string capital = "") {
    this->nation = nation;
    this->capital = capital;
}
string Nation::getNation() {
    return nation;
}
string Nation::getCapital() {
    return capital;
}
 



int main() {

    srand((unsigned)time(NULL));

    int choice = 0;
    string nation, capital;
    int size = 0;
    bool exist = false;

    vector<Nation> v;

    int num=0;

    cout << "*****"  << "나라의 수도 맞추기 게임을 시작합니다. " << "*****" << endl;

    while (choice != 3) {
        cout << "정보 입력: 1, 퀴즈: 2, 종료: 3 >> ";
        cin >> choice;

        if (choice == 1) {

            cout << "현재" << v.size() << "개의 나라가 입력되어 있습니다." << endl;
            cout << "나라와 수도를 입력하세요(no no 이면 입력 끝)" << endl;

            while (true) {
                exist = false;
                cout << v.size() + 1 << ">>";
                cin >> nation >> capital;

                if (nation == "no" && capital == "no")
                    break;

                    for (int i = 0; i < v.size(); i++) {
                        if (v[i].getNation() == nation && v[i].getCapital() == capital) {
                            cout << "already exist" << endl;
                            exist = true;
                        }
                    } 
                        if(!exist)
                            v.push_back(Nation(nation, capital));           
            }
        }

        if (choice == 2) {

                while (true) {
                    num = rand() % v.size();
                    cout << v[num].getNation() << "의 수도는?";
                    cin >> capital;
                    if (capital == "exit")
                        break;
                    else {
                        if (v[num].getCapital() == capital) {
                            cout << "Correct !!" << endl;
                        }
                        else {
                            cout << "NO !!" << endl;
                        }
                    }
                }
        }

    }

}