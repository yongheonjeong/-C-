#include <iostream>
using namespace std;

class Printer {
public:
    string model, manufacturer;
    int printedCount, availableCount;
    virtual void print(int pages) = 0;
    virtual void show() {
        cout << model << " ," << manufacturer << " ," << "남은 종이 " << availableCount << "장 ,";
    }
};

class InkJet : public Printer {
public:
    int availableInk;


    InkJet(string model = "Officejet V40", string manufacturer = "HP", int availableCount = 5, int availableInk = 10)
    {
        this->model = model;
        this->manufacturer = manufacturer;
        this->availableCount = availableCount;
        this->availableInk = availableInk;

        cout << " 레이저 : ";
        show();
        cout << "남은 토너 " << availableInk << endl;
    }

    virtual void print(int pages)
    {
        printedCount = pages;
        availableInk -= printedCount;
        availableCount -= printedCount;
        show();
        cout << "남은 잉크 " << availableInk << endl;
    }



};

class LaserPrinter : public Printer {
public:
    int availableToner;

    LaserPrinter(string model = "SCX-6x45", string manufacturer = "삼성전자", int availableCount = 3, int availableToner = 20)
    {
        this->model = model;
        this->manufacturer = manufacturer;
        this->availableCount = availableCount;
        this->availableToner = availableToner;

        cout << " 레이저 : ";
        show();
        cout << "남은 토너 " << availableToner << endl;

    }

    virtual void print(int pages) {

        printedCount = pages;
        availableToner -= printedCount;
        availableCount -= printedCount;
        show();
        cout << "남은 토너 " << availableToner << endl;
    }

 
};


int main() {
    cout << "현재 작동중인 2 대의 프린터는 아래와 같다" << endl;
    InkJet* InkJetPrinter = new InkJet;
    LaserPrinter* Laser = new LaserPrinter;

    int choice = 0;
    int printingCount = 0;
    char conti;
    while (true) {
        cout << "프린터(1:잉크젯, 2:레이저)와 매수 입력>>";
        cin >> choice >> printingCount;

        switch (choice) {
        case 1:
            if (InkJetPrinter->availableCount - printingCount >= 0 &&
                InkJetPrinter->availableInk - printingCount >= 0) {
                cout << "프린트 하였습니다." << endl;
                InkJetPrinter->print(printingCount);
                Laser->print(0);
            }
            else {
                cout << "용지가 부족하여 프린트할 수 없습니다." << endl;
                InkJetPrinter->print(0);
                Laser->print(0);
            }
            break;

        case 2:
            if (Laser->availableCount - printingCount >= 0 &&
                Laser->availableToner - printingCount >= 0) {
                cout << "프린트 하였습니다." << endl;
                InkJetPrinter->print(0);
                Laser->print(printingCount);
            }
            else {
                cout << "용지가 부족하여 프린트할 수 없습니다." << endl;
                InkJetPrinter->print(0);
                Laser->print(0);
            }
            break;
        }

        cout << "계속 프린트 하시겠습니까(y/n)>>";
        cin >> conti;

        if (conti == 'y') {
            continue;
        }
        else if (conti == 'n') {
            break;
        }
        else {
            continue;
        }
    }

}