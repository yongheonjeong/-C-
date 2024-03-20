#include <iostream>
using namespace std;

class Printer {
public:
    string model, manufacturer;
    int printedCount, availableCount;
    virtual void print(int pages) = 0;
    virtual void show() {
        cout << model << " ," << manufacturer << " ," << "���� ���� " << availableCount << "�� ,";
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

        cout << " ������ : ";
        show();
        cout << "���� ��� " << availableInk << endl;
    }

    virtual void print(int pages)
    {
        printedCount = pages;
        availableInk -= printedCount;
        availableCount -= printedCount;
        show();
        cout << "���� ��ũ " << availableInk << endl;
    }



};

class LaserPrinter : public Printer {
public:
    int availableToner;

    LaserPrinter(string model = "SCX-6x45", string manufacturer = "�Ｚ����", int availableCount = 3, int availableToner = 20)
    {
        this->model = model;
        this->manufacturer = manufacturer;
        this->availableCount = availableCount;
        this->availableToner = availableToner;

        cout << " ������ : ";
        show();
        cout << "���� ��� " << availableToner << endl;

    }

    virtual void print(int pages) {

        printedCount = pages;
        availableToner -= printedCount;
        availableCount -= printedCount;
        show();
        cout << "���� ��� " << availableToner << endl;
    }

 
};


int main() {
    cout << "���� �۵����� 2 ���� �����ʹ� �Ʒ��� ����" << endl;
    InkJet* InkJetPrinter = new InkJet;
    LaserPrinter* Laser = new LaserPrinter;

    int choice = 0;
    int printingCount = 0;
    char conti;
    while (true) {
        cout << "������(1:��ũ��, 2:������)�� �ż� �Է�>>";
        cin >> choice >> printingCount;

        switch (choice) {
        case 1:
            if (InkJetPrinter->availableCount - printingCount >= 0 &&
                InkJetPrinter->availableInk - printingCount >= 0) {
                cout << "����Ʈ �Ͽ����ϴ�." << endl;
                InkJetPrinter->print(printingCount);
                Laser->print(0);
            }
            else {
                cout << "������ �����Ͽ� ����Ʈ�� �� �����ϴ�." << endl;
                InkJetPrinter->print(0);
                Laser->print(0);
            }
            break;

        case 2:
            if (Laser->availableCount - printingCount >= 0 &&
                Laser->availableToner - printingCount >= 0) {
                cout << "����Ʈ �Ͽ����ϴ�." << endl;
                InkJetPrinter->print(0);
                Laser->print(printingCount);
            }
            else {
                cout << "������ �����Ͽ� ����Ʈ�� �� �����ϴ�." << endl;
                InkJetPrinter->print(0);
                Laser->print(0);
            }
            break;
        }

        cout << "��� ����Ʈ �Ͻðڽ��ϱ�(y/n)>>";
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