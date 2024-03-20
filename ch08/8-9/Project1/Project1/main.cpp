#include <iostream>
#include "Schedule.h"
#include "Seat.h"

using namespace std;
 
class AirlineBook {
    Schedule* schedule;
public:    
    AirlineBook();
    Schedule* getSchedule();
};

AirlineBook::AirlineBook() {
    schedule = new Schedule[3];
    schedule[0].setTime("07��");
    schedule[1].setTime("12��");
    schedule[2].setTime("17��");
}

Schedule* AirlineBook::getSchedule(){
    return schedule;
}

 


int main() {

    cout << "***** �Ѽ��װ��� ���Ű��� ȯ���մϴ� *****" << endl << endl;
    int select = 0;
    int time = 0;
    string name;
    int noSeat;

    AirlineBook airlinebook;

    while (true) {
        cout << "����:1, ���:2, ����:3, ������:4>>";
        cin >> select;

        if (select == 1) {
        
            cout << "07��:1, 12��:2, 17��:3>>";
            cin >> time;

            if (!(time >= 1 && time <= 3)) {
                cout << "�ùٸ� �ð��븦 �������ּ��� (1~3)" << endl;
                continue;
            }

            cout << airlinebook.getSchedule()[time - 1].getTime() << '\t';
            for (int i = 0; i < 8; i++)
            {
                cout << airlinebook.getSchedule()[time - 1].getSeat()[i].getSeats() << '\t';
            }
            cout << endl;

            cout << "�¼� ��ȣ>>";
            cin >> noSeat;
            if (!(noSeat >= 1 && noSeat <= 8)) {
                cout << "�¼���ȣ�� 1~8���Դϴ�." << endl;
                continue;
            }

            cout << "�̸� �Է�>>";
            cin >> name;

            airlinebook.getSchedule()[time - 1].getSeat()[noSeat - 1].setSeats(name);

        }

        if (select == 2) {

            cout << "07��:1, 12��:2, 17��:3>>";
            cin >> time;
            if (!(time >= 1 && time <= 3)) {
                cout << "�ùٸ� �ð��븦 �������ּ��� (1~3)" << endl;
                    continue;
            }
                  
            cout << airlinebook.getSchedule()[time - 1].getTime() << '\t';
            for (int i = 0; i < 8; i++)
            {
                cout << airlinebook.getSchedule()[time - 1].getSeat()[i].getSeats() << '\t';
            }
            cout << endl;

            cout << "�¼� ��ȣ>>";
            cin >> noSeat;
            if (!(noSeat >= 1 && noSeat <= 8)) {
                cout << "�¼���ȣ�� 1~8���Դϴ�." << endl;
                continue;
            }

            cout << "�̸� �Է�>>";
            cin >> name;

            if (airlinebook.getSchedule()[time - 1].getSeat()[noSeat - 1].getSeats() == name) {
                airlinebook.getSchedule()[time - 1].getSeat()[noSeat - 1].setSeats("---");
                cout << name << "���� ������ ��� ó���Ǿ����ϴ�." << endl;
            }

            else
                cout << "�ش� �¼��� �̸��� ��ġ���� �ʽ��ϴ�." << endl;
        }

        if (select == 3) {
            for (int t = 0; t < 3; t++) {
                cout << airlinebook.getSchedule()[t].getTime() << " : ";
                for (int s = 0; s < 8; s++)
                {
                    cout << airlinebook.getSchedule()[t].getSeat()[s].getSeats() << '\t';
                }
                cout << endl;
            }
            cout << endl;
        }

        if (select == 4) {
            cout << "���� �ý����� �����մϴ�." << endl;
            break;
        }

        else
            continue;
     
    }

    return 0;
}
