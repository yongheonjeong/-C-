#include <iostream>
using namespace std;

class Point{
    int x,y;
public:
    Point(int x,int y) { this->x = x; this->y = y; }
    int getX() { return x; }
    int getY() { return y; }
protected:
    void move(int x,int y) { this->x = x; this->y = y; }
};

class ColorPoint : public Point{
    string name;
public:
    ColorPoint() : Point(0,0) { this->name = "BLACK"; }  //4 

    ColorPoint(int x,int y,string name) : Point(x,y){
        this->name = name;
    }

    void setPoint(int x,int y){
        move(x,y);
    }

    void setColor(string name){
        this->name = name;
    }

    void show(){
        cout << name << "������ " << "(" << getX() << "," << getY() << ")�� ��ġ�� ���Դϴ�." << endl; 
    }
};

int main(){
    ColorPoint zeroPoint; //4
    zeroPoint.show(); //4

    ColorPoint cp(5,5,"RED");
    cp.setPoint(10,20);
    cp.setColor("BLUE");
    cp.show();

}