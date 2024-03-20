#include <iostream>
using namespace std;

class Converter{

protected:
    double ratio;
    virtual double convert(double src) = 0;
    virtual string getSourceString() = 0;
    virtual string getDestString() = 0;

public:
    Converter(double ratio) { this->ratio = ratio; }
    void run(){
        double src;
        cout << getSourceString() << "�� " << getDestString() << "�� �ٲߴϴ�. ";
        cout << getSourceString() << "�� �Է��ϼ��� >> ";
        cin >> src;
        cout << " ��ȯ ��� : " << convert(src) << getDestString() << endl;
    }
};

class WonToDollar : public Converter{
    
public:
    WonToDollar(double ratio) : Converter(ratio) {}

     virtual double convert(double src){
        double won = src;
        double dollar = won / ratio;
        return dollar;
    }

    virtual string getSourceString(){
        return "��";
    }
    virtual string getDestString(){
        return "�޷�";
    }
};

class KmToMile : public Converter{

public:
    KmToMile(double ratio) : Converter(ratio){}

    virtual double convert(double src){
        double KM = src;
        double Mile = KM / ratio;
        return Mile;
    }

    virtual string getSourceString(){
        return "Km";
    }
    virtual string getDestString(){
        return "Mile";
    }
};

int main(){
WonToDollar wd(1010);
wd.run();

KmToMile toMile(1.609341907907019);
toMile.run();
}