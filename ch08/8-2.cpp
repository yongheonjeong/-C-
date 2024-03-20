#include <iostream>
using namespace std;

class Circle{
int radius;
public:
    Circle(int radius=0) { this->radius = radius;}
    int getRadius(){ return radius; }
    void setRadius(int radius){ this->radius = radius; }
    double getArea() { return 3.14*radius*radius; } 
};

class NamedCircle : public Circle{
    string name;
public:
    NamedCircle();
    NamedCircle(int radius,string name);
    void setName(string name);
    string getName();
    void show();
};
NamedCircle::NamedCircle() : NamedCircle(0,""){}

NamedCircle::NamedCircle(int radius,string name) : Circle(radius) {
    this->name = name;
}

void NamedCircle::show(){
    cout << "반지름이 ";
    cout << getRadius();
    cout << "인 " << name << endl;
}

void NamedCircle::setName(string name){
    this->name = name;
}

string NamedCircle::getName(){
    return name;
}

int main(){
    NamedCircle pizza[5];
    cout << "5개의 정수 반지름과 원의 이름을 입력하세요" << endl;

    
    for(int i=0;i<5;i++){
        int radius;
        string name;
        cout << i+1 << ">> ";
        cin>>radius;
        cin>>name;
        pizza[i].setRadius(radius);
        pizza[i].setName(name); 
    }


    int max;
    string name;

    for(int i=0;i<5;i++){
       if(i==0){
        max = pizza[i].getRadius();
       }else{
        if(max<pizza[i].getRadius()){
            max = pizza[i].getRadius();
            name = pizza[i].getName();
        }
       }
    }

    cout << "가장 면적이 큰 피자는 " << name << "입니다";
    
    return 0;
}