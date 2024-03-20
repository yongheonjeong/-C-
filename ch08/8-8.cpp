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
    cout << model << " ," << manufacturer << " ,남은 종이 " << availableCount << "장 ";
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
    cout << "잉크젯 : ";
    getInfo();
    cout << "남은 잉크" << availableInk << endl;  
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

Razer::Razer(string model="SCX-6x45",string manufacturer="삼성전자",
int printedCount=0,int availableCount=3,int availableToner=20)
:  Printer(model,manufacturer,printedCount,availableCount)
{
    this->availableToner = availableToner;
    cout << "레이저 : ";
    getInfo();
    cout << "남은 토너" << availableToner << endl;  
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
    cout << "남은 잉크" << ink->getAvailableInk() << endl;  
    rzr->getInfo();
    cout << "남은 토너" << rzr->getAvailableToner() << endl;
}

int main(){

    cout << "현재 작동중인 2대의 프린터는 아래와 같다." <<endl;
    InkJet* ink = new InkJet();
    Razer* rzr = new Razer();

    int printer_select=0;
    int pages=0;
    char loop=0;
    
    while(true){
        cout << "프린터(1:잉크젯, 2:레이저)와 매수 입력 >> ";
        cin>>printer_select;
        cin>>pages;

        switch(printer_select){
            case 1:
                if(ink->getAvailableCount()-pages>=0 && ink->getAvailableInk()-pages>=0){
                    ink->printInkJet(pages);
                    cout << "프린트 하였습니다." << endl;
                    print_current_info(ink,rzr);
                    break;  
                }else{
                    cout << "용지가 부족하여 프린트 할 수 없습니다." << endl;
                    print_current_info(ink,rzr);
                    break;
                }
            case 2:
                    if(rzr->getAvailableCount()-pages>=0 && rzr->getAvailableToner()-pages>=0){
                    rzr->printRazer(pages);
                    cout << "프린트 하였습니다." << endl;
                    print_current_info(ink,rzr);
                    break;  
                }else{
                    cout << "용지가 부족하여 프린트 할 수 없습니다." << endl;
                    print_current_info(ink,rzr);
                    break;
                }
        }
        cout << "계속 프린트 하시겠습니까(y/n)>>";
        cin >> loop;

        if(loop == 'n'){
            cout << "InkPrinter로 총" << ink->getPrintedCount() << "장 출력하였습니다." << endl;
            cout << "RazerPrinter로 총" << rzr->getPrintedCount() << "장 출력하였습니다." << endl;
            cout << "프린터를 종료합니다." << endl;
            break;
        }else if(loop== 'y'){
            continue;
        }
        else{
            cout << "올바른 입력 바랍니다." << endl; 
            break;
        }
    }
}