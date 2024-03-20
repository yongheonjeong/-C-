#include <iostream>
using namespace std;

class Circle{
    int radius;
public:
    Circle(int radius=0) { this->radius = radius; }
    void show(){ cout << "radius = " << radius << " ÀÎ ¿ø " << endl; }
    Circle& operator++();
    Circle operator++(int x);
};

Circle& Circle::operator++(){
    Circle& tmp = *this;
    tmp.radius++;
    return tmp;
}

Circle Circle::operator++(int x){
    Circle tmp = *this;
    radius++;
    return tmp;
}


int main(){
Circle a(5),b(4);
++a;
b = a++;
a.show();
b.show();

}