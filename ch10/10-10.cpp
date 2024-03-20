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

    cout << "*****"  << "������ ���� ���߱� ������ �����մϴ�. " << "*****" << endl;

    while (choice != 3) {
        cout << "���� �Է�: 1, ����: 2, ����: 3 >> ";
        cin >> choice;

        if (choice == 1) {

            cout << "����" << v.size() << "���� ���� �ԷµǾ� �ֽ��ϴ�." << endl;
            cout << "����� ������ �Է��ϼ���(no no �̸� �Է� ��)" << endl;

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
                    cout << v[num].getNation() << "�� ������?";
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