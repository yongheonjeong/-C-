#include <iostream>
using namespace std;


class Comparable{ //8 
public:
    virtual bool operator>(Comparable& op2)=0;
    virtual bool operator<(Comparable& op2)=0;
    virtual bool operator==(Comparable& op2)=0;
};

class Circle : public Comparable{  // 8 
    int radius;
public:
    Circle(int radius=1) { this->radius = radius; }
    int getRadius() { return radius; }

    virtual bool operator>(Comparable& op2){
         Comparable* bptr = &op2;
         Circle* dptr = (Circle*)bptr;
        if(this->radius > dptr->radius)
            return true;
        else    
            return false;
    }

    virtual bool operator<(Comparable& op2){
         Comparable* bptr = &op2;
         Circle* dptr = (Circle*)bptr; 
        if(this->radius < dptr->radius)
            return true;
        else    
            return false;
    }

    virtual bool operator==(Comparable& op2){
          Comparable* bptr = &op2;
         Circle* dptr = (Circle*)bptr;
        if(this->radius == dptr->radius)
            return true;
        else    
            return false;
    }
};

template<class T>
T bigger(T a,T b){
    if(a>b) return a;
    else return b;
}

int main(){
    int a = 20,b=50,c;
    c = bigger(a,b);
    cout << "20과 50중 큰 값은 " << c << endl;
    Circle waffle(10),pizza(20),y;
    // 7번  y = bigger(waffle.getRadius(),pizza.getRadius());
    y = bigger(waffle,pizza);
    cout << "waffle 과 pizza 중 큰 것의 반지름은 " << y.getRadius() << endl;    
}