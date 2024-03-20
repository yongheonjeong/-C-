#include <iostream>
using namespace std;

class LoopAdder{
    string name;
    int x,y,sum;
    void read();
    void write();

protected:
    LoopAdder(string name=""){
        this->name = name;
    }
    int getX() { return x; }
    int getY() { return y; }
    virtual int calculate() = 0;

public:
    void run();
};

void LoopAdder::read(){
    cout << name << ":" << endl;
    cout << "ó�� ������ �ι�° ������ ���մϴ�. �� ���� �Է��ϼ��� >> ";
    cin >> x >> y;
}

void LoopAdder::write(){
    cout << x << "����" << y << "������ �� = " << sum << " �Դϴ�." << endl;
}

void LoopAdder::run(){
    read();
    sum = calculate();
    write();
}

class ForLoopAdder : public LoopAdder{

public:
    ForLoopAdder(string name) : LoopAdder(name){}
    virtual int calculate(){
        int sum = 0;
        for(int i=getX();i<=getY();i++){
            sum += i;
        }
        return sum;
    }
};

class WhileLoopAdder : public LoopAdder{

public:
    WhileLoopAdder(string name) : LoopAdder(name){}
    virtual int calculate(){
        int sum = 0;
        int i = getX();
        while(i<=getY()){
            sum += i;
            i++;
        }
        return sum;
    }
};

class DoWhileLoopAdder : public LoopAdder{

public:
    DoWhileLoopAdder(string name) : LoopAdder(name){}
    virtual int calculate(){
        int sum = 0;
        int i=getX();
        do{
            sum += i;
            i++;
        }while(i<=getY());
        
        return sum;
    }
};


int main(){
    ForLoopAdder forLoop("For Loop");
    forLoop.run();

    WhileLoopAdder whileLoop("While Loop");
    DoWhileLoopAdder doWhileLoop("Do While Loop");

    whileLoop.run();
    doWhileLoop.run();
}