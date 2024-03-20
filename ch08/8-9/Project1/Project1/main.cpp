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
    schedule[0].setTime("07시");
    schedule[1].setTime("12시");
    schedule[2].setTime("17시");
}

Schedule* AirlineBook::getSchedule(){
    return schedule;
}

 


int main() {

    cout << "***** 한성항공에 오신것을 환영합니다 *****" << endl << endl;
    int select = 0;
    int time = 0;
    string name;
    int noSeat;

    AirlineBook airlinebook;

    while (true) {
        cout << "예약:1, 취소:2, 보기:3, 끝내기:4>>";
        cin >> select;

        if (select == 1) {
        
            cout << "07시:1, 12시:2, 17시:3>>";
            cin >> time;

            if (!(time >= 1 && time <= 3)) {
                cout << "올바른 시간대를 선택해주세요 (1~3)" << endl;
                continue;
            }

            cout << airlinebook.getSchedule()[time - 1].getTime() << '\t';
            for (int i = 0; i < 8; i++)
            {
                cout << airlinebook.getSchedule()[time - 1].getSeat()[i].getSeats() << '\t';
            }
            cout << endl;

            cout << "좌석 번호>>";
            cin >> noSeat;
            if (!(noSeat >= 1 && noSeat <= 8)) {
                cout << "좌석번호는 1~8번입니다." << endl;
                continue;
            }

            cout << "이름 입력>>";
            cin >> name;

            airlinebook.getSchedule()[time - 1].getSeat()[noSeat - 1].setSeats(name);

        }

        if (select == 2) {

            cout << "07시:1, 12시:2, 17시:3>>";
            cin >> time;
            if (!(time >= 1 && time <= 3)) {
                cout << "올바른 시간대를 선택해주세요 (1~3)" << endl;
                    continue;
            }
                  
            cout << airlinebook.getSchedule()[time - 1].getTime() << '\t';
            for (int i = 0; i < 8; i++)
            {
                cout << airlinebook.getSchedule()[time - 1].getSeat()[i].getSeats() << '\t';
            }
            cout << endl;

            cout << "좌석 번호>>";
            cin >> noSeat;
            if (!(noSeat >= 1 && noSeat <= 8)) {
                cout << "좌석번호는 1~8번입니다." << endl;
                continue;
            }

            cout << "이름 입력>>";
            cin >> name;

            if (airlinebook.getSchedule()[time - 1].getSeat()[noSeat - 1].getSeats() == name) {
                airlinebook.getSchedule()[time - 1].getSeat()[noSeat - 1].setSeats("---");
                cout << name << "씨의 예약이 취소 처리되었습니다." << endl;
            }

            else
                cout << "해당 좌석에 이름과 일치하지 않습니다." << endl;
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
            cout << "예약 시스템을 종료합니다." << endl;
            break;
        }

        else
            continue;
     
    }

    return 0;
}
