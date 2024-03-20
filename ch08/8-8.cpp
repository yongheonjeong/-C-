#include <iostream>
using namespace std;

class Printer{
    string model,manufacturer;
    int printedCount,availableCount;
public:
    void print(int pages);
    Printer(string model,string manufacturer,int printedCount,int availableCount);
    int getAvailableCount();
    void getInfo();
    int getPrintedCount();
};

Printer::Printer(string model,string manufacturer,int printedCount,int availableCount){
    this->model = model;
    this->manufacturer = manufacturer;
    this->printedCount = printedCount;
    this->availableCount = availableCount;
    
}

void Printer::print(int pages){
    availableCount -= pages;
    printedCount += pages;
}


int Printer::getAvailableCount(){
    return availableCount;
}

void Printer::getInfo(){
    cout << model << " ," << manufacturer << " ,���� ���� " << availableCount << "�� ";
}

  int Printer::getPrintedCount(){
        return printedCount;
  }

class InkJet : public Printer{
    int availableInk;
public:
    InkJet(string model,string manufacturer,int printedCount,int availableCount,int availableInk);
    void printInkJet(int pages);
    int getAvailableInk();
    ~InkJet();
};

InkJet::InkJet(string model="Officejet V40",string manufacturer="HP",
int printedCount=0,int availableCount=5,int availableInk=10)
 : Printer(model,manufacturer,printedCount,availableCount)
{
    this->availableInk = availableInk;
    cout << "��ũ�� : ";
    getInfo();
    cout << "���� ��ũ" << availableInk << endl;  
}

void InkJet::printInkJet(int pages){
    this->availableInk -= pages;
    print(pages);
}

int InkJet::getAvailableInk(){
    return availableInk;
}

InkJet::~InkJet(){
    cout << "InkJet destructor" << endl;
}


class Razer : public Printer{
    int availableToner;
public:    
    Razer(string model,string manufacturer,int printedCount,int availableCount,int availableToner);
    void printRazer(int pages); 
    int getAvailableToner();
    ~Razer();
};

Razer::Razer(string model="SCX-6x45",string manufacturer="�Ｚ����",
int printedCount=0,int availableCount=3,int availableToner=20)
:  Printer(model,manufacturer,printedCount,availableCount)
{
    this->availableToner = availableToner;
    cout << "������ : ";
    getInfo();
    cout << "���� ���" << availableToner << endl;  
}

void Razer::printRazer(int pages){
    this->availableToner -= pages;
    print(pages);
}

int Razer::getAvailableToner(){
    return availableToner;
}

Razer::~Razer(){
    cout << "Razer destructor" << endl;
}

void print_current_info(InkJet* ink,Razer* rzr){

    ink->getInfo();
    cout << "���� ��ũ" << ink->getAvailableInk() << endl;  
    rzr->getInfo();
    cout << "���� ���" << rzr->getAvailableToner() << endl;
}

int main(){

    cout << "���� �۵����� 2���� �����ʹ� �Ʒ��� ����." <<endl;
    InkJet* ink = new InkJet();
    Razer* rzr = new Razer();

    int printer_select=0;
    int pages=0;
    char loop=0;
    
    while(true){
        cout << "������(1:��ũ��, 2:������)�� �ż� �Է� >> ";
        cin>>printer_select;
        cin>>pages;

        switch(printer_select){
            case 1:
                if(ink->getAvailableCount()-pages>=0 && ink->getAvailableInk()-pages>=0){
                    ink->printInkJet(pages);
                    cout << "����Ʈ �Ͽ����ϴ�." << endl;
                    print_current_info(ink,rzr);
                    break;  
                }else{
                    cout << "������ �����Ͽ� ����Ʈ �� �� �����ϴ�." << endl;
                    print_current_info(ink,rzr);
                    break;
                }
            case 2:
                    if(rzr->getAvailableCount()-pages>=0 && rzr->getAvailableToner()-pages>=0){
                    rzr->printRazer(pages);
                    cout << "����Ʈ �Ͽ����ϴ�." << endl;
                    print_current_info(ink,rzr);
                    break;  
                }else{
                    cout << "������ �����Ͽ� ����Ʈ �� �� �����ϴ�." << endl;
                    print_current_info(ink,rzr);
                    break;
                }
        }
        cout << "��� ����Ʈ �Ͻðڽ��ϱ�(y/n)>>";
        cin >> loop;

        if(loop == 'n'){
            cout << "InkPrinter�� ��" << ink->getPrintedCount() << "�� ����Ͽ����ϴ�." << endl;
            cout << "RazerPrinter�� ��" << rzr->getPrintedCount() << "�� ����Ͽ����ϴ�." << endl;
            cout << "�����͸� �����մϴ�." << endl;
            break;
        }else if(loop== 'y'){
            continue;
        }
        else{
            cout << "�ùٸ� �Է� �ٶ��ϴ�." << endl; 
            break;
        }
    }
}