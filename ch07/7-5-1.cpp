#include <iostream>
using namespace std;

class Color{
    int RED=0;
    int GREEN=0;
    int BLUE=0; 
public:
    Color(int RED,int GREEN,int BLUE);
    Color operator+(Color& op);
    bool operator==(Color& op);
    void show();

};

 Color Color::operator+(Color& op){
    Color tmp = *this;
    tmp.RED += op.RED;
    tmp.BLUE += op.BLUE;
    tmp.GREEN += op.GREEN;
    return tmp;
 }

 bool Color::operator==(Color& op){
    Color tmp = *this;
    if( tmp.RED == op.RED && tmp.BLUE == op.BLUE && tmp.GREEN == op.GREEN)
        return true;
    else 
        return false;
 }

Color::Color(int RED=0,int GREEN=0,int BLUE=0){
    this->RED = RED;
    this->GREEN = GREEN;
    this->BLUE = BLUE;
}
    
void Color::show(){
    cout << "RED: " << RED << " GREEN: " << GREEN << " BLUE: " << BLUE << endl;
}

int main(){
    Color red(255,0,0), blue(0,0,255),c;
    c = red + blue;
    c.show();

    Color fuchsia(255,0,255);
    if(c==fuchsia)
        cout << "����� ����";
    else
        cout << "����� �ƴ�";
    

    
}